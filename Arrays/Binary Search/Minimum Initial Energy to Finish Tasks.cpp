/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Bw0HySng9wo
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/
*/



/****************************************************************** C++ ******************************************************************/
//Approach (Binary search on answer + greedy sorting)
//T.C : O(n*logn)
//S.C : O(1)
class Solution {
public:

    bool isPossible(vector<vector<int>>& tasks, int mid) {
        for(auto &task : tasks) {
            int actual  = task[0];
            int minimum = task[1];

            if(minimum > mid) {
                return false;
            }

            mid -= actual;
        }

        return true;
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();

        int l = 0;
        int r = 1e9;

        int result = INT_MAX;

        auto lambda = [](auto &task1, auto& task2) {
            int diff1 = task1[1] - task1[0];
            int diff2 = task2[1] - task2[0];

            return diff1 > diff2;
        };

        sort(begin(tasks), end(tasks), lambda);


        while(l <= r) {
            int mid = l + (r-l)/2;

            if(isPossible(tasks, mid)) {
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        return result;
    }
};



/****************************************************************** JAVA ******************************************************************/
//Approach (Binary search on answer + greedy sorting)
//T.C : O(n*logn)
//S.C : O(1)
class Solution {

    public boolean isPossible(int[][] tasks, int mid) {

        for(int[] task : tasks) {
            int actual  = task[0];
            int minimum = task[1];

            if(minimum > mid) {
                return false;
            }

            mid -= actual;
        }

        return true;
    }

    public int minimumEffort(int[][] tasks) {

        int n = tasks.length;

        int l = 0;
        int r = (int)1e9;

        int result = Integer.MAX_VALUE;

        Arrays.sort(tasks, (task1, task2) -> {
            int diff1 = task1[1] - task1[0];
            int diff2 = task2[1] - task2[0];

            return diff2 - diff1;
        });

        while(l <= r) {

            int mid = l + (r-l)/2;

            if(isPossible(tasks, mid)) {
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        return result;
    }
}
