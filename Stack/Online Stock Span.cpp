/*
    MY YOUTUBE VIDEO ON THIS Qn : <soon>
    Company Tags                : Microsoft, Accolite, Amazon, FactSet, Samsung, Adobe, Flipkart
    Leetcode Link               : https://leetcode.com/problems/online-stock-span/
    GfG Link                    : https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1
*/

class StockSpanner {
public:
    stack<pair<int, int>> st;
    int c;
    StockSpanner() {
        st.push({INT_MAX, 0});
        c = 1;
    }
    
    int next(int price) {
        while(!st.empty() && st.top().first <= price)
            st.pop();
        
        int span = c - st.top().second;
        st.push({price, c});
        c++;
        return span;
    }
};
