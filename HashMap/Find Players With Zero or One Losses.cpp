/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=bXptmD2qWYI
    Company Tags                : Google, Indeed
    Leetcode Link               : https://leetcode.com/problems/find-players-with-zero-or-one-losses/
*/


/************************************************************ C++ ************************************************************/
//T.C : O(n*logn)
//S.C : O(n)
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> lost;
        
        for(auto &it : matches) {
            int lose = it[1];
            lost[lose]++;
        }
        
        vector<int> notLost;
        vector<int> oneLos;
        
        for(auto &it : matches) {
            int lose = it[1];
            int win  = it[0];
            
            if(lost[lose] == 1) {
                oneLos.push_back(lose);
            }
            if(lost.find(win) == lost.end()) {
                notLost.push_back(win);
                lost[win] = 2;
            }
            
        }
        
        sort(begin(notLost), end(notLost));
        sort(begin(oneLos), end(oneLos));
        
        return {notLost, oneLos};
        
    }
};


/************************************************************ JAVA ************************************************************/
//T.C : O(n*logn)
//S.C : O(n)
class Solution {
    public List<List<Integer>> findWinners(int[][] matches) {
        Map<Integer, Integer> lost = new HashMap<>();

        for (int[] it : matches) {
            int lose = it[1];
            lost.put(lose, lost.getOrDefault(lose, 0) + 1);
        }

        List<Integer> notLost = new ArrayList<>();
        List<Integer> oneLos = new ArrayList<>();

        for (int[] it : matches) {
            int lose = it[1];
            int win = it[0];

            if (lost.get(lose) == 1) {
                oneLos.add(lose);
            }
            if (!lost.containsKey(win)) {
                notLost.add(win);
                lost.put(win, 2);
            }
        }

        Collections.sort(notLost);
        Collections.sort(oneLos);

        return Arrays.asList(notLost, oneLos);
    }
}
