/*            SCROLL BELOW TO SEE JAVA CODE AS WELL            */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=cfXAsmrAJXg
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/
*/



/**************************************************************** C++ ********************************************************************/
//Method-1 (This method explains why Method-2 trick worked)
//T.C : O(n*D), where D is the max digit which can be <= 9 ~= O(n)
//S.C : O(1)
class Solution {
public:
    int minPartitions(string n) {
        int count = 0;

        while (true) {
            bool changed = false;

            for (char &ch : n) {
                if (ch != '0') {
                    ch--;          // subtract 1
                    changed = true;
                }
            }

            if (!changed)
                break;

            count++;
        }

        return count;
    }
};


//Method-2 (The largest character will take time to reach 0)
//T.C : o(length)
//S.C : O(1)
class Solution {
public:
    int minPartitions(string n) {
        return *max_element(begin(n), end(n))-'0';
    }
};




/**************************************************************** JAVA ********************************************************************/
//Method-1 (This method explains why Method-2 trick worked)
//T.C : O(n*D), where D is the max digit which can be <= 9 ~= O(n)
//S.C : O(1)
class Solution {
    public int minPartitions(String n) {

        char[] arr = n.toCharArray();
        int count = 0;

        while (true) {
            boolean changed = false;

            for (int i = 0; i < arr.length; i++) {
                if (arr[i] != '0') {
                    arr[i]--;      // subtract 1
                    changed = true;
                }
            }

            if (!changed)
                break;

            count++;
        }

        return count;
    }
}


//Method-2 (The largest character will take time to reach 0)
//T.C : o(length)
//S.C : O(1)
class Solution {
    public int minPartitions(String n) {

        char maxCh = '0';

        for (char ch : n.toCharArray()) {
            maxCh = (char)Math.max(maxCh, ch);
        }

        return maxCh - '0';
    }
}
