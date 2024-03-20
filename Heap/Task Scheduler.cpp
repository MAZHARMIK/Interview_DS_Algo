/*         Scroll below to see JAVA code also            */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=rYh-Kkbzsnw
    Company Tags  : Facebook
    Leetcode Link : https://leetcode.com/problems/task-scheduler/
    
    Greedy approach : https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Greedy/Task%20Scheduler.cpp
*/

/******************************************************* C++ ****************************************************/
//Approach (Heap + Greedy)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int leastInterval(vector<char>& tasks, int p) {
        int n = tasks.size();
        unordered_map<char, int> mp;
        
        for(char &ch : tasks) {
            mp[ch]++;
        }

        priority_queue<int> pq; //max heap
        //we want to finish the process which is most occurring (having highest frequency)
        //so that we don't have to finish in the last with p gaps.
        int time = 0;
        
        for(auto &it : mp) {
            pq.push(it.second);
        }
        
        while(!pq.empty()) {
            vector<int> temp;
            for(int i = 1; i<=p+1; i++) {
                //filling first p+1 characters
                if(!pq.empty()) {
                    temp.push_back(pq.top()-1); //finishing one instance of each process
                    pq.pop();
                }
            }
            
            for(int &freq : temp) {
                if(freq > 0)
                    pq.push(freq);
            }
            
            if(pq.empty()) //all processes finished
                time += temp.size();
            else
                time += (p+1); //we finished p+1 tasks above in the loop
            
        }
        
        return time;
    }
};


/******************************************************* JAVA ****************************************************/
//Approach (Heap + Greedy)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int leastInterval(char[] tasks, int p) {
        // Build frequency map
        int[] freq = new int[26];
        for (char ch : tasks) {
            freq[ch - 'A']++;
        }
        
        // Max heap to store frequencies
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                pq.offer(freq[i]);
            }
        }

        int time = 0;
        // Process tasks until the heap is empty
        while (!pq.isEmpty()) {
            int cycle = p + 1;
            List<Integer> store = new ArrayList<>();
            int taskCount = 0;
            // Execute tasks in each cycle
            while (cycle-- > 0 && !pq.isEmpty()) {
                int currentFreq = pq.poll();
                if (currentFreq > 1) {
                    store.add(currentFreq - 1);
                }
                taskCount++;
            }
            // Restore updated frequencies to the heap
            store.forEach(pq::offer);
            // Add time for the completed cycle
            time += (pq.isEmpty() ? taskCount : p + 1);
        }
        return time;
    }
}
