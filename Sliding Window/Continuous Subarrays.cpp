/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn   : 
    Company Tags                  : Will update soon
    Leetcode Link                 : https://leetcode.com/problems/continuous-subarrays
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 (Using Ordered Map)
//T.C : ~O(n) - Explained in the video why O(n) ?
//S.C : ~O(1) - Explained in the video why O(1) ?
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();

        map<int, int> mp;

        int i = 0;
        int j = 0;

        long long count = 0;

        while(j < n) {
            mp[nums[j]]++;
            
            while(abs(mp.rbegin()->first - mp.begin()->first) > 2) { //it means it is out of the bound
                //shrink window -move i index
                mp[nums[i]] -= 1;
                if(mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                i++;
            }

            count += j-i+1;
            j++;
        }

        return count;
    }
};



//Approach-2 (Using Ordered Map)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    #define P pair<int, int>

    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();

        priority_queue<P, vector<P>, greater<P>> minHeap;
        priority_queue<P> maxHeap;


        int i = 0;
        int j = 0;
        long long count = 0;

        while(j < n) { //O(n)
            minHeap.push({nums[j], j}); //Log(n)
            maxHeap.push({nums[j], j}); //Log(n)

            while(abs(maxHeap.top().first - minHeap.top().first) > 2) {
                i++;

                while(!maxHeap.empty() && maxHeap.top().second < i) {
                    maxHeap.pop();
                }

                while(!minHeap.empty() && minHeap.top().second < i) {
                    minHeap.pop();
                }
            }

            count += j-i+1;
            j++;
        }
        //T.C: O(nlogn)
        return count;
    }
};



/**************************************************************** JAVA ****************************************************************/
//Approach-1 (Using Ordered Map)
//T.C : ~O(n) - Explained in the video why O(n) ?
//S.C : ~O(1) - Explained in the video why O(1) ?
class Solution {
    public long continuousSubarrays(int[] nums) {
        int n = nums.length;
        TreeMap<Integer, Integer> map = new TreeMap<>();
        int i = 0, j = 0;
        long count = 0;

        while (j < n) {
            map.put(nums[j], map.getOrDefault(nums[j], 0) + 1);

            while (Math.abs(map.lastKey() - map.firstKey()) > 2) {
                map.put(nums[i], map.get(nums[i]) - 1);
                if (map.get(nums[i]) == 0) {
                    map.remove(nums[i]);
                }
                i++;
            }

            count += j - i + 1;
            j++;
        }

        return count;
    }
}



//Approach-2 (Using Ordered Map)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
    public long continuousSubarrays(int[] nums) {
        int n = nums.length;

        // Min-heap for smallest elements
        PriorityQueue<int[]> minHeap = new PriorityQueue<>((a, b) -> Integer.compare(a[0], b[0]));
        // Max-heap for largest elements
        PriorityQueue<int[]> maxHeap = new PriorityQueue<>((a, b) -> Integer.compare(b[0], a[0]));

        int i = 0, j = 0;
        long count = 0;

        while (j < n) {
            // Add the current element to both heaps
            minHeap.offer(new int[]{nums[j], j});
            maxHeap.offer(new int[]{nums[j], j});

            // Maintain the condition that the difference between max and min <= 2
            while (Math.abs(maxHeap.peek()[0] - minHeap.peek()[0]) > 2) {
                i++;

                // Remove elements outside the current window from the maxHeap
                while (!maxHeap.isEmpty() && maxHeap.peek()[1] < i) {
                    maxHeap.poll();
                }

                // Remove elements outside the current window from the minHeap
                while (!minHeap.isEmpty() && minHeap.peek()[1] < i) {
                    minHeap.poll();
                }
            }

            // Add the number of valid subarrays ending at index j
            count += j - i + 1;
            j++;
        }

        return count;
    }
}
