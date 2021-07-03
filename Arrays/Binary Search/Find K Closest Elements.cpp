/*
    Company Tags  : Google (with variation), Amazon, OYO Rooms
    Leetcode Link : https://leetcode.com/problems/find-k-closest-elements/
*/

//Approach-1 (Using priority queue : O((n+k)logk) (Time : 84ms)
class Solution {
public:
    typedef pair<int, int> P;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<P, vector<P>> pq;
        
        for(int i = 0; i<arr.size(); i++) {
            int diff = abs(x-arr[i]);
            
            pq.push({diff, arr[i]});
            if(pq.size() > k)
                pq.pop();
        }
        
        vector<int> result;
        while(!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        
        sort(begin(result), end(result));
        return result;
    }
};

//Approach-2 (O(n)) Making use of sorted property (Not Binary Search) 
//(Time : 36ms)
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size()-1;
        
        while(r-l >= k) {
            if(abs(arr[l]-x) <= abs(arr[r]-x))
                r--;
            else
                l++;
        }
        
        vector<int> result(arr.begin()+l, arr.begin()+l+k)
        return result;
    }
};

//Approach-3 (Using Binary Search ) O(log(n-k)) Time : 32ms
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0;
        int r = arr.size()-k; 
        /*
            Why r = arr.size()-k?
            Because, we will be comparing arr[mid] with arr[mid+k]
            for moving l and r.
            So, r should be arr.size()-k so that (mid+k) doesn't
            go out of bound
        */
        
		/*
				The tricky part of this solution is smart use of binary search.
				The binary search here is used to find the best left
				index ('l') rather than finding the closest element to x
				We are actually in search of best 'l' i.e. from where should
				we start to take k elements.
		*/
        while(l < r) {
            int mid = l + (r-l)/2;
            /*
                if arr[mid+k] is closer to x
				There is no way 'l' can start from mid.
                so, move l = mid+1
            */
            
            if(x - arr[mid] > arr[mid+k] - x)
                l = mid+1;
            else {
                /*
                    if arr[mid] is closer to x then:
                    There are chances that we can start 'l' from this mid
					and when this loop breaks (when l == r), so if r was 'mid'
					then 'l' will be 'mid' in the end too.
                */
                r = mid;
            }
        }
        //We have found the best l to start with. Now, starting from l, we need k elements
        vector<int> result(begin(arr)+l, begin(arr)+l+k);
        return result;
    }
};
