/*
    MY YOUTUBE VIDE ON THIS Qn		: https://www.youtube.com/watch?v=uVl4ftleTes
    Company Tags                        : Accolite, Amazon, Flipkart, Microsoft, Moonfrog Labs, OYO Rooms
    GfG Link                            : https://practice.geeksforgeeks.org/problems/topological-sort/1#
    Related Leetcode Qn                 : Course Schedule, Course Schedule II
    Course Schedule (Leetcode - 207)    : https://leetcode.com/problems/course-schedule/
    Course Schedule II (Leetcode - 210) : https://leetcode.com/problems/course-schedule-ii/
    Solution (Course Schedule)          : https://github.com/MAZHARMIK/Leetcode-May-Challenge-2020/blob/master/Course%20Schedule%20(C%2B%2B)
    Solution (Course Schedule II)       : https://github.com/MAZHARMIK/Leetcode-July-Challenge-2020/blob/master/Course%20Schedule%20II%20(C%2B%2B)
    NOTE: This can also be used to check if the graph contains cycle or not (Please see Line:56 below)
*/


//NOTE : This assumes that, we don't have cycle in the given directed graph. You can simply add few things in the same code to check for cycle also
//Or, see this : https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Topological%20Sorting/Course%20Schedule.cpp
class Solution {
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int N, vector<int> adj[])  {
	    queue<int> que;
	    vector<int> indegree(N, 0);
	    
	    //1
	    for(int u = 0; u<N; u++) {
	        for(int &v : adj[u]) {
	            indegree[v]++;
	        }
	    }
	    
	    //2. Fill que, indegree with 0
	    for(int i = 0; i<N; i++) {
	        if(indegree[i] == 0) {
	            que.push(i);
	        }
	    }
	    
	    //3. Simple BFS
	    vector<int> result;
	    while(!que.empty()) {
	        int u = que.front();
	        result.push_back(u);
	        que.pop();
	        
	        for(int &v : adj[u]) {
	            indegree[v]--;
	            
	            if(indegree[v] == 0) {
	                que.push(v);
	            }
	            
	        }
	    }
	    
	    return result;
	}
};
