/*
    Company Tags                        : Accolite, Amazon, Flipkart, Microsoft, Moonfrog Labs, OYO Rooms
    GfG Link                            : https://practice.geeksforgeeks.org/problems/topological-sort/1#
    Related Leetcode Qn                 : Course Schedule, Course Schedule II
    Course Schedule (Leetcode - 207)    : https://leetcode.com/problems/course-schedule/
    Course Schedule II (Leetcode - 210) : https://leetcode.com/problems/course-schedule-ii/
    Solution (Course Schedule)          : https://github.com/MAZHARMIK/Leetcode-May-Challenge-2020/blob/master/Course%20Schedule%20(C%2B%2B)
    Solution (Course Schedule II)       : https://github.com/MAZHARMIK/Leetcode-July-Challenge-2020/blob/master/Course%20Schedule%20II%20(C%2B%2B)
    NOTE: This can also be used to check if the graph contains cycle or not (Please see Line:56 below)
*/

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int N, vector<int> adj[]) {

        vector<int> indegree(N, 0);
    
        for(int u = 0; u<N; u++) {
            for(int &v : adj[u]) {
                indegree[v]++;
            }
        }
        
        queue<int> que;
        for(int i = 0; i<N; i++) {
            if(indegree[i] == 0) {
                que.push(i);
            }
        }
        vector<int> result;
        int count = 0;
        while(!que.empty()) {
            int curr = que.front();
            que.pop();
            count++;
    
            for(auto x:adj[curr]) {
                indegree[x]--;
                if(indegree[x] == 0) {
                    que.push(x);
                }
            }
    
            result.push_back(curr);
        }

        return result;
	}
};
