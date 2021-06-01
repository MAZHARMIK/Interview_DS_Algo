/*
    Company Tags  : LinkedIn (7 times)
    Leetcode Link : https://leetcode.com/problems/paint-house/
    Since, It's a premium Qn, hence providing the Description here : 
    Description :
    There are a row of n houses, each house can be painted with one of the three colors:red, blue or green.
    The cost of painting each house with a certain color is different. You have to paint all the houses such
    that no two adjacent houses have the same color, and you need to cost the least. Return the minimum cost.

    The cost of painting each house with a certain color is represented by a n x 3 cost matrix.
    For example, costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is the
    cost of painting house 1 with color green, and so on... Find the minimum cost to paint all houses.
    
    Example

    Example 1:

    Input: [[14,2,11],[11,14,5],[14,3,10]]

    Output: 10

    Explanation: Paint house 0 into blue, paint house 1 into green,
    paint house 2 into blue. Minimum cost: 2 + 5 + 3 = 10.
*/

class Solution {
public:
    int minCost(vector<vector<int>> &costs) {
        //we just have to find the minimum falling path sum
        int m = costs.size();
        if(m == 0)
            return 0;
        
        int n = 3;
        for(int row = 1; row < m; row++) {
             costs[row][0] += min(costs[row-1][1], costs[row-1][2]);
             costs[row][1] += min(costs[row-1][0], costs[row-1][2]);
             costs[row][2] += min(costs[row-1][0], costs[row-1][1]);
        }

        return min({costs[m-1][0], costs[m-1][1], costs[m-1][2]});
    }
};
