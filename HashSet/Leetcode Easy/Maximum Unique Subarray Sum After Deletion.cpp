/*     Scroll below to see JAVA code as well    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=0Q4cqxmR0qc
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion
*/


/*************************************************************** C++ ***************************************************************/
//Approach-1 (Using set)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> st;

        int sum = 0;

        int maxNeg = INT_MIN;

        for(int &num : nums) {
            if(num <= 0) {
                maxNeg = max(maxNeg, num);
            } else if(!st.count(num)) {
                sum += num;
                st.insert(num);
            }
        }
        
        return sum == 0 ? maxNeg : sum;
    }
};


//Approach-2 (Using constant space)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maxSum(vector<int>& nums) {
        //unordered_set<int> st;
        vector<int> st(101, -1);

        int sum = 0;

        int maxNeg = INT_MIN;

        for(int &num : nums) {
            if(num <= 0) {
                maxNeg = max(maxNeg, num);
            } else if(st[num] == -1) {
                sum += num;
                //st.insert(num);
                st[num] = 1;
            }
        }
        
        return sum == 0 ? maxNeg : sum;
    }
};



/*************************************************************** JAVA ***************************************************************/
//Approach-1 (Using set)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public int maxSum(int[] nums) {
        Set<Integer> set = new HashSet<>();
        
        int sum = 0;
        int maxNeg = Integer.MIN_VALUE;
        
        for(int num : nums) {
            if(num <= 0) {
                maxNeg = Math.max(maxNeg, num); 
            } else if(!set.contains(num)) {
                sum += num;
                set.add(num);
            }
        }
        
        return sum == 0 ? maxNeg : sum;
    }
}

//Approach-2 (Using constant space)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int maxSum(int[] nums) {
        int[] mp = new int[101];
        Arrays.fill(mp, -1); // initialize to -1
        
        int sum = 0;
        int maxNeg = Integer.MIN_VALUE;
        
        for(int num : nums) {
            if(num <= 0) {
                maxNeg = Math.max(maxNeg, num);
            } else if(mp[num] == -1) {
                sum += num;
                mp[num] = 1; 
            }
        }

        return sum > 0 ? sum : maxNeg;
    }
}
