/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=oyzF9AsOUQ8
    Company Tags                : Amazon, Meta
    Leetcode Link               : https://leetcode.com/problems/assign-cookies/
*/


/**************************************************** C++ ****************************************************/
//Approach (Sort and choose)
//T.C : O(mlogm + nlogn)
//S.C : O(1)
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(begin(g), end(g));
        sort(begin(s), end(s));
        
        int m = g.size();
        int n = s.size();
        
        int i = 0;
        int j = 0;
        
        while(i < m && j < n) {
            if(g[i] <= s[j]) {
                i++;
            }
            j++;
        }
        
        return i;
    }
};



/**************************************************** JAVA ****************************************************/
//Approach (Sort and choose)
//T.C : O(mlogm + nlogn)
//S.C : O(1)
class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        
        int m = g.length;
        int n = s.length;
        
        int i = 0;
        int j = 0;
        
        while (i < m && j < n) {
            if (g[i] <= s[j]) {
                i++;
            }
            j++;
        }
        
        return i;
    }
}
