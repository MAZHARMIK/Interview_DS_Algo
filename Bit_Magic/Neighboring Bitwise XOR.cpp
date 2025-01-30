/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=T1uAPDDFDmM
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/neighboring-bitwise-xor
*/

/******************************************************** C++ ********************************************************/
//Approach-1 (Simulation, starting with 0 and starting with 1)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();

        //First try with original[0] = 0;
        vector<int> original(n);
        original[0] = 0;
        for(int i = 0; i < n-1; i++) {
            original[i+1] = original[i] ^ derived[i];
        }

        if((original[n-1] ^ original[0]) == derived[n-1]) {
            return true;
        }

        //Now try with original[0] = 1;
        original[0] = 1;
        for(int i = 0; i < n-1; i++) {
            original[i+1] = original[i] ^ derived[i];
        }

        if((original[n-1] ^ original[0]) == derived[n-1]) {
            return true;
        }

        return false;
    }
};


//Approach-2 (Simple observation of XOR property)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int XOR = 0;

        for(int &x : derived) {
            XOR  = (XOR ^ x);
        }

        return XOR == 0;
    }
};


/******************************************************** JAVA ********************************************************/
//Approach-1 (Simulation, starting with 0 and starting with 1)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public boolean doesValidArrayExist(int[] derived) {
        int n = derived.length;

        //Try starting with original[0] = 0;
        int[] original = new int[n];
        original[0] = 0;
        for(int i = 0; i < n-1; i++) {
            original[i+1] = original[i] ^ derived[i];
        }

        if((original[n-1] ^ original[0]) == derived[n-1]) {
            return true;
        }

        //Let's try with original[0] = 1
        original[0] = 1;
        for(int i = 0; i < n-1; i++) {
            original[i+1] = original[i] ^ derived[i];
        }

        if((original[n-1] ^ original[0]) == derived[n-1]) {
            return true;
        }

        return false;
    }
}


//Approach-2 (Simple observation of XOR property)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public boolean doesValidArrayExist(int[] derived) {
        int XOR = 0;

        for(int x : derived) {
            XOR = (XOR ^ x);
        }

        return XOR == 0;
    }
}
