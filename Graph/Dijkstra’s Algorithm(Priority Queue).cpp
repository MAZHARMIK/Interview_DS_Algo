/*
	MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=xQ3vjWwFRuI
	Company Tags		    : Flipkart, Microsoft
	GfG Link		    : https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
*/

//Time : O(E * log(V))
//E = number of edges
//V = number of vertices
class Solution
{
	public:
	   //Function to find the shortest distance of all the vertices
    	   //from the source vertex S.
	    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

		vector<int> result(V, INT_MAX);

		result[S] = 0;
		pq.push({0, S});

		while(!pq.empty()) {

		    int d  = pq.top().first;
		    int node = pq.top().second;
		    pq.pop();

		    for(auto &vec : adj[node]) {

			int adjNode = vec[0];
			int dist    = vec[1];

			if(d + dist < result[adjNode]) {

			    result[adjNode] = d + dist;
			    pq.push({d+dist, adjNode});

			}

		    }

		}

		return result;

	    }
};
