/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=3Bge5OCcXUk
    Company Tags                : Amazon
    Leetcode Qn Link            : https://leetcode.com/problems/kth-largest-element-in-a-stream/
*/

//Approach - (Using min-heap)
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;
    
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int &x : nums) {
            pq.push(x);
            
            if(pq.size() > k)
                pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        
        if(pq.size() > K)
            pq.pop();
        
        return pq.top();
    }
};
