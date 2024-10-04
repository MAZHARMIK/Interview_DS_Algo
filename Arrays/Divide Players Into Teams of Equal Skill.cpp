/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=DtXt4DTrvOw
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/divide-players-into-teams-of-equal-skill
*/


/************************************************************ C++ ************************************************/
//Approach-1 (Using frequency of skills similar to counting sort)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();

        sort(begin(skill), end(skill));

        int i = 0;
        int j = n-1;
        int s = skill[i] + skill[j];

        long long chem = 0;

        while(i < j) {
            int currSkill = skill[i] + skill[j];

            if(currSkill != s) {
                return -1;
            }

            chem += (long long)(skill[i]) * (long long)(skill[j]);
            i++;
            j--;
        }
        

        return chem;

    }
};



//Approach-2 (Using frequency of skills similar to counting sort)
//T.C : O(n)
//S.C : O(1000) ~= O(1)
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();

        vector<int> vec(1001, 0);
        int SUM = 0;
        for(int &s : skill) {
            SUM += s;
            vec[s]++; //freq updated
        }

        int teams = n/2;

        if(SUM % teams != 0) {
            return -1;
        }

        int target = SUM / teams;
        long long chem = 0;

        for(int i = 0; i < n; i++) {
            int currSkill   = skill[i];
            int remainSkill = target - currSkill;

            if(vec[remainSkill] <= 0) {
                return -1;
            }

            chem += (long long)currSkill * (long long)(remainSkill);
            vec[remainSkill] -= 1;
        }

        return chem/2;

    }
};





/************************************************************ JAVA ************************************************/
//Approach-1 (Using frequency of skills similar to counting sort)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
    public long dividePlayers(int[] skill) {
        int n = skill.length;
        
        // Sort the skill array
        Arrays.sort(skill);
        
        int i = 0;
        int j = n - 1;
        int s = skill[i] + skill[j];
        
        long chem = 0;
        
        // Check each pair from both ends of the sorted array
        while (i < j) {
            int currSkill = skill[i] + skill[j];
            
            // If current pair sum is not equal to expected sum, return -1
            if (currSkill != s) {
                return -1;
            }
            
            // Calculate the chemistry and move to the next pair
            chem += (long) skill[i] * (long) skill[j];
            i++;
            j--;
        }
        
        return chem;
    }
}



//Approach-2 (Using frequency of skills similar to counting sort)
//T.C : O(n)
//S.C : O(1000) ~= O(1)
class Solution {
    public long dividePlayers(int[] skill) {
        int n = skill.length;

        // Frequency array to count occurrences of each skill value
        int[] freq = new int[1001];
        int totalSum = 0;

        for (int s : skill) {
            totalSum += s;
            freq[s]++; // Update frequency
        }

        int teams = n / 2;

        // Check if total sum is divisible by the number of teams
        if (totalSum % teams != 0) {
            return -1;
        }

        int targetSum = totalSum / teams;
        long chemistry = 0;

        for (int currSkill : skill) {
            int remainingSkill = targetSum - currSkill;

            // If the complementary skill is not available, return -1
            if (freq[remainingSkill] <= 0) {
                return -1;
            }

            chemistry += (long) currSkill * (long) remainingSkill;
            freq[remainingSkill]--; // Reduce the frequency of used skill
        }

        return chemistry / 2;
    }
}
