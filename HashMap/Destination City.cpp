/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=GyHzuQC7sd8
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/destination-city/
*/

/******************************************************************* C++ *******************************************************************/
//Approach-1 (Using HashMap) - Count Outdegrees
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> mp;
        
        for(auto &path : paths) {
            string source = path[0]; //outdegree
            mp[source]++;
        }
        
        for(auto &path : paths) {
            string dest = path[1];
            
            if(mp[dest] == 0) {
                return dest;
            }
        }
        
        return "";
    }
};

//Approach-2 (Using Hashset)
-> Link - https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/HashSet/Destination%20City.cpp


/******************************************************************* JAVA *******************************************************************/
//Approach-1 (Using HashMap) - Count Outdegrees
//T.C : O(n)
//S.C : O(n)
public class Solution {
    public String destCity(List<List<String>> paths) {
        Map<String, Integer> mp = new HashMap<>();
        
        for(List<String> path : paths) {
            String source = path.get(0); // outdegree
            mp.put(source, mp.getOrDefault(source, 0) + 1);
        }
        
        for(List<String> path : paths) {
            String dest = path.get(1);
            
            if(mp.getOrDefault(dest, 0) == 0) {
                return dest;
            }
        }
        
        return "";
    }
}


//Approach-2 (Using Hashset)
-> Link - https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/HashSet/Destination%20City.cpp
