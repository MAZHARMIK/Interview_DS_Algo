/*   Scroll below to see JAVA code also  */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=-ShPKo-FXbw
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
*/


/******************************************************* C++ *******************************************************/
//Approach (Brute Force All Possible Answers)
//T.C : O(n*k)
//S.C : O(2^k * k), storing 2^k substrings of length k each
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        //There should be exactly 2^k unique substrings
        unordered_set<string> st;
        
        int n          = s.length();
        int unique_sub = 1<<k; //or, pow(2,k)
            
        for(int i = k; i<=n; i++) {
            string a = s.substr(i-k, k);
            if(!st.count(a)) {
                st.insert(a);
                unique_sub--;
                
                if(unique_sub == 0)
                    return true;
            }
        }
        return false;
    }
};



/******************************************************* JAVA *******************************************************/
//Approach (Brute Force All Possible Answers)
//T.C : O(n*k)
//S.C : O(2^k * k), storing 2^k substrings of length k each
class Solution {
    public boolean hasAllCodes(String s, int k) {
        if(s.length() < k)
            return false;

        int uniqueSub      = 1<<k;
        HashSet<String> st = new HashSet<>();

        for(int i = k; i <= s.length(); i++) {
            String sub = s.substring(i-k, i);

            if(!st.contains(sub)) {
                st.add(sub);
                uniqueSub--;
            }

            if(uniqueSub == 0)
                return true;
        }

        return false;
    }
}
