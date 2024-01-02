/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=BR--_W8odmw
    Company Tags                : Added YouTube Link
    Leetcode Link               : https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/
*/

/****************************************************************** C++ ******************************************************************/
//Approach (Using frequency of elements)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        
        //unordered_map<int, int> mp;
        //Since 1 <= nums[i] <= nums.length (you can also use vector of size n)
        vector<int> mp(n+1);
        
        vector<vector<int>> result;

        for(int &num : nums) {
            int freq = mp[num];
            
            if(freq == result.size()) {
                result.push_back({});
            }
            
            result[freq].push_back(num);
            mp[num]++;
        }
        
        return result;
        
    }
};


/****************************************************************** JAVA ******************************************************************/
//Approach (Using frequency of elements)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public List<List<Integer>> findMatrix(int[] nums) {
        //Since 1 <= nums[i] <= nums.length (you can also use vector of size n to store frequency)
        int mp[] = new int[nums.length + 1];

        ArrayList<List<Integer>> result = new ArrayList<>();
        
        for (int c : nums) {
            
            if (mp[c] == result.size()) {
                result.add(new ArrayList<>());
            }

            result.get(mp[c]).add(c);
            mp[c]++;
        }

        return result;
    }
}
