/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=ZV-Hi1e1KL8
      Company Tags                : META
      Leetcode Link               : https://leetcode.com/problems/simplify-path/
*/

//Approach-1 (Using Stack)
class Solution {
public:
    string simplifyPath(string path) {
        string token = "";
        
        stringstream ss(path);
        stack<string> st;
        
        while(getline(ss, token, '/')) {

            if(token == "" || token == ".") continue;
            
            if (token != "..") 
                st.push(token);
            else if (!st.empty()) 
                st.pop();
        }
        
        string result = "";
        
        while(!st.empty()){ // add all the stack elements
            result="/"+st.top()+result;
            st.pop();
        }
        
        if(result.length()==0) // if no directory or file is present
            result="/"; // minimum root directory must be present in result
        
        return result;
    }
};

//Approach-2 (Using vector as stack)
class Solution {
public:
    string simplifyPath(string path) {
        string token = "";
        
        stringstream ss(path);
        vector<string> st;
        
        while(getline(ss, token, '/')) {

            if(token == "" || token == ".") continue;
            
            if (token != "..") 
                st.push_back(token);
            else if (!st.empty()) 
                st.pop_back();
        }
        
        string result = "";
        
        for(auto &token : st) {
            result += "/" + token;
        }
        
        return result.empty() ? "/" : result;
    }
};
