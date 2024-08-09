/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=tI8OO93t2zM
    Company Tags                : Microsoft
    Leetcode Link               : https://leetcode.com/problems/pass-the-pillow/description/
*/


/************************************************************ C++ ************************************************************/
//Approach-1 (Simple Simulation)
//T.C : O(time)
//S.C : O(1)
class Solution {
public:
    int passThePillow(int n, int time) {
        int idx  = 1;
        int dir  = 1;

        while(time > 0) {
            if(idx + dir >=1 && idx + dir <= n) {
                idx += dir;
                time--;
            } else {
                dir *= -1;
            }
        }
        return idx;
    }
};

//Approach-3
//T.C : O(time)
//S.C : O(1)
class Solution {
public:
    int passThePillow(int n, int time) {
        int p=1;
        bool rev = false;
        while(time--){
            if(p == n){
                rev=true;
            }else if(p == 1){
                rev = false;
            }
            if(rev){
                p--;
            }else{
                p++;
            }
        }
        return p;
    }
};


//Approach-2 (Simple Maths)
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    int passThePillow(int n, int time) {
        
        int totalFullRounds = time / (n-1);

        int timeLeft        = time % (n-1);

        if(totalFullRounds % 2 == 0) {
            return timeLeft + 1;
        } else {
            return n - timeLeft;
        }

        return -1;
    }
};


/************************************************************ JAVA ************************************************************/
//Approach-1 (Simple Simulation)
// T.C : O(time)
// S.C : O(1)
class Solution {
    public int passThePillow(int n, int time) {
        int idx = 1;
        int dir = 1;

        while (time > 0) {
            if (idx + dir >= 1 && idx + dir <= n) {
                idx += dir;
                time--;
            } else {
                dir *= -1;
            }
        }
        return idx;
    }
}


//Approach-2 (Simple Maths)
// T.C : O(1)
// S.C : O(1)
class Solution {
    public int passThePillow(int n, int time) {
        int totalFullRounds = time / (n - 1);
        int timeLeft = time % (n - 1);

        if (totalFullRounds % 2 == 0) {
            return timeLeft + 1;
        } else {
            return n - timeLeft;
        }
    }
}
