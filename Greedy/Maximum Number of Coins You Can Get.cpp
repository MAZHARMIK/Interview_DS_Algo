/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=H762GDF08mg
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/maximum-number-of-coins-you-can-get/
*/

/****************************************************************** C++ *****************************************************************************/
//Approach-1 (Using Greedy + 3 pointers)
//T.C : O(nlogn) - Sorting
//S.C : O(1)
//NOTE - You could also use q deque to push and pop from either side
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        
        sort(begin(piles), end(piles));
        
        int result = 0;
        
        int Bob = 0, Me = n-2, Alice = n-1;
        
        while(Me > Bob) {
            
            result += piles[Me];
        
            Me    -= 2;    
            Bob   += 1;
            Alice -= 2; //(You can remove this becasue it's required. I Used it for the sake of completeness)
        }
        
        return result;
    }
};


//Approach-2 (Using Greedy without 3 pointers)
//T.C : O(nlogn) - Sorting
//S.C : O(1)
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        
        sort(begin(piles), end(piles));
        
        int result = 0;

        
        for(int i = n/3; i <n; i+=2) {
            result += piles[i];
        }
        
        return result;
    }
};


/****************************************************************** JAVA *****************************************************************************/
//Approach-1 (Using Greedy + 3 pointers)
//T.C : O(nlogn) - Sorting
//S.C : O(1)
//NOTE - You could also use q deque to push and pop from either side
public class Solution {
    public int maxCoins(int[] piles) {
        int n = piles.length;

        Arrays.sort(piles);

        int result = 0;

        int Bob = 0, Me = n - 2, Alice = n - 1;

        while (Me > Bob) {
            result += piles[Me];

            Me -= 2;
            Bob += 1;
            Alice -= 2; // (You can remove this because it's required. I Used it for the sake of completeness)
        }

        return result;
    }
}

//Approach-2 (Using Greedy without 3 pointers)
//T.C : O(nlogn) - Sorting
//S.C : O(1)
public class Solution {
    public int maxCoins(int[] piles) {
        int n = piles.length;

        Arrays.sort(piles);

        int result = 0;

        for (int i = n / 3; i < n; i += 2) {
            result += piles[i];
        }

        return result;
    }
}
