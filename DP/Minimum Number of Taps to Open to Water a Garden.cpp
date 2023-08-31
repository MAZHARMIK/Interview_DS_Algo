/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=zClcHFT9X8E
    Company Tags                : Adobe, Amazon, Housing.com, Moonfrog Labs, OYO Rooms, Saplabs, Walmart
    Leetcode Link               : https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/
    Greedy Approach             : https://www.youtube.com/watch?v=2hzsf3D9Xvw
*/

//Approach-1 (Brute Force)
class Solution {
public:    
    int minTaps(int n, vector<int>& ranges) {
        int min   = 0;
        int max   = 0;
        int count = 0;
        while(max < n) {
            
            //Choose the tap with maximum range it can reach to right
            //For a given min value (to left)
            for(int i = 0; i < n + 1; i++) {
                if(i-ranges[i] <= min && i+ranges[i] > max)
                    max = i+ranges[i];
            }
            
            //It means we couldn't expand our range to right
            if(max == min)
                return -1;
            
            //Now, we have reached till max, next we want to cover more than this max
            //starting from min
            min = max;
            count++;
        }
        
        return count;
    }
};

//Approach-2 (Converting to Jump Game-II)
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> jumps(n+1, 0);
        
        for(int i = 0; i<n+1; i++) {
            int l = max(0, i-ranges[i]);
            int r = min(n, i+ranges[i]);
            
            jumps[l] = max(jumps[l], r-l); //from l, that's farthest I can jump to right
        }
        
        //Now this questions has turned to Jump Game II
        //Where you have maximum jump you can take form an index i and
        //you have to reach end
        
        //This is just Jump Game - II code
        int currEnd  = 0;
        int maxReach = 0;
        int count    = 0;
        for(int i = 0; i<n; i++) {
            maxReach = max(maxReach, jumps[i]+i);
            
            if(i == currEnd) {
                count++;
                currEnd = maxReach;
            }
        }
        
        if(currEnd >= n)
            return count;
        return -1;
    }
};

//Approach-3 (Recursion + Memo)
class Solution {
public:
    map<pair<int,int>,int> mp;
    int N;
    int solve(int i, int maxEnd, vector<pair<int,int>>& range) {
        if(i >= range.size())
            return maxEnd >= N ? 0 : 1e9;

        if(range[i].first > maxEnd)
            return 1e9;

        if(mp.find({i,maxEnd}) != mp.end())
            return mp[{i,maxEnd}];

        int not_open_tap = solve(i+1, maxEnd , range);
        
        int open_tap     = 1 + solve(i+1, max(maxEnd, range[i].second), range);

        return mp[{i, maxEnd}] = min(open_tap, not_open_tap); 
    }
    
    int minTaps(int n, vector<int>& ranges) {
        N = n;
        
        vector<pair<int,int>> range;

        for(int i = 0; i < ranges.size(); i++) {
            
            int start = max(0, i - ranges[i]);
            int end   = min(n, i + ranges[i]);
            
            range.push_back({start, end});
            
        }
        
        sort(range.begin(), range.end());
        
        int ans = solve(0, 0, range);
        
        return ans == 1e9 ? -1 : ans;
    }
};

//Approach-4 (Bottom UP : DP)
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> t(n+1, n+2);
        
        //t[i] = minimum taps needed to cover 0 to ith of Garden
        t[0] = 0; //I need 0 tap to cover 0 to 0
        
        //Why start from i = 0
        //Because value at ranges[0] also impacts the range {i-ranges[i], i+ranges[i]}
        //We will miss that impact if we skip i = 0
        for(int i = 0; i<n+1; i++) {
            
            int l = max(0, i-ranges[i]);
            int r = min(n, i+ranges[i]);
            
            /*
                0 to l is watered
                We now need to find minimum taps to cover from (l+1) to r
            */
            for(int j = l+1; j<=r; j++)
                
                /*
                    Check if this range from(left+1..right) can
                    be watered using less number of taps than previous
                */
                
                t[j] = min(t[j], t[l]+1);
            
        }
        
        //if min taps needed to water ground is greater than (n+1) we return -1
        //Because we only had (n+1) taps
        return t[n] > n+1 ? -1 : t[n];
    }
};
