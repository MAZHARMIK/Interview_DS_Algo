/*
    Company Tags    : Google
    Leetcode Link   : https://leetcode.com/problems/minimum-number-of-refueling-stops/
    Similar Problem : Leetcode 1642. Furthest Building You Can Reach
*/

//Approach-1 ( O(n^2) DP)
typedef unsigned long long ull;
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        
        vector<vector<ull>> t(n+1, vector<ull>(n+1, 0));
        //t[i][j] = Maximum distance reached if I stopped at 'j' fuelStops from total of 'i' fuelStops
        //i.e. j <= i
        
        //If j = 0, i.e. I did not use any fuelStops, Then maximum I can reach is 'startFuel' which I had initially
        
        //So, initialize the dp array with this information
        for(int i = 0; i<n+1; i++) {
            t[i][0] = startFuel;
        }
        
        //There is no point of filling 1st row because 
        //t[0][j] means I used j fuelStops from 0 fuelStops which doesn't make any sense for (j>0)
        //That's why I start from i = 1 and obviously j = 1 because for j = 0 we already populated the dp array
        
        for(int i = 1; i < n+1; i++) {
            for(int j = 1; j <= i; j++) { //I can use j=1 to j=i fuel stops and find max distance for t[i][j]
                //case-1 (I don't refuel at current fuelstop)
                //If I didn't refuel at current stop, the max distance I can cover is equal to maximum
                //distance I could cover from previous state
                t[i][j] = t[i-1][j];
                
                //case-2 (I will refuel at current fuelStop)
                //But check if you can even reach this station (stations[i-1][0]) or not from your previous station
                if(t[i-1][j-1] >= stations[i-1][0]) {
                    t[i][j] = max(t[i][j], t[i-1][j-1] + stations[i-1][1]);
                }
                
            }
        }
        
        //After you end up with all stations, check which t[n][j] was best for reaching target
        //Best means, minimum j used by you to reach target
        for(int j = 0; j<n+1; j++) {
            if(t[n][j] >= target)
                return j;
        }
        
        //You could never reach target, so return -1
        return -1;
    }
};


//Approach-2 : O(n) dp
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        
        vector<long long> t(n+1, 0);
        //t[j] = max distance that I can reach using j fuelStops
        
        //When I don't use any fuelStop, I can travel as much as I had startFuel in the beginning
        t[0] = startFuel;
        
        for(int i = 1; i<n+1; i++) {
            //traverse on all fuel stops
            
            //I can use all i fuelStops, or (i-1), or (i-2) ... till 0 to find which gave me best result
            //So. j goes from j = i to j = 0
            for(int j = i; j>=0; j--) {
                //But first, I need to check If I can even reach curr station or not to use it
                if(t[j] >= stations[i-1][0]) {
                    //So, we can u se this fuelStop and now we are using t[j+1] fuelStops
                    t[j+1] = max(t[j+1], t[j] + stations[i-1][1]);
                }
            }
        }
        
        //After you end up with all stations, check which was best for reaching target
        //Best means, minimum j used by you to reach target
        
        for(int j = 0; j<n+1; j++) {
            if(t[j] >= target)
                return j;
        }
        
        return -1;
    }
};


//Approach-3 : O(nlog(n)) using max-heap
//Similar Problem : Leetcode 1642. Furthest Building You Can Reach
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        
        priority_queue<int> pq; //max heap
        /*
			if we can't reach target, I will first use the largestfuel Station
			(which can take me farthest) and move ahead and keep doing this.
        */
        int curr = startFuel; //my current position
        int i = 0; //station index
        int result = 0;
        while(curr < target) { //until I reach my target
            while(i < n && curr >= stations[i][0]) {
                /*
					  Sice, I am already ahead of or at this station
					  (i.e. curr >= stations[i][0])  we don't use this
					  station and try to move ahead but I store this
					  station in maxheap to use in future
				*/
                pq.push(stations[i][1]);
				//Keep the station at top which can take me farthest (maximum gas)
                i++;
            }
            
            if(pq.empty()) //we can't move further now
                return -1;
            
            int dist = pq.top();
            pq.pop();
            
            curr += dist;
            result++;
        }
        
        return result;
        
    }
};
