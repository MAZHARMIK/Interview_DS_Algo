/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=IDC1rnr3vus
    Company Tags                : Microsoft, Accolite, Amazon, FactSet, Samsung, Adobe, Flipkart
    Leetcode Link               : https://leetcode.com/problems/online-stock-span/
    GfG Link                    : https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1
*/

class StockSpanner {
public:
    stack<pair<int, int>> st;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;
        
        while(!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        
        st.push({price, span});
        return span;
    }
};



