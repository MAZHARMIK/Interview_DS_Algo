/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=8jlP3D1Dnj4
    Company Tags                : Google
    Leetcode Link               : https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/

*/

/**************************************** C++ ****************************************/
class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.length();
        int alice = 0;
        int bob   = 0;
        
        for(int i = 1; i<n; i++) {
            
            if(colors[i-1] == colors[i] && colors[i] == colors[i+1]) {
                if(colors[i] == 'A')
                    alice++;
                else
                    bob++;
            }
        }
        
        return alice > bob;
    }
};


/**************************************** JAVA ****************************************/
public class Solution {
    public boolean winnerOfGame(String colors) {
        int n = colors.length();
        int alice = 0;
        int bob = 0;

        for (int i = 1; i < n - 1; i++) {
            if (colors.charAt(i - 1) == colors.charAt(i) && colors.charAt(i) == colors.charAt(i + 1)) {
                if (colors.charAt(i) == 'A') {
                    alice++;
                } else {
                    bob++;
                }
            }
        }

        return alice > bob;
    }
}
