/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=cH6VFgRaRW0
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/minimum-operations-to-equalize-binary-string/description/
*/


/************************************************************ C++ ************************************************/
//Approach-1 - Brute Force
//T.C : O(n*k) ~ O(n^2)
//S.C : O(n)
class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.length();

        int startZeros = 0;
        for(char &ch : s) {
            if(ch == '0')
                startZeros++;
        }

        if(startZeros == 0) {
            return 0; //no operations required
        }

        vector<int> operations(n+1, -1);
        //operations[z] = min operations required to reach state in which we have z 0s

        queue<int> que;
        que.push(startZeros);
        operations[startZeros] = 0;

        while(!que.empty()) {
            int z = que.front();
            que.pop();

            int minF = max(0, k-n+z);
            int maxF = min(k, z);

            for(int f = minF; f <= maxF; f++) {
                int newZ = z + k - 2*f;

                if(operations[newZ] == -1) {
                    operations[newZ] = operations[z] + 1;

                    if(newZ == 0) {
                        return operations[newZ];
                    }

                    que.push(newZ);
                }
            }
        }

        return -1;
    }
};


//Approach-2 - Optimal - Skipping already visited states
//T.C : O(n*logn)
//S.C : O(n)
class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.length();

        int startZeros = 0;
        for(char &ch : s) {
            if(ch == '0')
                startZeros++;
        }

        if(startZeros == 0) {
            return 0; //no operations required
        }

        vector<int> operations(n+1, -1);
        //operations[z] = min operations required to reach state in which we have z 0s

        set<int> evenSet;
        set<int> oddSet;

        for(int count = 0; count <= n; count++) {
            if(count%2 == 0) {
                evenSet.insert(count);
            } else {
                oddSet.insert(count);
            }
        }

        queue<int> que;
        que.push(startZeros);
        operations[startZeros] = 0;
        if(startZeros % 2 == 0) {
            evenSet.erase(startZeros);
        } else {
            oddSet.erase(startZeros);
        }

        while(!que.empty()) {
            int z = que.front();
            que.pop();
            
            int min_new_z = z + k - 2*min(k, z);
            int max_new_z = z + k - 2*max(0, k-n+z);

            set<int> &currSet = (min_new_z%2 == 0) ? evenSet : oddSet;

            auto it = currSet.lower_bound(min_new_z);

            while(it != currSet.end() && *it <= max_new_z) {
                int newZ = *it;

                if(operations[newZ] == -1) {
                    operations[newZ] = operations[z] + 1;

                    if(newZ == 0) {
                        return operations[newZ];
                    }

                    que.push(newZ);
                }

                it = currSet.erase(it);
            }
        }

        return -1;
    }
};


/************************************************************ JAVA ************************************************/
//Approach-1 - Brute Force
//T.C : O(n*k) ~ O(n^2)
//S.C : O(n)
class Solution {
    public int minOperations(String s, int k) {

        int n = s.length();

        int startZeros = 0;
        for(char ch : s.toCharArray()) {
            if(ch == '0')
                startZeros++;
        }

        if(startZeros == 0)
            return 0;

        int[] operations = new int[n+1];
        Arrays.fill(operations, -1);

        Queue<Integer> queue = new LinkedList<>();
        queue.offer(startZeros);

        operations[startZeros] = 0;

        while(!queue.isEmpty()) {

            int z = queue.poll();

            int minF = Math.max(0, k - n + z);
            int maxF = Math.min(k, z);

            for(int f = minF; f <= maxF; f++) {

                int newZ = z + k - 2*f;

                if(operations[newZ] == -1) {

                    operations[newZ] = operations[z] + 1;

                    if(newZ == 0)
                        return operations[newZ];

                    queue.offer(newZ);
                }
            }
        }

        return -1;
    }
}


//Approach-2 - Optimal - Skipping already visited states
//T.C : O(n*logn)
//S.C : O(n)
class Solution {
    public int minOperations(String s, int k) {

        int n = s.length();

        int startZeros = 0;
        for(char ch : s.toCharArray()) {
            if(ch == '0')
                startZeros++;
        }

        if(startZeros == 0)
            return 0;

        int[] operations = new int[n+1];
        Arrays.fill(operations, -1);

        TreeSet<Integer> evenSet = new TreeSet<>();
        TreeSet<Integer> oddSet = new TreeSet<>();

        for(int count = 0; count <= n; count++) {
            if(count % 2 == 0)
                evenSet.add(count);
            else
                oddSet.add(count);
        }

        Queue<Integer> queue = new LinkedList<>();

        queue.offer(startZeros);
        operations[startZeros] = 0;

        if(startZeros % 2 == 0)
            evenSet.remove(startZeros);
        else
            oddSet.remove(startZeros);

        while(!queue.isEmpty()) {

            int z = queue.poll();

            int minNewZ = z + k - 2*Math.min(k, z);
            int maxNewZ = z + k - 2*Math.max(0, k-n+z);

            TreeSet<Integer> currSet =
                    (minNewZ % 2 == 0) ? evenSet : oddSet;

            Integer val = currSet.ceiling(minNewZ); // lower_bound

            while(val != null && val <= maxNewZ) {

                int newZ = val;

                operations[newZ] = operations[z] + 1;

                if(newZ == 0)
                    return operations[newZ];

                queue.offer(newZ);

                currSet.remove(val);

                val = currSet.ceiling(minNewZ);
            }
        }

        return -1;
    }
}
