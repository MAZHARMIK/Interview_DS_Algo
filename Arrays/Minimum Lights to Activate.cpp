/*
    Company Tags  : Media.net
    Question Link : https://www.interviewbit.com/problems/minimum-lights-to-activate/
    
    Similar Leetcode Problem : Minimum Number of Taps to Open to Water a Garden (Leetcode-1326)
*/

int Solution::solve(vector<int> &A, int B) {
    int n     = A.size();
    int steps = 0;

    for(int i = 0; i<n;) {
        bool found = false;

        //I need to start from right most so that I can go furthest when I find first '1'
        int j = min(n-1, i+B-1);  
        for(; j>=max(0, i-B+1); j--) {
            if(A[j] == 1) {
                steps++;
                found = true;
                break;
            }
        }
        
        if(!found) return -1;

        //The point where I found '1' i.e. index 'j', it will lighten up bulbs till (j+B-1)
        //So, I need to jump directly to j+B
        i = j + B;
    }

    return steps;
}
