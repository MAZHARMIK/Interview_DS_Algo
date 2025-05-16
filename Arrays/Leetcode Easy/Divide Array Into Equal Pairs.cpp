/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=9aI7FO6ZEoA
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/divide-array-into-equal-pairs
*/

/*********************************************************** C++ **************************************************/
//Approach-1 (Using map)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(int &x : nums) {
            mp[x]++;
        }

        for(auto &it : mp) {
            if(it.second % 2 != 0) {
                return false;
            }
        }

        return true;
    }
};


//Approach-2 (Using map)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_set<int> st;

        for(int &x : nums) {
            if(st.count(x)) {
                st.erase(x);
            } else {
                st.insert(x);
            }
        }

        return st.empty();
    }
};


//Approach-3 (Using map)
//T.C : O(n)
//S.C : O(501) ~ O(1)
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<bool> paired(501, true); 
        //paird[i] = true , means ith element is present in pairs

        for(int &x : nums) {
            paired[x] = !paired[x];
        }

        for(int i = 0; i < 501; i++) {
            if(paired[i] == false) {
                return false;
            }
        }

        return true;


    }
};


//Approach-4 (Using sorting and comparing)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));

        for(int i = 1; i < n; i+=2) {
            if(nums[i] != nums[i-1]) {
                return false;
            }
        }

        return true;
    }
};


//Approach-5 (Using sorting and xor)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));

        for(int i = 1; i < n; i+=2) {
            if((nums[i] ^ nums[i-1]) != 0) {
                return false;
            }
        }

        return true;
    }
};



/*********************************************************** Java **************************************************/
// Approach-1 (Using map)
// T.C : O(n)
// S.C : O(n)
class Solution {
    public boolean divideArray(int[] nums) {
        Map<Integer, Integer> mp = new HashMap<>();
        
        for (int x : nums) {
            mp.put(x, mp.getOrDefault(x, 0) + 1);
        }
        
        for (int count : mp.values()) {
            if (count % 2 != 0) {
                return false;
            }
        }
        
        return true;
    }
}


// Approach-2 (Using set)
// T.C : O(n)
// S.C : O(n)
class Solution {
    public boolean divideArray(int[] nums) {
        Set<Integer> st = new HashSet<>();
        
        for (int x : nums) {
            if (st.contains(x)) {
                st.remove(x);
            } else {
                st.add(x);
            }
        }
        
        return st.isEmpty();
    }
}


// Approach-3 (Using boolean array)
// T.C : O(n)
// S.C : O(501) ~ O(1)
class Solution {
    public boolean divideArray(int[] nums) {
        boolean[] paired = new boolean[501]; 
        Arrays.fill(paired, true);
        // paired[i] = true means ith element is present in pairs

        for (int x : nums) {
            paired[x] = !paired[x];
        }

        for (int i = 0; i < 501; i++) {
            if (!paired[i]) {
                return false;
            }
        }
        
        return true;
    }
}


// Approach-4 (Using sorting and comparing)
// T.C : O(nlogn)
// S.C : O(1)
class Solution {
    public boolean divideArray(int[] nums) {
        Arrays.sort(nums);
        
        for (int i = 1; i < nums.length; i += 2) {
            if (nums[i] != nums[i - 1]) {
                return false;
            }
        }
        
        return true;
    }
}


// Approach-5 (Using sorting and xor)
// T.C : O(nlogn)
// S.C : O(1)
class Solution {
    public boolean divideArray(int[] nums) {
        Arrays.sort(nums);
        
        for (int i = 1; i < nums.length; i += 2) {
            if ((nums[i] ^ nums[i - 1]) != 0) {
                return false;
            }
        }
        
        return true;
    }
}
