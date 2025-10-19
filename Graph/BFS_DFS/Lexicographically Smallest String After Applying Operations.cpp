/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=SUkbctHiREI
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations
*/



/****************************************************************** C++ ******************************************************************/
//Approach-1 (Using BFS)
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
public:
    void rotate(string &s, int b) {
        reverse(begin(s), end(s));
        reverse(begin(s), begin(s) + b);
        reverse(begin(s) + b, end(s));
    }

    string findLexSmallestString(string s, int a, int b) {
        string smallestString = s;

        unordered_set<string> visited;
        queue<string> que;
        que.push(s);
        visited.insert(s);

        while(!que.empty()) {
            string curr = que.front();
            que.pop();

            if(curr < smallestString) {
                smallestString = curr;
            }

            //Add a to the digits
            string temp = curr;
            for(int i = 1; i < temp.length(); i+=2) {
                temp[i] = ((temp[i] - '0' + a) % 10) + '0';
            }

            if(!visited.count(temp)) {
                visited.insert(temp);
                que.push(temp);
            }

            //Rotate right by b
            rotate(curr, b);
            if(!visited.count(curr)) {
                visited.insert(curr);
                que.push(curr);
            }
        }

        return smallestString;

    }
};



//Approach-2 (Using DFS)
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
public:
    void rotate(string &s, int b) {
        reverse(begin(s), end(s));
        reverse(begin(s), begin(s) + b);
        reverse(begin(s) + b, end(s));
    }

    void dfs(string curr, int a, int b, unordered_set<string> &visited, string &smallestString) {
        if (visited.count(curr)) return;
        visited.insert(curr);
        if (curr < smallestString) smallestString = curr;

        string added = curr;
        for (int i = 1; i < added.size(); i += 2)
            added[i] = ((added[i] - '0' + a) % 10) + '0';
        dfs(added, a, b, visited, smallestString);

        rotate(curr, b);
        dfs(curr, a, b, visited, smallestString);
    }

    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> visited;
        string smallestString = s;
        dfs(s, a, b, visited, smallestString);
        return smallestString;
    }
};


/****************************************************************** JAVA ******************************************************************/
//Approach-1 (Using BFS)
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
    private String rotate(String s, int b) {
        StringBuilder sb = new StringBuilder(s);
        sb.reverse();
        reverseRange(sb, 0, b - 1);
        reverseRange(sb, b, sb.length() - 1);
        return sb.toString();
    }

    private void reverseRange(StringBuilder sb, int left, int right) {
        while (left < right) {
            char temp = sb.charAt(left);
            sb.setCharAt(left, sb.charAt(right));
            sb.setCharAt(right, temp);
            left++;
            right--;
        }
    }

    public String findLexSmallestString(String s, int a, int b) {
        Set<String> visited = new HashSet<>();
        Queue<String> que = new LinkedList<>();
        String smallestString = s;

        que.add(s);
        visited.add(s);

        while (!que.isEmpty()) {
            String curr = que.poll();
            if (curr.compareTo(smallestString) < 0)
                smallestString = curr;

            //Add 'a' to digits at odd indices
            char[] added = curr.toCharArray();
            for (int i = 1; i < added.length; i += 2) {
                int newDigit = ((added[i] - '0') + a) % 10;
                added[i] = (char) ('0' + newDigit);
            }
            String addedStr = new String(added);
            if (visited.add(addedStr)) {
                que.add(addedStr);
            }

            //Rotate right by b using helper
            String rotated = rotate(curr, b);
            if (visited.add(rotated)) {
                que.add(rotated);
            }
        }

        return smallestString;
    }
}



//Approach-2 (Using DFS)
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
    void rotate(StringBuilder s, int b) {
        int n = s.length();
        b %= n;
        reverse(s, 0, n - 1);
        reverse(s, 0, b - 1);
        reverse(s, b, n - 1);
    }

    void reverse(StringBuilder s, int l, int r) {
        while (l < r) {
            char temp = s.charAt(l);
            s.setCharAt(l, s.charAt(r));
            s.setCharAt(r, temp);
            l++;
            r--;
        }
    }

    void dfs(StringBuilder curr, int a, int b, Set<String> visited, StringBuilder smallest) {
        String str = curr.toString();
        if (visited.contains(str)) return;
        visited.add(str);
        if (str.compareTo(smallest.toString()) < 0)
            smallest.replace(0, smallest.length(), str);

        StringBuilder added = new StringBuilder(str);
        for (int i = 1; i < added.length(); i += 2) {
            int newDigit = (added.charAt(i) - '0' + a) % 10;
            added.setCharAt(i, (char) (newDigit + '0'));
        }
        dfs(added, a, b, visited, smallest);

        StringBuilder rotated = new StringBuilder(str);
        rotate(rotated, b);
        dfs(rotated, a, b, visited, smallest);
    }

    public String findLexSmallestString(String s, int a, int b) {
        Set<String> visited = new HashSet<>();
        StringBuilder smallest = new StringBuilder(s);
        dfs(new StringBuilder(s), a, b, visited, smallest);
        return smallest.toString();
    }
}
