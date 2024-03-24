/*   Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=saAEj_iL_FQ
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/most-frequent-ids/description/
*/

/************************************************************************* C++ **************************************************************/
//Using Map and Heap
//T.C : O(n^2logn)
//S.C : O(n)
class Solution {
public:
    typedef long long ll;

    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        int n = nums.size();

        unordered_map<ll, ll> mp; //{ID -> freq}
        
        vector<ll> result(nums.size());

        priority_queue<pair<ll, ll>>pq; //{freq, ID} 

        for(int i=0; i <n; i++){
            int ID = nums[i];
            int f  = freq[i];
            
            mp[ID] += f;


            pq.push({mp[ID], ID});

            while(pq.size() > 0 && mp[pq.top().second] != pq.top().first) {
                pq.pop();
            }

            result[i] = pq.top().first;
        }
        return result;
    }
};


/************************************************************************* JAVA **************************************************************/
//Using Map and Heap
//T.C : O(n^2logn)
//S.C : O(n)
public class Solution {
    public long[] mostFrequentIDs(int[] nums, int[] freq) {
        int n = nums.length;

        Map<Long, Long> mp = new HashMap<>(); //{ID -> freq}
        PriorityQueue<long[]> pq = new PriorityQueue<>((a, b) -> Long.compare(b[0], a[0])); //{freq, ID} 

        long[] result = new long[nums.length];

        for(int i = 0; i < n; i++) {
            long ID = nums[i];
            long f = freq[i];

            mp.put(ID, mp.getOrDefault(ID, 0L) + f);

            pq.offer(new long[]{mp.get(ID), ID});

            while (!pq.isEmpty() && mp.get(pq.peek()[1]) != pq.peek()[0]) {
                pq.poll();
            }

            result[i] = pq.peek()[0];
        }
        return result;
    }
}
