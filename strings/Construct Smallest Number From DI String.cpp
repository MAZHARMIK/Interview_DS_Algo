/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=rCjwDls-HPk
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/construct-smallest-number-from-di-string
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 - (Simple brute force)
//T.C : O(n * (n+1)!), (n+1)! permuations and n for matchesPattern()
//S.C : O(n+1) for result
class Solution {
public:
    bool matchesPattern(string &num, string &pattern) {
        for(int i = 0; i < pattern.length(); i++) {
            if((pattern[i] == 'I' && num[i] > num[i+1]) ||
                (pattern[i] == 'D' && num[i] < num[i+1])) {
                return false;
            }
        }

        return true;
    }

    string smallestNumber(string pattern) {
        int n = pattern.length(); //"IID" , n = 3
        string num = "";
        
        for(int i = 1; i <= n+1; i++) {
            num.push_back(i + '0'); 
        }

        //num = "1234"

        while(!matchesPattern(num, pattern)) {
            next_permutation(begin(num), end(num));
        }

        return num;

    }
};


//Approach-2 - (Simple using string as a stack) - You can use a stack<int> as well
//T.C : O(n)
//S.C : O(n) for the result
class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.length();

        string num = ""; //(n+1) //index 0 to index n

        int counter = 1;
        stack<char> st;

        for(int i = 0; i <= n; i++) {
            st.push(counter + '0');
            counter++;

            if(i == n || pattern[i] == 'I') {
                while(!st.empty()) {
                    num += st.top();
                    st.pop();
                }
            }
        }

        return num;

    }
};


/**************************************************************** Java ****************************************************************/
// Approach-1 - (Simple brute force)
// T.C : O(n * (n+1)!), (n+1)! permutations and n for matchesPattern()
// S.C : O(n+1) for result
class Solution {
    private boolean matchesPattern(String num, String pattern) {
        for (int i = 0; i < pattern.length(); i++) {
            if ((pattern.charAt(i) == 'I' && num.charAt(i) > num.charAt(i + 1)) ||
                (pattern.charAt(i) == 'D' && num.charAt(i) < num.charAt(i + 1))) {
                return false;
            }
        }
        return true;
    }

    public String smallestNumber(String pattern) {
        int n = pattern.length();
        char[] num = new char[n + 1];

        // Initialize num as "1234..." (n+1 characters)
        for (int i = 0; i <= n; i++) {
            num[i] = (char) ('1' + i);
        }

        // Generate permutations until we find one that matches the pattern
        while (!matchesPattern(new String(num), pattern)) {
            nextPermutation(num);
        }

        return new String(num);
    }

    private void nextPermutation(char[] num) {
        int i = num.length - 2;
        while (i >= 0 && num[i] >= num[i + 1]) {
            i--;
        }
        if (i >= 0) {
            int j = num.length - 1;
            while (num[j] <= num[i]) {
                j--;
            }
            swap(num, i, j);
        }
        reverse(num, i + 1);
    }

    private void swap(char[] num, int i, int j) {
        char temp = num[i];
        num[i] = num[j];
        num[j] = temp;
    }

    private void reverse(char[] num, int start) {
        int end = num.length - 1;
        while (start < end) {
            swap(num, start++, end--);
        }
    }
}


// Approach-2 - (Simple using string as a stack) - You can use a Stack<Integer> as well
// T.C : O(n)
// S.C : O(n) for the result
class Solution {
    public String smallestNumber(String pattern) {
        int n = pattern.length();
        StringBuilder result = new StringBuilder();
        Stack<Character> stack = new Stack<>();
        int counter = 1;

        for (int i = 0; i <= n; i++) {
            stack.push((char) ('0' + counter++)); // Push the next number

            if (i == n || pattern.charAt(i) == 'I') {
                while (!stack.isEmpty()) {
                    result.append(stack.pop());
                }
            }
        }

        return result.toString();
    }
}
