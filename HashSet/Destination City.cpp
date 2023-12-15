/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=GyHzuQC7sd8
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/destination-city/
*/

/******************************************************************* C++ *******************************************************************/
//Approach-1 (Using HashSet) - Count Outdegrees
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> st;
        
        for(auto &path : paths) {
            string source = path[0]; //source
            st.insert(source);
        }
        
        for(auto &path : paths) {
            string dest = path[1];
            
            if(st.find(dest) == st.end()) {
                return dest;
            }
        }
        
        return "";
    }
};

//Approach-2 (Using HashMap)
//Link - https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/HashMap/Destination%20City.cpp


/******************************************************************* JAVA *******************************************************************/
//Approach-1 (Using HashSet) - Count Outdegrees
//T.C : O(n)
//S.C : O(n)
public class Solution {
    public String destCity(List<List<String>> paths) {
        Set<String> st = new HashSet<>();
        
        for(List<String> path : paths) {
            String source = path.get(0); // source
            st.add(source);
        }
        
        for(List<String> path : paths) {
            String dest = path.get(1);
            
            if(!st.contains(dest)) {
                return dest;
            }
        }
        
        return "";
    }
}


//Approach-2 (Using HashMap)
//Link - https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/HashMap/Destination%20City.cpp
