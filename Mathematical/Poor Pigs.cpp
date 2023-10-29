/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=YQJLNxveyKg
    Company Tags                : Was asked in Aptitude (Will update the company name soon)
    Leetcode Link               : https://leetcode.com/problems/poor-pigs/
*/


/************************************************ C++ *********************************************************/
//Approach-1
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int T = minutesToTest/minutesToDie + 1;

        int pigs = 0;

        while(pow(T, pigs) < buckets) {
            pigs++;
        }


        return pigs;

        
    }
};

//Approach-2 (Using simple one liner)
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        //(T+1)^pigs = buckets
        //pigs = log(buckets)/log(T+1)

        return ceil(log2(buckets)/log2(minutesToTest/minutesToDie + 1));

        
    }
};


/************************************************ JAVA *********************************************************/
//Approach-1
public class Solution {
    public int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int T = minutesToTest / minutesToDie + 1;
        int pigs = 0;

        while (Math.pow(T, pigs) < buckets) {
            pigs++;
        }

        return pigs;
    }
}


//Approach-2 (Using simple one liner)
public class Solution {
    public int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        // Calculate T
        int T = minutesToTest / minutesToDie + 1;
        
        // Calculate the minimum number of pigs using the formula: pigs = ceil(log2(buckets) / log2(T+1))
        return (int) Math.ceil(Math.log(buckets) / Math.log(2) / Math.log(T + 1));
    }
}
