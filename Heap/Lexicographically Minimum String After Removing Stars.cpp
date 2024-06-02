/*     Scroll below to see JAVA code also  */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : soon
    Leetcode Link               : https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars/description/
*/


/*************************************************************** C++ ***************************************************************/
//Simple approach using heap
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    typedef pair<char, int> P;

    struct comp{
        bool operator()(P &p1, P& p2){
            if(p1.first == p2.first) {
                return p1.second < p2.second;
            }

            return p1.first > p2.first;
        }
    };

    string clearStars(string s) {
        int n = s.length();

        priority_queue<P, vector<P>, comp> pq;

        for(int i = 0; i < n; i++) { //O(n)
            if(s[i] != '*') {
                pq.push({s[i], i}); //log(n)
            } else {
                int idx = pq.top().second;
                pq.pop();
                s[idx] = '*';
            }
        }

        string result = "";
        for(int i = 0; i < n; i++) {
            if(s[i] != '*') {
                result.push_back(s[i]);
            }
        }

        return result;
    }
};


/*************************************************************** JAVA ***************************************************************/
//Simple approach using heap
//T.C : O(nlogn)
//S.C : O(n)
class Data {
    public char c;
    public int i;
    public Data(char c, int i) {
        this.c = c;
        this.i = i;
    }
}

class Solution {
    public String clearStars(String s) {
        char[] ans = s.toCharArray();
        Queue<Data> queue = new PriorityQueue<>((a, b) -> {
           if (a.c == b.c) {
               return b.i - a.i;
           }
            return Character.compare(a.c, b.c);
        });
        for (int i = 0;i < ans.length;i++) {
            char c = ans[i];
            if (c != '*') {
                queue.add(new Data(c, i));
                continue;
            }
            
            if (!queue.isEmpty()) {
                Data d = queue.poll();
                ans[d.i] = '*';
            }
        }
        StringBuilder sb = new StringBuilder();
        for (char c : ans) {
            if (c != '*') {
                sb.append(c);
            }
        }
        return sb.toString();
    }
}
