/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/three-consecutive-odds
*/

/*********************************************************** C++ **************************************************/
//Approach-1 (Iterating and checking consecutive 3 elements)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        //Approach-1
        int n = arr.size();
        
        for(int i = 0; i < n-2; i++) {
            if(arr[i]%2 && arr[i+1]%2 && arr[i+2]%2) {
                return true;
            }
        }
        return false;
    }
};


//Approach-2 (Iterating checking count of odd elements)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        //Approach-2
        int n = arr.size();
        int oddCount = 0;

        for(int i = 0; i < n; i++) {
            if(arr[i] % 2 == 1) {
                oddCount++;
            } else {
                oddCount = 0;
            }

            if(oddCount == 3)
                return true;
        }
        return false;
    }
};


/*********************************************************** JAVA **************************************************/
//Approach-1 (Iterating and checking consecutive 3 elements)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public boolean threeConsecutiveOdds(int[] arr) {
        for (int i = 0; i < arr.length - 2; i++) {
            if (arr[i] % 2 == 1 && arr[i + 1] % 2 == 1 && arr[i + 2] % 2 == 1) {
                return true;
            }
        }
        return false;
    }
}

//Approach-2 (Iterating checking count of odd elements)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public boolean threeConsecutiveOdds(int[] arr) {
        int oddCount = 0;

        for (int i = 0; i < arr.length; i++) {
            if (arr[i] % 2 == 1) {
                oddCount++;
            } else {
                oddCount = 0;
            }

            if (oddCount == 3) {
                return true;
            }
        }

        return false;
    }
}
