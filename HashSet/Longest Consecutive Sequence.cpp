/*
    Company Tags  : Amazon, Walmart, Microsoft, LinkedIn
    Leetcode Link : https://leetcode.com/problems/longest-consecutive-sequence/
*/

/*
  - You can do it in O(n3)
  - You can do it on O(nlogn)
  
  But they are basic approaches. This qn is mainly popular because of its O(n) approach which is discussed below
*/

//O(n) Approach

/*
For those who got confused by if the last solution is O(n^2) or O(n), please take a close look at the entering of the logic: 
                               if(!num_set.contains(num-1))
                               
That means, for example, {6,5,4,3,2,1} input, only the value 1 is valid for the loop(all other values have its (value - 1) in the set), that is O(n).
Another corner example, 2, 5, 6, 7, 9, 11. All of these numbers are the "entrance" for the logic but the while loop doesn't run much. That is O(n) as well.
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int& num : nums) {
            st.insert(num);
        }
        
        int maxL = 0;
        for(int& num : nums) {
            int prevNum = num-1;
            if(st.find(prevNum) == st.end()) {
                
                int tempL     = 0;
                int currNum   = num;
                
                while(st.find(currNum) != st.end()) {
                    tempL++;
                    currNum++;
                }
                
                maxL = max(maxL, tempL);
                
            }
        }
        
        return maxL;
    }
};


