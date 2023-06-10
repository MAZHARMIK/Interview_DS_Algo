/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=d50vvNSrqfk
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/
*/

//Using Binary Search
class Solution {
public:
    typedef long long ll;
    
    ll getSumElements(ll count, ll val) {
        
        return val*count - (count*(count+1))/2;
        
    }
    
    int maxValue(int n, int index, int maxSum) {
        
        ll left  = 1;
        ll right = maxSum;
        
        ll mid_val;
        int result = 0;
        
        
        while(left <= right) {
            
            mid_val = left + (right - left)/2;
            
            ll left_count = min((ll)index, mid_val-1);
            
            ll left_sum  = getSumElements(left_count, mid_val);
            
            left_sum += max((ll)0, index - mid_val+1);
            
            
            ll right_count = min((ll)n-index-1, mid_val-1);
            
            ll right_sum  = getSumElements(right_count, mid_val);
            
            right_sum += max((ll)0, n-index-1 - mid_val+1);
            
            
            
            if(left_sum + right_sum + mid_val <= maxSum) {
                result = max((ll)result, mid_val);
                
                left = mid_val+1;
            } else {
                right = mid_val-1;
            }
            
        }
        
        
        return result;
        
    }
};
