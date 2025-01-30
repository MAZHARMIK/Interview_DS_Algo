/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=1j_ssSAjDcI
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 (Brute Force Using unordered_set extra space)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        unordered_set<int> st;

        for(int i = 0; i < n; i++) {
            if(boxes[i] == '1') {
                st.insert(i);
            }
        }

        vector<int> answer(n, 0);

        for(int i = 0; i < n; i++) {
            for(auto &idx : st) {
                answer[i] += abs(i - idx);
            }
        }

        return answer;

    }
};


//Approach-2 (Brute Force with O(1) space)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();

        vector<int> answer(n, 0);

        for(int i = 0; i < n; i++) {

            if(boxes[i] == '1') {
                for(int j = 0; j < n; j++) {
                    answer[j] += abs(j-i);
                }
            }
        }

        return answer;
    }
};


//Approach-3 (Optimal Using Cumulative Sum)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();

        vector<int> answer(n, 0);

        int cumValue    = 0;
        int cumValueSum = 0;

        //Find moves for all left balls to index i
        //O(n)
        for(int i = 0; i < n; i++) {
            answer[i] = cumValueSum;
            
            cumValue += boxes[i] == '0' ? 0 : 1;
            
            cumValueSum += cumValue;
        }

        cumValue    = 0;
        cumValueSum = 0;
        //Find moves for all right balls to index i
        //O(n)
        for(int i = n-1; i >= 0; i--) {
            answer[i] += cumValueSum;
            
            cumValue += boxes[i] == '0' ? 0 : 1;
            
            cumValueSum += cumValue;
        }

        //O(n+n) ~ O(n)
        return answer;

    }
};


/**************************************************************** JAVA ****************************************************************/
//Approach-1 (Brute Force Using unordered_set extra space)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
    public int[] minOperations(String boxes) {
        int n = boxes.length();
        HashSet<Integer> set = new HashSet<>();

        for (int i = 0; i < n; i++) {
            if (boxes.charAt(i) == '1') {
                set.add(i);
            }
        }

        int[] answer = new int[n];

        for (int i = 0; i < n; i++) {
            for (int idx : set) {
                answer[i] += Math.abs(i - idx);
            }
        }

        return answer;
    }
}


//Approach-2 (Brute Force with O(1) space)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
    public int[] minOperations(String boxes) {
        int n = boxes.length();
        int[] answer = new int[n];

        for (int i = 0; i < n; i++) {
            if (boxes.charAt(i) == '1') {
                for (int j = 0; j < n; j++) {
                    answer[j] += Math.abs(j - i);
                }
            }
        }

        return answer;
    }
}


//Approach-3 (Optimal Using Cumulative Sum)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int[] minOperations(String boxes) {
        int n = boxes.length();
        int[] answer = new int[n];

        int cumValue = 0;
        int cumValueSum = 0;

        // Find moves for all left balls to index i
        for (int i = 0; i < n; i++) {
            answer[i] = cumValueSum;

            cumValue += boxes.charAt(i) == '0' ? 0 : 1;
            cumValueSum += cumValue;
        }

        cumValue = 0;
        cumValueSum = 0;

        // Find moves for all right balls to index i
        for (int i = n - 1; i >= 0; i--) {
            answer[i] += cumValueSum;

            cumValue += boxes.charAt(i) == '0' ? 0 : 1;
            cumValueSum += cumValue;
        }

        return answer;
    }
}
