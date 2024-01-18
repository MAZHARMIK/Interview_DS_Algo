/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=_twHfnNwTwE
    Company Tags                : Microsoft
    GfG Link                    : https://www.geeksforgeeks.org/problems/water-the-plants--170646/1
    Similar Leetcode Link       : https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/description/
*/

/************************************************************ C++ ***************************************************************************/
//Approach (Greedy sorting)
//T.C : O(nlogn)
//S.C : O(n)
class Solution{
    public:
    int min_sprinklers(int gallery[], int n) {
        vector<pair<int, int>> vec;
        
        for(int i = 0; i < n; i++) {
            if(gallery[i] == -1) 
                continue;
            
            int left  = max(0, i-gallery[i]);
            int right = min(n-1, i+gallery[i]);
            
            vec.push_back({left, right});
        }
        
        sort(begin(vec), end(vec));
        
        int count    = 0;
        int i        = 0;
        int target   = 0;
        
        while(target < n) {
            
            int maxEnd = -1;
            while(i < vec.size()) {
                if(vec[i].first > target)
                    break;
                
                maxEnd = max(maxEnd, vec[i].second);
                i++;
            }
            
            if(maxEnd < target) {
                return -1;
            }
            
            count++;
            target = maxEnd + 1;
        }
        
        return count;
    }
};




/************************************************************ JAVA ***************************************************************************/
//Approach (Greedy sorting)
//T.C : O(nlogn)
//S.C : O(n)
class Solution
{
    int min_sprinklers(int gallery[], int n)
    {
        int[][] sprinklers = new int[n][2];

        for (int i = 0; i < n; i++) {
            if (gallery[i] == -1)
                continue;

            int left = Math.max(0, i - gallery[i]);
            int right = Math.min(n - 1, i + gallery[i]);

            sprinklers[i][0] = left;
            sprinklers[i][1] = right;
        }

        Arrays.sort(sprinklers, Comparator.comparingInt(a -> a[0]));

        int count = 0;
        int i = 0;
        int target = 0;

        while (target < n) {
            int maxEnd = -1;
            while (i < sprinklers.length) {
                if (sprinklers[i][0] > target)
                    break;
                maxEnd = Math.max(maxEnd, sprinklers[i][1]);
                i++;
            }

            if (maxEnd < target) {
                return -1;
            }

            count++;
            target = maxEnd + 1;
        }

        return count;
    }
}
