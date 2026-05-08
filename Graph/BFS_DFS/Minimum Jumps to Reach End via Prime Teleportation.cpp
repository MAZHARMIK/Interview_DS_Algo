/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=lP3TWBQv1zs
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/minimum-jumps-to-reach-end-via-prime-teleportation
*/



/****************************************************************** C++ ******************************************************************/
//Approach (Using BFS + Sieve)
//T.C : O(maxEL * loglog(maxEl))
//S.C : O(maxEl + n)
class Solution {
public:
    vector<bool> isPrime;
    
    void buildSieve(int maxEl) {
        //fill isPrime
        isPrime.resize(maxEl+1, true);

        isPrime[0] = false;
        isPrime[1] = false;

        for(int num = 2; num*num <= maxEl; num++) {
            if(isPrime[num]) {

                for(int multiple = num*num; multiple <= maxEl; multiple += num) {
                    isPrime[multiple] = false;
                }
            }
        }
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, vector<int>> mp; //element -> indices
        int maxEl = 0;
        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
            maxEl = max(maxEl, nums[i]);
        }

        //build isPrime vector using Sieve
        buildSieve(maxEl); //O(maxEL * loglog(maxEl));

        queue<int> que;
        vector<bool> visited(n, false);
        que.push(0);
        visited[0] = true;

        unordered_set<int> seen;

        int steps = 0;
        //We visite each node only once - O(n)
        //O(n + maxEL * loglog(maxEl));
        while(!que.empty()) {
            int size = que.size();
            
            while(size--) {
                int i = que.front();
                que.pop();

                if(i == n-1) {
                    return steps;
                }

                if(i-1 >= 0 && !visited[i-1]) {
                    que.push(i-1);
                    visited[i-1] = true;
                }

                if(i+1 <= n-1 && !visited[i+1]) {
                    que.push(i+1);
                    visited[i+1] = true;
                }

                if(!isPrime[nums[i]] || seen.count(nums[i])) {
                    continue;
                }

                for(int multiple = nums[i]; multiple <= maxEl; multiple += nums[i]) {
                    if(!mp.contains(multiple)) {
                        continue;
                    }

                    for(int &j : mp[multiple]) {
                        if(!visited[j]) {
                            que.push(j);
                            visited[j] = true;
                        }
                    }
                }

                seen.insert(nums[i]);
            }

            steps++;
        }

        return steps;
    }
};



/****************************************************************** JAVA ******************************************************************/
//Approach (Using BFS + Sieve)
//T.C : O(maxEL * loglog(maxEl))
//S.C : O(maxEl + n)
class Solution {

    private boolean[] isPrime;

    private void buildSieve(int maxEl) {

        isPrime = new boolean[maxEl + 1];
        Arrays.fill(isPrime, true);

        if(maxEl >= 0) isPrime[0] = false;
        if(maxEl >= 1) isPrime[1] = false;

        for(int num = 2; num * num <= maxEl; num++) {

            if(isPrime[num]) {

                for(int multiple = num * num;
                    multiple <= maxEl;
                    multiple += num) {

                    isPrime[multiple] = false;
                }
            }
        }
    }

    public int minJumps(int[] nums) {

        int n = nums.length;

        HashMap<Integer, List<Integer>> mp = new HashMap<>();
        int maxEl = 0;

        for(int i = 0; i < n; i++) {

            mp.computeIfAbsent(nums[i], k -> new ArrayList<>()).add(i);

            maxEl = Math.max(maxEl, nums[i]);
        }

        buildSieve(maxEl);

        Queue<Integer> queue = new LinkedList<>();
        boolean[] visited = new boolean[n];

        queue.offer(0);
        visited[0] = true;

        HashSet<Integer> seen = new HashSet<>();

        int steps = 0;

        while(!queue.isEmpty()) {

            int size = queue.size();

            while(size-- > 0) {

                int i = queue.poll();

                if(i == n - 1) {
                    return steps;
                }

                // i - 1
                if(i - 1 >= 0 && !visited[i - 1]) {

                    queue.offer(i - 1);
                    visited[i - 1] = true;
                }

                // i + 1
                if(i + 1 < n && !visited[i + 1]) {

                    queue.offer(i + 1);
                    visited[i + 1] = true;
                }

                // skip if not prime or already processed
                if(!isPrime[nums[i]] || seen.contains(nums[i])) {
                    continue;
                }

                // visit all multiples
                for(int multiple = nums[i];
                    multiple <= maxEl;
                    multiple += nums[i]) {

                    if(!mp.containsKey(multiple)) {
                        continue;
                    }

                    for(int j : mp.get(multiple)) {

                        if(!visited[j]) {

                            queue.offer(j);
                            visited[j] = true;
                        }
                    }
                }

                seen.add(nums[i]);
            }

            steps++;
        }

        return -1;
    }
}
