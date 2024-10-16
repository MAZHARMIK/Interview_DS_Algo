/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=tGzgghQEDdA
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/longest-happy-string
*/

/************************************************************ C++ ************************************************************/
//Approach (simple thought process - heap)
//T.C : O(a+b+c)
//S.C : O(1)
class Solution {
public:
    typedef pair<int, char> P;
    string longestDiverseString(int a, int b, int c) {
        priority_queue<P, vector<P>> pq; //max-heap

        if(a > 0) {
            pq.push({a, 'a'});
        }
        if(b > 0) {
            pq.push({b, 'b'});
        }
        if(c > 0) {
            pq.push({c, 'c'});
        }

        string result = "";

        while(!pq.empty()) {
            int currCount = pq.top().first;
            int currChar = pq.top().second;
            pq.pop();

            if(result.length() >= 2 && result[result.length()-1] == currChar && result[result.length()-2] == currChar) {
                //we can't use currChar. Check for next largest freqency char
                if(pq.empty()) {
                    break;
                }

                int nextCount = pq.top().first;
                int nextChar = pq.top().second;
                pq.pop();

                result.push_back(nextChar);
                nextCount--;
                if(nextCount > 0) {
                    pq.push({nextCount, nextChar});
                }
            } else {
                currCount--;
                result.push_back(currChar);
            }

            if(currCount > 0) {
                pq.push({currCount, currChar});
            }
        }

        return result;
    }
};


/************************************************************ JAVA ************************************************************/
//Approach (simple thought process - heap)
//T.C : O(a+b+c)
//S.C : O(1)
class Solution {
    public String longestDiverseString(int a, int b, int c) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((x, y) -> y[0] - x[0]); // max-heap

        if (a > 0) {
            pq.offer(new int[]{a, 'a'});
        }
        if (b > 0) {
            pq.offer(new int[]{b, 'b'});
        }
        if (c > 0) {
            pq.offer(new int[]{c, 'c'});
        }

        StringBuilder result = new StringBuilder();

        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int currCount = curr[0];
            char currChar = (char) curr[1];

            // Check if the last two characters are the same as the current character
            if (result.length() >= 2 && result.charAt(result.length() - 1) == currChar 
                    && result.charAt(result.length() - 2) == currChar) {
                
                if (pq.isEmpty()) {
                    break; // No valid character to use
                }

                // Use the next most frequent character
                int[] next = pq.poll();
                int nextCount = next[0];
                char nextChar = (char) next[1];
                result.append(nextChar);
                nextCount--;
                
                if (nextCount > 0) {
                    pq.offer(new int[]{nextCount, nextChar});
                }
                
                // Push the current character back into the queue
                pq.offer(curr);
            } else {
                // Use the current character
                result.append(currChar);
                currCount--;

                if (currCount > 0) {
                    pq.offer(new int[]{currCount, currChar});
                }
            }
        }

        return result.toString();
    }
}
