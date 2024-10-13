/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists
*/

/************************************************************ C++ ************************************************************/
//Approach-1 (Using vector of indexes)
//T.C : O(n*k)
//S.C : O(k)
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();

        vector<int> vec(k, 0); //{0, 0, 0....}

        vector<int> resultRange = {-1000000, 1000000}; //(a, b)

        while(true) {
            int minEl        = INT_MAX;
            int maxEl        = INT_MIN;
            int minElListIdx = 0;

            for(int i = 0; i < k; i++) {
                int listIdx = i;
                int elIdx = vec[i];
                int element = nums[listIdx][elIdx];

                if(element < minEl) {
                    minEl = element;
                    minElListIdx = listIdx;
                }

                maxEl = max(maxEl, element);
            }

            //raneg (minEl, maxEl)
            if(maxEl - minEl < resultRange[1] - resultRange[0]) {
                resultRange[0] = minEl;
                resultRange[1] = maxEl;
            }

            //now shorten this range by moving minElement idx
            int nextIndex = vec[minElListIdx]+1;
            if(nextIndex >= nums[minElListIdx].size()) {
                break;
            }
            vec[minElListIdx] = nextIndex;
        }

        return resultRange;
    }
};



//Approach-2 (Using heap)
//T.C : O(n*log(k))
//S.C : O(k)
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();

        //{element, listIdx, idx} //vector<int>{a, b, c}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        int maxEl = INT_MIN;
        for(int i = 0; i < k; i++) {
            pq.push({nums[i][0], i, 0});
            maxEl = max(maxEl, nums[i][0]);
        }

        vector<int> resultRange = {-1000000, 1000000};

        while(!pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();

            int minEl = curr[0];
            int listIdx = curr[1];
            int idx     = curr[2];

            if(maxEl - minEl < resultRange[1] -  resultRange[0]) {
                resultRange[0] = minEl;
                resultRange[1] = maxEl;
            }

            //decrease the rangen fro minimums ide
            if(idx+1 < nums[listIdx].size()) {
                int nextElement = nums[listIdx][idx+1];
                pq.push({nextElement, listIdx, idx+1});
                maxEl = max(maxEl, nextElement);
            } else {
                break;
            }
        }

        return resultRange;
    }
};



/************************************************************ JAVA ************************************************************/
//Approach-1 (Using vector of indexes)
//T.C : O(n*k)
//S.C : O(k)
import java.util.*;

class Solution {
    public int[] smallestRange(List<List<Integer>> nums) {
        int k = nums.size();
        
        // This array will keep track of the current index for each list
        int[] vec = new int[k];
        
        // Initialize the result range with extreme values
        int[] resultRange = { -1000000, 1000000 };
        
        while (true) {
            int minEl = Integer.MAX_VALUE;
            int maxEl = Integer.MIN_VALUE;
            int minElListIdx = 0;

            // Find the minimum and maximum elements among the current elements in the k lists
            for (int i = 0; i < k; i++) {
                int listIdx = i;
                int elIdx = vec[i];
                int element = nums.get(listIdx).get(elIdx);
                
                if (element < minEl) {
                    minEl = element;
                    minElListIdx = listIdx;
                }
                
                maxEl = Math.max(maxEl, element);
            }

            // If the current range is smaller than the previous one, update resultRange
            if (maxEl - minEl < resultRange[1] - resultRange[0]) {
                resultRange[0] = minEl;
                resultRange[1] = maxEl;
            }

            // Move to the next element in the list that had the minimum element
            int nextIndex = vec[minElListIdx] + 1;
            if (nextIndex >= nums.get(minElListIdx).size()) {
                break;  // If any list is exhausted, we can't move further
            }
            vec[minElListIdx] = nextIndex;
        }

        return resultRange;
    }
}



//Approach-2 (Using heap)
//T.C : O(n*log(k))
//S.C : O(k)
class Solution {
    public int[] smallestRange(List<List<Integer>> nums) {
        int k = nums.size();
        
        // Priority Queue to store {element, listIdx, elementIdx}
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        
        int maxEl = Integer.MIN_VALUE;
        
        // Initialize the priority queue with the first element of each list
        for (int i = 0; i < k; i++) {
            pq.offer(new int[]{nums.get(i).get(0), i, 0});
            maxEl = Math.max(maxEl, nums.get(i).get(0));
        }
        
        // Initialize result range with large numbers
        int[] resultRange = { -1000000, 1000000 };
        
        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int minEl = curr[0];
            int listIdx = curr[1];
            int idx = curr[2];
            
            // Update the result range if the current range is smaller
            if (maxEl - minEl < resultRange[1] - resultRange[0]) {
                resultRange[0] = minEl;
                resultRange[1] = maxEl;
            }
            
            // Try to move to the next element in the list that contained the minimum element
            if (idx + 1 < nums.get(listIdx).size()) {
                int nextElement = nums.get(listIdx).get(idx + 1);
                pq.offer(new int[]{nextElement, listIdx, idx + 1});
                maxEl = Math.max(maxEl, nextElement);  // Update maxEl with the new element
            } else {
                break;  // If one list is exhausted, we can't continue forming valid ranges
            }
        }
        
        return resultRange;
    }
}
