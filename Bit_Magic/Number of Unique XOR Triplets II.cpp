/*   Scroll below to see JAVA code also  */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Will udpate later
    Leetcode Link               : https://leetcode.com/problems/number-of-unique-xor-triplets-ii
*/


/******************************************************* C++ *******************************************************/
//Approach-1 (Xor Pairs and then Xor triplets)
//T.C : O(n^2 + n*maxEl), maxEl = max element in nums
//S.C : O(maxEl), less than next power of 2 after maxEl
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        //Store all Pair Xors
        unordered_set<int> s1;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                s1.insert(nums[i] ^ nums[j]);
            }
        }

        //Find triplet xors
        unordered_set<int> s2;
        for(int pairXor : s1) {
            for(int &num : nums) {
                s2.insert(pairXor ^ num);
            }
        }

        return s2.size();
    }
};



//Approach-2 (Xor Pairs and then Xor triplets using vectors instead of set), Set involves hashing internally and hence this is an improved solution
//T.C : O(n^2 + n*maxEl), maxEl = max element in nums
//S.C : O(maxEl), less than next power of 2 after maxEl
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int maxEl = *max_element(begin(nums), end(nums));

        int T = 1;
        while(T <= maxEl) {
            T <<= 1; //T = T*2
        }

        vector<bool> s1(T, false); //XOR pair values set to true
        vector<bool> s2(T, false); //XOR triplet values set to true

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                s1[nums[i] ^ nums[j]] = true;
            }
        }

        for(int i = 0; i < T; i++) {
            if(s1[i] == true) {
                for(int &num : nums) {
                    s2[i ^ num] = true;
                }
            }
        }

        int count = 0; //unique xor count
        for(int i = 0; i < T; i++) {
            if(s2[i] == true)
                count++;
        }

        return count;

        
    }
};


/******************************************************* JAVA *******************************************************/
//Approach-1 (Xor Pairs and then Xor triplets)
//T.C : O(n^2 + n*maxEl), maxEl = max element in nums
//S.C : O(maxEl), less than next power of 2 after maxEl
class Solution {
    public int uniqueXorTriplets(int[] nums) {
        int n = nums.length;
        //Store all Pair Xors
        Set<Integer> s1 = new HashSet<>();
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                s1.add(nums[i] ^ nums[j]);
            }
        }
        //Find triplet xors
        Set<Integer> s2 = new HashSet<>();
        for(int pairXor : s1) {
            for(int num : nums) {
                s2.add(pairXor ^ num);
            }
        }
        return s2.size();
    }
}



//Approach-2 (Xor Pairs and then Xor triplets using vectors instead of set), Set involves hashing internally and hence this is an improved solution
//T.C : O(n^2 + n*maxEl), maxEl = max element in nums
//S.C : O(maxEl), less than next power of 2 after maxEl
class Solution {
    public int uniqueXorTriplets(int[] nums) {
        int n = nums.length;
        int maxEl = 0;
        for(int num : nums) {
            maxEl = Math.max(maxEl, num);
        }
        int T = 1;
        while(T <= maxEl) {
            T <<= 1; //T = T*2
        }
        boolean[] s1 = new boolean[T]; //XOR pair values set to true
        boolean[] s2 = new boolean[T]; //XOR triplet values set to true
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                s1[nums[i] ^ nums[j]] = true;
            }
        }
        for(int i = 0; i < T; i++) {
            if(s1[i] == true) {
                for(int num : nums) {
                    s2[i ^ num] = true;
                }
            }
        }
        int count = 0; //unique xor count
        for(int i = 0; i < T; i++) {
            if(s2[i] == true)
                count++;
        }
        return count;
    }
}
