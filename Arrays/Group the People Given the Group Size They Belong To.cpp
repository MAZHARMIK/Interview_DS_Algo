/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=QFjOkJt5hrI
    Company Tags                : LYFT
    Leetcode Link               : https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/
*/

/********************************* C++ *********************************/
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        
        vector<vector<int>> mp(n+1);
        vector<vector<int>> result;
        
        for(int i = 0; i<n; i++) {
            
            int l = groupSizes[i];
            
            mp[l].push_back(i);
            
            if(mp[l].size() == l) {
                result.push_back(mp[l]);
                mp[l] = {};
            }
            
        }
        
        return result;
    }
};

/********************************* JAVA *********************************/
class Solution {
    public List<List<Integer>> groupThePeople(int[] groupSizes) {
        int n = groupSizes.length;
        
        List<List<Integer>> result = new ArrayList();
        Map<Integer, List<Integer>> mp = new HashMap<>();
        
        for (int i = 0; i < n; ++i) {
            List<Integer> list = mp.computeIfAbsent(groupSizes[i], k -> new ArrayList());
            
            list.add(i);
            
            if (list.size() == groupSizes[i]) {
              result.add(list);
              mp.put(groupSizes[i], new ArrayList());
            }
            
        }
        return result;
    }
}
