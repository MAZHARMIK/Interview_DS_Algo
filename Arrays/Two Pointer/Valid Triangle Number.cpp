/*
    Company Tags  : Google (variation in qn)
    Leetcode Link : https://leetcode.com/problems/valid-triangle-number/
*/

//Approach-1 (Using Binary Search)
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)
            return 0;
        
        sort(begin(nums), end(nums));
        int count = 0;
        for(int i = 0; i<n-2; i++) {
            for(int j = i+1; j<n-1; j++) {
                int k = j+1;
                int sum = nums[i] + nums[j];
                
                if(k < n) {
                    int idx = lower_bound(begin(nums)+k, end(nums), sum) - begin(nums);
                    count += (idx-j-1);
                }
            }
        }
        
        return count;
    }
};

//Approach-2 (O(n^2) Using concept similar two 3-Sum)
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)
            return 0;
        
        sort(begin(nums), end(nums));
        int count = 0;
        for(int i = n-1; i>1; i--) {
            int l = 0, r = i-1;
            
            while(l < r) {
                if(nums[l] + nums[r] > nums[i]) {
                    count += (r-l);
                    r--;
                } else {
                    l++;
                }
            }
        }     
        return count;
    }
};

/*
Note : If we use 3-SUM approach like as shown below :
for(int i = 0; i<n-2;  i++) {
            int l = i+1,  r = n-1;
			while(l < r) {
			///code
			}
}

We won't be getting correct result.
Example : 
    2     2    3    4
	i     l         r
	
	nums[l]+nums[r] is not greater than nums[r]
	So, we increase l
	
	2     2    3    4
	i          l    r
	nums[l]+nums[r] > nums[r], we increment count by 1
	
	But if you notice we missed the triplet {2, 2, 3} XXXXXXXX ALERT!!!!!
	
	-----------------------------
	
	So, let's take same example with Approach-2
	 2     2    3    4
	 l		    r    i
	
	nums[l]+nums[r] is greater than nums[r], 
	it means nums[l+1]+nums[r]  > nums[r] or sure
	Also, nums[l+2]+nums[r]  > nums[r] or sure and so on until l < r
	So, {2, 3, 4}, {2, 3, 4} are valid
	
	Now, we decrement i--
	
	2     2    3    4
	l     r    i
	Here also, {2, 2, 3} is valid until l < r
*/
