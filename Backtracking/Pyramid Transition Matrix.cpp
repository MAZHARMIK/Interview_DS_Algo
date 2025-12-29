/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Airbnb, Google, Uber, Snapchat
    Leetcode Link               : https://leetcode.com/problems/pyramid-transition-matrix
*/


/************************************************************ C++ ************************************************/
//Approach (Khandani Backtracking template -> all possible options)
//T.C : ~(L^n) , L = maximum count of top characters available for each pairs in allowed, n = bottom.length()
//S.C : O(n^2) recursion stack can go at most n levels deep, and at each level you keep a partially built row of length ≤ n, so the total stack memory is O(n × n) = O(n²).
class Solution {
public:
    unordered_map<string, bool> t;

    bool solve(string curr, unordered_map<string, vector<char>>& mp, int idx, string above) {
        if(curr.length() == 1) { //pyramid is formed and we are at the top
            return true;
        }

        string key = curr + "_" + to_string(idx) + "_" + above;

        if(t.count(key))
            return t[key];

        if(idx == curr.length()-1) { //time to move to next row i.e. abocve row
            return t[key] =  solve(above, mp, 0, "");
        }

        string pair = curr.substr(idx, 2);
        if(mp.find(pair) == mp.end()) {
            return t[key] = false;
        }

        for(char &ch : mp[pair]) {
            above.push_back(ch); //DO

            if(solve(curr, mp, idx+1, above) == true) //EXPLORE
                return t[key] = true;
            
            above.pop_back(); //UNDO
        }

        return t[key] = false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> mp;

        for(auto& pattern : allowed) {
            mp[pattern.substr(0, 2)].push_back(pattern[2]); //"ABC"
        }

        return solve(bottom, mp, 0, "");
    }
};




/************************************************************ JAVA ************************************************/
//Approach (Khandani Backtracking template -> all possible options)
//T.C : ~(L^n) , L = maximum count of top characters available for each pairs in allowed, n = bottom.length()
//S.C : O(n^2) recursion stack can go at most n levels deep, and at each level you keep a partially built row of length ≤ n, so the total stack memory is O(n × n) = O(n²).
class Solution {
    private Map<String, Boolean> t = new HashMap<>();

    public boolean pyramidTransition(String bottom, List<String> allowed) {
        // Build mapping from pair -> list of possible top blocks
        Map<String, List<Character>> mp = new HashMap<>();
        for (String pattern : allowed) {
            String pair = pattern.substring(0, 2);
            char top = pattern.charAt(2);
            mp.computeIfAbsent(pair, k -> new ArrayList<>()).add(top);
        }

        return solve(bottom, mp, 0, new StringBuilder());
    }

    private boolean solve(String curr, Map<String, List<Character>> mp, int idx, StringBuilder above) {
        if (curr.length() == 1) {
            // Pyramid is complete
            return true;
        }

        String key = curr + "_" + idx + "_" + above.toString();
        if (t.containsKey(key)) {
            return t.get(key);
        }

        if (idx == curr.length() - 1) {
            // Finished building current above row; move up
            boolean result = solve(above.toString(), mp, 0, new StringBuilder());
            t.put(key, result);
            return result;
        }

        String pair = curr.substring(idx, idx + 2);
        if (!mp.containsKey(pair)) {
            t.put(key, false);
            return false;
        }

        for (char ch : mp.get(pair)) {
            above.append(ch); // DO
            if (solve(curr, mp, idx + 1, above)) { // EXPLORE
                t.put(key, true);
                return true;
            }
            above.deleteCharAt(above.length() - 1); // UNDO
        }

        t.put(key, false);
        return false;
    }
}
