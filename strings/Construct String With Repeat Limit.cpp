/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Jghze8B3E7M
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/construct-string-with-repeat-limit
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 (Using pointers and frequency table)
//T.C : O(n)
//S.C : O(26)
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> count(26, 0); //S.C : O(26)
        for(char &ch : s) { //T.C : O(n)
            count[ch-'a']++;
        }

        string result;

        int i = 25; //start form last letter so that we can find the largest character first
        while(i >= 0) { //O(26)
            if(count[i] == 0) {
                i--;
                continue;
            }

            char ch  = 'a' + i; //you will get the character
            int freq = min(count[i], repeatLimit);

            result.append(freq, ch);
            count[i] -= freq;

            if(count[i] > 0) {
                //find next largest character
                int j = i-1;
                while(j >= 0 && count[j] == 0) { //O(26)
                    j--;
                }

                if(j < 0) {
                    break;
                }

                result.push_back('a' + j);
                count[j]--;
            }
        }

        return result;
    }
};


//Approach-2 (Using max-heap + frequency table)
//T.C : O(n)
//S.C : O(26)
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> count(26, 0);
        for(char &ch : s) {
            count[ch-'a']++;
        }

        priority_queue<char> pq;
        for(int i = 0; i < 26; i++) {
            if(count[i] > 0) {
                char ch = 'a' + i;
                pq.push(ch);
            }
        }

        string result;
        while(!pq.empty()) {
            char ch = pq.top();
            pq.pop();

            int freq = min(count[ch-'a'], repeatLimit);
            result.append(freq, ch);

            count[ch-'a'] -= freq;

            if(count[ch-'a'] > 0 && !pq.empty()) {
                char nextChar = pq.top();
                pq.pop();

                result.push_back(nextChar);
                count[nextChar-'a']--;

                if(count[nextChar-'a'] > 0) {
                    pq.push(nextChar);
                }

                pq.push(ch);

            }
        }

        return result;
    }
};



/**************************************************************** JAVA ****************************************************************/
//Approach-1 (Using pointers and frequency table)
//T.C : O(n)
//S.C : O(26)
class Solution {
    public String repeatLimitedString(String s, int repeatLimit) {
        int[] count = new int[26]; // Frequency array to store character counts
        
        // Count the frequency of each character
        for (char ch : s.toCharArray()) { // T.C: O(n)
            count[ch - 'a']++;
        }

        StringBuilder result = new StringBuilder();
        int i = 25; // Start from the largest character (z)

        while (i >= 0) { // T.C: O(26)
            if (count[i] == 0) {
                i--;
                continue;
            }

            char ch = (char) ('a' + i); // Convert index to character
            int freq = Math.min(count[i], repeatLimit); // Append up to 'repeatLimit' times
            
            for (int k = 0; k < freq; k++) {
                result.append(ch);
            }
            count[i] -= freq;

            if (count[i] > 0) {
                // Find the next largest character
                int j = i - 1;
                while (j >= 0 && count[j] == 0) { // O(26)
                    j--;
                }

                if (j < 0) {
                    break; // No more characters left to append
                }

                result.append((char) ('a' + j)); // Append the next largest character once
                count[j]--;
            }
        }

        return result.toString();
    }
}


//Approach-2 (Using max-heap + frequency table)
//T.C : O(n)
//S.C : O(26)
import java.util.PriorityQueue;

class Solution {
    public String repeatLimitedString(String s, int repeatLimit) {
        int[] count = new int[26]; // Frequency array to store character counts
        
        // Count the frequency of each character
        for (char ch : s.toCharArray()) { // T.C: O(n)
            count[ch - 'a']++;
        }

        // Max heap (priority queue) to store characters in descending order
        PriorityQueue<Character> pq = new PriorityQueue<>((a, b) -> b - a);
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                pq.offer((char) ('a' + i));
            }
        }

        StringBuilder result = new StringBuilder();

        while (!pq.isEmpty()) {
            char ch = pq.poll(); // Get the largest character
            int freq = Math.min(count[ch - 'a'], repeatLimit); // Append up to 'repeatLimit' times
            
            for (int i = 0; i < freq; i++) {
                result.append(ch);
            }
            count[ch - 'a'] -= freq;

            // If the current character still has remaining occurrences
            if (count[ch - 'a'] > 0 && !pq.isEmpty()) {
                char nextChar = pq.poll(); // Get the next largest character
                result.append(nextChar);
                count[nextChar - 'a']--;

                // Reinsert characters into the priority queue if they still have remaining occurrences
                if (count[nextChar - 'a'] > 0) {
                    pq.offer(nextChar);
                }
                pq.offer(ch);
            }
        }

        return result.toString();
    }
}
