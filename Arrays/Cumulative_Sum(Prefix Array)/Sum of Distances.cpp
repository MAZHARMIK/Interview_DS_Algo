/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn    : https://www.youtube.com/watch?v=qCE3U8MkOhA
    Company Tags                   : Will update later
    Leetcode Link                  : https://leetcode.com/problems/sum-of-distances/description
*/


/************************************************************ C++ *****************************************************/
//Approach (Using prefix sum and map)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    typedef long long ll;

    vector<ll> distance(vector<int>& nums) {
        int n = nums.size();

        vector<ll> arr(n, 0);

        unordered_map<int, ll> indexSum;   //nums[i] -> sum of i's
        unordered_map<int, ll> indexCount; //nums[i] -> frequency

        //Left to Right
        for(int i = 0; i < n; i++) {
            ll freq = indexCount[nums[i]];
            ll sum  = indexSum[nums[i]];

            arr[i] += freq*i - sum;

            indexCount[nums[i]] += 1;
            indexSum[nums[i]]   += i;
        }

        indexSum.clear();
        indexCount.clear();

        //Right to Left
        for(int i = n-1; i >= 0; i--) {
            ll freq = indexCount[nums[i]];
            ll sum  = indexSum[nums[i]];

            arr[i] += sum - freq*i;

            indexCount[nums[i]] += 1;
            indexSum[nums[i]]   += i;
        }

        return arr;
    }
};




/************************************************************ JAVA *****************************************************/
//Approach (Using prefix sum and map)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public long[] distance(int[] nums) {
        int n = nums.length;
        long[] arr = new long[n];

        Map<Integer, Long> indexSum = new HashMap<>();
        Map<Integer, Long> indexCount = new HashMap<>();

        // Left to Right
        for (int i = 0; i < n; i++) {
            long freq = indexCount.getOrDefault(nums[i], 0L);
            long sum  = indexSum.getOrDefault(nums[i], 0L);

            arr[i] += freq * i - sum;

            indexCount.put(nums[i], freq + 1);
            indexSum.put(nums[i], sum + i);
        }

        indexSum.clear();
        indexCount.clear();

        // Right to Left
        for (int i = n - 1; i >= 0; i--) {
            long freq = indexCount.getOrDefault(nums[i], 0L);
            long sum  = indexSum.getOrDefault(nums[i], 0L);

            arr[i] += sum - freq * i;

            indexCount.put(nums[i], freq + 1);
            indexSum.put(nums[i], sum + i);
        }

        return arr;
    }
}
