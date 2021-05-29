/*
  Company Tags : codenation, Amazon, MakeMyTrip, MAQ Software, Wipro, SAP Labs
  Link to Qn : https://leetcode.com/problems/rotate-array/
*/

//Approach-1 (Writing own reversal function)
class Solution {
public:
    void reverse(vector<int>& nums, int start, int end){
        int temp;
        while(start < end){
            temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        
	//right rotate
        reverse(nums, 0, n-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, n-1);
	
	/*
	Just for knowledge
	//left rotate
        reverse(nums, 0, k);
        reverse(nums, k+1, n-1);
        reverse(nums, 0, n-1);
	*/
    }
};

//Approach-2 (Using C++ STL)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
		
		//Right rotation
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
		
		//Left rotation
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
