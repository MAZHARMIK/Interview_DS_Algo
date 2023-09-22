/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=6VHDJMYtn3Q
      Company Tags                : GOOGLE
      Leetcode Link               : https://leetcode.com/problems/minimum-speed-to-arrive-on-time/
      Similar Porblems - 
            https://leetcode.com/problems/koko-eating-bananas/
            https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
            https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets
            https://leetcode.com/problems/magnetic-force-between-two-balls/
            Allocate Minimum Number Of Pages (https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1)
*/

/*
  Two hints in this Qn which lead to Binary Search
  - The range of possible values here is 1 - 10^7. In binary search, we have to find answer from a sorted array. 
    Here we are left of finding answer from a sorted range. That's why it can be done using binary search

  - We have to find a speed x such that total time taken is less than the time given in problem,
    if I take too less speed then, it will take much more time and
    if we take more speed it will take less time but we need to keep speed to minimum.
    It hints towards moving towards left or right which we do in Binary Search
*/

//Binary Search
class Solution {
public:
    
    double possible(vector<int>& dist, int speed) {
        
        double time = 0.0;
        int n = dist.size();
        
        for(int i = 0; i < n - 1; i++) {
            
            double t = (double)dist[i]/(double)speed;
            
            time += ceil(t);
            
        }
        
        time += (double)dist[n-1]/(double)speed;
        
        return time;
        
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l = 1;
        int r = 1e7;
        
        int minSpeed = -1;
        
        while(l <= r) {
            
            int mid = l + (r-l)/2;
            
            if(possible(dist, mid) <= hour) {
                minSpeed = mid;
                r = mid-1;
            } else {
                l = mid+1; //need to speed up
            }
            
        }
        
        return minSpeed;
    }
};
