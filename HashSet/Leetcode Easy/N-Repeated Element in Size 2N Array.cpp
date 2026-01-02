/*                   SCROLL BELOW TO SEE JAVA CODE AS WELL                 */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Google, Amazon, Microsoft, Adobe, Apple, Cisco
    Leetcode Link               : https://leetcode.com/problems/n-repeated-element-in-size-2n-array
*/


/*************************************************************** C++ ***************************************************************/
//Approach-1 (Using Hashset)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> st;
        
        for (int &num : nums) {
            if(st.count(num))
                return num;
            
            st.insert(num);
        }
        
        return -1;
    }
};


//Approach-2 (Using 10^4 Size array ~ Constant Space)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {    
        vector<int> freq(10001, 0);
        
        for (int &num : nums) {
            freq[num]++;
            if (freq[num] > 1) //all other elements appear exactly once
                return num;
        }
        
        return -1;
    }
};



//Approach-3 (Without using any extra variable to store space - True Constant Space)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 2; i<n; i++) {
            if(nums[i] == nums[i-1] || nums[i] == nums[i-2])
                return nums[i];
        }
        
        return nums[n-1];
    }
};



/*************************************************************** JAVA ***************************************************************/
//Approach-1 (Using Hashset)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public int repeatedNTimes(int[] nums) {
        Set<Integer> set = new HashSet<>();
        
        for (int num : nums) {
            if (set.contains(num))
                return num;
            set.add(num);
        }
        
        return -1;
    }
}


//Approach-2 (Using 10^4 Size array ~ Constant Space)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int repeatedNTimes(int[] nums) {
        int[] freq = new int[10001];
        
        for (int num : nums) {
            freq[num]++;
            if (freq[num] > 1) // all other elements appear exactly once
                return num;
        }
        
        return -1;
    }
}



//Approach-3 (Without using any extra variable to store space - True Constant Space)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int repeatedNTimes(int[] nums) {
        int n = nums.length;
        
        for (int i = 2; i < n; i++) {
            if (nums[i] == nums[i - 1] || nums[i] == nums[i - 2])
                return nums[i];
        }
        
        return nums[n - 1];
    }
}
