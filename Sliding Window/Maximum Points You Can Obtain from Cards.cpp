/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Media.net, Google (Most asked in 2021)
    Leetcode Link               : https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
    Also known as               : Pick From Both Sides
*/

/*
    Solution with explanation:
    Keywords : Minimum/Maximum , k cards (similar to k-size window)  (Hints towards Sliding Window Technique)
*/


//Approach-1 (Sliding Window)
class Solution {
public:
    int solve_sliding_window(vector<int>& cardPoints, int& k) {
        //When we find max score of size k, we are left with subarray of size (n-k) which has minimum sum
        //so, we find total_sum and we find minimum_sum of subarrays of size (n-k)
        //choose best of (total_sum - minimum_sum)
        //Best way to use sliding window technique
        /*
            Example : cardPoints{5, 7, 2, 100, 1}, k = 3
            total_sum = 115
            window_size = n-k = 5-3 = 2
            window_1 = {5, 7}  , sum = 12
            window_2 = {7, 2}  , sum = 9   -> minimum
            window_3 = {2, 100}, sum = 102
            window_4 = {100, 1}, sum = 101
            
            return total_sum - 9 = 115 - 9 = 106
        */
        int n        = nums.size();
        int totalSum = 0;
        int l        = n-k;
        int currSum  = 0;
        int minSum   = INT_MAX;
        int i = 0,  j = 0;
        
        while(j < n) {
            totalSum += nums[j];
            currSum  += nums[j];
            if(j-i+1 == l) {
                minSum   = min(minSum, currSum);
                currSum -= nums[i];
                i++;
            }
            j++;
        }
        return minSum == INT_MAX ? totalSum : totalSum-minSum;
    }
    
    int maxScore(vector<int>& cardPoints, int k) {
        return solve_sliding_window(cardPoints, k);
    }
};


//Approach-2 (Recur + Memo) - TLE
class Solution {
public:
    int k, n;
    unordered_map<string, int> mp;
    int solve(vector<int>& nums, int i, int j, int count) {
        if(count == k)
            return 0;
        if(i >= n || j < 0)
            return 0;
        
        string key = to_string(i) + "_" + to_string(j) + "_" + to_string(count);
        if(mp.find(key) != end(mp))
            return mp[key];
        
        int take_i = nums[i] + solve(nums, i+1, j, count+1);
        int take_j = nums[j] + solve(nums, i, j-1, count+1);

        return mp[key] = max(take_i, take_j);
    }
    
    int maxScore(vector<int>& cardPoints, int k) {
        this->mp.clear();
        this->k = k;
        this->n = cardPoints.size();
        
        return solve(cardPoints, 0, n-1, 0);
    }
};

//Approach-3 (DP)
class Solution {
public:
    int solve_dp(vector<int>& cardPoints, int& k) {
        //Example : cardPoints{5, 7, 2, 100, 1}, k = 3
        vector<int> front_card(k);
        vector<int> back_card(k);
        int n = cardPoints.size();
        front_card[0] = cardPoints[0];
        back_card[0]  = cardPoints[n-1];
        
        for(int i = 1; i<=k-1; i++) {
            front_card[i] = front_card[i-1] + cardPoints[i];
            back_card[i]  = back_card[i-1] + cardPoints[n-i-1];
        }
        //front_card {5, 12, 14} ; front_card[i] = sum when we take (i+1) elements from front
        //back_card  {1, 101, 103}; back_card[i] = sum when we take (i+1) elements from back
        
        //let's suppose we took k elements front front or back whichever gives me max
        int maxScr = max(back_card[k-1], front_card[k-1]); //max(103, 14)
        
        /*
            You have following options (for k = 3)
            # front_elements              # back_elements               maxScr
            0 elements                      3 elements (i.e.2, 100, 1)    103   -> back_card[k-1]
            
            1 elements (i.e.5)              2 elements (i.e. 100, 1)      106   -> MAXIMUM :-)
            
            2 elements (i.e.5, 7)           1 elements (i.e. 1)           13
            
            3 elements (i.e.5, 7, 2)        0 elements                    14   -> front_card[k-1]
            
        */
        
        
        for(int i = 0; i<=k-2; i++) { //we have already considered i = k-1 (to determine maxScr above)
            
            int sum_front = front_card[i];     //front_card[0] = {5}       sum = 5
            int sum_back  = back_card[k-i-2];  //back_card[1]  = {100, 1}  sum = 101
            
            if(sum_front + sum_back > maxScr)
                maxScr = sum_front + sum_back;
            
        }
        
        return maxScr;
        
    }
    
    int maxScore(vector<int>& cardPoints, int k) {
        return solve_dp(cardPoints, k);
    }
};
