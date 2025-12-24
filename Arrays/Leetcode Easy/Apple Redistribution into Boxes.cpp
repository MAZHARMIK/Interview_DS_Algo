/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=e7ZHyvP_3Sk
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/apple-redistribution-into-boxes
*/

/*********************************************************** C++ **************************************************/
//Approach-1 (Using std::sort so that we can Simply assign the apples to largest boxes first)
//T.C : O(n + mlogm) 
//S.C : O(1)
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(begin(capacity), end(capacity), greater<int>()); //H.W : Counting Sort

        int totalApple = accumulate(begin(apple), end(apple), 0);

        int count = 0;
        int i = 0;
        while(totalApple > 0) {
            totalApple -= capacity[i];
            count++;
            i++;
        }

        return count; //total number of boxes used
    }
};



//Approach-2 (Using counting sort so that we can Simply assign the apples to largest boxes first)
//T.C : O(n + m) 
//S.C : O(1)
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApple = accumulate(begin(apple), end(apple), 0);

        // Counting sort frequency array
        vector<int> freq(51, 0);
        for (int cap : capacity) {
            freq[cap]++;
        }

        int count = 0;

        // Start using boxes with largest capacity
        for (int cap = 50; cap >= 1 && totalApple > 0; cap--) {
            while (freq[cap] > 0 && totalApple > 0) {
                totalApple -= cap;
                freq[cap]--;
                count++;
            }
        }

        return count;
    }
};




/*********************************************************** JAVA **************************************************/
//Approach-1 (Using Arrays.sort so that we can simply assign the apples to largest boxes first)
//T.C : O(n + m log m)
//S.C : O(1)
class Solution {
    public int minimumBoxes(int[] apple, int[] capacity) {
        // Sort capacity in descending order
        Arrays.sort(capacity);
        int totalApple = 0;
        for (int a : apple) {
            totalApple += a;
        }

        int count = 0;
        int i = capacity.length - 1;

        while (totalApple > 0) {
            totalApple -= capacity[i];
            count++;
            i--;
        }

        return count; // total number of boxes used
    }
}



//Approach-2 (Using counting sort so that we can simply assign the apples to largest boxes first)
//T.C : O(n + m)
//S.C : O(1)
class Solution {
    public int minimumBoxes(int[] apple, int[] capacity) {
        int totalApple = 0;
        for (int a : apple) {
            totalApple += a;
        }

        // Counting sort frequency array (capacity range: 1 to 50)
        int[] freq = new int[51];
        for (int cap : capacity) {
            freq[cap]++;
        }

        int count = 0;

        // Use boxes with maximum capacity first
        for (int cap = 50; cap >= 1 && totalApple > 0; cap--) {
            while (freq[cap] > 0 && totalApple > 0) {
                totalApple -= cap;
                freq[cap]--;
                count++;
            }
        }

        return count;
    }
}
