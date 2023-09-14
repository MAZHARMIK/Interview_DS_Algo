/*
      MY YOUTUBE VIDEO ON THIS Qn : 
      Company Tags                : GOOGLE
      Leetcode Link               : https://leetcode.com/problems/reconstruct-itinerary/
*/

//Approach-1 (Using adj of string to vector and sorting it)
//T.C : O(V^2)
class Solution {
public:
    unordered_map<string, vector<string>> adj;
    vector<string> route;
    int numTickets = 0;
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
		numTickets = tickets.size();
        
		for (auto& t : tickets) {
            string u = t[0];
            string v = t[1];
            
			adj[u].push_back(v);
		}
        
        // Sort vertices in the adjacency list by lexical order
        for (auto &edges : adj) {
            sort(begin(edges.second), end(edges.second));
        }
        
        vector<string> temp;
        DFS("JFK", temp);
        return route;
    }
    
    bool DFS(string fromAirport, vector<string>& temp) {
        temp.push_back(fromAirport);
        
        // we have used all tickets, this is a valid path return the result
        if (temp.size() == numTickets+1) {
            route = temp;
            return true;
        }
        
        //You have already found the route (first valid lexicographically path)

        
        vector<string>& neighbors = adj[fromAirport];
        
        // at the current layer, try its neighbors in the sorted order
        for(int i = 0; i < neighbors.size(); i++) {
            
            string toAirport = neighbors[i];
            
            // remove ticket(route) from graph so that it won't be reused 
            neighbors.erase(neighbors.begin()+i);
            
            if(DFS(toAirport, temp))
                return true;
            
            // if the current path is invalid, restore the current ticket
            neighbors.insert(neighbors.begin()+i, toAirport);            
        }
        
        temp.pop_back();
        return false;
    }
};

//Approach-2 (Using adj of string to min-heap)
class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
    vector<string> result;
    void dfs(string u) {
        auto & edges = adj[u];
        
        while (!edges.empty())
        {
            string v = edges.top();
            edges.pop();
            dfs(v);
        }
        result.push_back(u);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto e : tickets)
            adj[e[0]].push(e[1]);
        
        dfs("JFK");
        reverse(result.begin(), result.end());
        return result;
    }
};
