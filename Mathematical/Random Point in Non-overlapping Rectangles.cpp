/*
    Company Tags  : Google
    Leetcode Link : https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/
*/

class Solution {
public:
    vector<vector<int>> rects;
    map<int, int> mp;
    int sum = 0;
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        int n = rects.size();
        
        for(int i = 0; i<n; i++) {
            int x1 = rects[i][0];
            int x2 = rects[i][2];
            int y1 = rects[i][1];
            int y2 = rects[i][3];
            
            sum += (x2-x1+1) * (y2-y1+1);
            /*
                Why +1 ?
                Let's say we have one side of rectangle as follows
                
                (1, 4)---------------------(3, 4)
                How many points are there in between them ?
                (1, 4) -- (2, 4) -- (3, 4) -- (4, 4)
                Total  : 4 points
                i.e. (x2-x1+1)
            */
            
            mp[sum] = i; //storing (point -> rectangle) in map for quick access later
        }
    }
    
    vector<int> pick() {
        int randomPoint = rand()%sum + 1;  //random point between [1 to sum]
        //So, we have got a random point to pick
        //Now, find which rectangle has this point
        //Use binary search/linear search for it or lower_bound in map
        
        auto it       = mp.upper_bound(randomPoint);
        int rectIndex = it->second;
            
        int x1 = rects[rectIndex][0];
        int x2 = rects[rectIndex][2];
        int y1 = rects[rectIndex][1];
        int y2 = rects[rectIndex][3];
        
        //int x = x1 + some random value within range of length
        //int y = y1 + some random value within range of breadth
        
        int x = x1 + rand()%(x2-x1+1);
        int y = y1 + rand()%(y2-y1+1);
        
        return {x, y};
    }
};
