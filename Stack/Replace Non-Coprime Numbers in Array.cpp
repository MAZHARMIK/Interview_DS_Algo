/*     Scroll below to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/replace-non-coprime-numbers-in-array
*/


/********************************************************************** C++ **********************************************************************/
//Approach (Using vector as a stack)
//T.C : O(n * log(x)), where log comes from GCD
//S.C : O(1)
class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> result; //or you can use a stack

        //Processing left to right
        for(int num : nums) {

            while(!result.empty()) {
                int prev = result.back();
                int curr = num;

                int GCD = gcd(prev, curr);
                if(GCD == 1) {
                    break;
                }

                result.pop_back();
                int LCM = prev / GCD * curr;

                num = LCM; //merged number
            }
            result.push_back(num); //merged num put back to result
        }
        return result;
    }
};


/********************************************************************** JAVA **********************************************************************/
//Approach (Using vector as a stack)
//T.C : O(n * log(x)), where log comes from GCD
//S.C : O(1)
class Solution {
    public List<Integer> replaceNonCoprimes(int[] nums) {
        List<Integer> result = new ArrayList<>();

        for (int num : nums) {
            // Keep merging while the last number and current num are non-coprime
            while (!result.isEmpty()) {
                int prev = result.get(result.size() - 1);
                int g = gcd(prev, num);

                if (g == 1) {
                    break; // coprime, stop merging
                }

                // Remove last and merge with current
                result.remove(result.size() - 1);
                long lcm = (long) prev / g * num; // use long to avoid overflow
                num = (int) lcm;
            }
            result.add(num);
        }

        return result;
    }

    // Euclidean algorithm for GCD
    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
