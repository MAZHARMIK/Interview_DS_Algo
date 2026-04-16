/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/closest-equal-element-queries
*/


/************************************************************ C++ *****************************************************/
//Approach - Store in map and use binary search to find indices
//T.C : O(Q * log(n))
//S.C : O(n)
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        
        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> result;

        for(int qi : queries) { //O(Q)
            int element = nums[qi];
            vector<int>& vec = mp[element];

            int sz = vec.size();

            //no more occurence of this element
            if(sz == 1) {
                result.push_back(-1);
                continue;
            }

            int pos = lower_bound(begin(vec), end(vec), qi) - begin(vec); //log(n)
            int res = INT_MAX;

            //Right Neighbour - pos+1
            int right = vec[(pos+1) % sz];
            int d = abs(qi - right);//straught forqward distance
            int circularDist = n-d;
            res = min({res, d, circularDist});


            //Left Neighbour - pos-1
            int left = vec[(pos-1+sz) % sz];
            d = abs(qi - left);//straught forqward distance
            circularDist = n-d;
            res = min({res, d, circularDist});

            result.push_back(res);
        }

        return result;
    }
};


/************************************************************ JAVA *****************************************************/
//Approach - Store in map and use binary search to find indices
//T.C : O(Q * log(n))
//S.C : O(n)
class Solution {
    public List<Integer> solveQueries(int[] nums, int[] queries) {
        int n = nums.length;

        Map<Integer, List<Integer>> mp = new HashMap<>();

        // store indices
        for (int i = 0; i < n; i++) {
            mp.computeIfAbsent(nums[i], k -> new ArrayList<>()).add(i);
        }

        List<Integer> result = new ArrayList<>();

        for (int qi : queries) { // O(Q)
            int element = nums[qi];
            List<Integer> vec = mp.get(element);

            int sz = vec.size();

            // no more occurrence
            if (sz == 1) {
                result.add(-1);
                continue;
            }

            int pos = Collections.binarySearch(vec, qi);
            int res = Integer.MAX_VALUE;

            // Right neighbor
            int right = vec.get((pos + 1) % sz);
            int d = Math.abs(qi - right);
            int circularDist = n - d;
            res = Math.min(res, Math.min(d, circularDist));

            // Left neighbor
            int left = vec.get((pos - 1 + sz) % sz);
            d = Math.abs(qi - left);
            circularDist = n - d;
            res = Math.min(res, Math.min(d, circularDist));

            result.add(res);
        }

        return result;
    }
}
