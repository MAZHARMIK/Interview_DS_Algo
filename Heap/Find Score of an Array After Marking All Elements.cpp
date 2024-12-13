/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=VsMVlAPolXw
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements
*/

/************************************************************ C++ ************************************************************/
//Approach-1 (Sorting array with indices)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> vec(n);

        for(int i = 0; i < n; i++) {
            vec[i] = {nums[i], i};
        }

        sort(begin(vec), end(vec)); //O(nlogn)

        long long score = 0;
        vector<bool> visited(n, false);

        for(int i = 0; i < n; i++) { //O(n)
            int element = vec[i].first;
            int idx     = vec[i].second;
            if(visited[idx] == false) {
                visited[idx] = true;
                score += element;

                if(idx-1 >= 0 && visited[idx-1] == false) {
                    visited[idx-1] = true;
                }
                if(idx+1 < n && visited[idx+1] == false) {
                    visited[idx+1] = true;
                }
            }
        }

        return score;
    }
};



//Approach-2 (Using min-heap)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    #define P pair<int, int>
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false);

        priority_queue<P, vector<P>, greater<P>> pq;
        for(int i = 0; i < n; i++) {//n
            pq.push({nums[i], i}); //log(n)
        }

        long long score = 0;
        while(!pq.empty()) { //n
            P temp = pq.top();
            int element = temp.first;
            int idx = temp.second;
            pq.pop(); //log(n)

            if(!visited[idx]) {
                visited[idx] = true;
                score += element;

                if(idx-1 >= 0 && !visited[idx-1]) {
                    visited[idx-1] = true;
                }
                if(idx+1 < n && !visited[idx+1]) {
                    visited[idx+1] = true;
                }
            }
        }

        return score;
    }
};


/************************************************************ JAVA ************************************************************/
//Approach-1 (Sorting array with indices)
//T.C : O(nlogn)
//S.C : O(n)
import java.util.Arrays;

class Solution {

    public long findScore(int[] nums) {
        int n = nums.length;
        long score = 0;

        // Create an array of pairs (value, index)
        int[][] pairs = new int[n][2];
        for (int i = 0; i < n; i++) {
            pairs[i][0] = nums[i];
            pairs[i][1] = i;
        }

        // Sort the pairs by value, and by index if values are equal
        Arrays.sort(pairs, (a, b) -> {
            if (a[0] != b[0]) return Integer.compare(a[0], b[0]);
            return Integer.compare(a[1], b[1]);
        });

        boolean[] visited = new boolean[n];

        // Process the sorted pairs
        for (int i = 0; i < n; i++) {
            int value = pairs[i][0];
            int index = pairs[i][1];

            if (!visited[index]) {
                score += value;
                visited[index] = true;

                // Mark adjacent indices as visited
                if (index - 1 >= 0) {
                    visited[index - 1] = true;
                }
                if (index + 1 < n) {
                    visited[index + 1] = true;
                }
            }
        }

        return score;
    }
}


//Approach-2 (Using min-heap)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {

    public long findScore(int[] nums) {
        int n = nums.length;
        boolean[] visited = new boolean[n];
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
            if (a[0] != b[0]) return Integer.compare(a[0], b[0]);
            return Integer.compare(a[1], b[1]);
        });

        // Populate the priority queue
        for (int i = 0; i < n; i++) {
            pq.add(new int[] { nums[i], i });
        }

        long score = 0;

        // Process the elements in the priority queue
        while (!pq.isEmpty()) {
            int[] element = pq.poll();
            int value = element[0];
            int index = element[1];

            if (!visited[index]) {
                score += value;
                visited[index] = true;

                // Mark adjacent indices as visited
                if (index - 1 >= 0) {
                    visited[index - 1] = true;
                }
                if (index + 1 < n) {
                    visited[index + 1] = true;
                }
            }
        }

        return score;
    }
}
