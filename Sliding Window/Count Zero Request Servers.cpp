/*			Scroll below to see JAVA code also			*/
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=iMCVsCcJl_Q
    Company Tag                 : will update later
    Leetcode Link               : https://leetcode.com/problems/count-zero-request-servers/description/
*/


/*************************************************************** C++ *************************************************/
//Approach (Sorting + Sliding Window)
//T.C : O(nlogn + qlogq), n = log.size(), q = query.size()
//S.C : O(n + q)
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = logs.size();

        auto lambda = [](vector<int>& vec1, vector<int>& vec2) {
            return vec1[1] < vec2[1];
        };

        sort(begin(logs), end(logs), lambda);

        int q = queries.size();
        vector<pair<int,int>> timeIndex(q);     // {time, original idx}
        for (int i = 0; i < q; i++) 
            timeIndex[i] = {queries[i], i};

        sort(begin(timeIndex), end(timeIndex));

        unordered_map<int,int> mp;              //count unique servers in the window
        vector<int> result(q);

        int i = 0, j = 0;
        for (auto [curtime, ind] : timeIndex) {
            int start = curtime - x;
            int end   = curtime;

            // right expand: time <= end
            while (j < m && logs[j][1] <= end) {
                mp[logs[j][0]]++;
                j++;
            }

            // left shrink: time < start
            while (i < m && logs[i][1] < start) {
                mp[logs[i][0]]--;
                if (mp[logs[i][0]] == 0) 
                    mp.erase(logs[i][0]);
                
                i++;
            }

            //mp.size() unique servers got requests. So, n - mp.size() did not recieve requests 
            result[ind] = n - mp.size();
        }

        return result;
    }
};




/*************************************************************** JAVA *************************************************/
//Approach (Sorting + Sliding Window)
//T.C : O(nlogn + qlogq), n = log.size(), q = query.size()
//S.C : O(n + q)
class Solution {
    public int[] countServers(int n, int[][] logs, int x, int[] queries) {
        int m = logs.length;
        
        // Sort logs by time (index 1)
        Arrays.sort(logs, (a, b) -> a[1] - b[1]);
        
        int q = queries.length;
        int[][] timeIndex = new int[q][2];  // {time, original index}
        for (int i = 0; i < q; i++) {
            timeIndex[i][0] = queries[i];
            timeIndex[i][1] = i;
        }
        
        // Sort timeIndex by time
        Arrays.sort(timeIndex, (a, b) -> a[0] - b[0]);
        
        Map<Integer, Integer> mp = new HashMap<>();  // server_id -> count in window
        int[] result = new int[q];
        
        int i = 0, j = 0;
        for (int[] pair : timeIndex) {
            int curtime = pair[0];
            int ind = pair[1];
            
            int start = curtime - x;
            int end = curtime;
            
            // Right expand: time <= end
            while (j < m && logs[j][1] <= end) {
                int serverId = logs[j][0];
                mp.put(serverId, mp.getOrDefault(serverId, 0) + 1);
                j++;
            }
            
            // Left shrink: time < start
            while (i < m && logs[i][1] < start) {
                int serverId = logs[i][0];
                mp.put(serverId, mp.get(serverId) - 1);
                if (mp.get(serverId) == 0) {
                    mp.remove(serverId);
                }
                i++;
            }
            
            // mp.size() unique servers got requests
            result[ind] = n - mp.size();
        }
        
        return result;
    }
}
