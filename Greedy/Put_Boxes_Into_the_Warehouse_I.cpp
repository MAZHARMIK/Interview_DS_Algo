/*
    Company Tags  : Google 
    Leetcode Link : https://leetcode.com/problems/put-boxes-into-the-warehouse-i/
    
    Since, it's a Premimum Question, below is the description and example
    Description

    You are given two arrays of positive integers, boxes and warehouse, representing the heights of some boxes of unit width and the heights of n rooms in a warehouse respectively. The warehouse's rooms are labelled from 0 to n - 1 from left to right where warehouse[i] (0-indexed) is the height of the ith room.

    Boxes are put into the warehouse by the following rules:

        Boxes cannot be stacked.
        You can rearrange the insertion order of the boxes.
        Boxes can only be pushed into the warehouse from left to right only.
        If the height of some room in the warehouse is less than the height of a box, then that box and all other boxes behind it will be stopped before that room.

    Return the maximum number of boxes you can put into the warehouse.
    
    Example 1:
    Input: boxes = [4,3,4,1], warehouse = [5,3,3,4,1]
    Output: 3
    
    Example 2:
    Input: boxes = [1,2,2,3,4], warehouse = [3,4,1,2]
    Output: 3
*/

//Approach-1

class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        sort(boxes.begin(), boxes.end());
        int lastWareHouse = warehouse.size()-1;

        int Count = 0;
        for(int i = 0; i<boxes.size(); i++) {
            int h_box = boxes[i];

            int j = 0;

            while(j <= lastWareHouse && warehouse[j] >= h_box)
                j++;

            if(j == 0)
                break;

            if(j <= lastWareHouse) {
                lastWareHouse = j-2;
            } else {
                lastWareHouse--;
            }
            Count++;
        }
        return Count;
    }
};

//Approach-2
class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        int m = boxes.size();
        int n = warehouse.size();

        int minVal = INT_MAX;
        //Since the entry room of warehouse will be the deciding factor
        //example :
        //1  2  3
        //1  2  3  4
        //2nd box can't reach till 3rd ware house because the first ware house h is 1
        //So, from a point, the minimum height is the limiting factor after that point
        for(int i = 0; i<n; i++) {
            minVal = min(minVal, warehouse[i]);
            warehouse[i] = minVal;
        }

        int i = 0, j = n-1;
        int count = 0;
        sort(boxes.begin(), boxes.end());
        while(i<m && j>=0) {
            if(warehouse[j] >= boxes[i]) {
                i++;
                j--;
                count++;
            } else {
                j--;
            }
        }
        return count;
    }
};
