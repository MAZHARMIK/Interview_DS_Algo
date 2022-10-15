/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=-uc7OCrjp8g
    Company Tags                : Amazon, MentorGraphics
    Qn Link                     : https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1#
*/

typedef long long ll;
vector<ll> printFirstNegativeInteger(ll A[], ll N, ll k) {
    list<ll> dll; //You can use queue, dequeue etc as well
    vector<ll> result;
    int i = 0, j = 0;
    
    while(j < N) {
        if(A[j] < 0)
            dll.push_back(A[j]);
        
        if(j-i+1 == k) {
            ll neg = dll.empty() ? 0 : dll.front();
            result.push_back(neg);
            if(A[i] < 0 && !dll.empty()) {
                dll.pop_front();
            }
            i++;
        }
        j++;
    }
    return result;
    
 }


//Approach-2 (Another good way to solve this)
typedef long long ll;
vector<ll> printFirstNegativeInteger(ll A[], ll N, ll K) {
        
        deque<ll> deq;
        vector<ll> result;
        
        for(ll i = 0; i<K; i++) {
            if(A[i] < 0)
                deq.push_back(i);
        }
        
        for(int i = K; i<N; i++) {
            if(!deq.empty()) {
                result.push_back(A[deq.front()]);
            } else {
                result.push_back(0);
            }
            
            while(!deq.empty() && deq.front() < i-K+1) {
                deq.pop_front();
            }
            
            if(A[i] < 0)
                deq.push_back(i);
        }
        
        if(!deq.empty())
            result.push_back(A[deq.front()]);
        else
            result.push_back(0);
            
        return result;
        
 }
