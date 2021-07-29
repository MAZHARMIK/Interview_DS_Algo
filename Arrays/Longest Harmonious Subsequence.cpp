/*
    Company Tags  : LiveRamp
    Leetcode Link : https://leetcode.com/problems/longest-harmonious-subsequence/
*/

//Approach-1 (First solution that comes to our mind)  : TLE
//Double loop and find the count of largest subsequence
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        
        int maxC = 0;
        for(int i = 0; i<n; i++) {
            int c = 0;
            bool found = false;
            for(int j = 0; j<n; j++) {
                if(nums[j] == nums[i]+1 || nums[j] == nums[i]) {
                    if(nums[i] != nums[j])
                        found = true; //To avoid cases like {1, 1, 1, 1, 1} output should be 0
                    c++;
                }
            }
            if(found)
                maxC = max(maxC, c);
            
        }
        return maxC;
    }
};

//Approach-2 (Sorting) Accepted
/*
Since we have to find the subsequence, we just need to find the next largest
by 1 and calculate distance
*/
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        int maxC = 0;
        
        sort(begin(nums), end(nums));
        
        for(int i = 0; i<n; i++) {
            int num = nums[i];
            
            int idx = upper_bound(begin(nums), end(nums), num) - begin(nums);
            int j = idx+1;
            while(j < n && nums[j] == nums[idx])  j++; //to include duplicate values
            
            idx = j==idx+1 ? idx : j-1;
            
            if(idx < n && nums[idx] - nums[i] <= 1) maxC = max(maxC, idx-i+1);
        }
        
        return maxC;
    }
};

//Approach-3 (Why not use upper bound in map)
/*Use count as your benefit*/
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        int maxC = 0;
        map<int, int> mp;
        
        for(int &x : nums) mp[x]++;
        
        for(int i = 0; i<n; i++) {
            int num = nums[i];
            
            auto it = mp.upper_bound(num);
            if(it->first - num == 1) {
                maxC = max(maxC, mp[num]+it->second);
            }
            
        }
        
        return maxC;
    }
};

//Approach-4 (Enhancing Approach-3 above) Accepted
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        int maxC = 0;
        map<int, int> mp;
        
        for(int &x : nums) mp[x]++;
        
        for(auto &it : mp) {
            int findNum = it.first+1;
            if(mp.find(findNum) != end(mp)) {
                maxC = max(maxC, it.second + mp[findNum]);
            }
        }
        
        return maxC;
    }
};
