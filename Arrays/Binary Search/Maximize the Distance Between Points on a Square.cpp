/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/maximize-the-distance-between-points-on-a-square/
*/



/****************************************************************** C++ ******************************************************************/
//Approach-1 (Binary Search + Backtracking Brute Force)
//T.C : O(n^k * k² * log side)
//S.C : O(k)
class Solution {
public:
    int manhattan(vector<int>& vec1, vector<int>& vec2) {
        return abs(vec1[0] - vec2[0]) + abs(vec1[1] - vec2[1]);
    }

    bool solve(vector<vector<int>>& points, int k, int d, int start, vector<int>& chosen) {
        if (chosen.size() == k)
            return true;
        
        for (int i = start; i < points.size(); i++) {
            bool valid = true;
            for (int idx : chosen) {
                if (manhattan(points[i], points[idx]) < d) {
                    valid = false;
                    break;
                }
            }
            if (!valid)
                continue;
            
            chosen.push_back(i);
            if (solve(points, k, d, i + 1, chosen))
                return true;
            chosen.pop_back();
        }
        return false;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int l = 0, r = 2 * side;
        int best = 0;
        
        while (l <= r) {
            int mid = (l + r) / 2;
            vector<int> chosen;
            
            if (solve(points, k, mid, 0, chosen)) {
                best = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return best;
    }
};



//Approach-2 (Binary Search + Optimised check)
//T.C : O(nlogn + log(side) + nlogn)
//S.C : O(n)
class Solution {
public:
    typedef long long ll;

    ll get1D(int side, int x, int y) {
        if (y == 0) 
            return x; 
        if (x == side)
            return side + y;
        if (y == side)
            return 3LL * side - x;
        
        return 4LL * side - y;
    }
    
    bool canSelectKPoints(const vector<ll>& extended, int n, int k, int side, int minDist) {
        ll perimeter = 4LL * side;
        
        for (int i = 0; i < n; i++) {
            int count = 1;
            int index = i;
            ll lastPos = extended[i];

            for (int j = 1; j < k; j++) {
                ll target = lastPos + minDist;
                auto it = lower_bound(extended.begin() + index + 1, extended.begin() + i + n, target);
                if (it == extended.begin() + i + n) break;

                index = it - extended.begin();
                lastPos = extended[index];
                count++;
            }

            if (count == k && (extended[i] + perimeter - lastPos) >= minDist)
                return true;
        }
        return false;
    }
    
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<ll> positions(n);
        ll perimeter = 4LL * side;

        for (int i = 0; i < n; i++)
            positions[i] = get1D(side, points[i][0], points[i][1]);

        sort(positions.begin(), positions.end());

        vector<ll> extended(2 * n);
        for (int i = 0; i < n; i++) {
            extended[i] = positions[i];
            extended[i + n] = positions[i] + perimeter;
        }

        int left = 0, right = 2 * side, result = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canSelectKPoints(extended, n, k, side, mid)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
};



/****************************************************************** Java ******************************************************************/
// Approach-1 (Binary Search + Backtracking Brute Force)
// T.C : O(n^k * k² * log side)
// S.C : O(k)
class Solution {
    public int manhattan(int[] vec1, int[] vec2) {
        return Math.abs(vec1[0] - vec2[0]) + Math.abs(vec1[1] - vec2[1]);
    }

    public boolean solve(int[][] points, int k, int d, int start, List<Integer> chosen) {
        if (chosen.size() == k)
            return true;
        
        for (int i = start; i < points.length; i++) {
            boolean valid = true;
            for (int idx : chosen) {
                if (manhattan(points[i], points[idx]) < d) {
                    valid = false;
                    break;
                }
            }
            if (!valid)
                continue;
            
            chosen.add(i);
            if (solve(points, k, d, i + 1, chosen))
                return true;
            chosen.remove(chosen.size() - 1);
        }
        return false;
    }

    public int maxDistance(int side, int[][] points, int k) {
        int l = 0, r = 2 * side;
        int best = 0;
        
        while (l <= r) {
            int mid = (l + r) / 2;
            List<Integer> chosen = new ArrayList<>();
            
            if (solve(points, k, mid, 0, chosen)) {
                best = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return best;
    }
}


// Approach-2 (Binary Search + Optimized Check)
// T.C : O(nlogn + log(side) + nlogn)
// S.C : O(n)
class Solution {
    public long get1D(int side, int x, int y) {
        if (y == 0) 
            return x; 
        if (x == side)
            return side + y;
        if (y == side)
            return 3L * side - x;
        
        return 4L * side - y;
    }
    
    public boolean canSelectKPoints(long[] extended, int n, int k, int side, int minDist) {
        long perimeter = 4L * side;
        
        for (int i = 0; i < n; i++) {
            int count = 1;
            int index = i;
            long lastPos = extended[i];

            for (int j = 1; j < k; j++) {
                long target = lastPos + minDist;
                int it = Arrays.binarySearch(extended, index + 1, i + n, target);
                if (it < 0) it = -it - 1; 
                if (it == i + n) break;

                index = it;
                lastPos = extended[index];
                count++;
            }

            if (count == k && (extended[i] + perimeter - lastPos) >= minDist)
                return true;
        }
        return false;
    }
    
    public int maxDistance(int side, int[][] points, int k) {
        int n = points.length;
        long[] positions = new long[n];
        long perimeter = 4L * side;

        for (int i = 0; i < n; i++)
            positions[i] = get1D(side, points[i][0], points[i][1]);

        Arrays.sort(positions);

        long[] extended = new long[2 * n];
        for (int i = 0; i < n; i++) {
            extended[i] = positions[i];
            extended[i + n] = positions[i] + perimeter;
        }

        int left = 0, right = 2 * side, result = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canSelectKPoints(extended, n, k, side, mid)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
}
