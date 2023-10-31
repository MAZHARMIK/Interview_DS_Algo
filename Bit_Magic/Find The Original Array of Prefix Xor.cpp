/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=TDjmp768H3Q
      Company Tags                : Microsoft
      Leetcode Link               : https://leetcode.com/problems/find-the-original-array-of-prefix-xor
*/

/*************************************************** C++ ***************************************************/
//Approach-1 (Using extra array)
//T.C : O(n)
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();

        vector<int> arr;
        arr.push_back(pref[0]);

        for(int i = 1; i<n; i++) {
            arr.push_back(pref[i] ^ pref[i-1]);
        }

        
        return arr;
    }
};

//Approach-2 (Without Using extra array)
//T.C : O(n)
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();

        for(int i = n-1; i > 0; i--) {
            pref[i] = pref[i] ^ pref[i-1];
        }

        
        return pref;
    }
};


/*************************************************** JAVA ***************************************************/
//Approach-1 (Using extra array)
//T.C : O(n)
class Solution {
    public List<Integer> findArray(List<Integer> pref) {
        int n = pref.size();

        List<Integer> arr = new ArrayList<>();
        arr.add(pref.get(0));

        for (int i = 1; i < n; i++) {
            arr.add(pref.get(i) ^ pref.get(i - 1));
        }

        return arr;
    }
}

//Approach-2 (Without Using extra array)
//T.C : O(n)
class Solution {
    public List<Integer> findArray(List<Integer> pref) {
        int n = pref.size();

        for (int i = n - 1; i > 0; i--) {
            pref.set(i, pref.get(i) ^ pref.get(i - 1));
        }

        return pref;
    }
}


