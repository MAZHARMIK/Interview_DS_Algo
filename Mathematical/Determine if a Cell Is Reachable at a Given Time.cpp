/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=1k5-LnJlH78
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time/
*/

/*********************************************** C++ ***********************************************/
//Approach - 1 (Brute Force : Won't work with High Contraints - Infinte Board)
class Solution {
public:
    vector<vector<int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {-1, 1}, {1, -1}, {1, 1}, {-1, -1}};
    
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx < 0 || sy < 0) {
            return false;
        }
        
        if(t == 0) {
            return sx == fx && sy == fy;
        }
        
        for(auto &dir : directions) {
            int sx_ = sx + dir[0];
            int sy_ = sy + dir[1];
            
            if(isReachableAtTime(sx_, sy_, fx, fy, t-1))
                return true;
        }
        
        return false;
        
    }
};

//Approach-2 (Using Maths)
//T.C : O(1)
class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int vert_dist = abs(sy-fy);
        int hor_dist  = abs(sx-fx);
        
        if(vert_dist == 0 && hor_dist == 0 && t == 1) {
            return false;
        }
        
        return t >= max(vert_dist, hor_dist);
        
    }
};


/*********************************************** JAVA ***********************************************/
//Approach - 1 (Brute Force : Won't work with High Contraints - Infinte Board)
public class Solution {
    private final int[][] directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {-1, 1}, {1, -1}, {1, 1}, {-1, -1}};

    public boolean isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if (sx < 0 || sy < 0) {
            return false;
        }

        if (t == 0) {
            return sx == fx && sy == fy;
        }

        for (int[] dir : directions) {
            int sx_ = sx + dir[0];
            int sy_ = sy + dir[1];

            if (isReachableAtTime(sx_, sy_, fx, fy, t - 1)) {
                return true;
            }
        }

        return false;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int sx = 1, sy = 1, fx = 3, fy = 3, t = 2;
        boolean result = solution.isReachableAtTime(sx, sy, fx, fy, t);
        System.out.println("Is reachable within time? " + result);
    }
}


//Approach-2 (Using Maths)
//T.C : O(1)
public class Solution {
    public boolean isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int vertDist = Math.abs(sy - fy);
        int horDist = Math.abs(sx - fx);

        if (vertDist == 0 && horDist == 0 && t == 1) {
            return false;
        }

        return t >= Math.max(vertDist, horDist);
    }
}

