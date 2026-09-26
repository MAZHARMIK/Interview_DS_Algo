/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=nZvRDBEH8OQ
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string
*/


/*************************************************************** C++ ***************************************************************/
//Approach-1
//T.C : O(n+m) //TRaversing all characters in s and knowledge
//S.C : O(n+m)
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.length();
        unordered_map<string, string> mp;


        for(auto &vec : knowledge) {
            mp[vec[0]] = vec[1];
        }

        string result = "";
        int i = 0;
        while(i < n) {
            if(isalpha(s[i])) {
                result.push_back(s[i]);
            } else { //(
                i++;
                string temp = "";
                while(i < n && s[i] != ')') {
                    temp.push_back(s[i]);
                    i++;
                }
                result += mp.count(temp) ? mp[temp] : "?";
            }
            i++;
        }

        return result;
    }
};



//Approach-2
//T.C : O(n+m) //TRaversing all characters in s and knowledge
//S.C : O(n+m)
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.length();
        unordered_map<string, string> mp;


        for(auto &vec : knowledge) {
            mp[vec[0]] = vec[1];
        }

        string result = "";
        string temp = "";
        bool bracketOpened = false;
        int i = 0;
        
        while(i < n) {
            if(s[i] == '(') {
                bracketOpened = true;
            } else if(s[i] == ')') {
                result += mp.count(temp) ? mp[temp] : "?";
                bracketOpened = false;
                temp = "";
            } else if(bracketOpened) {
                temp.push_back(s[i]);
            } else {
                result.push_back(s[i]);
            }

            i++;
        }

        return result;
    }
};





//Approach-3
//T.C : O(n+m) //TRaversing all characters in s and knowledge
//S.C : O(n+m)
class Solution {
public:
    //Code 3
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.length();

        unordered_map<string, string> mp;

        for(auto &vec : knowledge) {
            //vec[0], vec[1]
            mp[vec[0]] = vec[1];
        }

        string result = "";
        int i = 0;

        while(i < n) {
            if(s[i] == '(') {
                int j = s.find(")", i+1);
                string temp = s.substr(i+1, j-i-1);
                result += mp.count(temp) ? mp[temp] : "?";
                i = j;
            } else {
                result.push_back(s[i]);
            }

            i++;
        }
        return result;
    }
};




/*************************************************************** JAVA ***************************************************************/
//Approach-1
//T.C : O(n+m) //Traversing all characters in s and knowledge
//S.C : O(n+m)
class Solution {
    public String evaluate(String s, List<List<String>> knowledge) {
        int n = s.length();
        Map<String, String> mp = new HashMap<>();

        for (List<String> vec : knowledge) {
            mp.put(vec.get(0), vec.get(1));
        }

        StringBuilder result = new StringBuilder();
        int i = 0;
        while (i < n) {
            if (Character.isAlphabetic(s.charAt(i))) {
                result.append(s.charAt(i));
            } else { //(
                i++;
                StringBuilder temp = new StringBuilder();
                while (i < n && s.charAt(i) != ')') {
                    temp.append(s.charAt(i));
                    i++;
                }
                result.append(mp.getOrDefault(temp.toString(), "?"));
            }
            i++;
        }

        return result.toString();
    }
}


//Approach-2
//T.C : O(n+m) //Traversing all characters in s and knowledge
//S.C : O(n+m)
class Solution {
    public String evaluate(String s, List<List<String>> knowledge) {
        int n = s.length();
        Map<String, String> mp = new HashMap<>();

        for (List<String> vec : knowledge) {
            mp.put(vec.get(0), vec.get(1));
        }

        StringBuilder result = new StringBuilder();
        StringBuilder temp = new StringBuilder();
        boolean bracketOpened = false;
        int i = 0;

        while (i < n) {
            char c = s.charAt(i);
            if (c == '(') {
                bracketOpened = true;
            } else if (c == ')') {
                result.append(mp.getOrDefault(temp.toString(), "?"));
                bracketOpened = false;
                temp = new StringBuilder();
            } else if (bracketOpened) {
                temp.append(c);
            } else {
                result.append(c);
            }

            i++;
        }

        return result.toString();
    }
}


//Approach-3
//T.C : O(n+m) //Traversing all characters in s and knowledge
//S.C : O(n+m)
class Solution {
    public String evaluate(String s, List<List<String>> knowledge) {
        int n = s.length();
        Map<String, String> mp = new HashMap<>();

        for (List<String> vec : knowledge) {
            mp.put(vec.get(0), vec.get(1));
        }

        StringBuilder result = new StringBuilder();
        int i = 0;

        while (i < n) {
            if (s.charAt(i) == '(') {
                int j = s.indexOf(")", i + 1);
                String temp = s.substring(i + 1, j);
                result.append(mp.getOrDefault(temp, "?"));
                i = j;
            } else {
                result.append(s.charAt(i));
            }

            i++;
        }
        return result.toString();
    }
}
