/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/count-collisions-on-a-road
*/


/**************************************************************** C++ ****************************************************************/
//Approach (Simple iteration and simulation)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.length();

        int i = 0; //left boundary
        while(i < n && directions[i] == 'L') {
            i++;
        }

        int j = n-1;
        while(j >= 0 && directions[j] == 'R') {
            j--;
        }

        int collisions = 0;
        while(i <= j) {
            if(directions[i] != 'S') {
                collisions++;
            }
            i++;
        }

        return collisions;
    }
};



/**************************************************************** JAVA ***************************************************************/
//Approach (Simple iteration and simulation)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int countCollisions(String directions) {
        int n = directions.length();

        int i = 0; // left boundary
        while (i < n && directions.charAt(i) == 'L') {
            i++;
        }

        int j = n - 1; // right boundary
        while (j >= 0 && directions.charAt(j) == 'R') {
            j--;
        }

        int collisions = 0;
        while (i <= j) {
            if (directions.charAt(i) != 'S') {
                collisions++;
            }
            i++;
        }

        return collisions;
    }
}
