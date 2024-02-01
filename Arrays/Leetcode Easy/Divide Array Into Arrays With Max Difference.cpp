/*                                        Scroll down to see JAVA code also                                              /*

/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=lmLHdY7nd2M
    Company Tags                : Google
    Leetcode Link               : https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/
*/

/************************************************************ C++ **************************************************/
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> result;
        
        sort(begin(nums), end(nums));
        
        for(int i = 0; i <= n-3; i += 3) {
            if(nums[i+2] - nums[i] > k) {
                return {};
            }
            
            result.push_back({nums[i], nums[i+1], nums[i+2]});
        }
        
        return result;
    }
};


/************************************************************ JAVA **************************************************/
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
    public int[][] divideArray(int[] nums, int k) {
        int n = nums.length;

        Arrays.sort(nums);

        int[][] result = new int[n / 3][3];
        int index = 0;

        for (int i = 0; i <= n - 3; i += 3) {
            if (nums[i + 2] - nums[i] > k) {
                return new int[0][0];
            }

            result[index++] = new int[]{nums[i], nums[i + 1], nums[i + 2]};
        }

        return result;
    }
}
