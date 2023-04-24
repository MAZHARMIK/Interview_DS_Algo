/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=GBzie2ETYQg
    Company Tags                : Google, Amazon
    Leetcode Qn Link            : https://leetcode.com/problems/last-stone-weight/
*/

//Approach-1 (Brute Force - Accepted) TC : (n^2 * log(n))
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int heighest=-1;
        int sec_heighest;
        
        while(stones.size()>1)
        {
            sort(stones.begin(),stones.end());
            
            int a = stones.back(); stones.pop_back();
            int b = stones.back(); stones.pop_back();

            stones.push_back(abs(a-b));
        
        }

       
        return stones[0];
    }     
};

//Approach-2 (Using Heap)- TC : (nlog(n))
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq; //max-heap
        for(int i:stones)
            pq.push(i);
        while(pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            if(a != b)
                pq.push(abs(a-b));
        }
        
        if(pq.size())
            return pq.top();
        return 0;
    }
};
