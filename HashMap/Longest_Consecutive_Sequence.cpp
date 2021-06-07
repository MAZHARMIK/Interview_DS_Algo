/*
    Company Tags  : Google, Zoho, Amazon, Walmart, Linkedin
    Leetcode Link : https://leetcode.com/problems/longest-consecutive-sequence/
    //NOTE : This question is also known as "Longest Consecutive Subsequence"
*/

//Approach-1 (sort and find : Time - O(nlog(n))

//Approach-2 (Using hash map and intelligent tweak : O(n))
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, bool> mp;
        
        for(int &x : nums)
            mp[x] = true;
                    
        for(int &x : nums) {
            //It means we have number/s before this 'x' which are a potential start to the consecutive
            //sequence of which this 'x' is a member
            if(mp.find(x-1) != mp.end()) {
                mp[x] = false;
            }
        }
        
        int maxL = 0;
        for(auto it : mp) {
            int x = it.first;
            if(it.second == true) {
                int tempL = 1;
                
                while(mp.find(x+tempL) != mp.end()) { //Why O(n) ? This while loop doesn't get called for all numebrs. Number of times 
                     tempL++;                         //this while loop runs for few sum up to 'n' 
                }
                
                maxL = max(maxL, tempL);
            }
        }
        
        return maxL;
        
    }
};

//Approach-3 (Using unordered_set in place of hashmap in Approach-2) Time : O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(begin(nums), end(nums));
                
        int maxL = 0;
        
        for(const int &x : st) {
            //It means we have numbers before this 'x' which is a potential start to the consecutive
            //sequence of which this 'x' is a member
            if(st.find(x-1) != st.end()) {
                continue;
            }
            
            int tempL = 1;
            while(st.find(x+tempL) != st.end()) { //find in unordered_set takes O(1) time.
                tempL++;
            }
            
            maxL = max(maxL, tempL);
        }
        
        return maxL;
        
    }
};
