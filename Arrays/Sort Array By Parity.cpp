/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=fMzddofgQOk
      Company Tags                : META
      Leetcode Link               : https://leetcode.com/problems/sort-array-by-parity/
*/

/************************************************************ C++ ************************************************************/
//Approach-1 (Using simple iteration)
//T.C : O(n)
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int j = 0;
        
        for(int i = 0; i<nums.size(); i++) {
            
            if(nums[i]%2 == 0) {//even
                swap(nums[i], nums[j]);
                j++;
            }
        }
        
        return nums;
    }
};

//Approach-2 (Writing your own custom comparator for sorting)
class Solution {
public:
    
    static bool comparator(int a, int b) {
        return a%2 < b%2; //a%2 will be 0 if it's even and since we do a%2 < b%2, hence a will come first if it's even
    }
    
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(begin(nums), end(nums), comparator);
        
        return nums;
    }
};

/************************************************************ JAVA ************************************************************/
//Approach-1 (Using simple iteration)
//T.C : O(n)
class Solution {
    public int[] sortArrayByParity(int[] nums) {
        int j = 0;

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] % 2 == 0) { // even
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                j++;
            }
        }

        return nums;
    }
}


//Approach-2 (Writing your own custom comparator for sorting)
//T.C : O(nlog(n))
class Solution {
    
    static boolean comparator(int a, int b) {
        
        /*
        NOTE : return a%2 < b%2;
        This is causing "Comparison method violates its general contract!" Error.
        So, for JAVA, I have written below comparator
        */
        
        // If both 'a' and 'b' are even or both are odd, compare them as usual.
        if ((a % 2 == 0 && b % 2 == 0) || (a % 2 != 0 && b % 2 != 0)) {
            return a < b;
        }

        // If 'a' is even and 'b' is odd, 'a' should come before 'b'.
        return a % 2 == 0;
    }
    
    public int[] sortArrayByParity(int[] nums) {
        
        Integer[] numsWrapper = new Integer[nums.length];
        for (int i = 0; i < nums.length; i++) {
            numsWrapper[i] = nums[i];
        }
        
        Arrays.sort(numsWrapper, new Comparator<Integer>() {
            public int compare(Integer a, Integer b) {
                return comparator(a, b) ? -1 : 1;
            }
        });
        
        for (int i = 0; i < nums.length; i++) {
            nums[i] = numsWrapper[i];
        }
        
        return nums;
    }
}
