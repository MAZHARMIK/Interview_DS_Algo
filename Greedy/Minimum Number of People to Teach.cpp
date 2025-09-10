/*         Scroll below to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/minimum-number-of-people-to-teach
*/


/********************************************************************** C++ **********************************************************************/
//Approach (Greedily picking the mostKnown language among the sadUsers (those who cannpt talk to their friends))
//T.C : O(m*n)
//S.C : O(m+n)
class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> sadUsers;

        for(auto &friends : friendships) {
            int u = friends[0] - 1; //convert this to - based indexing
            int v = friends[1] - 1;

            unordered_set<int> langSet(begin(languages[u]), end(languages[u]));
            bool canTalk = false;
            for(int lang : languages[v]) {
                if(langSet.count(lang)) {
                    canTalk = true;
                    break;
                }
            }

            if(!canTalk) {
                sadUsers.insert(u);
                sadUsers.insert(v);
            }
        }

        //Find max known language among sad users
        vector<int> language(n+1, 0);
        int mostKnownLang = 0;

        for(int user : sadUsers) {
            for(int lang : languages[user]) {
                language[lang]++;
                mostKnownLang = max(mostKnownLang, language[lang]);
            }
        }

        return sadUsers.size() - mostKnownLang;
        
    }
};



/********************************************************************** JAVA **********************************************************************/
//Approach (Greedily picking the mostKnown language among the sadUsers (those who cannpt talk to their friends))
//T.C : O(m*n)
//S.C : O(m+n)
class Solution {
    public int minimumTeachings(int n, int[][] languages, int[][] friendships) {
        Set<Integer> sadUsers = new HashSet<>(); // users who can't talk to their friend
        
        // Find sadUsers
        for (int[] friends : friendships) {
            int u = friends[0] - 1;
            int v = friends[1] - 1;
            
            // check if u and v share a common language
            Set<Integer> langSet = new HashSet<>();
            for (int lang : languages[u]) {
                langSet.add(lang);
            }
            
            boolean canTalk = false;
            for (int lang : languages[v]) {
                if (langSet.contains(lang)) {
                    canTalk = true;
                    break;
                }
            }
            
            // if they cannot talk, mark them as sad
            if (!canTalk) {
                sadUsers.add(u);
                sadUsers.add(v);
            }
        }
        
        // Count how many sadUsers already know each language
        int[] languageCount = new int[n + 1];
        int mostKnownLang = 0;
        
        for (int user : sadUsers) {
            for (int lang : languages[user]) {
                languageCount[lang]++;
                mostKnownLang = Math.max(mostKnownLang, languageCount[lang]);
            }
        }
        
        // total sadUsers - mostKnownLang
        return sadUsers.size() - mostKnownLang;
    }
}
