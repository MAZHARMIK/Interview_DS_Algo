/*
    Company Tags  : Google, Twitter
    Leetcode Link : https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
*/

//Approach-1 (Naive Priority_queue approach O(n*nlog(k))
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        
        for(vector<int>& vec : matrix) {
            for(int &x : vec) {
                pq.push(x);
                if(pq.size() > k)
                    pq.pop();
            }
        }
        
        return pq.top();
    }
};

//Approach-2 (Binary Search : O(log(max-min) * n)
class Solution {
public:
    int n;
    //This function is in itself a Question (Find rank of an element in a sorted matrix) IMPORTANT
    int lessThanEqualToCount(vector<vector<int>>& matrix, int target) {
        int i = 0, j = n-1;
        int count = 0;
		//O(n)
        while(i < n) {
          while(j >= 0 && matrix[i][j] > target)
            j--;
          count += j+1;
          i++;
        }
        return count;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
          n = matrix.size();
          int l = matrix[0][0];
          int h = matrix[n-1][n-1];
			
		  //O(log(max-min))
          while(l <= h) {
            int mid = l + (h-l)/2;
            int dist = lessThanEqualToCount(matrix, mid);
            if(dist < k)
              l = mid+1;
            else
              h = mid-1;
          }
          return l;
    }
};
