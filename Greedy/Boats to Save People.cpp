/*  
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=UsQzOL6r0HY
    Company Tags                : Google
    Leetcode Link               : https://leetcode.com/problems/boats-to-save-people/
*/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        
        
        //sort the array
        sort(begin(people), end(people));
        
        int i = 0, j = n-1;
        
        int boats = 0;
        
        while(i <= j) {
            if(people[j] + people[i] <= limit) {
                i++;
                j--;
            } else {
                j--;
            }
            boats += 1;
        }
        
        return boats;
    }
};
