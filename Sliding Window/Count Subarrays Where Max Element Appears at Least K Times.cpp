/*    Scroll below to see JAVA code also   */
/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=06VaWkj8e-0
      Company Tags                : will update soon
      Leetcode Link               : https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/
*/


/****************************************************************************** C++ ****************************************************************/
//Approach-1 (Classic sliding window)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxE = *max_element(begin(nums), end(nums));
        
        int n = nums.size();
        int i = 0, j = 0;
        
        long long result = 0;
        int countMax = 0;
        
        while(j < n) {
            if(nums[j] == maxE) {
                countMax++;
            }
            
            while(countMax >= k) {
                result += n-j;
                
                if(nums[i] == maxE) {
                    countMax--;
                }
                i++;
            }
            j++;
        }
        
        return result;
    }
};


//Approach-2 (Without Sliding Window)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxE = *max_element(begin(nums), end(nums));
        
        int n = nums.size();
        
        long long result = 0;

        vector<int> maxIndices;
        
        for(int i = 0; i < n; i++) {
            if(nums[i] == maxE) {
                maxIndices.push_back(i);
            }
            
            int size = maxIndices.size();
            if(size >= k) {
                int last_i = maxIndices[size-k];
                result += last_i+1;
            }
        }
        
        return result;
    }
};



/****************************************************************************** JAVA ****************************************************************/
//Approach-1 (Classic sliding window)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public long countSubarrays(int[] nums, int k) {
        int maxE = Arrays.stream(nums).max().getAsInt();

        int n = nums.length;
        int i = 0, j = 0;

        long result = 0;
        int countMax = 0;

        while (j < n) {
            if (nums[j] == maxE) {
                countMax++;
            }

            while (countMax >= k) {
                result += n - j;

                if (nums[i] == maxE) {
                    countMax--;
                }
                i++;
            }
            j++;
        }

        return result;
    }
}


//Approach-2 (Without Sliding Window)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public long countSubarrays(int[] nums, int k) {
        int maxE = Arrays.stream(nums).max().getAsInt();

        int n = nums.length;

        long result = 0;

        List<Integer> maxIndices = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            if (nums[i] == maxE) {
                maxIndices.add(i);
            }

            int size = maxIndices.size();
            if (size >= k) {
                int last_i = maxIndices.get(size - k);
                result += last_i + 1;
            }
        }

        return result;
    }
}
