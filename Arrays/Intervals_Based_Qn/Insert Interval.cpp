/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=XXaVIDIbUn4
    Company Tags                : Google, Twitter, Microsoft, Apple, Amazon
    Leetcode Link               : https://leetcode.com/problems/insert-interval/
*/

//Approach-1 (TLE) Time : (O(n^2))
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


//Approach-2 (Time and space : O(n))
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
