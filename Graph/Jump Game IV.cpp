/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=tr1WHelOhJU
    Company Tags                : Google, Microsoft, Adobe, Amazon
    Leetcode Link               : https://leetcode.com/problems/jump-game-iv/
*/


//Approach-2 (BFS : Accepted) - O(n)
class Solution {
public:
    int solve_BFS(vector<int>& arr, int& n) {
        vector<bool> visited(n, false);
        unordered_map<int, vector<int>> mp; //why ?  Because, we need to access those indices where arr[i] == arr[j]
        
        for(int i = 0; i<n; i++) {
            mp[arr[i]].push_back(i);
        }
        
        queue<int> que;
        que.push(0);
        visited[0] = true;
        int steps = 0;
        
        while(!que.empty()) {
            int size = que.size();
            
            //check this level
            while(size--) {
                int curr = que.front();
                que.pop();
                
                if(curr == n-1) {
                    //BFS ensures minimum steps
                    //We are moving level by level
                    return steps;
                }
                
                int left  = curr-1;
                int right = curr+1;
                
                if(left >= 0 && !visited[left]) {
                    que.push(left);
                    visited[left] = true;
                }
                
                if(right < n && !visited[right]) {
                    que.push(right);
                    visited[right] = true;
                }
                
                for(const int &idx : mp[arr[curr]]) {
                    if(!visited[idx]) {
                        que.push(idx);
                        visited[idx] = true;
                    }
                }
                //If you don't erase it, you may be again checking for it
                //in future. It will cause TLE
                mp.erase(arr[curr]);
            }
            steps++;
        }
        
        return -1;
    }
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n == 1)
            return 0;
        return solve_BFS(arr, n);
    }
};


//Approach-2 - DFS
/*
DFS -> TLE

DFS+Memoization does not work, when all of the following 3 dependency exists: 
  - forward dependency, i.e., mem[start] depends on mem[start + 1];
  - backward dependncy, i.e., mem[start] depends on mem[start - 1];
  - jump dependency, i.e., mem[start] depends on mem[x];
You mark an index visited and return the value of that index if it was visited in past
but, that value may not be optimal (shotest) in DFS because DFS traverses nodes in random    
order, and we only cache the first result it find.

Why BFS ?
With BFS you can stop as soon as you reach the goal. With DFS you might reach the goal (or memoize any result) via a sub-optimal path.
To be sure you get the optimal solution with DFS, you can't use memoization because you might still find a shorter path at any point in the future.
*/
//Approach-2 (DFS - TLE)
class Solution {
public:
    vector<bool> visited;
    vector<int> t;
    unordered_map<int, vector<int>> mp;
    int solve_DFS(vector<int>& arr, int idx) {
        //reached destination
        if(idx == arr.size()-1)
            return 0;
        
        int min_step = INT_MAX;
        // jump to idx + 1
        if (idx + 1 < arr.size() && !visited[idx+1]) {
            visited[idx+1] = true;
            min_step = min(min_step, solve_DFS(arr, idx+1) + 1);
            visited[idx+1] = false; //you need to do this for trying (idx-1) and same number indices
        }
        // jump to idx - 1
        if (idx - 1 >= 0 && !visited[idx-1]) {
            visited[idx-1] = true;
            min_step = min(min_step, solve_DFS(arr, idx-1) + 1);
            visited[idx-1] = false;
        }
        // jump to same number with different idx
        for (int next_idx : mp[arr[idx]]) {
            if (next_idx == idx) {continue;}
            if (!visited[next_idx]) {
                visited[next_idx] = true;
                min_step = min(min_step, solve_DFS(arr, next_idx) + 1);
                visited[next_idx] = false;
            }
        }
        
        t[idx] = min(t[idx], min_step);
        return t[idx];
    }
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        visited.resize(n);
        t.resize(n, INT_MAX);
        mp.clear();
        for(int i = 0; i<n; i++) {
            mp[arr[i]].push_back(i);
        }
        visited[0] = true;
        return solve_DFS(arr, 0);
    }
};

