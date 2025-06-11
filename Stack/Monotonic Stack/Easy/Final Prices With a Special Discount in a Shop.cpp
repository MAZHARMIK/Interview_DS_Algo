/*                   Scroll below to see JAVA code as well                */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=y5CZ7LhqSAU
    Company Tags                : will update later
    Letcode Link                : https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop
    
    Monotonic Data Structures Concepts Playlist - https://www.youtube.com/watch?v=yRyumGu_owg&list=PLpIkg8OmuX-IpUPXh3z8oeKSfRkKhjaTV
*/


/************************************************************ C++ ************************************************************/
//Approach-1 (Brute Force)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> result(begin(prices), end(prices));

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(prices[j] <= prices[i]) {

                    result[i] -= prices[j];
                    break;
                }
            }
        }

        return result;
    }
};


//Approach-2 (Monotonic Stack)
//T.C : O(2*n) ~= O(n)
//S.C : O(n) due to stack
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> result(begin(prices), end(prices));
        stack<int> st;
        
        for(int i = 0; i < n; i++) {

            while(!st.empty() && prices[i] <= prices[st.top()]) {
                result[st.top()] -= prices[i];
                st.pop();
            }
            st.push(i);
        }

        return result;
    }
};



/************************************************************ JAVA ************************************************************/
//Approach-1 (Brute Force)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
    public int[] finalPrices(int[] prices) {
        int n = prices.length;
        int[] result = prices.clone(); // Clone the prices array for result

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (prices[j] <= prices[i]) {
                    result[i] -= prices[j];
                    break; // Exit inner loop after applying the discount
                }
            }
        }

        return result;
    }
}

//Approach-2 (Monotonic Stack)
//T.C : O(2*n) ~= O(n)
//S.C : O(n) due to stack
class Solution {
    public int[] finalPrices(int[] prices) {
        int n = prices.length;
        int[] result = prices.clone(); // Clone the prices array for result
        Stack<Integer> stack = new Stack<>(); // Stack to keep track of indices

        for (int i = 0; i < n; i++) {
            // Process stack while the current price is less than or equal to the price at the index stored in the stack
            while (!stack.isEmpty() && prices[i] <= prices[stack.peek()]) {
                int index = stack.pop(); // Get the top index
                result[index] -= prices[i]; // Apply the discount
            }
            stack.push(i); // Push the current index onto the stack
        }

        return result;
    }
}
