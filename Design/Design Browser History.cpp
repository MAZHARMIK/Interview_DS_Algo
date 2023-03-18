/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=FNcanLK6aZs
    Company Tags                : META
    Leetcode Link               : https://leetcode.com/problems/design-browser-history/
*/

class BrowserHistory {
public:
    stack<string> past; //back
    stack<string> future; //future
    string curr;
    
    BrowserHistory(string homepage) {
        curr = homepage;
    }
    
    void visit(string url) {
        
        past.push(curr);
        curr = url;
        
        future = stack<string>();
        
    }
    
    string back(int steps) {
        
        while(steps > 0 && !past.empty()) {
            
            future.push(curr);
            curr = past.top();
            past.pop();
            steps--;
            
        }
        
        return curr;
    }
    
    string forward(int steps) {
        
        while(steps > 0 && !future.empty()) {
            
            past.push(curr);
            curr = future.top();
            future.pop();
            steps--;
            
        }
        
        return curr;
        
    }
};
