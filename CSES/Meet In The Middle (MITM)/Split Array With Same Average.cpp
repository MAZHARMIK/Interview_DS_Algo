/*     Scroll below to see JAVA code as well    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=KmsHhgkCrXg
    What is Meet In The Middle  : https://www.youtube.com/watch?v=NCr27WYjCH4
    Company Tags                : Will update later
    Leetcode Link               : https://leetcode.com/problems/split-array-with-same-average/description/
*/


/******************************************************************************* C++ ************************************************************************************************/
//Approach (Using MITM)
//T.C : O(n^2 * 2^n)  where n = N/2
//S.C : O(2^n)        where n = N/2
class Solution {
public:
    //returns true if "need" exists in the sorted vector
    bool binarySearch(vector<int>& arr, int need) {
        int low = 0, hi = arr.size() - 1;

        while(low <= hi) {
            int mid = low + (hi - low) / 2;
            if(arr[mid] == need)       
                return true;
            else if(arr[mid] < need)  
                low = mid + 1;
            else
                hi = mid - 1;
        }

        return false;
    }

    bool splitArraySameAverage(vector<int>& nums) {
        int N = nums.size();
        int S = accumulate(begin(nums), end(nums), 0);
        int n1 = N/2;      //left side
        int n2 = N - n1;   //right side

        //Key idea: both groups must have average = S/N.
        //So we just need ONE non-empty proper subset A with:
        //   sum(A)/size(A) == S/N   =>   sum(A)*N == size(A)*S

        //sumsLeft : size -> {subsetSums}
        unordered_map<int, vector<int>> sumsLeft;
        for(int mask = 0; mask < (1 << n1); mask++) {
            int s = 0; //subset sum
            int count = 0;
            for(int i = 0; i < n1; i++) {
                if(mask & (1 << i)) {
                    s += nums[i];
                    count++;
                }
            }
            sumsLeft[count].push_back(s);
        }

        //sumsRight : size -> {subsetSums}
        unordered_map<int, vector<int>> sumsRight;
        for(int mask = 0; mask < (1 << n2); mask++) {
            int s = 0; //subset sum
            int count = 0;
            for(int i = 0; i < n2; i++) {
                if(mask & (1 << i)) {
                    s += nums[n1+i];
                    count++;
                }
            }
            sumsRight[count].push_back(s);
        }

        //NOTE : Sorting a bucket of size b costs O(b log b). Time Complexity -  O(2^n · log(2^n)) = O(n · 2^n).
        for(int count = 0; count <= n2; count++) {
            //sumsRight[count] this is my vector of subset sum having subset of size count
            sort(begin(sumsRight[count]), end(sumsRight[count]));
        }

        for(int k = 0; k <= n1; k++) { //how many elements from left
            for(int leftSubSum : sumsLeft[k]) {
                //size is NOT fixed. can pick m elements from right, m is free.
                for(int m = 0; m <= n2; m++) {
                    int size = k + m; //total size of subset
                    if(size == 0 || size == N) continue; //A empty or B empty is not allowed

                    //need : rightSubSum such that (leftSubSum + rightSubSum)*N == size*S
                    //   =>  rightSubSum = size*S/N - leftSubSum
                    if(size * S % N != 0) 
                        continue; //if not integer, no subset sum can match

                    int need = size * S / N - leftSubSum;

                    //exact match check via binary search
                    if(binarySearch(sumsRight[m], need)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};


/******************************************************************************* JAVA ************************************************************************************************/
//Approach (Using MITM)
//T.C : O(n^2 * 2^n)  where n = N/2
//S.C : O(2^n)        where n = N/2
class Solution {
    //returns true if "need" exists in the sorted list
    private boolean binarySearch(List<Integer> arr, int need) {
        int low = 0, hi = arr.size() - 1;

        while(low <= hi) {
            int mid = low + (hi - low) / 2;
            if(arr.get(mid) == need)
                return true;
            else if(arr.get(mid) < need)
                low = mid + 1;
            else
                hi = mid - 1;
        }

        return false;
    }

    public boolean splitArraySameAverage(int[] nums) {
        int N = nums.length;
        int S = 0;
        for(int num : nums) S += num;
        int n1 = N/2;      //left side
        int n2 = N - n1;   //right side

        //Key idea: both groups must have average = S/N.
        //So we just need ONE non-empty proper subset A with:
        //   sum(A)/size(A) == S/N   =>   sum(A)*N == size(A)*S

        //sumsLeft : size -> {subsetSums}
        Map<Integer, List<Integer>> sumsLeft = new HashMap<>();
        for(int mask = 0; mask < (1 << n1); mask++) {
            int s = 0; //subset sum
            int count = 0;
            for(int i = 0; i < n1; i++) {
                if((mask & (1 << i)) != 0) {
                    s += nums[i];
                    count++;
                }
            }
            sumsLeft.computeIfAbsent(count, key -> new ArrayList<>()).add(s);
        }

        //sumsRight : size -> {subsetSums}
        Map<Integer, List<Integer>> sumsRight = new HashMap<>();
        for(int mask = 0; mask < (1 << n2); mask++) {
            int s = 0; //subset sum
            int count = 0;
            for(int i = 0; i < n2; i++) {
                if((mask & (1 << i)) != 0) {
                    s += nums[n1+i];
                    count++;
                }
            }
            sumsRight.computeIfAbsent(count, key -> new ArrayList<>()).add(s);
        }

        //NOTE : Sorting a bucket of size b costs O(b log b). Time Complexity -  O(2^n · log(2^n)) = O(n · 2^n).
        for(int count = 0; count <= n2; count++) {
            //sumsRight[count] this is my vector of subset sum having subset of size count
            Collections.sort(sumsRight.computeIfAbsent(count, key -> new ArrayList<>()));
        }

        for(int k = 0; k <= n1; k++) { //how many elements from left
            for(int leftSubSum : sumsLeft.getOrDefault(k, new ArrayList<>())) {
                //size is NOT fixed. can pick m elements from right, m is free.
                for(int m = 0; m <= n2; m++) {
                    int size = k + m; //total size of subset
                    if(size == 0 || size == N) continue; //A empty or B empty is not allowed

                    //need : rightSubSum such that (leftSubSum + rightSubSum)*N == size*S
                    //   =>  rightSubSum = size*S/N - leftSubSum
                    if(size * S % N != 0)
                        continue; //if not integer, no subset sum can match

                    int need = size * S / N - leftSubSum;

                    //exact match check via binary search
                    if(binarySearch(sumsRight.getOrDefault(m, new ArrayList<>()), need)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
}
