/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/maximize-active-section-with-trade-i
*/


/**************************************************************** C++ ****************************************************************/
//Approach (target 1s and find max pair sum of zero blocks)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();

        //existing count of 1s
        int activeCount = count(begin(s), end(s), '1');

        vector<int> inactiveBlocks;
        int i = 0;
        while(i < n) {
            if(s[i] == '0') {
                int start = i;
                while(i < n && s[i] == '0') i++;

                inactiveBlocks.push_back(i-start);
            } else {
                i++;
            }
        }

        int maxPairSum = 0;
        //max(inactiveBlocks[i] + inactiveBlocks[i-1])
        for(int i = 1; i < inactiveBlocks.size(); i++) {
            maxPairSum = max(maxPairSum, inactiveBlocks[i] + inactiveBlocks[i-1]);
        }

        return maxPairSum + activeCount;
    }
};


/**************************************************************** JAVA ****************************************************************/
//Approach (target 1s and find max pair sum of zero blocks)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public int maxActiveSectionsAfterTrade(String s) {
        int n = s.length();

        // existing count of 1s
        int activeCount = 0;
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '1') activeCount++;
        }

        List<Integer> inactiveBlocks = new ArrayList<>();
        int i = 0;
        while (i < n) {
            if (s.charAt(i) == '0') {
                int start = i;
                while (i < n && s.charAt(i) == '0') i++;

                inactiveBlocks.add(i - start);
            } else {
                i++;
            }
        }

        int maxPairSum = 0;
        // max(inactiveBlocks[i] + inactiveBlocks[i-1])
        for (int j = 1; j < inactiveBlocks.size(); j++) {
            maxPairSum = Math.max(maxPairSum, inactiveBlocks.get(j) + inactiveBlocks.get(j - 1));
        }

        return maxPairSum + activeCount;
    }
}
