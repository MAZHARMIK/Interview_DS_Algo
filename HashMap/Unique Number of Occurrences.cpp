/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=b2_rw2NZkr8
    Company Tags                : Google, Twitter, Amazon, Netflix
    Leetcode Link               : https://leetcode.com/problems/unique-number-of-occurrences/
*/

/****************************************************************************** JAVA ******************************************************************************/
//Approach-1 (Simple using hash map and set)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        
        //store frequency of each numbers
        for(int &x : arr) {
            mp[x]++;
        }
        
        unordered_set<int> st;
        
        for(auto &it : mp) {
            int freq = it.second; //it.first = number
            
            if(st.find(freq) != st.end())
                return false;
            st.insert(freq);
        }
        
        return true;
    }
};


//Approach-2 (Making benefit of constraints)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> vec(2001, 0);
        
        for(int &x : arr) {
            vec[x + 1000]++;
        }
        
        sort(begin(vec), end(vec));
        
        for(int i = 1; i<2001; i++) {
            if(vec[i] != 0 && vec[i] == vec[i-1])
                return false;
        }
        
        
        return true;
    }
};


//Approach-3 (Improvement on Approach-2)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> vec(2001, 0);
        
        for(int &x : arr) {
            vec[x + 1000]++;
        }
        
        for(int i = 1; i<2001; i++) {
            if(vec[i] == 0) continue;

            int idx = abs(vec[i]);
            
            if (vec[idx] < 0) {
                return false;
            }

            vec[idx] = -1;
        }
        
        
        return true;
    }
};

/****************************************************************************** JAVA ******************************************************************************/
//Approach-1 (Simple using hash map and set)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        HashMap<Integer, Integer> map = new HashMap<>();
        
        // Store frequency of each number
        for (int x : arr) {
            map.put(x, map.getOrDefault(x, 0) + 1);
        }
        
        HashSet<Integer> set = new HashSet<>();
        
        for (int freq : map.values()) {
            if (set.contains(freq)) {
                return false;
            }
            set.add(freq);
        }
        
        return true;
    }
}


//Approach-2 (Making benefit of constraints)
//T.C : O(nlogn)
//S.C : O(1)
public class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        int[] vec = new int[2001];

        for (int x : arr) {
            vec[x + 1000]++;
        }

        Arrays.sort(vec);

        for (int i = 1; i < 2001; i++) {
            if (vec[i] != 0 && vec[i] == vec[i - 1]) {
                return false;
            }
        }

        return true;
    }
}


//Approach-3 (Improvement on Approach-2)
//T.C : O(n)
//S.C : O(1)
public class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        int[] vec = new int[2001];

        for (int x : arr) {
            vec[x + 1000]++;
        }

        for (int i = 0; i < 2001; i++) {
            if(vec[i] == 0) continue;

            int idx = Math.abs(vec[i]);
            
            if (vec[idx] < 0) {
                return false;
            }

            vec[idx] = -1;
        }

        return true;
    }
}
