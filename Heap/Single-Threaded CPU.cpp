/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=9zRXNLbl0FI
    Company Tags                : Google
    Leetcode Link               : https://leetcode.com/problems/single-threaded-cpu/
*/

//TC : O(nlogn)
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        
        vector<array<int, 3>> sortedTasks;
        
        for(int i = 0; i<n; i++) {
            int start_time = tasks[i][0];
            int processing_time = tasks[i][1];
            
            sortedTasks.push_back({start_time, processing_time, i});
        }
        
        //sort it
        sort(begin(sortedTasks), end(sortedTasks)); //O(nlogn)
        
        vector<int> result;
        
        long long curr_time = 0;
        int idx             = 0;
        
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<> > pq; //min_heap
        
        while(idx < n || !pq.empty()) {
            
            if(pq.empty() && curr_time < sortedTasks[idx][0]) {
                curr_time = sortedTasks[idx][0];
            }
            
            
            while(idx < n && sortedTasks[idx][0] <= curr_time) {
                pq.push({sortedTasks[idx][1], sortedTasks[idx][2]}); //log(n)
                idx++;
            }
            
            pair<int, int> curr_task = pq.top();
            pq.pop();
            
            curr_time += curr_task.first; //processing time
            result.push_back(curr_task.second);
        }
        
        o(nlogn)
        return result;
    }
};
