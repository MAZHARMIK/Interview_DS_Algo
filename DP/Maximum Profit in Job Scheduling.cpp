/*
    MY YOUTUBE VIDEO ON THIS Qn : Recursion + Memo - https://www.youtube.com/watch?v=LL0tVxlAeV4
                                  Bottom Up        - soon I will upload (You can see the code below)
    Company Tags                : Google, Doordash, Airbnb, Adobe
    Leetcode Link               : https://leetcode.com/problems/maximum-profit-in-job-scheduling/
    Similar Leetcode Qn         : Maximum Number of Events That Can Be Attended II (YouTube  : https://www.youtube.com/watch?v=9ykgLt25X9c)
*/

/******************************************************************* C++ *******************************************************************/
//Approach-1 (Recur + Memo)
//T.C : O(nlogn), where n is the number of jobs
//S.C : O(n), where n is the number of jobs.
class Solution {
public:
    int memo[50001];
    int n;
    //find the first job jiska starting point >= currentJob ka end point
    int getNextIndex(vector<vector<int>>& array, int l, int currentJobEnd) {
        int r = n-1;
        
        int result = n+1;
        
        while(l <= r) {
            int mid = l + (r-l)/2;
            
            if(array[mid][0] >= currentJobEnd) { //we can take this task
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        
        return result;
    }
    
    int solve(vector<vector<int>>& array, int i) {
        if(i >= n)
            return 0;
        
        if(memo[i] != -1)
            return memo[i];
        
        int next  = getNextIndex(array, i+1, array[i][1]);
        
        int taken = array[i][2] + solve(array, next);
        int notTaken = solve(array, i+1);
        
        return memo[i] = max(taken, notTaken);
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();
        
        memset(memo, -1, sizeof(memo));
        
        vector<vector<int>> array(n, vector<int>(3, 0)); //{s, e, p}
        
        for(int i = 0; i<n; i++) {
            array[i][0] = startTime[i];
            array[i][1] = endTime[i];
            array[i][2] = profit[i];
        }
        
        auto comp = [&](auto& vec1, auto& vec2) {
              return vec1[0] <= vec2[0];
        };
        
        //sort kardo according to sart time
        sort(begin(array), end(array), comp);
        
        return solve(array, 0);
    }
};


//Approach-2 (Bttom Up) - Video coming soon
//T.C :  O(nlogn), where n is the number of jobs
//S.C : O(n)
class Solution {
public:
    int binarySearch(const vector<vector<int>>& jobs, int end, int left, int right) {
        int result = -1;  // Initialize result to -1 to handle cases where no job is found

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (jobs[mid][1] <= end) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        int dp[n]; 
        vector<vector<int>> jobs(n, vector<int>(3));

        for(int i = 0; i < n; i++) { 
            jobs[i][0] = startTime[i]; 
            jobs[i][1] = endTime[i]; 
            jobs[i][2] = profit[i]; 
        }

        sort(jobs.begin(), jobs.end(), [](const vector<int>& m, const vector<int>& n) {
            return m[1] < n[1];
        });

        dp[0] = jobs[0][2];

        for (int i = 1; i < n; i++) {
            int prev = 0;

            // Use binary search function to find the previous job
            int lastJobIndex = binarySearch(jobs, jobs[i][0], 0, i - 1);
            if (lastJobIndex != -1) {
                prev = dp[lastJobIndex];
            }

            dp[i] = max(prev + jobs[i][2], dp[i-1]);
        }
        
        return dp[n - 1];
    }
};


//Approach-3 (Same as Approach-2. Here we have used struct and not used binary search) - Video coming soon
//T.C :  O(n^2), where n is the number of jobs
//S.C : O(n)
class Solution {
public:    
    struct job {
        int start; 
        int end; 
        int profit; 
    };
    
    static int sfn(job m, job n) {
        return m.end < n.end;
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
	    int n = startTime.size();
        int dp[n]; 
        vector<job> jobs(n);

	    for(int i = 0; i < n; i++) { 
            jobs[i].start = startTime[i]; 
            jobs[i].end = endTime[i]; 
            jobs[i].profit = profit[i]; 
        }
	    sort(jobs.begin(), jobs.end(), sfn);
        dp[0] = jobs[0].profit;
        // Main code goes here
        for (int i = 1; i < n; i++) {
            int prev = 0;
            for (int j = i - 1; j>=0; j--){
                if (jobs[i].start >= jobs[j].end) {
                    prev = dp[j];
                    break;
                }
            }
            dp[i] = max(prev + jobs[i].profit, dp[i-1]);
        }
        
	    return dp[n - 1];
    }
};


/******************************************************************* JAVA *******************************************************************/
//Approach-1 (Recur + Memo)
//T.C : O(nlogn), where n is the number of jobs
//S.C : O(n), where n is the number of jobs.
class Solution {
    private int[] memo;
    private int n;

    // Find the first job whose starting point >= currentJob's end point
    private int getNextIndex(int[][] array, int l, int currentJobEnd) {
        int r = n - 1;
        int result = n + 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (array[mid][0] >= currentJobEnd) { // we can take this task
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return result;
    }

    private int solve(int[][] array, int i) {
        if (i >= n)
            return 0;

        if (memo[i] != -1)
            return memo[i];

        int next = getNextIndex(array, i + 1, array[i][1]);

        int taken = array[i][2] + solve(array, next);
        int notTaken = solve(array, i + 1);

        return memo[i] = Math.max(taken, notTaken);
    }

    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        n = startTime.length;

        memo = new int[n];
        Arrays.fill(memo, -1);

        int[][] array = new int[n][3]; // {s, e, p}

        for (int i = 0; i < n; i++) {
            array[i][0] = startTime[i];
            array[i][1] = endTime[i];
            array[i][2] = profit[i];
        }

        Arrays.sort(array, Comparator.comparingInt(vec -> vec[0]));

        return solve(array, 0);
    }
}

//Approach-2 (Bttom Up) - Video coming soon
//T.C :  O(nlogn), where n is the number of jobs
//S.C : O(n)
class Solution {
    private int binarySearch(int[][] jobs, int end, int left, int right) {
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (jobs[mid][1] <= end) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }

    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        int n = startTime.length;
        int[][] jobs = new int[n][3];

        for (int i = 0; i < n; i++) {
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }

        Arrays.sort(jobs, Comparator.comparingInt(m -> m[1]));

        int[] dp = new int[n];
        dp[0] = jobs[0][2];

        for (int i = 1; i < n; i++) {
            int prev = 0;
            int lastJobIndex = binarySearch(jobs, jobs[i][0], 0, i - 1);

            if (lastJobIndex != -1) {
                prev = dp[lastJobIndex];
            }

            dp[i] = Math.max(prev + jobs[i][2], dp[i - 1]);
        }

        return dp[n - 1];
    }
}

//Approach-3 (Bottom Up DP) - Video coming soon
//T.C :  O(n^2), where n is the number of jobs
//S.C : O(n)
class Solution {
    class Job {
        int start;
        int end;
        int profit;

        public Job(int start, int end, int profit) {
            this.start = start;
            this.end = end;
            this.profit = profit;
        }
    }

    private static int compareJobs(Job m, Job n) {
        return Integer.compare(m.end, n.end);
    }

    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        int n = startTime.length;
        int[] dp = new int[n];
        Job[] jobs = new Job[n];

        for (int i = 0; i < n; i++) {
            jobs[i] = new Job(startTime[i], endTime[i], profit[i]);
        }

        Arrays.sort(jobs, Comparator.comparingInt(j -> j.end));

        dp[0] = jobs[0].profit;

        for (int i = 1; i < n; i++) {
            int prev = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (jobs[i].start >= jobs[j].end) {
                    prev = dp[j];
                    break;
                }
            }
            dp[i] = Math.max(prev + jobs[i].profit, dp[i - 1]);
        }

        return dp[n - 1];
    }
}
