/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=YQoN-z3HKI4
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/circle-and-rectangle-overlapping/description/
*/


/*********************************************************** C++ **************************************************/
//Approach-1 (Nearest point check and compare)
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        //nearest point
        int xi;
        int yi;

        if(x1 > xCenter) {
            xi = x1;
        } else if(x2 < xCenter) {
            xi = x2;
        } else {
            xi = xCenter;
        }


        if(y1 > yCenter) {
            yi = y1;
        } else if(y2 < yCenter) {
            yi = y2;
        } else {
            yi = yCenter;
        }

        //(xi, yi) ------- (xCenter, yCenter)
        return sqrt((xi - xCenter)*(xi - xCenter) + (yi - yCenter)*(yi - yCenter)) <= radius;
    }
};



//Approach-2 (Same thing using clamp)
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        //nearest point
        int xi = clamp(xCenter, x1, x2);
        int yi = clamp(yCenter, y1, y2);

        if(y1 > yCenter) {
            yi = y1;
        } else if(y2 < yCenter) {
            yi = y2;
        } else {
            yi = yCenter;
        }

        //(xi, yi) ------- (xCenter, yCenter)
        return sqrt((xi - xCenter)*(xi - xCenter) + (yi - yCenter)*(yi - yCenter)) <= radius;
    }
};




/*********************************************************** JAVA **************************************************/
//Approach-1 (Nearest point check and compare)
//T.C : O(1)
//S.C : O(1)
class Solution {
    public boolean checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        //nearest point
        int xi;
        int yi;

        if (x1 > xCenter) {
            xi = x1;
        } else if (x2 < xCenter) {
            xi = x2;
        } else {
            xi = xCenter;
        }

        if (y1 > yCenter) {
            yi = y1;
        } else if (y2 < yCenter) {
            yi = y2;
        } else {
            yi = yCenter;
        }

        //(xi, yi) ------- (xCenter, yCenter)
        long dx = xi - xCenter;
        long dy = yi - yCenter;
        return dx * dx + dy * dy <= (long) radius * radius;
    }
}


//Approach-2 (Same thing using Min and Max - Java doesn't have anything equivalent to std::clamp in C++)
//T.C : O(1)
//S.C : O(1)
class Solution {
    public boolean checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        //nearest point
        int xi = Math.max(x1, Math.min(x2, xCenter));
        int yi = Math.max(y1, Math.min(y2, yCenter));

        //(xi, yi) ------- (xCenter, yCenter)
        long dx = xi - xCenter;
        long dy = yi - yCenter;
        return dx * dx + dy * dy <= (long) radius * radius;
    }
}
