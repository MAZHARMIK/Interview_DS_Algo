/*
    Company Tags : Microsoft (variation)
    Link         : https://leetcode.com/contest/weekly-contest-205/
*/

//Approach-1 (Using stack)
class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        stack<pair<char, int>> st;

        int n = s.length();
        int price = 0;
        for(int i = 0; i<n; i++) {
            if(st.empty() || st.top().first != s[i]) {
                st.push({s[i], cost[i]});
            } else {
                price += min(st.top().second, cost[i]);
                if(st.top().second < cost[i]) {
                    st.pop();
                    st.push({s[i], cost[i]});
                }
            }
        }

        return price;
    }
};

//Approach-2 (Greedy but very smart (without O(n) space)
/*
	Example : "aaa" , {2, 3, 1}
	This example best shows the intuition behind the below approach
*/
class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int n = s.length();
        int price = 0;
        int prev = 0;
        
        for(int i = 0; i<n; i++) {
            if(i > 0 && s[i] != s[i-1])
                prev = 0;
            
            price += min(prev, cost[i]);
            prev  = max(prev, cost[i]);
        }        

        return price;
    }
};
