/*         Scroll below to see JAVA code as well        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=9rCmrMed8h8
    Company Tags                : Amazon, Google, Nutanix
    Leetcode Qn Link            : https://leetcode.com/problems/merge-intervals/
*/


/************************************************************************ C++ ************************************************************/
//Approach-1 (Brute Force)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int i = 0;
        while(i < intervals.size()-1) {
            int i_start = intervals[i][0];
            int i_end  = intervals[i][1];
            bool merge = false;
            for(int j = i+1; j<intervals.size(); j++) {

                int j_start = intervals[j][0];
                int j_end  = intervals[j][1];

                if(!(i_end < j_start || i_start > j_end)) {
                    //overlap. Merge them
                    intervals[i][0] = min(i_start, j_start);
                    intervals[i][1] = max(i_end, j_end);
                    //erase j
                    intervals.erase(intervals.begin()+j);
                    merge = true;
                    break;
                }

            }        
            if(!merge) {
                i++;
            }
        }
        return intervals;
    }
};


//Approach-2 (Using sorting)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals)); //on the basis of start point
        
        vector<vector<int>> result;

        result.push_back(intervals[0]);

        for(int i = 1; i<intervals.size(); i++) {

            int curr_start = intervals[i][0];
            int curr_end = intervals[i][1];

            //if no overlap
            if(curr_start > result.back()[1]) {
                result.push_back(intervals[i]);
            } else {
                //there is an overlap
                result.back()[1] = max(result.back()[1], curr_end);
            }

        }

        return result;

    }
};



/************************************************************************ Java ************************************************************/
// Approach-1 (Brute Force)
// T.C : O(n^2)
// S.C : O(1)
import java.util.*;

class Solution {
    public int[][] merge(int[][] intervals) {
        int i = 0;
        while (i < intervals.length - 1) {
            int i_start = intervals[i][0];
            int i_end = intervals[i][1];
            boolean merge = false;
            
            for (int j = i + 1; j < intervals.length; j++) {
                int j_start = intervals[j][0];
                int j_end = intervals[j][1];
                
                if (!(i_end < j_start || i_start > j_end)) {
                    // Overlap. Merge them
                    intervals[i][0] = Math.min(i_start, j_start);
                    intervals[i][1] = Math.max(i_end, j_end);
                    
                    // Erase j by shifting elements
                    for (int k = j; k < intervals.length - 1; k++) {
                        intervals[k] = intervals[k + 1];
                    }
                    
                    intervals = Arrays.copyOf(intervals, intervals.length - 1);
                    merge = true;
                    break;
                }
            }
            
            if (!merge) {
                i++;
            }
        }
        return intervals;
    }
}


// Approach-2 (Using Sorting)
// T.C : O(n log n)
// S.C : O(n)
class Solution2 {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0])); // Sort based on start point
        
        List<int[]> result = new ArrayList<>();
        result.add(intervals[0]);
        
        for (int i = 1; i < intervals.length; i++) {
            int curr_start = intervals[i][0];
            int curr_end = intervals[i][1];
            
            // If no overlap
            if (curr_start > result.get(result.size() - 1)[1]) {
                result.add(intervals[i]);
            } else {
                // There is an overlap
                result.get(result.size() - 1)[1] = Math.max(result.get(result.size() - 1)[1], curr_end);
            }
        }
        
        return result.toArray(new int[result.size()][]);
    }
}
