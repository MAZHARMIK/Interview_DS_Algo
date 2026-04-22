/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/words-within-two-edits-of-dictionary
*/


/**************************************************************** C++ ****************************************************************/
//Approach (Iterate and check)
//T.C : O(q * d * n), q = queries.size(), d = dictionary.size(), n = query[i].length()
//S.C : O(1)
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries,
                                vector<string>& dictionary) {
        vector<string> result;

        for (string& query : queries) {
            
            for (string& s : dictionary) {
                int diff = 0;

                for (int i = 0; i < query.size(); i++) {
                    if (query[i] != s[i]) {
                        ++diff;
                    }

                    if(diff > 2)
                        break;
                }

                if (diff <= 2) {
                    result.push_back(query);
                    break;
                }
            }
        }
        return result;
    }
};




/**************************************************************** JAVA ****************************************************************/
//Approach (Iterate and check)
//T.C : O(q * d * n), q = queries.size(), d = dictionary.size(), n = query[i].length()
//S.C : O(1)
class Solution {
    public List<String> twoEditWords(String[] queries, String[] dictionary) {
        List<String> result = new ArrayList<>();

        for (String query : queries) {

            for (String s : dictionary) {
                int diff = 0;

                for (int i = 0; i < query.length(); i++) {
                    if (query.charAt(i) != s.charAt(i)) {
                        diff++;
                    }

                    if (diff > 2)
                        break;
                }

                if (diff <= 2) {
                    result.add(query);
                    break;
                }
            }
        }

        return result;
    }
}
