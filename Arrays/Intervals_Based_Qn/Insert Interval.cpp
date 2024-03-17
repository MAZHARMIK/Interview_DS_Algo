/*   Scroll below to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=XXaVIDIbUn4
    Company Tags                : Google, Twitter, Microsoft, Apple, Amazon
    Leetcode Link               : https://leetcode.com/problems/insert-interval/
*/


/************************************************** C++ **************************************************/
//Approach-1 (TLE) 
//T.C : (O(n^2))
//S.C : O(1)
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        
        while(i < intervals.size()) {
            if(intervals[i][1] < newInterval[0])
                i++;
            else if (intervals[i][0] > newInterval[1]){
                intervals.insert(intervals.begin() + i, newInterval);
                return intervals;
            } else {
                //Overlap : merge them
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
                intervals.erase(intervals.begin()+i);
            }
        }
        
        intervals.push_back(newInterval);
        return intervals;
    }
};


//Approach-2
//T.C : O(n)
//S.C : O(n) for result
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        vector<vector<int>> result;
        
        while(i < intervals.size()) {
            if(intervals[i][1] < newInterval[0]) {
                result.push_back(intervals[i]);
            } else if (intervals[i][0] > newInterval[1]) {
                break;
            } else {
                //Overlap : merge them
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
            i++;
        }
        
        result.push_back(newInterval);
        while(i < intervals.size()) {
            result.push_back(intervals[i]);
            i++;
        }
        return result;
    }
};


/************************************************** JAVA **************************************************/
//Approach-1 (Brute Force : TLE) 
//T.C : (O(n))
//S.C : O1)
class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        int i = 0;

        while (i < intervals.length) {
            if (intervals[i][1] < newInterval[0])
                i++;
            else if (intervals[i][0] > newInterval[1]) {
                List<int[]> result = new ArrayList<>();
                for (int j = 0; j < i; j++) {
                    result.add(intervals[j]);
                }
                result.add(newInterval);
                for (int j = i; j < intervals.length; j++) {
                    result.add(intervals[j]);
                }
                return result.toArray(new int[result.size()][]);
            } else {
                // Overlap: merge them
                newInterval[0] = Math.min(newInterval[0], intervals[i][0]);
                newInterval[1] = Math.max(newInterval[1], intervals[i][1]);
                List<int[]> tempList = new ArrayList<>();
                for (int j = 0; j < intervals.length; j++) {
                    if (j != i) {
                        tempList.add(intervals[j]);
                    }
                }
                intervals = tempList.toArray(new int[tempList.size()][]);
            }
        }

        List<int[]> result = new ArrayList<>();
        for (int[] interval : intervals) {
            result.add(interval);
        }
        result.add(newInterval);
        return result.toArray(new int[result.size()][]);
    }
}


//Approach-2
//T.C : O(n)
//S.C : O(n) for result
class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        int i = 0;
        List<int[]> result = new ArrayList<>();
        int n = intervals.length;

        while (i < n) {
            if (intervals[i][1] < newInterval[0]) {
                result.add(intervals[i]);
            } else if (intervals[i][0] > newInterval[1]) {
                break;
            } else {
                // Merge the intervals and check further
                newInterval[0] = Math.min(newInterval[0], intervals[i][0]);
                newInterval[1] = Math.max(newInterval[1], intervals[i][1]);
            }
            i++;
        }

        result.add(newInterval);
        while (i < n) {
            result.add(intervals[i]);
            i++;
        }

        return result.toArray(new int[result.size()][]);
    }
}
