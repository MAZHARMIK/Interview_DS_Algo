/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=uJaWNFdm2IU
    Company Tags                : Amazon
    Leetcode Link               : https://leetcode.com/problems/path-crossing/
*/


/*************************************************************** C++ ***************************************************************/
//Approach (simply simulate and check visited)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<string> st;
        
        int x = 0;
        int y = 0;
        string key = to_string(x) + "_" + to_string(y);
        st.insert(key);
        
        for(char &ch : path) {
            if(ch == 'E') {
                x += 1;
            } else if(ch == 'W') {
                x -= 1;
            } else if(ch == 'N') {
                y += 1;
            } else {
                y -= 1;
            }
            
            key = to_string(x) + "_" + to_string(y);
            if(st.find(key) != st.end()) {
                return true;
            }
            
            st.insert(key);
        }
        
        return false;
    }
};


/*************************************************************** JAVA ***************************************************************/
//Approach (simply simulate and check visited)
//T.C : O(n)
//S.C : O(n)
public class Solution {
    public boolean isPathCrossing(String path) {
        Set<String> set = new HashSet<>();

        int x = 0;
        int y = 0;
        String key = x + "_" + y;
        set.add(key);

        for (char ch : path.toCharArray()) {
            if (ch == 'E') {
                x += 1;
            } else if (ch == 'W') {
                x -= 1;
            } else if (ch == 'N') {
                y += 1;
            } else {
                y -= 1;
            }

            key = x + "_" + y;
            if (set.contains(key)) {
                return true;
            }

            set.add(key);
        }

        return false;
    }
}
