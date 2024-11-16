/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : Approach-1 : https://www.youtube.com/watch?v=P1_yXMhqC50
                                  Approach-2 : https://www.youtube.com/watch?v=7xkCA80h5a4
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 (Using sliding window)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> result(n-k+1, -1);

        int count = 1; //count of consecutive elements

        //preprocess the first window
        for(int i = 1; i < k; i++) {
            if(nums[i] == nums[i-1]+1) {
                count++;
            } else {
                count = 1;
            }
        }

        if(count == k) {
            result[0] = nums[k-1];
        }

        int i = 1;
        int j = k;

        while(j < n) {
            if(nums[j] == nums[j-1]+1) {
                count++;
            } else {
                count = 1;
            }

            if(count >= k) {
                result[i] = nums[j];
            }

            i++;
            j++;
        }

        return result;

    }
};


//Approach-2 (Using monotonic deque)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int> deq; //Monotonic deque
        vector<int> result;

        for(int j = 0; j < n; j++) {

            if(deq.size() == k) {
                deq.pop_front(); //deq ka size ab k-1, ab jth element ko hum insert karne ka soch sakte hain deque me
            }

            if(!deq.empty() && deq.back() != nums[j]-1) { //nums[j] is not consecutive to deq.back() element
                deq.clear();
            }

            deq.push_back(nums[j]);

            if(j >= k-1) {
                if(deq.size() == k) {
                    result.push_back(deq.back()); //max element hoga becau monotonic hai
                } else {
                    result.push_back(-1); //else -1
                }
            }
        }

        return result;
    }
};

/**************************************************************** JAVA ****************************************************************/
//Approach (Using sliding window)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int[] resultsArray(int[] nums, int k) {
        int n = nums.length;

        int[] result = new int[n - k + 1];
        // Initialize the result array with -1
        java.util.Arrays.fill(result, -1);

        int count = 1; // Count of consecutive elements

        // Preprocess the first window
        for (int i = 1; i < k; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                count++;
            } else {
                count = 1;
            }
        }

        // Check if the first window satisfies the condition
        if (count == k) {
            result[0] = nums[k - 1];
        }

        int i = 1;
        int j = k;

        // Process the sliding window
        while (j < n) {
            if (nums[j] == nums[j - 1] + 1) {
                count++;
            } else {
                count = 1;
            }

            if (count >= k) {
                result[i] = nums[j];
            }

            i++;
            j++;
        }

        return result;
    }
}


//Approach-2 (Using monotonic deque)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public int[] resultsArray(int[] nums, int k) {
        int n = nums.length;

        Deque<Integer> deq = new LinkedList<>(); // Monotonic deque
        int[] result = new int[n - k + 1];
        int index = 0;

        for (int j = 0; j < n; j++) {
            // If deque size equals k, remove the front element
            if (deq.size() == k) {
                deq.pollFirst();
            }

            // If deque is not empty and current element is not consecutive to the last element
            if (!deq.isEmpty() && deq.peekLast() != nums[j] - 1) {
                deq.clear();
            }

            // Add the current element to the deque
            deq.offerLast(nums[j]);

            // Once we process the first k elements
            if (j >= k - 1) {
                if (deq.size() == k) {
                    result[index++] = deq.peekLast(); // Last element is the max due to monotonic property
                } else {
                    result[index++] = -1; // Otherwise, add -1
                }
            }
        }

        return result;
    }
}
