/*
    Company Tags  : Google (variation)
    Leetcode Link : https://leetcode.com/problems/max-chunks-to-make-sorted-ii/
*/

//Approach-1 : Time - O(n), Space - O(n)
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> rightMin(n);
        rightMin[n-1] = arr[n-1];
        
        for(int i = n-2; i>=0; i--)
            rightMin[i] = min(rightMin[i+1], arr[i]);
        
        int leftMax = arr[0];
        
        int count = 0;
        
        /*
            If current leftMax is less than or equal to
            minimum of all elements to its right,
            it means it can't have an impact further.
            It belongs to a chunk till this point only.
            And then, we move ahead.
        */
        
        for(int i = 0; i<n-1; i++) {
            leftMax = max(leftMax, arr[i]);
            if(leftMax <= rightMin[i+1])
                count++;
        }
        
        return count+1;
    }
};


//Approach-2 (Using similar concept of "Max Chunks To Make Sorted I"
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> sorted(arr);
        sort(begin(sorted), end(sorted));
        
        vector<int> MAX(n);
        MAX[0] = arr[0];
        for(int i = 1; i<n; i++)
            MAX[i] = max(MAX[i-1], arr[i]);
        
        int rightMax = MAX[n-1];
        int count    = 0;
        for(int  i = n-1; i>=0; i--) {
            if(sorted[i] == MAX[i]) {
                if(sorted[i] > rightMax)
                    continue; //because we need to include this as well for being sorted correctly
                
                rightMax = arr[i];
                count++;
            }
        }
        
        return count;
    }
};

//Approach-3 (O(nlogn)) But smartest approach
/*
    Why does this work ?
    Intuition -
    Let "sorted" be the input "arr" array after being sorted.
    A "chunk" is an interval [i, j] such that arr[i], ..., arr[j]
    is just a permutation of sorted[i], ..., sorted[j].
    
    Since each chunk is just a permutation, the sums of these
    two lists of numbers will be equal.
    And the point where cumulative sum gets equal, that's the
    point of partition of chunk.
*/
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> sorted(arr);
        sort(begin(sorted), end(sorted));
        
        long long sum1 = 0, sum2 = 0;
        int count = 0;
        for(int i = 0; i<n; i++) {
            sum1 += arr[i];
            sum2 += sorted[i];
            
            if(sum1 == sum2)
                count++;
        }
        
        return count;
    }
};
