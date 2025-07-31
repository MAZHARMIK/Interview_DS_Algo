/*    Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Jlj4LUJhQJY
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/bitwise-ors-of-subarrays/description
*/


/*************************************************************************** C++ ******************************************************************************************/
//Approach (using hashset to store previous or values)
//T.C : O(n*32) ~ O(n)
//S.C : O(n*32) ~ O(n)
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> prev;
        unordered_set<int> curr;
        unordered_set<int> result;

        for(int i = 0; i < arr.size(); i++) {

            for(const int& x : prev) {
                curr.insert(x | arr[i]);
                result.insert(x | arr[i]);
            }

            curr.insert(arr[i]);
            result.insert(arr[i]);

            prev = curr;
            curr.clear();
        }

        return result.size();
    }
};



/*************************************************************************** JAVA ******************************************************************************************/
//Approach (using hashset to store previous or values)
//T.C : O(n*32) ~ O(n)
//S.C : O(n*32) ~ O(n)
class Solution {
    public int subarrayBitwiseORs(int[] arr) {
        Set<Integer> prev = new HashSet<>();
        Set<Integer> curr = new HashSet<>();
        Set<Integer> result = new HashSet<>();

        for (int num : arr) {
            for (int x : prev) {
                curr.add(x | num);
                result.add(x | num);
            }

            curr.add(num);
            result.add(num);

            prev = curr;
            curr = new HashSet<>();
        }

        return result.size();
    }
}
