/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/vowel-spellchecker
*/


/************************************************************ C++ *****************************************************/
//Approach - Using map and set
//T.C : O(N), N = total length of all the input strings and queries
//S.C : O(N)
class Solution {
public:
    unordered_set<string> exactWords;          // stores original words
    unordered_map<string, string> caseMap;     // lowercase : original word
    unordered_map<string, string> vowelMap;    // masked vowels : original word
    
    string toLower(const string& s) {
        string res = s;
        for (char& c : res) {
            c = tolower(c);
        }
        return res;
    }

    string maskVowels(const string& s) {
        string res = s;
        for (char& c : res) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                c = '*';
            }
        }
        return res;
    }

    string checkForMatch(const string& query) {
        // Exact match
        if (exactWords.count(query)) {
            return query;
        }

        // Case error match
        string lowerQuery = toLower(query);
        if (caseMap.count(lowerQuery)) {
            return caseMap[lowerQuery];
        }

        // Vowel error match
        string maskedQuery = maskVowels(lowerQuery);
        if (vowelMap.count(maskedQuery)) {
            return vowelMap[maskedQuery];
        }

        // 4. No match
        return "";
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        exactWords.clear();
        caseMap.clear();
        vowelMap.clear();

        for (string word : wordlist) {
            exactWords.insert(word);

            string lowerWord = toLower(word);
            if (caseMap.find(lowerWord) == caseMap.end()) { //Add only 1st occurrence
                caseMap[lowerWord] = word;
            }

            string maskedWord = maskVowels(lowerWord);
            if (vowelMap.find(maskedWord) == vowelMap.end()) { //Add only 1st occurrence
                vowelMap[maskedWord] = word;
            }
        }

        vector<string> result;
        for (string query : queries) {
            result.push_back(checkForMatch(query));
        }
        return result;
    }
};



/************************************************************ JAVA *****************************************************/
//Approach - Using map and set
//T.C : O(N), N = total length of all the input strings and queries
//S.C : O(N)
class Solution {
    Set<String> exactWords = new HashSet<>();                 // stores original words
    Map<String, String> caseMap = new HashMap<>();            // lowercase : original word
    Map<String, String> vowelMap = new HashMap<>();           // masked vowels : original word

    private String toLower(String s) {
        return s.toLowerCase();
    }

    private String maskVowels(String s) {
        StringBuilder sb = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (isVowel(c)) {
                sb.append('*');
            } else {
                sb.append(c);
            }
        }
        return sb.toString();
    }

    private boolean isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    private String checkForMatch(String query) {
        // 1. Exact match
        if (exactWords.contains(query)) {
            return query;
        }

        // 2. Case-insensitive match
        String lowerQuery = toLower(query);
        if (caseMap.containsKey(lowerQuery)) {
            return caseMap.get(lowerQuery);
        }

        // 3. Vowel-insensitive match
        String maskedQuery = maskVowels(lowerQuery);
        if (vowelMap.containsKey(maskedQuery)) {
            return vowelMap.get(maskedQuery);
        }

        // 4. No match
        return "";
    }

    public String[] spellchecker(String[] wordlist, String[] queries) {
        exactWords.clear();
        caseMap.clear();
        vowelMap.clear();

        // Preprocess wordlist
        for (String word : wordlist) {
            exactWords.add(word);

            String lowerWord = toLower(word);
            caseMap.putIfAbsent(lowerWord, word);  // keep only first occurrence

            String maskedWord = maskVowels(lowerWord);
            vowelMap.putIfAbsent(maskedWord, word); // keep only first occurrence
        }

        String[] result = new String[queries.length];
        for (int i = 0; i < queries.length; i++) {
            result[i] = checkForMatch(queries[i]);
        }
        return result;
    }
}
