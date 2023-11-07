/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=T67MicJdTug
    Company Tags                : Meta, Google, Amazon
    Leetcode Link               : https://leetcode.com/problems/eliminate-maximum-number-of-monsters/
*/

/********************************************************** C++ **********************************************************/
//Using simple Greedy
//T.C : O(nlogn)
class Solution {
public:
    typedef pair<int, int> P;
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        
        vector<int> vec(n);
        
        for(int i = 0; i<n; i++) {
            vec[i] = ceil((float) dist[i] / speed[i]);
        }
        
        
        sort(begin(vec), end(vec));
        

        
        int count = 1;
        
        int time_passed = 1;
        for(int i = 1; i<n; i++) {
            if(vec[i] - time_passed <= 0)
                return count;
            
            count++;
            time_passed++;
        }
        
        return count;
        
        
    }
};


/********************************************************** JAVA **********************************************************/
class Solution {
    public int eliminateMaximum(int[] dist, int[] speed) {
        int n = dist.length;
        
        int[] vec = new int[n];
        
        for (int i = 0; i < n; i++) {
            vec[i] = (int) Math.ceil((double) dist[i] / speed[i]);
        }
        
        Arrays.sort(vec);
        
        int count = 1;
        
        int timePassed = 1;
        for (int i = 1; i < n; i++) {
            if (vec[i] - timePassed <= 0) {
                return count;
            }
            
            count++;
            timePassed++;
        }
        
        return count;
    }
}
