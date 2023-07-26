/*
      MY YOUTUBE VIDEO ON THIS Qn : 
      Company Tags                : will update soon
      Leetcode Link               : https://leetcode.com/problems/minimum-speed-to-arrive-on-time/
      Similar Leetcode Porblem    :  https://leetcode.com/problems/koko-eating-bananas/

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
        
        for(int i = 0; i < dist.size(); i++) {
            
            double t = (double)dist[i]/(double)speed;
            
            if(i == dist.size()-1)
                time += t;
            else
                time += ceil(t);
            
        }
        
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
