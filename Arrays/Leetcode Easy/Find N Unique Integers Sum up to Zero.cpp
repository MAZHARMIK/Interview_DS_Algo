/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Pt_kSV_0HDU
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero
*/

/*********************************************************** C++ **************************************************/
//Approach-1 (iterate linear)
//T.C : O(n) 
//S.C : O(1)
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result(n);

        int start = 1;
        int i = 0;
        while(i+1 < n) {
            result[i] = start;
            result[i+1] = -start;

            i+= 2;
            start++;
        }

        return result;
    }
};


//Approach-2 (two pointer)
//T.C : O(n) 
//S.C : O(1)
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result(n);

        int i = 0;
        int j = n-1;
        int start = 1;
        while(i < j) {
            result[i] = start;
            result[j] = -start;
            start++;

            i++;
            j--;
        }

        return result;
    }
};


/*********************************************************** JAVA **************************************************/
//Approach-1 (iterate linear)
//T.C : O(n) 
//S.C : O(1)
class Solution {
    public int[] sumZero(int n) {
        int[] result = new int[n];

        int start = 1;
        int i = 0;
        while (i + 1 < n) {
            result[i] = start;
            result[i + 1] = -start;

            i += 2;
            start++;
        }

        return result;
    }
}


//Approach-2 (two pointer)
//T.C : O(n) 
//S.C : O(1)
class Solution {
    public int[] sumZero(int n) {
        int[] result = new int[n];

        int i = 0;
        int j = n - 1;
        int start = 1;
        while (i < j) {
            result[i] = start;
            result[j] = -start;

            start++;
            i++;
            j--;
        }

        return result;
    }
}
