/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=ULWeRPZHphw
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/find-words-containing-character
*/

/*********************************************************** C++ **************************************************/
//Approach (usin c++ STL)
//T.C : O(m*n) 
//S.C : O(1)
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> res;
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            if (words[i].find(x) != string::npos) {
                res.push_back(i);
            }
        }
        return res;
    }
};



/*********************************************************** JAVA **************************************************/
//T.C : O(m*n) 
//S.C : O(1)
class Solution {
    public List<Integer> findWordsContaining(String[] words, char x) {
        List<Integer> result = new ArrayList<>();

        for (int i = 0; i < words.length; i++) {
            if (words[i].chars().anyMatch(ch -> ch == x)) {
                result.add(i);
            }
        }

        return result;
    }
}
