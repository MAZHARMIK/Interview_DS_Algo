/*	Scroll below to see JAVA code also	*/
/*
	MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=NePJRPCuOwg
    	Company Tags  		    : Uber, Facebook, Microsoft, Yelp, Google, Snapchat, Amazon, Cisco - Qn had small Variations
    	Leetcode Link 		    : https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/
*/


/************************************************************************ C++ ************************************************************************/
//Approach-1 (Naive O(n^2) approach that comes to mind first)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        
        vector<int> endTimes(n, -1); //at max we will have 0 to n-1 chairs
        
        /*
            We need to sort the times based on arrival time but we don't want to
            loose the friend number after sorting. So, store the arrival time
            of targetFriend because it's given in the question that 
            Each arrival time is distinct.
        */
        
        int targetArrivalTime = times[targetFriend][0];
        
        sort(begin(times), end(times));
        
        for(vector<int> &time : times) {
            int arrival = time[0];
            int depart  = time[1];
            //Find the first unoccupied chair
            for(int i = 0; i<n; i++) {
                if(endTimes[i] <= arrival) {
                    endTimes[i] = depart; //update with current friend depart time
                    
                    if(arrival == targetArrivalTime)
                        return i;
                    break;
                }
            }
        }
        return -1;
    }
};


//Approach-2 (Using min-heaps)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    typedef pair<int, int> P;

    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        
        int n = times.size();
        priority_queue<P, vector<P>, greater<P> > occupied; //{departTime, chairNo}
        priority_queue<int, vector<int>, greater<int>> free; //min heap of unoccupied chairs
        
        int targetFriendArrival = times[targetFriend][0];
		
        //Sort based on arrival time
        sort(times.begin(),times.end());
        
		int chairNo = 0;

        for(int i = 0; i < n; i++) {
            int arrival  = times[i][0];
            int depart   = times[i][1];
            
            //free chairs accordingly
            while(!occupied.empty() && occupied.top().first <= arrival) {
                free.push(occupied.top().second); //this chair is now free
                occupied.pop();
            }

            if(free.empty()) {
                occupied.push({depart, chairNo});

                if(arrival == targetFriendArrival)
                    return chairNo;

                chairNo++;
            } else {
                int leastChairAvailable = free.top();
                free.pop();
                if(arrival == targetFriendArrival) {
                    return leastChairAvailable;
                }
                occupied.push({depart, leastChairAvailable});
            }
        }

        return -1;
    }
    
};

//Approach - 3 (min heap + set)
/*
    priority_queue(min heap) - To get the friend with minimum departure time
    ordered_set              - To get the least available chair
*/
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    typedef pair<int, int> p;
    priority_queue<p, vector<p>, greater<p>> pq;
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        
        int targetArrivalTime = times[targetFriend][0];
        
        sort(begin(times), end(times));
        
        set<int> chairNum; //ordered set (we will get the least available chair number in the beginning) (You could also use min heap for this also)
        
        int lastChair = 0;
        
        for(vector<int> &time : times) {
            int arrival  = time[0];
            int depart   = time[1];
            int currSeat = -1;
 
            while(!pq.empty() && pq.top().first <= arrival) {
                chairNum.insert(pq.top().second); //insert the chairs which are being emptied
                pq.pop();
            }

            if(chairNum.empty()) {
                currSeat = lastChair;
                lastChair++;
            } else {
                currSeat = *(chairNum.begin());  //ordered set (we will get the least available chair number in the beginning)
                chairNum.erase(currSeat); //this chair is now occupied
            }
            pq.push({depart, currSeat});
            if(arrival == targetArrivalTime)
                return currSeat;
        }
        
        return -1;
    }
};




/************************************************************************ C++ ************************************************************************/
//Approach-1 (Naive O(n^2) approach that comes to mind first)
//T.C : O(n^2)
//S.C : O(n)




//Approach-2 (Using min-heaps)
//T.C : O(nlogn)
//S.C : O(n)



//Approach - 3 (min heap + set)
/*
    priority_queue(min heap) - To get the friend with minimum departure time
    ordered_set              - To get the least available chair
*/
//T.C : O(nlogn)
//S.C : O(n)
