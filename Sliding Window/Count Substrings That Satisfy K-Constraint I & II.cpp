/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=2d1ALG8wwDc
    Company Tags                : Will update soon
    Leetcode Link -
    Count Substrings That Satisfy K-Constraint I  : https://leetcode.com/problems/count-substrings-that-satisfy-k-constraint-i
    Count Substrings That Satisfy K-Constraint II : https://leetcode.com/problems/count-substrings-that-satisfy-k-constraint-ii
*/


/**************************************************************** C++ ****************************************************************/

////////////////////////////////////////////// "Count Substrings That Satisfy K-Constraint I" //////////////////////////////////////////////
//Approach-1 (Using Brute Force)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.length();

        int result = 0;

        for(int i = 0; i < n; i++) {

            int count0 = 0;
            int count1 = 0;

            for(int j = i; j < n; j++) {
                if(s[j] == '0') {
                    count0++;
                } else {
                    count1++;
                }

                if(count0 <= k || count1 <= k) {
                    result += 1;
                } else {
                    break;
                }
            }
        }

        return result;
    }
};


////////////////////////////////////////////// "Count Substrings That Satisfy K-Constraint I" //////////////////////////////////////////////
//Approach-2 (Using Sliding Window)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.length();

        int result = 0;

        int count0 = 0;
        int count1 = 0;

        int i = 0;
        int j = 0;

        //T.C : O(n)
        while(j < n) {
            if(s[j] == '0') {
                count0++;
            } else {
                count1++;
            }

            while(count0 > k && count1 > k) { //unsatisfied window, keep shrinking
                if(s[i] == '0') {
                    count0--;
                } else {
                    count1--;
                }
                i++;
            }

            result += (j - i + 1);
            j++;
        }

        return result;
    }
};



////////////////////////////////////////////// "Count Substrings That Satisfy K-Constraint II" //////////////////////////////////////////////
//(Using Sliding Window and cumulative sum)
//T.C : O(n + Q), where n = s.length and Q = number of queries
//S.C : O(n)
class Solution {
public:
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) {
        int n = s.length();
        
        vector<int> leftMost(n, 0);
        vector<int> rightMost(n, 0);

        //leftMost[j] = i; //For index j, what is the left most valid index i until which we get valid substring
        int i = 0;
        int j = 0;
        unordered_map<char, int> mp;

        while(j < n) {
            mp[s[j]]++;
            while(mp['0'] > k && mp['1'] > k) {
                mp[s[i]]--;
                i++;
            }

            leftMost[j] = i;
            j++;
        }

        //rightMost[j] = i; //For index j, what is the right most valid index until which we get valid substring
        mp.clear();
        i = n-1;
        j = n-1;
        while( j >= 0) {
            mp[s[j]]++;
            while(mp['0'] > k && mp['1'] > k) {
                mp[s[i]]--;
                i--;
            }
            rightMost[j] = i;
            j--;
        }

        //tempValidSubstr[j] = number of valid substrings ending at index j
        vector<int> tempValidSubstr(n, 0);
        for(int j = 0; j < n; j++) {
            tempValidSubstr[j] = j - leftMost[j] + 1;
        }

        //cumSum
        vector<long long> cumSum(n, 0);
        cumSum[0] = tempValidSubstr[0];
        for(int i = 1; i < n; i++) {
            cumSum[i] = cumSum[i-1] + tempValidSubstr[i];
        }

        vector<long long> result;
        for(vector<int>& query : queries) {
            int low  = query[0];
            int high = query[1];

            int validRightIdx = min(high, rightMost[low]);

            long long length = validRightIdx - low + 1;

            long long tempResult = length * (length+1)/2;

            tempResult += cumSum[high] - cumSum[validRightIdx];

            result.push_back(tempResult);


        }

        return result;
      
    }
};




/**************************************************************** JAVA ****************************************************************/

////////////////////////////////////////////// "Count Substrings That Satisfy K-Constraint I" //////////////////////////////////////////////
//Approach-1 (Using Brute Force)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
    public int countKConstraintSubstrings(String s, int k) {
        int n = s.length();
        int result = 0;

        for (int i = 0; i < n; i++) {
            int count0 = 0;
            int count1 = 0;

            for (int j = i; j < n; j++) {
                if (s.charAt(j) == '0') {
                    count0++;
                } else {
                    count1++;
                }

                if (count0 <= k || count1 <= k) {
                    result += 1;
                } else {
                    break;
                }
            }
        }

        return result;
    }
}



////////////////////////////////////////////// "Count Substrings That Satisfy K-Constraint I" //////////////////////////////////////////////
//Approach-2 (Using Sliding Window)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int countKConstraintSubstrings(String s, int k) {
        int n = s.length();

        int result = 0;

        int count0 = 0;
        int count1 = 0;

        int i = 0;
        int j = 0;

        // T.C: O(n)
        while (j < n) {
            if (s.charAt(j) == '0') {
                count0++;
            } else {
                count1++;
            }

            while (count0 > k && count1 > k) { // Unsatisfied window, keep shrinking
                if (s.charAt(i) == '0') {
                    count0--;
                } else {
                    count1--;
                }
                i++;
            }

            result += (j - i + 1);
            j++;
        }

        return result;
    }
}



////////////////////////////////////////////// "Count Substrings That Satisfy K-Constraint II" //////////////////////////////////////////////
//(Using Sliding Window and cumulative sum)
//T.C : O(n + Q), where n = s.length and Q = number of queries
//S.C : O(n)
class Solution {
    public long[] countKConstraintSubstrings(String s, int k, int[][] queries) {
        int n = s.length();
        
        int[] leftMost = new int[n];
        int[] rightMost = new int[n];
        
        // Left-most valid index for each position
        int i = 0;
        int j = 0;
        Map<Character, Integer> mp = new HashMap<>();
        
        while (j < n) {
            mp.put(s.charAt(j), mp.getOrDefault(s.charAt(j), 0) + 1);
            while (mp.getOrDefault('0', 0) > k && mp.getOrDefault('1', 0) > k) {
                mp.put(s.charAt(i), mp.get(s.charAt(i)) - 1);
                i++;
            }
            leftMost[j] = i;
            j++;
        }
        
        // Right-most valid index for each position
        mp.clear();
        i = n - 1;
        j = n - 1;
        while (j >= 0) {
            mp.put(s.charAt(j), mp.getOrDefault(s.charAt(j), 0) + 1);
            while (mp.getOrDefault('0', 0) > k && mp.getOrDefault('1', 0) > k) {
                mp.put(s.charAt(i), mp.get(s.charAt(i)) - 1);
                i--;
            }
            rightMost[j] = i;
            j--;
        }
        
        // Number of valid substrings ending at each position
        int[] tempValidSubstr = new int[n];
        for (j = 0; j < n; j++) {
            tempValidSubstr[j] = j - leftMost[j] + 1;
        }
        
        // Cumulative sum of valid substrings
        long[] cumSum = new long[n];
        cumSum[0] = tempValidSubstr[0];
        for (i = 1; i < n; i++) {
            cumSum[i] = cumSum[i - 1] + tempValidSubstr[i];
        }
        
        long[] result = new long[queries.length];
        for (i = 0; i < queries.length; i++) {
            int low = queries[i][0];
            int high = queries[i][1];
            
            int validRightIdx = Math.min(high, rightMost[low]);
            
            long length = validRightIdx - low + 1;
            
            long tempResult = length * (length + 1) / 2;
            
            if (validRightIdx < high) {
                tempResult += cumSum[high] - cumSum[validRightIdx];
            }
            
            result[i] = tempResult;
        }
        
        return result;
    }
}
