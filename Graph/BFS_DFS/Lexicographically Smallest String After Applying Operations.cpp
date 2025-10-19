/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=SUkbctHiREI
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations
*/



/****************************************************************** C++ ******************************************************************/
//Approach (Using BFS)
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




/****************************************************************** JAVA ******************************************************************/
//Approach (Using BFS)
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
