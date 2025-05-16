/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=c-hV30Ffj6o
    Company Tags                : Will update later
    Leetcode Link               : https://leetcode.com/problems/choose-k-elements-with-maximum-sum
*/

/************************************************************ C++ ************************************************************/
//Approach-1 (Brute Force) - TLE
//T.C : O(n * (nlogk + klogk))
//S.C : O(n*k)
class Solution {
public:
    typedef long long ll;
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int n = nums1.size();

        vector<ll> result(n, 0);

        //O(n * ((nlogk) + (klogk)))
        for(int i = 0; i < n; i++) { //O(n)
            priority_queue<int, vector<int>, greater<int>> pq;
            for(int j = 0; j < n; j++) { //O(n * log(k))
                if(nums1[j] < nums1[i]) {
                    //jth index is the valid candidate
                    //Find the element in nums2 at jth index
                    pq.push(nums2[j]); //O(log(k))
                    if(pq.size() > k) {
                        pq.pop(); //O(log(k))
                    }
                }
            }

            long long sum = 0;
            while(!pq.empty()) { //K
                sum += pq.top();
                pq.pop(); //O(logk)
            }

            result[i] = sum;
        }

        return result;
    }
};



//Approach-2 (Using sorting and heap)
//T.C : O(n + nlogn + nlogk)
//S.C : O(n + k)
class Solution {
public:
    typedef long long ll;
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();

        vector<vector<int>> vec(n); //vec[i] = {nums1[i], i, nums2[i]}
        for(int i = 0; i < n; i++) { //O(n)
            vec[i] = {nums1[i], i, nums2[i]};
        }

        sort(begin(vec), end(vec)); //O(nlogn)

        vector<ll> result(n, 0);
        priority_queue<int, vector<int>, greater<int>> pq;
        ll sum = 0;

        for(int i = 0; i < n; i++) { //O(nlogk)
            if(i > 0 && vec[i-1][0] == vec[i][0]) {
                ll ans = result[vec[i-1][1]]; 
                result[vec[i][1]] = ans;
            } else {
                result[vec[i][1]] = sum;
            }

            pq.push(vec[i][2]);
            sum += vec[i][2];
            if(pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
        }

        return result;

    }
};



/************************************************************ JAVA ************************************************************/
/************************************************************ Java ************************************************************/

//Approach-1 (Brute Force) - TLE
//T.C : O(n * (nlogk + klogk))
//S.C : O(n*k)
class Solution {
    public long[] findMaxSum(int[] nums1, int[] nums2, int k) {
        int n = nums1.length;
        long[] result = new long[n];

        //O(n * ((nlogk) + (klogk)))
        for (int i = 0; i < n; i++) { //O(n)
            PriorityQueue<Integer> pq = new PriorityQueue<>();
            for (int j = 0; j < n; j++) { //O(n * log(k))
                if (nums1[j] < nums1[i]) {
                    //jth index is the valid candidate
                    //Find the element in nums2 at jth index
                    pq.add(nums2[j]); //O(log(k))
                    if (pq.size() > k) {
                        pq.poll(); //O(log(k))
                    }
                }
            }

            long sum = 0;
            while (!pq.isEmpty()) { //K
                sum += pq.poll(); //O(logk)
            }

            result[i] = sum;
        }

        return result;
    }
}

//Approach-2 (Using sorting and heap)
//T.C : O(n + nlogn + nlogk)
//S.C : O(n + k)
class Solution {
    public long[] findMaxSum(int[] nums1, int[] nums2, int k) {
        int n = nums1.length;
        int[][] vec = new int[n][3]; //vec[i] = {nums1[i], i, nums2[i]}
        for (int i = 0; i < n; i++) { //O(n)
            vec[i][0] = nums1[i];
            vec[i][1] = i;
            vec[i][2] = nums2[i];
        }

        Arrays.sort(vec, (a, b) -> Integer.compare(a[0], b[0])); //O(nlogn)

        long[] result = new long[n];
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        long sum = 0;

        for (int i = 0; i < n; i++) { //O(nlogk)
            if (i > 0 && vec[i - 1][0] == vec[i][0]) {
                long ans = result[vec[i - 1][1]];
                result[vec[i][1]] = ans;
            } else {
                result[vec[i][1]] = sum;
            }

            pq.add(vec[i][2]);
            sum += vec[i][2];
            if (pq.size() > k) {
                sum -= pq.poll();
            }
        }

        return result;
    }
}
