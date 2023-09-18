/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Amazon (Same variation : They just want to chec if you go for Binary Search as an improvement)
    Leetcode Link               : https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
*/

//Approach-1 (Using Binary Search)
//T.C : O(m*log(n)) + O(m*log(m))
//S.C : O(m) to store count of ones and corresponding row in the vector
class Solution {
public:
    
    typedef pair<int, int> P;
    
    int binarySearch(vector<int>& arr, int l, int r) {
        int mid;
        int result = -1;
        while(l <= r) {
            mid = l + (r-l)/2;
            
            if(arr[mid] == 1) {
                result = mid;
                l = mid+1;
            } else if(arr[mid] == 0) {
                r = mid-1;
            }
            
        }
        return result+1; //0 based indexing. We need to return number of count of 1s in that row
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<P> countOnes; //Pair : Because we want to store {count of 1s, which row}
        
        //O(m*log(n))
        for(int row = 0; row < m; row++) {
            
            int num_ones = binarySearch(mat[row], 0, n-1); //O(log(n))
            
            countOnes.push_back({num_ones, row});
        }
        
        sort(begin(countOnes), end(countOnes)); //O(mlog(m))
        //Sorted in Ascending order which will take care that if num_ones is equal, then sort based on index in acesnding gorder
        
        vector<int> result(k);
        
        for(int i = 0; i < k; i++) {
            result[i] = countOnes[i].second;
        }
        
        return result;
    }
};

//Approach-2 (Using Priority_queue - max-heap of size k)
//Why max-heap - So that when the size of mac-heap reaches more than k, we pop the bigger elements because we need answer in descending order of weakness of rows
//T.C : //O(m*log(n) + m*log(k))
//S.C : O(k) to store count of ones and corresponding row in the min-heap
class Solution {
public:
    
    typedef pair<int, int> P;
    
    int binarySearch(vector<int>& arr, int l, int r) {
        int mid;
        int result = -1;
        while(l <= r) {
            mid = l + (r-l)/2;
            
            if(arr[mid] == 1) {
                result = mid;
                l = mid+1;
            } else if(arr[mid] == 0) {
                r = mid-1;
            }
            
        }

        return result+1;
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        priority_queue<P> pq;
        
        //O(m*log(n) + m*log(k))
        for(int row = 0; row < m; row++) {
            
            int num_ones = binarySearch(mat[row], 0, n-1); //O(log(n))
            
            pq.push({num_ones, row});
            
            if(pq.size() > k)
                pq.pop();

        }
       
        
        vector<int> result(k);
        int j = k-1;

        //log(k)
        while(!pq.empty()) {
            P temp = pq.top();
            pq.pop();
            
            result[j--] = temp.second;
         }
        
        return result;
    }
};
