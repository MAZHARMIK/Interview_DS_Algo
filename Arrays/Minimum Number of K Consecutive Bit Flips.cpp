/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Google
    Leetcode Link               : https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/description
*/

//SUGGESTION - Solve Leetcode-319 (Bulb Switcher) as well. It's kind of a similar problem (not exactly same)


/********************************************************************** C++ **********************************************************************/
//Approach-1 (Using auxiliary array to mark Flipped indices)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();

        int flips = 0;
        vector<bool> isFlipped(n, false);
        int flipCountFromPastForCurri = 0;

        for(int i = 0; i < n; i++) {
            if(i >= k && isFlipped[i-k] == true){
                flipCountFromPastForCurri--;                     
            }
            
            if(flipCountFromPastForCurri % 2 == nums[i]) {
                if(i+k > n){
                    return -1;
                }
                flipCountFromPastForCurri++;
                isFlipped[i] = true;
                flips++;
            }
        }

        return flips;
    }
};



//Approach-2 (Using same input to mark Flipped indices - We will be manipulating the input as well)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();

        int flips = 0;
        
        int index_i_kitna_flip_jhela = 0;

        for(int i = 0; i < n; i++) {

            if(i >= k && nums[i-k] == 2) { //Was it flipped
                index_i_kitna_flip_jhela--;
            }
            
            if(index_i_kitna_flip_jhela % 2 == nums[i]) {
                if(i+k > n){
                    return -1;
                }
                index_i_kitna_flip_jhela++;
                nums[i] = 2; //Marking as flipped
                flips++;
            }
        }

        return flips;
    }
};


//Approach-3 (Using deque to mark Flipped indices)
//T.C : O(n)
//S.C : O(k)
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();

        int flips = 0;
        deque<int> flipQue;
        int index_i_kitna_flip_jhela = 0;

        for(int i = 0; i < n; i++) {
            if(i >= k){
                index_i_kitna_flip_jhela -= flipQue.front();
                flipQue.pop_front();
            }
            
            if(index_i_kitna_flip_jhela % 2 == nums[i]) {
                if(i+k > n){
                    return -1;
                }
                index_i_kitna_flip_jhela++;
                flipQue.push_back(1);
                flips++;
            } else {
                flipQue.push_back(0);
            }
        }

        return flips;
    }
};



/********************************************************************** JAVA **********************************************************************/
//Approach-1 (Using auxiliary array to mark Flipped indices)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public int minKBitFlips(int[] nums, int k) {
        int n = nums.length;

        int flips = 0;
        boolean[] isFlipped = new boolean[n];
        int flipCountFromPastForCurri = 0;

        for (int i = 0; i < n; i++) {
            if (i >= k && isFlipped[i - k]) {
                flipCountFromPastForCurri--;
            }

            if (flipCountFromPastForCurri % 2 == nums[i]) {
                if (i + k > n) {
                    return -1;
                }
                flipCountFromPastForCurri++;
                isFlipped[i] = true;
                flips++;
            }
        }

        return flips;
    }
}


//Approach-2 (Using same input to mark Flipped indices - We will be manipulating the input as well)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int minKBitFlips(int[] nums, int k) {
        int n = nums.length;

        int flips = 0;
        int index_i_kitna_flip_jhela = 0;

        for (int i = 0; i < n; i++) {

            if (i >= k && nums[i - k] == 2) { // Was it flipped
                index_i_kitna_flip_jhela--;
            }

            if (index_i_kitna_flip_jhela % 2 == nums[i]) {
                if (i + k > n) {
                    return -1;
                }
                index_i_kitna_flip_jhela++;
                nums[i] = 2; // Marking as flipped
                flips++;
            }
        }

        return flips;
    }
}


//Approach-3 (Using deque to mark Flipped indices)
//T.C : O(n)
//S.C : O(k)
class Solution {
    public int minKBitFlips(int[] nums, int k) {
        int n = nums.length;

        int flips = 0;
        Deque<Integer> flipQue = new LinkedList<>();
        int index_i_kitna_flip_jhela = 0;

        for (int i = 0; i < n; i++) {
            if (i >= k) {
                index_i_kitna_flip_jhela -= flipQue.pollFirst();
            }

            if (index_i_kitna_flip_jhela % 2 == nums[i]) {
                if (i + k > n) {
                    return -1;
                }
                index_i_kitna_flip_jhela++;
                flipQue.addLast(1);
                flips++;
            } else {
                flipQue.addLast(0);
            }
        }

        return flips;
    }
}
