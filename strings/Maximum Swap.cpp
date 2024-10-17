/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=6tsqLTvLAf8
    Company Tags                : META
    Leetcode Link               : https://leetcode.com/problems/maximum-swap
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 (using space to store maxRight Indices)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num); //stoi 
        int n = s.length();

        vector<int> maxRight(n); //stores the index of max element to right

        maxRight[n-1] = n-1;
        for(int i = n-2; i >= 0; i--) {
            int rightMaxIdx = maxRight[i+1];
            int rightMaxElement = s[rightMaxIdx];

            maxRight[i] = (s[i] > rightMaxElement) ? i : rightMaxIdx;
        }

        for(int i = 0; i < n; i++) {
            int maxRightIdx = maxRight[i];
            int maxRightElement = s[maxRightIdx];
            if(s[i] < maxRightElement) {
                swap(s[i], s[maxRightIdx]);
                return stoi(s);
            }
        }

        return num;
    }
};


//Approach-2 (using constant space)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.length();

        vector<int> maxRight(10, -1); //0,1,2.....9

        for(int i = 0; i < n; i++) {
            int idx = s[i] - '0'; //'2' -'0' = 2
            maxRight[idx] = i;
        }

        for(int i = 0; i < n; i++) {
            char currChar = s[i];
            int currDigit = currChar - '0';

            for(int digit = 9; digit > currDigit; digit--) {
                if(maxRight[digit] > i) {
                    swap(s[i], s[maxRight[digit]]);
                    return stoi(s);
                }
            }
        }

        return num;
    }
};




/**************************************************************** JAVA ****************************************************************/
//Approach-1 (using space to store maxRight Indices)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public int maximumSwap(int num) {
        String s = Integer.toString(num); // Convert num to string
        int n = s.length();

        // Array to store the index of the maximum element to the right
        int[] maxRight = new int[n];

        // Initialize the last element of maxRight
        maxRight[n - 1] = n - 1;

        // Fill the maxRight array, starting from the second last element
        for (int i = n - 2; i >= 0; i--) {
            int rightMaxIdx = maxRight[i + 1];
            char rightMaxElement = s.charAt(rightMaxIdx);

            // Update maxRight with the index of the maximum element
            if (s.charAt(i) > rightMaxElement) {
                maxRight[i] = i;
            } else {
                maxRight[i] = rightMaxIdx;
            }
        }

        // Find the first position where swapping will maximize the number
        for (int i = 0; i < n; i++) {
            int maxRightIdx = maxRight[i];
            char maxRightElement = s.charAt(maxRightIdx);

            // If there is a bigger digit to the right, swap and return the result
            if (s.charAt(i) < maxRightElement) {
                char[] charArray = s.toCharArray();
                char temp = charArray[i];
                charArray[i] = charArray[maxRightIdx];
                charArray[maxRightIdx] = temp;

                // Convert back to integer and return
                return Integer.parseInt(new String(charArray));
            }
        }

        return num; // If no swap is possible, return the original number
    }
}


//Approach-2 (using constant space)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int maximumSwap(int num) {
        String s = Integer.toString(num); // Convert num to string
        int n = s.length();

        int[] maxRight = new int[10]; // To store the last occurrence of each digit
        for (int i = 0; i < 10; i++) {
            maxRight[i] = -1;
        }

        // Fill the maxRight array with the last occurrence index of each digit
        for (int i = 0; i < n; i++) {
            int idx = s.charAt(i) - '0'; // Convert char to integer
            maxRight[idx] = i;
        }

        // Find the first place to swap to get the largest number
        for (int i = 0; i < n; i++) {
            int currDigit = s.charAt(i) - '0';
            
            // Try to find a larger digit to swap with current one
            for (int digit = 9; digit > currDigit; digit--) {
                if (maxRight[digit] > i) {
                    // Swap the current digit with the larger one found
                    char[] charArray = s.toCharArray();
                    char temp = charArray[i];
                    charArray[i] = charArray[maxRight[digit]];
                    charArray[maxRight[digit]] = temp;
                    
                    // Return the modified number
                    return Integer.parseInt(new String(charArray));
                }
            }
        }

        return num; // If no swap is made, return the original number
    }
}
