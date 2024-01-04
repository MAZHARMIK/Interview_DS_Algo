/*
    MY YOUTUBE VIDEO ON THIS Qn   : https://www.youtube.com/watch?v=LK0c7tCzKmM
    Company Tags                  : Google, Amazon, Microsoft, Ola Cabs, Qualcomm
    Leetcode Link                 : https://leetcode.com/problems/single-number-ii/
    GfG Link                      : https://www.geeksforgeeks.org/problems/find-element-occuring-once-when-all-other-are-present-thrice/1
*/

//Approach-1
/*
    Simply maintain a unordered_map. 
    Find the element having frequency 1
    Space Complexity = O(n)
    Time Complexity = O(n)
*/

//Approach-2
/*
    Sort + Smart Traversal
    Time - O(nlogn)
    Space - No extra space
*/

//Approach - 3 (Time Complexity : O(32*n))
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int result = 0;
        
        for(int i = 0; i<32; i++) {
            
            int temp = (1 << i);
            
            int countOne  = 0;
            int countZero = 0;
            
            for(int &num : nums) {
                
                if((num&temp) == 0) {
                    countZero++;
                } else {
                    countOne++;
                }
                
            }
            
            if(countOne % 3 == 1) {
                result = (result | temp);
            }
            
        }
        
        return result;
        
    }
};
