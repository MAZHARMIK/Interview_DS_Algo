/*      Scroll down to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=wHXZ5_JmLa8
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/shortest-uncommon-substring-in-an-array
*/


/********************************************************************* C++ ************************************************************************/
//Approach (Straight forward brute force)
//Only one smart move is to precompute the substrings so that you don't have to check for same substring again and again
//T.C : ~O(n^4)
//S.C : O(n^3) storing all unique substrings in seen (In worst case we will have n^2 substrings from each string (suppose of length n) and let's we have n string in total
class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        vector<string> result;
        unordered_map<string, int> unique_substr;

        for (string& str : arr) {

            unordered_set<string> seen; //Explained in video why we need this seen

            for (int i = 0; i < str.length(); i++) {
                for (int j = i + 1; j <= str.length(); j++) {

                    string substring = str.substr(i, j - i);
                    if (seen.find(substring) == seen.end()) {
                        unique_substr[substring]++;
                        seen.insert(substring);
                    }

                }
            }
        }
        for (const string& str : arr) {
            string shortest = "";

            for (int i = 0; i < str.length(); i++) {
                for (int j = i + 1; j <= str.length(); j++) {

                    string substring = str.substr(i, j - i);

                    if (unique_substr[substring] == 1 &&
                        (shortest == "" || substring.length() < shortest.length() 
                        || (substring.length() == shortest.length() && substring < shortest))) {

                        shortest = substring;
                    
                    }

                }
            }

            result.push_back(shortest);
        }
        return result;
    }
};


/********************************************************************* JAVA ************************************************************************/
//Approach (Straight forward brute force)
//Only one smart move is to precompute the substrings so that you don't have to check for same substring again and again
//T.C : ~O(n^4)
//S.C : O(n^3) storing all unique substrings in seen (In worst case we will have n^2 substrings from each string (suppose of length n) and let's we have n string in total
public class Solution {
    public String[] shortestSubstrings(String[] arr) {
        ArrayList<String> result = new ArrayList<>();
        HashMap<String, Integer> unique_substr = new HashMap<>();

        for (String str : arr) {
            HashSet<String> seen = new HashSet<>();

            for (int i = 0; i < str.length(); i++) {
                for (int j = i + 1; j <= str.length(); j++) {
                    String substring = str.substring(i, j);
                    
                    if (!seen.contains(substring)) {
                        unique_substr.put(substring, unique_substr.getOrDefault(substring, 0) + 1);
                        seen.add(substring);
                    }
                }
            }
        }

        for (String str : arr) {
            String shortest = "";

            for (int i = 0; i < str.length(); i++) {
                for (int j = i + 1; j <= str.length(); j++) {
                    String substring = str.substring(i, j);

                    if (unique_substr.get(substring) == 1 &&
                            (shortest.equals("") || substring.length() < shortest.length()
                                    || (substring.length() == shortest.length() && substring.compareTo(shortest) < 0))) {
                        shortest = substring;
                    }
                }
            }

            result.add(shortest);
        }

        return result.toArray(new String[0]);
    }
}
