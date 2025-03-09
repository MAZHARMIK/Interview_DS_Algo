/*         Scroll below to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=EZVLzXvaQ2A
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/alternating-groups-ii/description/
*/


/********************************************************************** C++ **********************************************************************/
//Approach-1 (Brute Force)
//T.C : O(n*k)
//S.C : O(1)
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
    
        for (int i = 0; i < k - 1; i++) {
            colors.push_back(colors[i]);
        }
        
        int result = 0;
        for (int i = 0; i < n; i++) {
            bool isAlternating = true;
            for (int j = i; j < i + k - 1; j++) {
                if (colors[j] == colors[j + 1]) {
                    isAlternating = false;
                    break;
                }
            }
            if (isAlternating) {
                result++;
            }
        }
        
        return result;
    }
};


//Approach-2 (Sliding Window using Khandani Template)
//T.C : O(n+k)
//S.C : O(1) (But you can mention you have to add k-1 extra elements so space complexity ideally should be O(k-1))
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();

        int N = n + (k-1);
        for(int i = 0; i < k-1; i++) {
            colors.push_back(colors[i]); //to handle wrap around (circular array)
        }

        int result = 0;
        int i = 0;
        int j = 1; //because we have to check index j-1 for checking alterate
        while(j < N) {
            if(colors[j] == colors[j-1]) {
                i = j;
                j++;
                continue;
            }

            if(j - i + 1 == k) {
                result++;
                i++;
            }

            j++;
        }

        return result;
    }
};


//Approach-3 (Using simple counting in 2 Pass)
//T.C : O(n+k)
//S.C : O(1)
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();

        int result = 0;

        int length = 1; //i = 0 index wala element
        int last   = colors[0];
        //1st Pass
        for(int i = 1; i < n; i++) {
            if(colors[i] == last) {
                length = 1;
                last = colors[i];
                continue;
            }

            length++;

            if(length >= k) {
                result++;
            }

            last = colors[i];
        }

        //T.C : O(n)
        //2nd Pass
        for(int i = 0; i < k-1; i++) { //checking starting (k-1) elements
            if(colors[i] == last) {
                length = 1;
                last = colors[i];
                break;
            }

            length++;

            if(length >= k) {
                result++;
            }

            last = colors[i];
        }

        return result;


    }
};


/********************************************************************** Java **********************************************************************/
// Approach-1 (Brute Force)
// T.C : O(n*k)
// S.C : O(1)
class Solution {
    public int numberOfAlternatingGroups(int[] colors, int k) {
        int n = colors.length;
        
        int[] extended = new int[n + k - 1];
        System.arraycopy(colors, 0, extended, 0, n);
        for (int i = 0; i < k - 1; i++) {
            extended[n + i] = colors[i];
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            boolean isAlternating = true;
            for (int j = i; j < i + k - 1; j++) {
                if (extended[j] == extended[j + 1]) {
                    isAlternating = false;
                    break;
                }
            }
            if (isAlternating) {
                result++;
            }
        }
        
        return result;
    }
}


// Approach-2 (Sliding Window using Khandani Template)
// T.C : O(n+k)
// S.C : O(1) (But you can mention you have to add k-1 extra elements so space complexity ideally should be O(k-1))
class Solution {
    public int numberOfAlternatingGroups(int[] colors, int k) {
        int n = colors.length;
        int N = n + (k - 1);

        int[] extended = new int[N];
        System.arraycopy(colors, 0, extended, 0, n);
        for (int i = 0; i < k - 1; i++) {
            extended[n + i] = colors[i]; // to handle wrap-around (circular array)
        }

        int result = 0;
        int i = 0, j = 1; // because we have to check index j-1 for checking alternate
        
        while (j < N) {
            if (extended[j] == extended[j - 1]) {
                i = j;
                j++;
                continue;
            }

            if (j - i + 1 == k) {
                result++;
                i++;
            }

            j++;
        }

        return result;
    }
}


// Approach-3 (Using simple counting in 2 Pass)
// T.C : O(n+k)
// S.C : O(1)
class Solution {
    public int numberOfAlternatingGroups(int[] colors, int k) {
        int n = colors.length;
        int result = 0;

        int length = 1; // i = 0 index wala element
        int last = colors[0];

        // 1st Pass
        for (int i = 1; i < n; i++) {
            if (colors[i] == last) {
                length = 1;
                last = colors[i];
                continue;
            }

            length++;

            if (length >= k) {
                result++;
            }

            last = colors[i];
        }

        // T.C : O(n)
        // 2nd Pass
        for (int i = 0; i < k - 1; i++) { // checking starting (k-1) elements
            if (colors[i] == last) {
                length = 1;
                last = colors[i];
                break;
            }

            length++;

            if (length >= k) {
                result++;
            }

            last = colors[i];
        }

        return result;
    }
}
