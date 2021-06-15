 //Recur+Memo -> TLE : Time : O(N*K) after memoization
class Solution {
public:
    int maxScore = INT_MIN;
    int K;
    int n;
    unordered_map<int, int> mp;

    int maxScoreUtilRecursionMemo(vector<int>& nums, int idx) {
        if(idx == n-1) {
            return nums[idx];
        }
        if(mp.find(idx) != mp.end())
            return mp[idx];
        
        int maxScore = INT_MIN;
        for(int i = idx+1; i<=min(idx+K, n-1); i++) {
            maxScore = max(maxScore, maxScoreUtilRecursionMemo(nums, i));
        }
        
        return mp[idx] = nums[idx] + maxScore;
    }
	
	int maxResult(vector<int>& nums, int k) {
		n = nums.size();
		K = k;
		return maxScoreUtilRecursionMemo(nums, 0);        
    	}
};

//DP -> TLE : Time : O(N*K) :For every index i, we find best element among
//elements at {i+1, i+2, ... i+k}
class Solution {
public:
    int maxScore = INT_MIN;
    int K;
    int n;

    int maxScoreUtilBottomUp(vector<int>& nums) {
        vector<int> t(n, -1);
        //t[i] = maximum score to reach end from index i
        t[n-1] = nums[n-1];
        for(int i = n-2; i>=0; i--) {
            int maxNextStep = INT_MIN;
            for(int j = 1; j<=K; j++) {
                maxNextStep = max(maxNextStep, t[min(i+j, n-1)]);
            }
            
            t[i] = nums[i] + maxNextStep;
        }
        return t[0];
    }
	
	int maxResult(vector<int>& nums, int k) {
        n = nums.size();
        K = k;
        
        return maxScoreUtilBottomUp(nums);   
    }
	

//Accepted : O(N), we store the max element among k sized window
//in monotonic decreasing deque
class Solution {
public:
    int maxScore = INT_MIN;
    int K;
    int n;
	
    int maxScoreUtilOptimized(vector<int>& nums) {
        vector<int> t(n, -1);
        //t[i] = maximum score to reach end from index i
        t[n-1] = nums[n-1];
        
        deque<int> deq;
        
        deq.push_back(n-1);
        
        for(int i = n-2; i>=0; i--) {
            
            //first remove those(maximum values) who are out of index
            while(!deq.empty() && deq.front() > i+K)
                deq.pop_front();
            
            t[i] = nums[i] + t[deq.front()];
            
            //maintaining monotonic decreasing deque
            while(!deq.empty() && t[deq.back()] <= t[i]) {
                deq.pop_back();
            }
            deq.push_back(i);
        }
        return t[0];
    }

    int maxResult(vector<int>& nums, int k) {
        n = nums.size();
        K = k;
               
        return maxScoreUtilOptimized(nums);
    }
};
