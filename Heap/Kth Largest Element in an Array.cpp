/*
    MY YOUTUBE VIDEO ON THIS Qn :  Approach-1 and Approach-2 : https://www.youtube.com/watch?v=cI0shWNnB4o
                                   Approach-3 : https://www.youtube.com/watch?v=QFoNfrP7knk
    Company Tags                :  Flipkart, VMWare, Accolite, Amazon, Microsoft, Snapdeal, ABCO, SAP Labs, Cisco, Rockstand
    Leetcode Qn Link            :  https://leetcode.com/problems/kth-largest-element-in-an-array/

    NOTE - 3rd Approach (Using Quick Select) should fall in Array Playlist Category but I have maintained all solutions here only.

*/

************************************************************ C++ ************************************************************
//Approach-1 Using Min-heap (T.C : n*logn)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //min heap
        priority_queue<int, vector<int>, greater<int>> minh;
        
        for(int i:nums) {
            minh.push(i);
            if(minh.size() > k)
                minh.pop();
        }
        
        return minh.top();
    }
};


//Approach-2 Using sorting (T.C : n*logn)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(begin(nums), end(nums), greater<int>());
        return nums[k - 1];
    }
};


//Approach-3 (Using QuickSelect Algorithm
//Time complexity: O(n) on average, O(n2) in the worst case (See video above for explanation)
class Solution {
public:
    
    int partition_algo(vector<int>& nums, int L, int R) {
        
        int P = nums[L];
        int i = L+1; //0
        int j = R; //0
        
        while(i <= j) {
            
            if(nums[i] < P && nums[j] > P) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
            
            if(nums[i] >= P) {
                i++;
            }
            
            if(nums[j] <= P) {
                j--;
            }
            
        }
        
        swap(nums[L], nums[j]);
        return j; //P is at jth index
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        
        int L = 0;
        int R = n-1;
        
        int pivot_idx = 0;
        
        //kth largest pivot element - nums[k-1] (descendinforder me partition karenge)
        
        while(true) {
            
             pivot_idx = partition_algo(nums, L, R);
            
            if(pivot_idx == k-1) {
                break;
            } else if(pivot_idx > k-1) { //2nd larget , 4th larget
                R = pivot_idx - 1;
            } else {
                L = pivot_idx + 1;
            }
            
        }
        
        
        return nums[pivot_idx];
        
    }
};




************************************************************ JAVA ************************************************************
//Approach-1 Using Min-heap (T.C : n*logn)
class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> minh = new PriorityQueue<>();
        for (int num: nums) {
            minh.add(num);
            if (minh.size() > k) {
                minh.remove();
            }
        }
        
        return minh.peek();
    }
}
    
//Approach-2 Using sorting (T.C : n*logn)
class Solution {
    public int findKthLargest(int[] nums, int k) {
        Arrays.sort(nums); //Ascending order
        return nums[nums.length - k];
    }
}


//Approach-3 (Using QuickSelect Algorithm
//Time complexity: O(n) on average, O(n2) in the worst case (See video above for explanation)
class Solution {
    
    private void swap(int[] nums, int x, int y) {
        int temp = nums[x];
        nums[x] = nums[y];
        nums[y] = temp;
    }
    
    public int partition_algo(int[] nums, int L, int R) {
        
        int P = nums[L];
        int i = L+1; //0
        int j = R; //0
        
        while(i <= j) {
            
            if(nums[i] < P && nums[j] > P) {
                swap(nums, i, j);
                i++;
                j--;
            }
            
            if(nums[i] >= P) {
                i++;
            }
            
            if(nums[j] <= P) {
                j--;
            }
            
        }
        
        swap(nums, L, j);
        return j; //P is at jth index
    }
    
    public int findKthLargest(int[] nums, int k) {
        int n = nums.length;
        
        int L = 0;
        int R = n-1;
        
        int pivot_idx = 0;
        
        //kth largest pivot element - nums[k-1] (descendinforder me partition karenge)
        
        while(true) {
            
            pivot_idx = partition_algo(nums, L, R);
            
            if(pivot_idx == k-1) {
                break;
            } else if(pivot_idx > k-1) { //2nd larget , 4th larget
                R = pivot_idx - 1;
            } else {
                L = pivot_idx + 1;
            }
            
        }
        
        
        return nums[pivot_idx];
    }
}
