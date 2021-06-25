/*
    Company Tags  : Google (with variation)
    Leetcode Link : https://leetcode.com/problems/find-right-interval/
*/

//Approach-1 (Naive - Time : (O(n^2))
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<vector<int>, int> mp; //interval to index

        int n = intervals.size();
        vector<int> result(n, -1);
            for(int i = 0; i<n; i++) {
                mp[intervals[i]] = i;
        }

        sort(begin(intervals), end(intervals));

        for(int i = n-2; i>=0; i--) {
            bool found = false;
            for(int j = i; j<n; j++) {
                
                if(intervals[j][0] >= intervals[i][1]) {
                    
                    result[mp[intervals[ i ] ] ] = mp[intervals[j]];
                    
                    found = true;
                    
                    break;
                }
            }
        }

        return result;
    }
};

//Approach-2 (Using Binary Search, map<vector, int>) Time : O(nlogn)
class Solution {
public:
    int binarySearch(vector<vector<int>>& intervals, int l, int r, int& target) {
        int result = -1;
        while(l <= r) {
            int mid = l + (r-l)/2;
            
            if(intervals[mid][0] >= target) {
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        
        return result;
    }
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<vector<int>, int> mp; //interval to index

        int n = intervals.size();
        vector<int> result(n, -1);
        
            for(int i = 0; i<n; i++) {
                mp[intervals[i]] = i;
        }

        sort(begin(intervals), end(intervals));

        for(int i = n-2; i>=0; i--) {
            
            int idx = binarySearch(intervals, i, n-1, intervals[i][1]);
            
            if(idx != -1) {
                vector<int> interval = intervals[idx];
                result[mp[intervals[i]]] = mp[interval];
            }
        }

        return result;
    }
};

//Approach-3 (Using Binary Search, map<int, int>) Time : O(nlogn)
class Solution {
public:
    int binarySearch(vector<vector<int>>& intervals, int l, int r, int& target) {
        int result = -1;
        while(l <= r) {
            int mid = l + (r-l)/2;
            
            if(intervals[mid][0] >= target) {
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        
        return result;
    }
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> mp; //interval to index

        int n = intervals.size();
        vector<int> result(n, -1);
        
            for(int i = 0; i<n; i++) {
                mp[intervals[i][0]] = i;
                //Hint from question : each starti is unique.
                //That's why always focus on each detail of the question
                //It's given for some reason
        }

        sort(begin(intervals), end(intervals));

        for(int i = n-2; i>=0; i--) {
            int idx = binarySearch(intervals, i, n-1, intervals[i][1]);
            if(idx != -1) {
                vector<int> interval = intervals[idx];
                result[mp[intervals[i][0]]] = mp[interval[0]];
            }
        }

        return result;
    }
};


//Approach-4  (Using map and lower_bound STL, clean) Time : O(nlogn)
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> mp;
        int n = intervals.size();
        
        vector<int> result(n, -1);
        
        for(int i = 0; i<n; i++) {
            mp[intervals[i][0]] = i;
        }
        
        for(int i = 0; i<n; i++) {
            int end_i = intervals[i][1]; //end_i
            //Now, find the interval whose start intervals[j][0] (start_j) >= end_i
            
            auto end_j = mp.lower_bound(end_i);
            
            if(end_j != end(mp)) {
                result[i] = end_j->second;
            }
            
            
        }
        return result;
    }
};
