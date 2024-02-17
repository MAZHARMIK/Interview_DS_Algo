/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=dUkdAjY23p8
    Company Tags    		: Microsoft, Google
    Leetcode Link   		: https://leetcode.com/problems/furthest-building-you-can-reach/
    Similar Problem 		: https://leetcode.com/problems/minimum-number-of-refueling-stops/
    
    This is actually a concept of Lazy Greedy Problem (Using priority_queue)
*/

//(GREEDY - FAIL. WRONG APPROACH. SEE below to find out why ?)
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        //greedily I'll use bricks because ladder helps me to jump to next
	//building irrespective of the height difference
        
        int n = heights.size();
        int i = 0;
        for( ; i<n-1 ; i++) {
            if(heights[i] >= heights[i+1]) {
                continue;
            }
            
            int diff = heights[i+1] - heights[i];
            if(bricks >= diff) {
                bricks -= diff;
                continue;
            }
            
            if(ladders > 0) {
                ladders--;
            } else
                break;
        }
        return i;
    }
};

Why above fails ?
Let's take an example :
[1,5,1,2,3,4,10000]
4
1
Initially:
bricks = 4
ladder = 1

        For, 1->5
        If I use bricks,
        bricks  = 4 - (5-1) = 0
        ladders = 1
        
        Now, 
        5->1 costs nothing
        
        For, 1->2
        I will use my only ladder
        bricks  = 0
        ladders = 0
        
        So, i reached till 2 (i.e. index 3 only) WRONG ANSWER
        
        -----------------------
        Now, if i had used ladder from 1->5, let's see what difference it
		would have created
        For, 1->5
        If I use ladder this time,
        bricks  = 4
        ladders = 0
        
        Now, 
        5->1 costs nothing
        
        For, 1->2
        I will use bricks
        bricks  = 4 - (2-1) = 3
        ladders = 0
        
        Now, for 2->3, I have bricks which can help me (as I need only (3-2) brick out of 3 bricks available)
        bricks  = 3 - (3-2) = 2
        ladders = 0
        
        For 3->4, I have bricks which can help me (as I need only (4-3) brick out of 2 bricks available)
        bricks  = 2 - (4-3) = 1
        ladders = 0
        
        Now, I can't go to 1000 from 4.
        So, I reached till 4 (i.e. index 5) RIGHT ANSWER
        
        So, what to do ?
        Just keep track of maximum amount of bricks you had used in past (say maxBricks). 
        Before, using a ladder, have look that the curr difference(diff = heights[i+1]-heights[i]) is smaller
        than last maximum amount of bricks you had used. So, we can regain those bricks and use a ladder    
        instead in the past. This way, you saved (maxBricks - diff) amount of bricks which can be used later



/***************************************************************** C++ *****************************************************************/
//Accepted Approach
//Using Lazy Greedy
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {      
        int n = heights.size();
    
        priority_queue<int> pq;
        
        int i = 0;
        for(;i < n-1;i++) {
            if(heights[i] >= heights[i+1]) {
                continue;
            }
            
            int diff = heights[i+1]-heights[i];
            if(diff <= bricks) {
                bricks -= diff;
                pq.push(diff); //I used diff bricks here (keep track of it)
            } else if(ladders > 0) {
                if(!pq.empty()) {
                    int max_bricks_past = pq.top();
                    if(max_bricks_past > diff) {
                        //it means i unneccasrily used huge bricks in past. Let's get it back
                        bricks += max_bricks_past;
                        pq.pop();
                        pq.push(diff);
                        bricks -= diff;
                    }
                }
                ladders--; //either used in past or present
            } else {
                break;
            }
        }
        return i;
    }
};


//Approach-2 (Recursion + Memoization) - Memory Limit Exceed due to high constraint
//Link - https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/DP/Furthest%20Building%20You%20Can%20Reach.cpp



/***************************************************************** JAVA *****************************************************************/
//Accepted Approach
//Using Lazy Greedy
//T.C : O(nlogn)
//S.C : O(n)
public class Solution {
    public int furthestBuilding(int[] heights, int bricks, int ladders) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

        for (int i = 0; i < heights.length - 1; i++) {
            if (heights[i] >= heights[i + 1]) continue;
            bricks -= heights[i + 1] - heights[i];
            pq.add(heights[i + 1] - heights[i]);

            if (bricks < 0) {
                bricks += pq.poll();
                if (ladders > 0) ladders--;
                else return i;
            }
        }

        return heights.length - 1;
    }
}
