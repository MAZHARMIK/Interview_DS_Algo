/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/total-waviness-of-numbers-in-range-ii/
*/

/*********************************************************** C++ **************************************************/
//Approach-1 (Digit DP - Counting waviness contribution per position)
//T.C : O(n * 10 * 10 * 10) where n = number of digits ~ O(1) since n <= 15
//S.C : O(n * 10 * 10) for memoization
class Solution {
public:
    typedef long long ll;
    string s;
    int n;

    ll dpTotalNumbers[16][10][10];
    ll dpTotalWaviness[16][10][10];

    pair<ll, ll> solve(int curr, int prevPrev, int prev, bool isLimitedWithActualNumber, bool isLeadingZero) {
        if (curr == n) {
            return {1, 0}; // no more score can be generated and we found one last number
        }

        if (!isLimitedWithActualNumber && !isLeadingZero && prevPrev >= 0 && prev >= 0) {
            if (dpTotalNumbers[curr][prevPrev][prev] != -1) {
                return {dpTotalNumbers[curr][prevPrev][prev], dpTotalWaviness[curr][prevPrev][prev]};
            }
        }

        ll totalNumbers   = 0;
        ll totalWaveScore = 0;

        int limitDigit = isLimitedWithActualNumber ? (s[curr] - '0') : 9;

        for (int digit = 0; digit <= limitDigit; digit++) {
            bool newIsLeadingZero = isLeadingZero && (digit == 0);

            int newPrevPrev = prev;
            int newPrev     = newIsLeadingZero ? -1 : digit;

            auto [remainTotalNumbers, remainTotalWaveScore] = solve(
                curr + 1, newPrevPrev, newPrev,
                isLimitedWithActualNumber && (digit == limitDigit),
                newIsLeadingZero
            );

            if (!newIsLeadingZero && prevPrev >= 0 && prev >= 0) {
                bool isPeak   = (prevPrev < prev && prev > digit);
                bool isValley = (prevPrev > prev && prev < digit);

                if (isPeak || isValley) {
                    totalWaveScore += remainTotalNumbers;
                }
            }

            totalNumbers   += remainTotalNumbers;
            totalWaveScore += remainTotalWaveScore;
        }

        if (!isLimitedWithActualNumber && !isLeadingZero && prevPrev >= 0 && prev >= 0) {
            dpTotalNumbers[curr][prevPrev][prev]  = totalNumbers;
            dpTotalWaviness[curr][prevPrev][prev] = totalWaveScore;
        }

        return {totalNumbers, totalWaveScore};
    }

    ll func(ll num) {
        if (num < 100) { // we need at least 3 digits (0 to 99 are invalid)
            return 0;
        }

        memset(dpTotalNumbers, -1, sizeof(dpTotalNumbers));
        memset(dpTotalWaviness, -1, sizeof(dpTotalWaviness));

        s = to_string(num);
        n = s.length();

        auto [totalNumbers, totalWaveScore] = solve(0, -1, -1, true, true);

        return totalWaveScore;
    }

    long long totalWaviness(long long num1, long long num2) {
        return func(num2) - func(num1 - 1);
    }
};

/*********************************************************** JAVA **************************************************/
//Approach-1 (Digit DP - Counting waviness contribution per position)
//T.C : O(n * 10 * 10 * 10) where n = number of digits ~ O(1) since n <= 15
//S.C : O(n * 10 * 10) for memoization
class Solution {
    String s;
    int n;
    long[][] dpTotalNumbers  = new long[16][10 * 10];
    long[][] dpTotalWaviness = new long[16][10 * 10];
    boolean[][] visited      = new boolean[16][10 * 10];

    private long[] solve(int curr, int prevPrev, int prev, boolean isLimited, boolean isLeadingZero) {
        if (curr == n) {
            return new long[]{1, 0};
        }

        int key = (prevPrev < 0 ? 0 : prevPrev) * 10 + (prev < 0 ? 0 : prev);

        if (!isLimited && !isLeadingZero && prevPrev >= 0 && prev >= 0) {
            if (visited[curr][key]) {
                return new long[]{dpTotalNumbers[curr][key], dpTotalWaviness[curr][key]};
            }
        }

        long totalNumbers   = 0;
        long totalWaveScore = 0;
        int  limitDigit     = isLimited ? (s.charAt(curr) - '0') : 9;

        for (int digit = 0; digit <= limitDigit; digit++) {
            boolean newIsLeadingZero = isLeadingZero && (digit == 0);
            int newPrevPrev = prev;
            int newPrev     = newIsLeadingZero ? -1 : digit;

            long[] result = solve(
                curr + 1, newPrevPrev, newPrev,
                isLimited && (digit == limitDigit),
                newIsLeadingZero
            );

            long remNumbers   = result[0];
            long remWaveScore = result[1];

            if (!newIsLeadingZero && prevPrev >= 0 && prev >= 0) {
                boolean isPeak   = (prevPrev < prev && prev > digit);
                boolean isValley = (prevPrev > prev && prev < digit);

                if (isPeak || isValley) {
                    totalWaveScore += remNumbers;
                }
            }

            totalNumbers   += remNumbers;
            totalWaveScore += remWaveScore;
        }

        if (!isLimited && !isLeadingZero && prevPrev >= 0 && prev >= 0) {
            dpTotalNumbers[curr][key]  = totalNumbers;
            dpTotalWaviness[curr][key] = totalWaveScore;
            visited[curr][key]         = true;
        }

        return new long[]{totalNumbers, totalWaveScore};
    }

    private long func(long num) {
        if (num < 100) return 0;

        dpTotalNumbers  = new long[16][100];
        dpTotalWaviness = new long[16][100];
        visited         = new boolean[16][100];

        s = Long.toString(num);
        n = s.length();

        long[] result = solve(0, -1, -1, true, true);
        return result[1];
    }

    public long totalWaviness(long num1, long num2) {
        return func(num2) - func(num1 - 1);
    }
}
