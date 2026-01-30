/*   Scroll below to see JAVA code also  */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=RnCZCzFivl8
    Company Tags                : Will udpate later
    Leetcode Link               : https://leetcode.com/problems/construct-the-minimum-bitwise-array-ii
*/


/******************************************************* C++ *******************************************************/
//Approach (Brute Force All Possible Answers)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> result;


        for(int &num : nums) {
            if(num == 2) {
                result.push_back(-1);
                continue;
            }

            bool found = false;
            for(int j = 1; j < 32; j++) {
                if((num & (1 << j)) > 0) { //set bit
                    continue;
                }

                //we found an unset bit at jth position
                result.push_back((num ^ (1 << (j-1)))); //set the first set bit to 0
                found = true;
                break;
            }

            if(!found)
                result.push_back(-1);
        }

        return result;
    }
};



/******************************************************* JAVA *******************************************************/
//Approach (Brute Force All Possible Answers)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int[] minBitwiseArray(List<Integer> nums) {
        int n = nums.size();
        int[] result = new int[n];

        for (int i = 0; i < n; i++) {
            int num = nums.get(i);

            if (num == 2) {
                result[i] = -1;
                continue;
            }

            boolean found = false;

            for (int j = 1; j < 32; j++) {
                // if jth bit is set, skip
                if ((num & (1 << j)) != 0) {
                    continue;
                }

                // found an unset bit at position j
                // flip (j-1)th bit
                result[i] = num ^ (1 << (j - 1));
                found = true;
                break;
            }

            if (!found) {
                result[i] = -1;
            }
        }

        return result;
    }
}
