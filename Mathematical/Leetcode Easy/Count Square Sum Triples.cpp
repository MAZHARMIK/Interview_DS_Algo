/*    Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn  : https://www.youtube.com/watch?v=1S9DMNtKx2w
    Company Tags                 : will update later
    Leetcode Link                : https://leetcode.com/problems/count-square-sum-triples
*/


/********************************************************************* C++ *********************************************************************/
//Approach (Using simple maths)
//T.C : O(n^2 * log(n))
//S.C : O(1)
class Solution {
public:
    int countTriples(int n) { 
        int count = 0;

        for(int a = 1 ; a <= n ; a++) {
            for(int b = a+1 ; b <= n ; b++) {
                int s = (a*a) + (b*b);
                int x = sqrt(s);
                if( x*x == s && x <= n )
                    count += 2;
            }
        }
        return count;
    }
};



/********************************************************************* JAVA *********************************************************************/
//Approach (Using simple maths)
//T.C : O(n^2 * log(n))
//S.C : O(1)
class Solution {
    public int countTriples(int n) {
        int count = 0;

        for (int a = 1; a <= n; a++) {
            for (int b = a + 1; b <= n; b++) {
                int s = (a * a) + (b * b);
                int x = (int) Math.sqrt(s);
                if (x * x == s && x <= n) {
                    count += 2;
                }
            }
        }

        return count;
    }
}
