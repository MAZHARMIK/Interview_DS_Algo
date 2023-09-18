/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=X1ZG-CXkmEM
    Company Tags                : Amazon (Same variation : They just want to chec if you go for Binary Search as an improvement)
    Leetcode Link               : https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
*/

/***************************************** C++ *****************************************/
//Approach-1 (Using Sorting + Binary Search)
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

//Approach-2 (Using Priority_queue - max-heap of size k + Binary Search)
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


/***************************************** JAVA *****************************************/
//Approach-1 (Using Sorting + Binary Search)
//T.C : O(m*log(n)) + O(m*log(m))
//S.C : O(m) to store count of ones and corresponding row in the vector
class Solution 
{
    public int[] kWeakestRows(int[][] mat, int k)  {
        List<int[]> countOnes = new ArrayList<>();
        int ind = 0;
        for(int[] a: mat) {
            int soldiers = binarySearch(a);
            countOnes.add(new int[]{ind++, soldiers});
        }
        
        countOnes.sort((x1, x2) -> (x1[1]-x2[1]));
        
        int[] res = new int[k];
        
        for(int i=0;i<k;i++)
            res[i] = countOnes.get(i)[0];
        
        return res;
    }
    
    public int binarySearch(int[] a) {
        
        int n = a.length;
        int l = 0, r = n-1;
        int result = -1;
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(a[mid] == 1) {
                result = mid;
                l = mid+1;
            }
            else
                r = mid-1;
        }
        return result+1;
    }
}


//Approach-2 (Using max-heap + Binary Search)
//Why max-heap - So that when the size of mac-heap reaches more than k, we pop the bigger elements because we need answer in descending order of weakness of rows
//T.C : //O(m*log(n) + m*log(k))
//S.C : O(k) to store count of ones and corresponding row in the min-heap
class Solution {
    public int[] kWeakestRows(int[][] mat, int k) {
        int m = mat.length;
        int n = mat[0].length;
        
        //max-heap
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] != b[0] ? b[0] - a[0] : b[1] - a[1]);
        
        int[] ans = new int[k];
        
        for (int i = 0; i < mat.length; i++) {
            pq.offer(new int[] {numOnes(mat[i], 0, n-1), i});
            //pq.offer(new int[] {binarySearch(mat[i], 0, n-1), i});
            if (pq.size() > k)
                pq.poll();
        }
        
        while (k > 0)
            ans[--k] = pq.poll()[1];
        
        return ans;
    }
    
    private int numOnes(int[] arr, int l, int r) {

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
}
