/*
    MY YOUTUBE VIDEO FOR THIS Qn : https://www.youtube.com/watch?v=gsSLay-wcaw
    Company Tags                 : Amazon
    Leetcode Link                : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size()-1;
        
        while(i < j) {
            if(numbers[i]+numbers[j] == target) {
                return {i+1, j+1};
            }
            
            if(numbers[i]+numbers[j] > target)
                j--;
            else
                i++;
        }
        return {};
    }
};
