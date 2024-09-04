/*     Scroll below to see JAVA code also    */
/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=K8lMDgaAn4w
      Company Tags                : Jane Street
      Leetcode Link               : https://leetcode.com/problems/walking-robot-simulation/description/
*/


/********************************************************************** C++ ********************************************************/
//Simple Simulation
//T.C : O(m + n * maxValCommand), m = size of obstacles, n = size of commands
//S.C : O(m)
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> st;
        for(vector<int>& obs : obstacles) {
            string key = to_string(obs[0]) + "_" + to_string(obs[1]);
            st.insert(key);
        }

        int x = 0;
        int y = 0;
        int maxD = 0;

        //Pointing to North
        pair<int, int> dir = {0, 1}; //N

        for(int i = 0; i < commands.size(); i++) {
            if(commands[i] == -2) { //left 90 degree
                dir = {-dir.second, dir.first};
            } else if(commands[i] == -1) { //right 90 degree
                dir = {dir.second, -dir.first};
            } else { //move to the direction step by step
                for(int step = 0; step < commands[i]; step++) {
                    int newX = x + dir.first;
                    int newY = y + dir.second;

                    string nextKey = to_string(newX) + "_" + to_string(newY);

                    if(st.find(nextKey) != st.end()) {
                        break;
                    }

                    x = newX;
                    y = newY;
                }
            }

            maxD = max(maxD, x*x + y*y);
        }

        return maxD;
    }
};



/********************************************************************** JAVA ***********************************************************/
//Simple Simulation
//T.C : O(m + n * maxValCommand), m = size of obstacles, n = size of commands
//S.C : O(m)
class Solution {
    public int robotSim(int[] commands, int[][] obstacles) {
        // Use HashSet to store obstacle positions as strings
        HashSet<String> obstacleSet = new HashSet<>();
        for (int[] obs : obstacles) {
            String key = obs[0] + "_" + obs[1];
            obstacleSet.add(key);
        }

        int x = 0;
        int y = 0;
        int maxDistance = 0;

        // Initially pointing North
        int[] dir = {0, 1}; // North

        // Process each command
        for (int i = 0; i < commands.length; i++) {
            if (commands[i] == -2) { // turn left 90 degrees
                dir = new int[]{-dir[1], dir[0]};
            } else if (commands[i] == -1) { // turn right 90 degrees
                dir = new int[]{dir[1], -dir[0]};
            } else { // move forward step by step
                for (int step = 0; step < commands[i]; step++) {
                    int newX = x + dir[0];
                    int newY = y + dir[1];

                    String nextKey = newX + "_" + newY;

                    // If there's an obstacle, stop moving in this direction
                    if (obstacleSet.contains(nextKey)) {
                        break;
                    }

                    // Move to the new position
                    x = newX;
                    y = newY;
                }
            }

            // Update the maximum distance from the origin
            maxDistance = Math.max(maxDistance, x * x + y * y);
        }

        return maxDistance;
    }
}
