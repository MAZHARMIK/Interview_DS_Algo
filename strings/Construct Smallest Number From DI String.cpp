/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/construct-smallest-number-from-di-string
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 - (Simple brute force)
//T.C : O(n * (n+1)!), (n+1)! permuations and n for matchesPattern()
//S.C : O(n+1) for result
class Solution {
public:
    bool matchesPattern(string &sequence, string &pattern) {
        for (int i = 0; i < pattern.length(); i++) {
            if ((pattern[i] == 'I' && sequence[i] > sequence[i + 1]) ||
                (pattern[i] == 'D' && sequence[i] < sequence[i + 1])) {
                return false;
            }
        }
        return true;
    }

    string smallestNumber(string pattern) {
        int n = pattern.length();
        string result = "";

        for (int number = 1; number <= n + 1; number++) {
            result.push_back(number + '0');
        }

        while (!matchesPattern(result, pattern)) {
            next_permutation(begin(result), end(result));
        }

        return result;
    }
};


//Approach-2 - (Simple using string as a stack) - You can use a stack<int> as well
//T.C : O(n)
//S.C : O(n) for the result
class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.length();
        string result;
        string numStack;
        int counter = 1;

        for (int i = 0; i <= n; i++) {
            numStack.push_back(counter + '0');
            counter++;

            if (i == n || pattern[i] == 'I') {
                while (!numStack.empty()) {
                    result += numStack.back();
                    numStack.pop_back();
                }
            }
        }

        return result;
    }
};



/**************************************************************** Java ****************************************************************/
// Approach-1 - (Simple brute force)
// T.C : O(n * (n+1)!), (n+1)! permutations and n for matchesPattern()
// S.C : O(n+1) for result
class Solution {
    private boolean matchesPattern(String sequence, String pattern) {
        for (int i = 0; i < pattern.length(); i++) {
            if ((pattern.charAt(i) == 'I' && sequence.charAt(i) > sequence.charAt(i + 1)) ||
                (pattern.charAt(i) == 'D' && sequence.charAt(i) < sequence.charAt(i + 1))) {
                return false;
            }
        }
        return true;
    }

    public String smallestNumber(String pattern) {
        int n = pattern.length();
        StringBuilder result = new StringBuilder();
        
        for (int number = 1; number <= n + 1; number++) {
            result.append(number);
        }

        char[] resultArr = result.toString().toCharArray();
        while (!matchesPattern(new String(resultArr), pattern)) {
            nextPermutation(resultArr);
        }

        return new String(resultArr);
    }

    private void nextPermutation(char[] arr) {
        int i = arr.length - 2;
        while (i >= 0 && arr[i] >= arr[i + 1]) {
            i--;
        }
        if (i >= 0) {
            int j = arr.length - 1;
            while (arr[j] <= arr[i]) {
                j--;
            }
            swap(arr, i, j);
        }
        reverse(arr, i + 1);
    }

    private void swap(char[] arr, int i, int j) {
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    private void reverse(char[] arr, int start) {
        int end = arr.length - 1;
        while (start < end) {
            swap(arr, start, end);
            start++;
            end--;
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
        StringBuilder numStack = new StringBuilder();
        int counter = 1;

        for (int i = 0; i <= n; i++) {
            numStack.append(counter);
            counter++;

            if (i == n || pattern.charAt(i) == 'I') {
                result.append(numStack.reverse());
                numStack.setLength(0);
            }
        }

        return result.toString();
    }
}
