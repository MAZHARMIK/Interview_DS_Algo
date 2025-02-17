/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/letter-tile-possibilities
*/


/************************************************************ C++ ************************************************/
//Approach-1 (Using simple backtracking Khandani Template)
//T.C : O(n!)
//S.C : O(n * n!), total possible sequences = n! and each having n length
class Solution {
public:
    int n;

    void solve(string& tiles, vector<bool>& used, unordered_set<string>& result, string &curr) {
        result.insert(curr);

        for(int i = 0; i < n; i++) {
            if(used[i])
                continue;

            curr.push_back(tiles[i]);
            used[i] = true;

            solve(tiles, used, result, curr);

            used[i] = false;
            curr.pop_back();
        }
    }

    int numTilePossibilities(string tiles) {
        n = tiles.length();
        vector<bool> used(n, false);
        unordered_set<string> result;
        string curr = "";

        solve(tiles, used, result, curr);

        return result.size()-1;
    }
};


//Approach-2 (Using count of characters + backtracking)
//T.C : O(n!)
//S.C : O(n), total possible sequences = n! and each having n length
class Solution {
public:
    int total;
    void findSequences(vector<int>& count) {
        total++;

        for (int pos = 0; pos < 26; pos++) {
            if (count[pos] == 0) {
                continue;
            }

            count[pos]--;
            findSequences(count);
            count[pos]++;
        }
    }

    int numTilePossibilities(std::string tiles) {
        total = 0;

        vector<int> count(26, 0);
        for (char c : tiles) {
            count[c - 'A']++;
        }

        findSequences(count);
        return total-1;
    }
};


/************************************************************ JAVA ************************************************/
// Approach-1 (Using simple backtracking Khandani Template)
// T.C : O(n!)
// S.C : O(n * n!), total possible sequences = n! and each having n length
class Solution {
    int n;

    public int numTilePossibilities(String tiles) {
        n = tiles.length();
        boolean[] used = new boolean[n];
        Set<String> result = new HashSet<>();
        StringBuilder curr = new StringBuilder();

        solve(tiles, used, result, curr);
        return result.size() - 1; // Subtract 1 to exclude the empty sequence
    }

    private void solve(String tiles, boolean[] used, Set<String> result, StringBuilder curr) {
        result.add(curr.toString());

        for (int i = 0; i < n; i++) {
            if (used[i])
                continue;

            // Choose the tile at index i
            curr.append(tiles.charAt(i));
            used[i] = true;

            // Explore further with this choice
            solve(tiles, used, result, curr);

            // Backtrack: remove the tile and mark it unused
            used[i] = false;
            curr.deleteCharAt(curr.length() - 1);
        }
    }
}


// Approach-2 (Using count of characters + backtracking)
// T.C : O(n!)
// S.C : O(n), total possible sequences = n! and each having n length
class Solution {
    private int total;

    private void findSequences(int[] count) {
        total++;

        for (int pos = 0; pos < 26; pos++) {
            if (count[pos] == 0) {
                continue;
            }

            count[pos]--;
            findSequences(count);
            count[pos]++;
        }
    }

    public int numTilePossibilities(String tiles) {
        total = 0;

        int[] count = new int[26];
        for (char c : tiles.toCharArray()) {
            count[c - 'A']++;
        }

        findSequences(count);
        return total - 1;
    }
}
