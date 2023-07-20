/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=7isfomHzzno
    Company Tags                : Uber, lyft
    Leetcode Link               : https://leetcode.com/problems/asteroid-collision/
*/

//Using a stack<int> (T.C : O(n))
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        
        for(int &a : asteroids) {
            
            while(!st.empty() && a < 0 && st.top() > 0) {
                int sum = a + st.top();
                if(sum < 0) {
                    st.pop();
                } else if(sum > 0) {
                    a = 0;
                    break;
                } else {
                    st.pop();
                    a = 0;
                }
            }
            
            if(a != 0)
                st.push(a);
            
        }
        
        int s = st.size();
        
        vector<int> result(s);
        int i = s-1;
        while(!st.empty()) {
            result[i] = st.top();
            st.pop();
            i--;
        }
        
        return result;
    }
};


//Using vector<int> as stack - T.C (O(n))
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        
        for(int &a : asteroids) {
            
            while(!st.empty() && a < 0 && st.back() > 0) {
                int sum = a + st.back();
                if(sum < 0) {
                    st.pop_back();
                } else if(sum > 0) {
                    a = 0;
                    break;
                } else {
                    st.pop_back();
                    a = 0;
                }
            }
            
            if(a != 0)
                st.push_back(a);
            
        }
        
        
        return st;
    }
};
