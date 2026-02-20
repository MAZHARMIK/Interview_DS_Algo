/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/special-binary-string
*/


/************************************************************ C++ ******************************************************/
//Approach : (Recursion)
//T.C : ~O(n^2)
//S.C : O(n) stack space and to store special substrings
class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> specials;

        int start = 0;
        int sum = 0;

        for(int i = 0; i < s.length(); i++) {
            sum += s[i] == '1' ? 1 : -1;

            if(sum == 0) {
                string inner = s.substr(start+1, i-start-1);
                specials.push_back("1" + makeLargestSpecial(inner) + "0");
                start = i+1;
            }
        }


        sort(begin(specials), end(specials), greater<string>());

        string result;
        for(string &str : specials) {
            result += str;
        }

        return result;    
    }
};



/************************************************************ JAVA ******************************************************/
//Approach : (Recursion)
//T.C : ~O(n^2)
//S.C : O(n) stack space and to store special substrings
class Solution {
    public String makeLargestSpecial(String s) {

        List<String> specials = new ArrayList<>();
        int count = 0;
        int start = 0;

        for (int i = 0; i < s.length(); i++) {
            count += (s.charAt(i) == '1') ? 1 : -1;

            if (count == 0) {
                String inner = s.substring(start + 1, i);

                String processed = "1" + makeLargestSpecial(inner) + "0";
                specials.add(processed);

                start = i + 1;
            }
        }

        Collections.sort(specials, Collections.reverseOrder());


        StringBuilder result = new StringBuilder();
        for (String str : specials) {
            result.append(str);
        }

        return result.toString();
    }
}
