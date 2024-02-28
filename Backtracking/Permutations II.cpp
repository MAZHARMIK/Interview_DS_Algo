/*                 Scroll down to see JAVA code also     */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Vd2YizhbN74
    Company Tags                : Google, Accolite, Amazon, OYO Rooms, Samsung, Snapdeal, Citrix, Walmart, MAQ Software, Cisco, Apple
    Leetcode Qn Link            : https://leetcode.com/problems/permutations-ii/
*/

/********************************************************* C++ *********************************************************/
//Approach-1 (Using same concept as Permutation-I but keeping count to avoid duplicates)
//T.C : O(N * N!)
//S.C : O(N)
class Solution {
public:
    int n;
    vector<vector<int>> result;
    void backtrack(vector<int>& temp, unordered_map<int, int>& mp) {

        if (temp.size() == n) { //we got all numbers
            result.push_back(temp);
            return;
        }

        for (auto& [num, count] : mp) {

            if (count == 0)
                continue;
            
            // Do something
            temp.push_back(num);
            mp[num]--;

            // Explore it
            backtrack(temp, mp);

            // Undo it
            temp.pop_back();
            mp[num]++;
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        unordered_map<int, int> mp;
        
        // count the occurrence of each number
        for (int& num : nums) {
            mp[num]++;
        }
        
        vector<int> temp;
        backtrack(temp, mp);
        
        return result;
    }
};



//Approach-2 (Using swap technique but avoiding duplicates by using set)
//T.C : O(N * N!) worst case
//S.C : O(N)
class Solution {
public:
    vector<vector<int>> result;
    int n;
    void solve(int idx, vector<int>& nums) {
        if(idx == n) {
            result.push_back(nums);
            return;
        }
        
        unordered_set<int> uniqueSet;
        for(int i = idx; i < n; i++) {
            
            if(uniqueSet.count(nums[i]) > 0) {
                continue;
            }
            
            uniqueSet.insert(nums[i]);
            
            swap(nums[i], nums[idx]);

            solve(idx+1, nums);

            swap(nums[i], nums[idx]);
            
        }
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        
        solve(0, nums);
        
        return result;
    }
};


/********************************************************* JAVA *********************************************************/
//Approach-1 (Using same concept as Permutation-I but keeping count to avoid duplicates)
//T.C : O(N * N!)
//S.C : O(N)
class Solution {
    private List<List<Integer>> result = new ArrayList<>();
    private int n;

    public List<List<Integer>> permuteUnique(int[] nums) {
        n = nums.length;
        Map<Integer, Integer> mp = new HashMap<>();

        // Count the occurrence of each number
        for (int num : nums) {
            mp.put(num, mp.getOrDefault(num, 0) + 1);
        }

        List<Integer> temp = new ArrayList<>();
        backtrack(temp, mp);

        return result;
    }

    private void backtrack(List<Integer> temp, Map<Integer, Integer> mp) {
        if (temp.size() == n) { // We got all numbers
            result.add(new ArrayList<>(temp));
            return;
        }

        for (Map.Entry<Integer, Integer> entry : mp.entrySet()) {
            int num = entry.getKey();
            int count = entry.getValue();

            if (count == 0)
                continue;

            // Do something
            temp.add(num);
            mp.put(num, count - 1);

            // Explore it
            backtrack(temp, mp);

            // Undo it
            temp.remove(temp.size() - 1);
            mp.put(num, count);
        }
    }
}


//Approach-2 (Using swap technique but avoiding duplicates by using set)
//T.C : O(N * N!) worst case
//S.C : O(N)
class Solution {
    private List<List<Integer>> result = new ArrayList<>();
    private int n;

    public List<List<Integer>> permuteUnique(int[] nums) {
        n = nums.length;

        solve(0, nums);

        return result;
    }

    private void solve(int idx, int[] nums) {
        if (idx == n) {
            List<Integer> permutation = new ArrayList<>();
            for (int num : nums) {
                permutation.add(num);
            }
            result.add(permutation);
            return;
        }

        Set<Integer> uniqueSet = new HashSet<>();
        for (int i = idx; i < n; i++) {

            if (uniqueSet.contains(nums[i])) {
                continue;
            }

            uniqueSet.add(nums[i]);

            swap(nums, i, idx);

            solve(idx + 1, nums);

            swap(nums, i, idx);
        }
    }

    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
