/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=5FWc--uZRwo
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/diagonal-traverse-ii/
*/

//Approach-1 (Using map)
//T.C : O(n) where n = all elements in grid
//S.C : O(n) We took map to store all elements
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> mp;
        
        
        for(int row = nums.size()-1; row >= 0; row--) {
            for(int col = 0; col < nums[row].size(); col++) {
                
                mp[row+col].push_back(nums[row][col]);
                
            }
        }
        
        vector<int> result;
        int diagonal = 0;
        
        while(mp.find(diagonal) != mp.end()) {
            
            for(int &num : mp[diagonal]) {
                result.push_back(num);
            }
            diagonal++;
        }
        
        return result;
        
    }
};


//Approach-2 (Usign BFS)
//T.C : O(n) visiting all elements
//S.C : O(sqrt(n)) -> See my youtube video above for explanation
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        queue<pair<int, int>> que;
        que.push({0, 0});
        vector<int> result;
        
        while (!que.empty()) {
            auto [row, col] = que.front();
            que.pop();
            result.push_back(nums[row][col]);
            
            if (col == 0 && row + 1 < nums.size()) {
                que.push({row + 1, col});
            }
            
            if (col + 1 < nums[row].size()) {
                que.push({row, col + 1});
            }
        }
        
        return result;
    }
};


/******************************************************************** JAVA **************************************************************************/
//Approach-1 (Using map)
//T.C : O(n) where n = all elements in grid
//S.C : O(n) We took map to store all elements
class Solution {
    public int[] findDiagonalOrder(List<List<Integer>> nums) {
        Map<Integer, List<Integer>> groups = new HashMap();
        int n = 0;
        for (int row = nums.size() - 1; row >= 0; row--) {
            for (int col = 0; col < nums.get(row).size(); col++) {

                if (!groups.containsKey(row + col)) {
                    groups.put(row + col, new ArrayList<Integer>());
                }

                groups.get(row + col).add(nums.get(row).get(col));
                n++;
            }
        }

        int[] result = new int[n];
        int i = 0;
        int diagonal = 0;

        while (groups.containsKey(diagonal)) {
            for (int num : groups.get(diagonal)) {
                result[i] = num;
                i++;
            }

            diagonal++;
        }

        return result;
    }
}


//Approach-2 (Usign BFS)
//T.C : O(n) visiting all elements
//S.C : O(sqrt(n)) -> See my youtube video above for explanation
class Solution {
    public int[] findDiagonalOrder(List<List<Integer>> nums) {
        Queue<Pair<Integer, Integer>> que = new LinkedList();
        que.offer(new Pair(0, 0));
        List<Integer> ans = new ArrayList();
        
        while (!que.isEmpty()) {
            Pair<Integer, Integer> p = que.poll();
            int row = p.getKey();
            int col = p.getValue();
            ans.add(nums.get(row).get(col));
            
            if (col == 0 && row + 1 < nums.size()) {
                que.offer(new Pair(row + 1, col));
            }
            
            if (col + 1 < nums.get(row).size()) {
                que.offer(new Pair(row, col + 1));
            }
        }
        
        // Java needs conversion
        int[] result = new int[ans.size()];
        int i = 0;
        for (int num : ans) {
            result[i] = num;
            i++;
        }
        
        return result;
    }
}


