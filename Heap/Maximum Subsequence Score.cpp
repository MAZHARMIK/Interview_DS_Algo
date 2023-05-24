/*
    MY YOUTUBE VIDEO ON THIS Qn : <soon>
    Company Tags                : Amazon
    Leetcode Link               : https://leetcode.com/problems/maximum-subsequence-score/
*/

//Approach-1 (DP - TLE)
class Solution {
public:
    int K;
    int n;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    void removeNums2_i(int num) {
        vector<int> temp;
        
        while(!pq.empty()) {
            int x = pq.top();
            pq.pop();
            
            if(x == num) {
                break;
            }
            temp.push_back(x);
        }
        
        for(int &x : temp) {
            pq.push(x);
        }
    }
    
    long long solve(vector<int>& nums1, vector<int>& nums2, int sum, int min, int i, int count) {
        if(count == K) {
            return sum * min;
        }
         if(i >= n) {
            return 0;
        }

        pq.push(nums2[i]);
        
        long take_i = solve(nums1 , nums2 , sum + nums1[i] , pq.top(), i+1 , count+1);
        
        removeNums2_i(nums2[i]);
        
        long not_take_i = solve(nums1 , nums2 , sum, min, i+1 , count);
        
        return max(take_i, not_take_i);
    }
    
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        K = k;
        n = nums1.size();
        
        return solve(nums1 , nums2 , 0 , 0 , 0 , 0);
    }
};


//Approach-2 (Using Priority Queue + Sorting)
