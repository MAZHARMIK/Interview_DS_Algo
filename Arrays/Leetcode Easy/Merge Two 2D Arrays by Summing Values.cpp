/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=G2XFLIjoIHA
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values
*/

/*********************************************************** C++ **************************************************/
//Approach-1 (Using unordered_map + sorting)
//T.C : O(m+n + NlogN), N = m+n, m = nums1.size(), n = nums2.size()
//S.C : O(m+n)
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        unordered_map<int, int> mp;
        vector<vector<int>> result;

        for(int i = 0; i < m; i++) {
            int id  = nums1[i][0];
            int val = nums1[i][1];

            mp[id] += val;
        }

        for(int i = 0; i < n; i++) {
            int id  = nums2[i][0];
            int val = nums2[i][1];

            mp[id] += val;
        }

        for(auto &it : mp) {
            int key = it.first;
            int val = it.second;

            result.push_back({key, val});
        }

        sort(begin(result), end(result)); //{id, val}

        return result;
    }
};



//Approach-2 (Using ordered+map)
//T.C : O(m+n + NlogN), insertion in ordered_map is logarithmic time complexity
//S.C : O(m+n)
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        map<int, int> mp;
        vector<vector<int>> result;

        for(int i = 0; i < m; i++) {
            int id  = nums1[i][0];
            int val = nums1[i][1];

            mp[id] += val;
        }

        for(int i = 0; i < n; i++) {
            int id  = nums2[i][0];
            int val = nums2[i][1];

            mp[id] += val;
        }

        for(auto &it : mp) {
            int key = it.first;
            int val = it.second;

            result.push_back({key, val});
        }

        return result;
    }
};


//Approach-3 (Using 2 Pointers)
//T.C : O(m+n)
//S.C : O(1)
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        int i = 0;
        int j = 0;
        vector<vector<int>> result;
        
        while(i < m && j < n) {
            if(nums1[i][0] < nums2[j][0]) {
                result.push_back(nums1[i]);
                i++;
            } else if(nums2[j][0] < nums1[i][0]) {
                result.push_back(nums2[j]);
                j++;
            } else {
                result.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                i++;
                j++;
            }
        }

        while(i < m) {
            result.push_back(nums1[i]);
            i++;
        }

        while(j < n) {
            result.push_back(nums2[j]);
            j++;
        }
        
        return result;
    }
};



/*********************************************************** Java **************************************************/
// Approach-1 (Using HashMap + Sorting)
// T.C : O(m+n + NlogN), N = m+n, m = nums1.length, n = nums2.length
// S.C : O(m+n)
class Solution {
    public int[][] mergeArrays(int[][] nums1, int[][] nums2) {
        int m = nums1.length;
        int n = nums2.length;
        
        Map<Integer, Integer> map = new HashMap<>();
        List<int[]> result = new ArrayList<>();
        
        for (int i = 0; i < m; i++) {
            int id = nums1[i][0];
            int val = nums1[i][1];
            
            map.put(id, map.getOrDefault(id, 0) + val);
        }
        
        for (int i = 0; i < n; i++) {
            int id = nums2[i][0];
            int val = nums2[i][1];
            
            map.put(id, map.getOrDefault(id, 0) + val);
        }
        
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            result.add(new int[]{entry.getKey(), entry.getValue()});
        }
        
        result.sort(Comparator.comparingInt(a -> a[0])); // {id, val}
        
        return result.toArray(new int[0][]);
    }
}


// Approach-2 (Using TreeMap)
// T.C : O(m+n + NlogN), insertion in TreeMap is logarithmic time complexity
// S.C : O(m+n)
class Solution {
    public int[][] mergeArrays(int[][] nums1, int[][] nums2) {
        int m = nums1.length;
        int n = nums2.length;
        
        TreeMap<Integer, Integer> map = new TreeMap<>();
        List<int[]> result = new ArrayList<>();
        
        for (int i = 0; i < m; i++) {
            int id = nums1[i][0];
            int val = nums1[i][1];
            
            map.put(id, map.getOrDefault(id, 0) + val);
        }
        
        for (int i = 0; i < n; i++) {
            int id = nums2[i][0];
            int val = nums2[i][1];
            
            map.put(id, map.getOrDefault(id, 0) + val);
        }
        
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            result.add(new int[]{entry.getKey(), entry.getValue()});
        }
        
        return result.toArray(new int[0][]);
    }
}


// Approach-3 (Using Two Pointers)
// T.C : O(m+n)
// S.C : O(1)
class Solution {
    public int[][] mergeArrays(int[][] nums1, int[][] nums2) {
        int m = nums1.length;
        int n = nums2.length;
        
        int i = 0, j = 0;
        List<int[]> result = new ArrayList<>();
        
        while (i < m && j < n) {
            if (nums1[i][0] < nums2[j][0]) {
                result.add(nums1[i]);
                i++;
            } else if (nums2[j][0] < nums1[i][0]) {
                result.add(nums2[j]);
                j++;
            } else {
                result.add(new int[]{nums1[i][0], nums1[i][1] + nums2[j][1]});
                i++;
                j++;
            }
        }
        
        while (i < m) {
            result.add(nums1[i]);
            i++;
        }
        
        while (j < n) {
            result.add(nums2[j]);
            j++;
        }
        
        return result.toArray(new int[0][]);
    }
}
