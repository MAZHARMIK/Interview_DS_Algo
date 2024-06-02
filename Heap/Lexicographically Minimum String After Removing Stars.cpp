/*     Scroll below to see JAVA code also  */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=-0xkQYTP1I0
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
class P {
    public char c;
    public int i;
    public P(char c, int i) {
        this.c = c;
        this.i = i;
    }
}

class Solution {
    public String clearStars(String s) {
        char[] str = s.toCharArray();
        Queue<P> pq = new PriorityQueue<>((a, b) -> {
           if (a.c == b.c) {
               return b.i - a.i;
           }
            return Character.compare(a.c, b.c);
        });
        
        for (int i = 0; i < str.length; i++) {
            char c = str[i];
            if (c != '*') {
                pq.add(new P(c, i));
                continue;
            }
            
            if (!pq.isEmpty()) {
                P p = pq.poll();
                str[p.i] = '*';
            }
        }
        char[] result = new char[str.length]; 
        int index = 0;
        for (char c : str) {
            if (c != '*') {
                result[index++] = c;
            }
        }
        return new String(result, 0, index); 
    }
}
