/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-i
*/


/************************************************************ C++ ************************************************/
//Approach (Using max-heap + sliding window)
//T.C : O(n * k * log(k))
//S.C : O(k)
class Solution {
public:
    typedef pair<int, int> P; //freq, element
    int findTopXSum(unordered_map<int, int>& mp, int x) {
        //min-heap
        priority_queue<P, vector<P>, greater<P>> pq; //O(k) space

        for(auto &it : mp) { //O(k * log(k))
            pq.push({it.second, it.first});

            if(pq.size() > x) {
                pq.pop(); //remove smallest element from the top
            }
        }

        int sum = 0;
        while(!pq.empty()) { //K
            auto [freq, val] = pq.top(); //
            pq.pop(); //log(k)

            sum += freq*val;
        }

        return sum;
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();

        unordered_map<int, int> mp; //O(k)

        vector<int> result;

        int i = 0;
        int j = 0;
        //T.C : O(n * klogk)
        while(j < n) { //khandani sliding window template
            mp[nums[j]]++;

            if(j - i + 1 == k) {
                result.push_back(findTopXSum(mp, x));

                mp[nums[i]]--;
                if(mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                i++;
            }

            j++;
        }

        return result;
    }
};




/************************************************************ JAVA ************************************************/
//Approach (Using max-heap + sliding window)
//T.C : O(n * k * log(k))
//S.C : O(k)
class Solution {
    private int findTopXSum(Map<Integer, Integer> map, int x) {
        PriorityQueue<int[]> pq = new PriorityQueue<>(
            (a, b) -> (a[0] == b[0]) ? a[1] - b[1] : a[0] - b[0]
        );

        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            int freq = entry.getValue();
            int val = entry.getKey();
            pq.offer(new int[]{freq, val});

            if (pq.size() > x) {
                pq.poll();
            }
        }

        int sum = 0;
        while (!pq.isEmpty()) {
            int[] pair = pq.poll();
            sum += pair[0] * pair[1];
        }

        return sum;
    }

    public int[] findXSum(int[] nums, int k, int x) {
        int n = nums.length;
        Map<Integer, Integer> map = new HashMap<>();
        List<Integer> result = new ArrayList<>();

        int i = 0, j = 0;

        while (j < n) {
            map.put(nums[j], map.getOrDefault(nums[j], 0) + 1);

            if (j - i + 1 == k) {
                result.add(findTopXSum(map, x));

                map.put(nums[i], map.get(nums[i]) - 1);
                if (map.get(nums[i]) == 0) map.remove(nums[i]);
                i++;
            }

            j++;
        }

        return result.stream().mapToInt(Integer::intValue).toArray();
    }
}
