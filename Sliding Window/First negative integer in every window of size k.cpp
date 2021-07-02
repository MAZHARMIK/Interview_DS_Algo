/*
    Company Tags : Amazon
    Qn Link      : https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1#
*/

typedef long long ll;
vector<ll> printFirstNegativeInteger(ll A[], ll N, ll k) {
    list<ll> dll; //You can use queue, dequeue etc as well
    vector<ll> result;
    int i = 0, j = 0;
    
    while(j < N) {
        if(A[j] < 0)
            dll.push_back(A[j]);
        
        if(j-i+1 >= k) {
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
