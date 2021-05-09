/*
    Company Tags  : It's a classic heap problem often asked in Google with variations
    Leetcode Link : https://leetcode.com/problems/construct-target-array-with-multiple-sums/
*/
//Brute force will not work as the contraints are high. Numbers can go to large values and if you try 
//to reach that value starting from 1, you'll get TLE for sure. That's why think of a different way to sovle (shown below)
//Don't be upset if this solution didn't come into your mind. I couldn't solve it too at one go. But I learned a lot from this. Read comments below for clarity
class Solution {
    typedef long long ll;
public:
    bool isPossible(vector<int>& target) {
        int n       = target.size();
        
        priority_queue<ll> pq;
        ll sum = 0;
        for(int x:target) {
            pq.push(x);
            sum += x;
        }
        
        while(!pq.empty()) {
            ll biggest_before = pq.top();
            pq.pop();
            
            if(biggest_before == 1) //all elements 1
                return true;
            
            ll remain_sum = sum - biggest_before;
            if(remain_sum >= biggest_before)
                return false;
            if(remain_sum == 1) //we are left with one element 1
                return true;
            if(remain_sum == 0) //No solution. We need to subtract remain_sum from biggest
                return false;
            
            //int biggest_after = biggest_before - remain_sum; //this will take too long if biggest is large
            //example : [2, 1000] -> [2, 998]  -> [2, 996] ....
            //So, it's better to find the last value
            
            ll biggest_after = biggest_before % remain_sum;
            if(biggest_after < 1) //we need minimum '1' for all elements
                return false;
            
            sum = remain_sum + biggest_after; //Explantion below
            /*
                [2, 1005]
                sum             = 1007
                biggest_before  = 1005
                remain_sum      = 2
                After reduction
                [2, 3]
                biggest_after   = 3
                remain_sum      = 2
                sum             = remain_sum + biggest_after
            */
            pq.push(biggest_after);
        }
        
        return true;
    }
};
