/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=r2LPa779amQ
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/time-needed-to-buy-tickets/
*/

/*********************************************************** C++ **************************************************/
//Approach-1 (Using Queue to simply simulate the operations)
//T.C : O(n*m) -> Loop runs until queue is empty and in worst case all people have maximum m tickets 
//S.C : O(n)
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        queue<int> que;

        for (int i = 0; i < n; i++) {
            que.push(i);
        }

        int time = 0;

        while (!que.empty()) {
            time++;
            int front = que.front();
            que.pop();
            
            tickets[front]--;
            
            if (k == front && tickets[front] == 0) {
                return time;
            }
            if (tickets[front] != 0) {
                que.push(front);
            }
        }

        return time;
    }
};


//Approach-2 (Using Array for simulation)
//T.C : O(m*n) - Outer loop will run until nums[k] is 0. So in worst case nums[k] has max value m 
//S.C : O(1)
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int time = 0;

        if (tickets[k] == 1)
            return k + 1;

        while (tickets[k] > 0) {
            for (int i = 0; i < n; i++) {

                if (tickets[i] != 0) {
                    tickets[i]--;
                    time++;
                }

                if (tickets[k] == 0)
                    return time;
            }
        }

        return time;
    }
};


//Approach-3 (Using simple observation)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        
        for (int i = 0; i < tickets.size(); i++) {
            
            if (i <= k) {
                time += min(tickets[k], tickets[i]);
            } else {
                time += min(tickets[k] - 1, tickets[i]);
            }
        }
        
        return time;
    }
};


/*********************************************************** JAVA **************************************************/
// Approach-1: Using Queue to simulate the operations
// Time Complexity: O(n*m)
// Space Complexity: O(n)
import java.util.LinkedList;
import java.util.Queue;

class SolutionApproach1 {
    public int timeRequiredToBuy(int[] tickets, int k) {
        int n = tickets.length;
        Queue<Integer> que = new LinkedList<>();

        for (int i = 0; i < n; i++) {
            que.add(i);
        }

        int time = 0;

        while (!que.isEmpty()) {
            time++;
            int front = que.poll();
            tickets[front]--;
            
            if (k == front && tickets[front] == 0) {
                return time;
            }
            if (tickets[front] != 0) {
                que.add(front);
            }
        }

        return time;
    }
}

// Approach-2: Using Array for simulation
// Time Complexity: O(m*n)
// Space Complexity: O(1)
class SolutionApproach2 {
    public int timeRequiredToBuy(int[] tickets, int k) {
        int n = tickets.length;
        int time = 0;

        if (tickets[k] == 1)
            return k + 1;

        while (tickets[k] > 0) {
            for (int i = 0; i < n; i++) {

                if (tickets[i] != 0) {
                    tickets[i]--;
                    time++;
                }

                if (tickets[k] == 0)
                    return time;
            }
        }

        return time;
    }
}

// Approach-3: Using simple observation
// Time Complexity: O(n)
// Space Complexity: O(1)
class SolutionApproach3 {
    public int timeRequiredToBuy(int[] tickets, int k) {
        int time = 0;
        
        for (int i = 0; i < tickets.length; i++) {
            
            if (i <= k) {
                time += Math.min(tickets[k], tickets[i]);
            } else {
                time += Math.min(tickets[k] - 1, tickets[i]);
            }
        }
        
        return time;
    }
}
