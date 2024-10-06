/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=J9KwcuukMZE
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/sentence-similarity-iii
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 (simple using pointers)
//T.C : O(m+n)
//S.C : O(m+n)
class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        if(s1.length() < s2.length()) {
            swap(s1, s2);
        }

        vector<string> vec1, vec2;
        stringstream ss1(s1);
        string token;
        while(ss1 >> token) {
            vec1.push_back(token);
        }

        stringstream ss2(s2);
        while(ss2 >> token) {
            vec2.push_back(token);
        }

        int i = 0, j = vec1.size()-1; //s1 (vec1)
        int k = 0, l = vec2.size()-1; //s2 (vec2)

        while(k < vec2.size() && i < vec1.size() && vec2[k] == vec1[i]) {
            k++;
            i++;
        }

        while(l >= k && vec2[l] == vec1[j]) {
            j--;
            l--;
        }
        
        return l < k;

    }
};



//Approach-2 (simple deque)
//T.C : O(m+n)
//S.C : O(m+n)
class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        if(s1.length() < s2.length()) {
            swap(s1, s2);
        }

        deque<string> deq1, deq2;
        stringstream ss1(s1);
        string token;
        while(ss1 >> token) {
            deq1.push_back(token);
        }

        stringstream ss2(s2);
        while(ss2 >> token) {
            deq2.push_back(token);
        }

        while(!deq1.empty() && !deq2.empty() && deq1.front() == deq2.front()) {
            deq1.pop_front();
            deq2.pop_front();
        }

        while(!deq1.empty() && !deq2.empty() && deq1.back() == deq2.back()) {
            deq1.pop_back();
            deq2.pop_back();
        }
        
        return deq2.empty();

    }
};


/**************************************************************** JAVA ****************************************************************/
//Approach-1 (simple using pointers)
//T.C : O(m+n)
//S.C : O(m+n)
class Solution {
    public boolean areSentencesSimilar(String s1, String s2) {
        if (s1.length() < s2.length()) {
            String temp = s1;
            s1 = s2;
            s2 = temp;
        }

        List<String> vec1 = new ArrayList<>();
        List<String> vec2 = new ArrayList<>();

        // Splitting strings by spaces
        vec1 = Arrays.asList(s1.split(" "));
        vec2 = Arrays.asList(s2.split(" "));

        int i = 0, j = vec1.size() - 1; // s1 (vec1)
        int k = 0, l = vec2.size() - 1; // s2 (vec2)

        // Check for matching prefix
        while (k < vec2.size() && i < vec1.size() && vec2.get(k).equals(vec1.get(i))) {
            k++;
            i++;
        }

        // Check for matching suffix
        while (l >= k && vec2.get(l).equals(vec1.get(j))) {
            j--;
            l--;
        }

        return l < k;
    }
}



//Approach-2 (simple deque)
//T.C : O(m+n)
//S.C : O(m+n)
import java.util.*;

class Solution {
    public boolean areSentencesSimilar(String s1, String s2) {
        // Ensure s1 is the longer string
        if (s1.length() < s2.length()) {
            String temp = s1;
            s1 = s2;
            s2 = temp;
        }

        // Split the strings into Deques
        Deque<String> deq1 = new LinkedList<>(Arrays.asList(s1.split(" ")));
        Deque<String> deq2 = new LinkedList<>(Arrays.asList(s2.split(" ")));

        // Remove matching words from the front
        while (!deq1.isEmpty() && !deq2.isEmpty() && deq1.peekFirst().equals(deq2.peekFirst())) {
            deq1.pollFirst();
            deq2.pollFirst();
        }

        // Remove matching words from the back
        while (!deq1.isEmpty() && !deq2.isEmpty() && deq1.peekLast().equals(deq2.peekLast())) {
            deq1.pollLast();
            deq2.pollLast();
        }

        // If deq2 is empty, then s2 is a sub-sequence of s1
        return deq2.isEmpty();
    }
}
