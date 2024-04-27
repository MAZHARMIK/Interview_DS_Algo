/*     Scroll down to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=yUNjMFE1tGo
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/freedom-trail
    DP Solution                 : https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/DP/DP%20on%20Strings/Freedom%20Trail.cpp
*/

/************************************************************ C++ ************************************************/
//Approach (Using DIjkstra's)
//T.C : O(nm log(nm)) where n = length of ring, m = length of keyword. n*m = maximum number of pairs we visit is the number of unique possible pairs and push and pop
      //operations will take log(n*m)
//S.C : O(n*m) pairs stored in heap
class Solution {
public:
    int countSteps(int ringIndex, int i, int n) {
        int dist       = abs(i - ringIndex);
        int wrapAround =  n - dist;
        
        return min(dist, wrapAround);
    }
    
    int findRotateSteps(string ring, string key) {
        int n = ring.length();
        int m = key.length();
        
        unordered_map<char, vector<int>> adj; // char --> {indices in ring where char is present}
        for (int i = 0; i < n; i++) {
            char ch = ring[i];
            adj[ch].push_back(i);
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});

        set<pair<int, int>> visited;
        
        int totalSteps = 0;
        while (!pq.empty()) {
            vector<int> vec = pq.top();
            pq.pop();
            
            totalSteps    = vec[0];
            int ringIndex = vec[1];
            int keyIndex  = vec[2];
            
            if (keyIndex == m) {
                break;
            }
            
            if (visited.count({ringIndex, keyIndex})) {
                continue;
            }

            visited.insert({ringIndex, keyIndex});
            
            for (int nextIndex : adj[key[keyIndex]]) {
                pq.push({totalSteps + countSteps(ringIndex, nextIndex, n), 
                            nextIndex, keyIndex + 1});
            }
        }
        
        return totalSteps + m; //Note : totalSteps is for bringing each character to 12:00 position and then printing each of them will take m steps
    }
};

/************************************************************ JAVA ************************************************/
//Approach (Using DIjkstra's)
//T.C : O(nm log(nm)) where n = length of ring, m = length of keyword. n*m = maximum number of pairs we visit is the number of unique possible pairs and push and pop
      //operations will take log(n*m)
//S.C : O(n*m) pairs stored in heap
import java.util.*;

public class Solution {
    public int countSteps(int ringIndex, int i, int n) {
        int dist = Math.abs(i - ringIndex);
        int wrapAround = n - dist;
        
        return Math.min(dist, wrapAround);
    }
    
    public int findRotateSteps(String ring, String key) {
        int n = ring.length();
        int m = key.length();
        
        Map<Character, List<Integer>> adj = new HashMap<>(); // char --> {indices in ring where char is present}
        for (int i = 0; i < n; i++) {
            char ch = ring.charAt(i);
            if (!adj.containsKey(ch)) {
                adj.put(ch, new ArrayList<>());
            }
            adj.get(ch).add(i);
        }

        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.offer(new int[]{0, 0, 0});

        Set<String> visited = new HashSet<>();
        
        int totalSteps = 0;
        while (!pq.isEmpty()) {
            int[] vec = pq.poll();
            
            totalSteps    = vec[0];
            int ringIndex = vec[1];
            int keyIndex  = vec[2];
            
            if (keyIndex == m) {
                break;
            }
            
            if (visited.contains(ringIndex + "-" + keyIndex)) {
                continue;
            }

            visited.add(ringIndex + "-" + keyIndex);
            
            for (int nextIndex : adj.get(key.charAt(keyIndex))) {
                pq.offer(new int[]{totalSteps + countSteps(ringIndex, nextIndex, n), 
                            nextIndex, keyIndex + 1});
            }
        }
        
        return totalSteps + m; //Note : totalSteps is for bringing each character to 12:00 position and then printing each of them will take m steps
    }
}
