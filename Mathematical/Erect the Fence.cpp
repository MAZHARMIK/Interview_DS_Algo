/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=et3dtYzVGQQ
    Company Tags                : Google
    Leetcode Link               : https://leetcode.com/problems/erect-the-fence/
*/

class Solution {
public:
    
    int findEquationValue(pair<int, int>& P1, pair<int, int>& P2, pair<int, int> P3) {
        
        int x1 = P1.first;
        int x2 = P2.first;
        int x3 = P3.first;
        
        int y1 = P1.second;
        int y2 = P2.second;
        int y3 = P3.second;
        
        return (y3-y2)*(x2-x1)-(y2-y1)*(x3-x2);
        
    }
    
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        sort(begin(trees), end(trees));
        
        vector<vector<int>> result;
        
        deque<pair<int, int>> upper, lower;
        
        
        for(auto &point : trees) {
            
            int l = lower.size();
            int u = upper.size();
            
            //sabse pehle lower ka dekhte hain
            while(l >= 2 && findEquationValue(lower[l-2], lower[l-1], {point[0], point[1]}) < 0) {
                l--;
                lower.pop_back();
            }
            
            while(u >= 2 && findEquationValue(upper[u-2],upper[u-1],{point[0],point[1]}) > 0) {
                u--;
                upper.pop_back();
            }
            
            upper.push_back({point[0], point[1]});
            lower.push_back({point[0], point[1]}); 
        }
        
        set<pair<int, int>> st;
        
        for(auto &point : upper) {
            st.insert(point);
        }
        
        for(auto &point : lower) {
            st.insert(point);
        }
        
        for(auto &point : st) {
            result.push_back({point.first, point.second});
        }
        
        return result;
        
    }
};
