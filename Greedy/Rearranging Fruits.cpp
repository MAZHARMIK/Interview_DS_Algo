/*         Scroll below to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/rearranging-fruits/description/
*/


/********************************************************************** C++ **********************************************************************/
//Approach (Greedily swapping directly element or swapping via minimum element)
//T.C : O(n), Average time complexity of nth_element is O(n)
//S.C : O(n)
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> mp;
        int minEl = INT_MAX;

        for(int &x : basket1) {
            mp[x]++;
            minEl = min(minEl, x);
        }

        for(int &x : basket2) {
            mp[x]--;
            minEl = min(minEl, x);
        }

        vector<int> finalList;
        for(auto &it : mp) {
            int cost  = it.first;
            int count = it.second;

            if(count == 0) {
                continue;
            }

            if(count % 2 != 0) {
                return -1;
            }

            for(int c = 1; c <= abs(count)/2; c++) {
                finalList.push_back(cost);
            }
        }

        //sort(begin(finalList), end(finalList)); //no need to sort entire array
        nth_element(begin(finalList), begin(finalList)+finalList.size()/2, end(finalList));

        long long result = 0;
        for(int i = 0; i < finalList.size()/2; i++) {
            result += min(finalList[i], minEl*2);
        }

        return result;

    }
};



/********************************************************************** JAVA **********************************************************************/
//Approach (Greedily swapping directly element or swapping via minimum element)
//T.C : O(n), Average time complexity of nth_element is O(n)
//S.C : O(n)
class Solution {
    public long minCost(int[] basket1, int[] basket2) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        int minEl = Integer.MAX_VALUE;

        // Populate the map and find the minimum element from basket1
        for (int x : basket1) {
            mp.put(x, mp.getOrDefault(x, 0) + 1);
            minEl = Math.min(minEl, x);
        }

        // Update the map with elements from basket2
        for (int x : basket2) {
            mp.put(x, mp.getOrDefault(x, 0) - 1);
            minEl = Math.min(minEl, x);
        }

        ArrayList<Integer> finalList = new ArrayList<>();

        // Process the map to create finalList
        for (Map.Entry<Integer, Integer> entry : mp.entrySet()) {
            int cost = entry.getKey();
            int count = entry.getValue();

            if (count == 0) {
                continue;
            }

            if (count % 2 != 0) {
                return -1;  // Immediate return if counts are not even
            }

            // Add half of the count to finalList
            for (int c = 1; c <= Math.abs(count) / 2; c++) {
                finalList.add(cost);
            }
        }

        // Find the min of the elements
        Collections.sort(finalList); // Since we're dealing with costs, we can sort to find the minimum values
        long result = 0;

        // Calculate the minimum cost by using the least costs
        for (int i = 0; i < finalList.size() / 2; i++) {
            result += Math.min(finalList.get(i), minEl * 2);
        }

        return result;
    }
}
