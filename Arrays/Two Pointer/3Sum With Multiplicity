/*
    Company Tags  : Quora
    Leetcode Link : https://leetcode.com/problems/3sum-with-multiplicity/
*/

//Approach-1 (Sorting- Two Pointer)
class Solution {
public:
    long ans = 0;
    void twoSum(vector<int>& nums, int k, int target) {
        int i = k, j = nums.size()-1;
        while(i < j) {
            if(nums[i]+nums[j] > target)
                j--;
            else if(nums[i] + nums[j] < target)
                i++;
            else {
                if(nums[i] != nums[j]) {
                    int c1 = 1, c2 = 1;
                    while(i < j && nums[i] == nums[i+1]) {
                        c1++;
                        i++;
                    }
                    
                    while(j > i && nums[j] == nums[j-1]) {
                        c2++;
                        j--;
                    }
                    
                    ans += (c1*c2);
                    i++;
                    j--;
                } else {
                    int duplicates = j-i+1;
                    ans += (duplicates*(duplicates-1)/2);
                    break;
                }
            }
        }
    }
    int threeSumMulti(vector<int>& nums, int target) {
        ans = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size()-2; i++) {
            twoSum(nums, i+1, target-nums[i]);
        }
        long K = 1e9+7;
        return ans%K;
    }
};

//Approach-2 (Making use of constraint 0 <= arr[i] <= 100)
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        long ans = 0;
        long K   = 1e9+7;
        
        vector<int> cnt(101);
        for(int& x:arr) {
            cnt[x]++;
        }
        
        for(int num1 = 0; num1<=100; num1++) {
            for(int num2 = num1; num2<=100; num2++) {
                int num3 = target - (num1 + num2);
                if(num3 >= 0 && num3 <= 100) {
                    if(num1 == num2 && num2 == num3) {
                        long n = cnt[num1];
                        //we choose 3 elements from n i.e. nC3
                        ans += n*(n-1)*(n-2)/(3*2*1);
                    } else if(num1 == num2) {
                        long n1 = cnt[num1]; //choose 2 from here i.e. nC2
                        long n2 = cnt[num3]; //choose this frequency for all nC2 from above (n1)

                        ans += (n1*(n1-1)/2) * n2;
                    } else if(num1 < num2 && num2 < num3) {
                        ans += cnt[num1] * cnt[num2] * cnt[num3];
                    }
                }
            }
        }
        
        return ans%K;
        
    }
};
