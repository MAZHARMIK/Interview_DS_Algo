/*
    Company Tags  : Google
    Leetcode Link : https://leetcode.com/problems/shortest-distance-to-target-color/   (Leetcode - 1182)
    
    Since this is a premium question, I am providing the Description and exmaple here :
    Problem:

    You are given an array colors, in which there are three colors: 1, 2 and 3.

    You are also given some queries. Each query consists of two integers i and c,
    return the shortest distance between the given index i and the target color c. If there is no solution return -1.


    Example 1:

    Input: colors = [1,1,2,1,3,2,2,3,3], queries = [[1,3],[2,2],[6,1]]
    Output: [3,0,3]
    Explanation: 
    The nearest 3 from index 1 is at index 4 (3 steps away).
    The nearest 2 from index 2 is at index 2 itself (0 steps away).
    The nearest 1 from index 6 is at index 3 (3 steps away).

    Example 2:

    Input: colors = [1,2], queries = [[0,3]]
    Output: [-1]
    Explanation: There is no 3 in the array.

    Constraints:

        1 <= colors.length <= 5*10^4
        1 <= colors[i] <= 3
        1 <= queries.length <= 5*10^4
        queries[i].length == 2
        0 <= queries[i][0] < colors.length
        1 <= queries[i][1] <= 3
*/

//Approach (Look at the constraints man, it definitely can't be done in O(n^2) which is a naive approach)
//So, we use binary search or C++ STL (lower_bound)


class Solution {
public:
    int getClosestIndex(vector<int>& nums, int& targetIndex) {
        int pos = lower_bound(begin(nums), end(nums), targetIndex) - nums.begin();

        if(pos == 0)
            return nums[0];

        if(pos ==  nums.size()) {
            return nums[nums.size()-1];
        }

        //it can be either closest to nums[pos] or nums[pos-1]
        if(nums[pos] - targetIndex < targetIndex - nums[pos-1])
            return nums[pos];
        
        return nums[pos-1];
    }

    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size();
        vector<int> result;
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i<n; i++) {
            mp[colors[i]].push_back(i);
        }

        for(vector<int> &query : queries) {
            int targetIndex = query[0];
            int targetColor = query[1];
            if(mp.find(targetColor) == end(mp)) {
                result.push_back(-1);
                continue;
            }

            int closeIdx = getClosestIndex(mp[targetColor], targetIndex);

            result.push_back(abs(targetIndex - closeIdx));
        }

        return result;
    }
};

//This is written just to test my code above
int main() {
    vector<int> colors{1, 1, 2, 1, 3, 2, 2, 3, 3};
    vector<vector<int>> queries = {{1,3},{2,2},{6,1}};

    Solution obj;
    vector<int> result = obj.shortestDistanceColor(colors, queries);
    for(int &x : result)
        cout << x << " ";

return 0;
}
