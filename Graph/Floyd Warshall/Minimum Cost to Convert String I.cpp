/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/minimum-cost-to-convert-string-i/
*/

/***************************************************************** C++ ******************************************************************************/
//Approach-1 (Using Simple Floyd Warshall Algorithm)
//T.C : O(n)  -> Because other for loops run only for constant time 26*26*26
//S.C : O(1) -> We take distances matrix of 26*26 which is constant
class Solution {
public:
    
    void FloydWarshall(vector<vector<long long>>& distances, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        for (int i = 0; i < original.size(); ++i) {
            int s = original[i] - 'a';
            int t = changed[i] - 'a';
            
            distances[s][t] = min(distances[s][t], (long long)cost[i]);
        }
        
        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]); 
                }
            }
        }
    }
    
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> distances(26, vector<long long>(26, INT_MAX));
        
        FloydWarshall(distances, original, changed, cost);

        long long ans = 0;
        for (int i = 0; i < source.size(); i++) {
            
            if (source[i] == target[i]) continue;

            if (distances[source[i] - 'a'][target[i] - 'a'] == INT_MAX) 
                return -1;
            
            else ans += distances[source[i] - 'a'][target[i] - 'a'];
        }

        return ans;
    }
};

//Approach-2 (Simply replace Floyd Warshall with Dijkstra's Algorithm)
//Link (Inside my "Dijkstra's Based Problems" Warshall folder) - 



/***************************************************************** JAVA ******************************************************************************/
//Approach-1 (Using Simple Floyd Warshall Algorithm)
//T.C : O(n)  -> Because other for loops run only for constant time 26*26*26
//S.C : O(1) -> We take distances matrix of 26*26 which is constant
public class Solution {

    private void FloydWarshall(long[][] distances, char[] original, char[] changed, int[] cost) {
        for (int i = 0; i < original.length; ++i) {
            int s = original[i] - 'a';
            int t = changed[i] - 'a';
            distances[s][t] = Math.min(distances[s][t], (long) cost[i]);
        }

        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    distances[i][j] = Math.min(distances[i][j], distances[i][k] + distances[k][j]);
                }
            }
        }
    }

    public long minimumCost(String source, String target, char[] original, char[] changed, int[] cost) {
        long[][] distances = new long[26][26];
        for (int i = 0; i < 26; i++) {
            Arrays.fill(distances[i], Integer.MAX_VALUE);
        }

        FloydWarshall(distances, original, changed, cost);

        long ans = 0;
        for (int i = 0; i < source.length(); i++) {
            if (source.charAt(i) == target.charAt(i)) {
                continue;
            }

            if (distances[source.charAt(i) - 'a'][target.charAt(i) - 'a'] == Integer.MAX_VALUE) {
                return -1;
            } else {
                ans += distances[source.charAt(i) - 'a'][target.charAt(i) - 'a'];
            }
        }

        return ans;
    }
}
