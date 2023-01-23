/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=ottPfSr3xls
    Company Tags                : Amazon, Uber, Microsoft
    Leetcode Link               : https://leetcode.com/problems/find-the-town-judge/
*/

//Approach-1 (Using Indegree and Outdegree)
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n+1);
        vector<int> outdegree(n+1);
        
        for(vector<int> &vec : trust) {
            indegree[vec[1]]++;
            outdegree[vec[0]]++;
        }
        
        for(int i = 1; i<n+1; i++) {
            if(indegree[i] == n-1 && outdegree[i] == 0)
                return i;
        }
        
        return -1;
    }
};


//Approach-2 (Using Single Count array)
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> count(n+1);
        
        for(vector<int> &vec : trust) {
            count[vec[0]]--;
            count[vec[1]]++;
        }
        
        for(int i = 1; i<n+1; i++) {
            if(count[i] == n-1)
                return i;
        }
        
        return -1;
    }
};
