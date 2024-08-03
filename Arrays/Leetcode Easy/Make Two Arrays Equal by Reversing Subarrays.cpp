/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=va0iQjn8rXU
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays
*/


/********************************************************* C++ *********************************************************/
//Approach - 1 (Sorting)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i<arr.size(); i++){
            if(arr[i] != target[i])
                return false;
        }
        return true;
    }
};


//Approach-2 (Using map)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> mp;
        for (int num : arr) {
            mp[num]++;
        }

        for (int &num : target) {
            if (mp.find(num) == mp.end())
                return false;

            mp[num]--;
            if (mp[num] == 0) {
                mp.erase(num);
            }
        }
        return mp.size() == 0;
    }
};



/********************************************************* JAVA *********************************************************/
//Approach - 1 (Sorting)
// T.C : O(nlogn)
// S.C : O(1)
class Solution {
    public boolean canBeEqual(int[] target, int[] arr) {
        Arrays.sort(target);
        Arrays.sort(arr);
        
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] != target[i])
                return false;
        }
        return true;
    }
}


// Approach-2 (Using map)
// T.C : O(n)
// S.C : O(n)
class Solution {
    public boolean canBeEqual(int[] target, int[] arr) {
        HashMap<Integer, Integer> map = new HashMap<>();
        
        for (int num : arr) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        
        for (int num : target) {
            if (!map.containsKey(num)) {
                return false;
            }
            map.put(num, map.get(num) - 1);
            if (map.get(num) == 0) {
                map.remove(num);
            }
        }
        
        return map.isEmpty();
    }
}
