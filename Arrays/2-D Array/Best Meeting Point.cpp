/*
    Company Tags  : Twitter
    Leetcode Link : https://leetcode.com/problems/Best-Meeting-Point/
    
    Since it's a PREMIUM Qn, I am providing the Description and Example as well below 
    
    Description:
    A group of two or more people wants to meet and minimize the total travel distance.
    You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group.
    The distance is calculated using Manhattan Distance, 
    where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.
    
    Example : 
    For example, given three people living at (0,0), (0,4), and (2,2):

    1 - 0 - 0 - 0 - 1
    |   |   |   |   |
    0 - 0 - 0 - 0 - 0
    |   |   |   |   |
    0 - 0 - 1 - 0 - 0

    The point (0,2) is an ideal meeting point, as the total travel distance of 2+2+2=6 is minimal. So return 6.

*/

//Approach-1 (Using sorting) Time : O(m*n log(m*n))
/*
Intuition : Collect x-coordinates of all people, collect y-coordinates of all people and then Find the Median (by sorting) of x an y coordinates separately
            That median coordinate will be the best pointing point. Now, find distance of all people with this median point
*/

class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> xCoord;
        vector<int> yCoord;

        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == 1) {
                    xCoord.push_back(i);
                    yCoord.push_back(j);
                }
            }
        }

        sort(begin(xCoord), end(xCoord));
        sort(begin(yCoord), end(yCoord));

        int l = xCoord.size()/2;
        int x = xCoord[l];
        int y = yCoord[l];

        int d = 0;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == 1) {
                    d += abs(x-i) + abs(y-j);
                }
            }
        }

        return d;
    }
};

//Approach-2 (Without sorting) Time : O(m*n)
/*
  Store the x coordinates by traversing row-wise (They will be stored in sorted order already)
  Store the y coordinates by traversing col-wise (They will be stored in sorted order already)
*/

class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> xCoord;
        vector<int> yCoord;

        //row-wise
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == 1) {
                    xCoord.push_back(i);
                }
            }
        }

        //col-wise
        for(int j = 0; j<n; j++) {
            for(int i = 0; i<m; i++) {
                if(grid[i][j] == 1) {
                    yCoord.push_back(j);
                }
            }
        }

        int l = xCoord.size()/2;
        int x = xCoord[l];
        int y = yCoord[l];

        int d = 0;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == 1) {
                    d += abs(x-i) + abs(y-j);
                }
            }
        }

        return d;
    }
};
