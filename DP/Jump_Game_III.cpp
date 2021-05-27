/*
    Company Tags  : Please let me know when you get it :-)
    Leetcode Link : https://leetcode.com/problems/jump-game-iii/
*/

//Approach-1 (DFS)
class Solution {
public:
    bool dfs(vector<int>& arr, int start, int& n) {
        if(start < 0 || start >= n || arr[start] < 0)
            return false;
        if(arr[start] == 0)
            return true;
        //I don't want to check start again in future
        //I could memoize it as well but making use of the fact
        //0 <= arr[i] < arr.length
        arr[start] = -arr[start];
		
        int left    = dfs(arr, start-arr[start], n);
        int right = dfs(arr, start+arr[start], n);
        
        return left||right;
    }
    bool canReach(vector<int>& arr, int start) {
        int n = (int) arr.size();
        return dfs(arr, start, n);
    }
};

//Approach-2 (BFS)
class Solution {
public:
    bool bfs(vector<int>& arr, int start, int n) {
        queue<int> que;
        que.push(start);
        
        while(!que.empty()) {
            int curr = que.front();
            que.pop();
            
            //reached 0
            if(arr[curr] == 0)
                return true;
            
            //This was visited before. Ignore
            if(arr[curr] < 0)
                continue;
            
            int left  = curr + arr[curr];
            int right = curr - arr[curr];
            
            if(left >= 0 && left < n)
                que.push(left);
            if(right >= 0 && right < n)
                que.push(right);
            
            //curr is visited and its neighbours are explored. We don't need it
            arr[curr] = -arr[curr];
        }
        
        return false;
    }  
    bool canReach(vector<int>& arr, int start) {
        int n = (int) arr.size();
        return bfs(arr, start, n);
    }
};
