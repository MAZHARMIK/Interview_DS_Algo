/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=nmNLu1Qz-C0
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/build-an-array-with-stack-operations/
*/

/************************************************** C++ **************************************************/
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int stream = 1;
        
        vector<string> result;
        
        int i = 0;
        while(i < target.size() && stream <= n) {
            result.push_back("Push");
            
            if(stream == target[i]) {
                i++;
            } else {
                result.push_back("Pop");
            }
            stream++;
        }
        
        return result;
    }
};


/************************************************** JAVA **************************************************/
//T.C : O(n)
//S.C : O(1)
class Solution {
    public List<String> buildArray(int[] target, int n) {
        int stream = 1;
        List<String> result = new ArrayList<>();
        
        int i = 0;
        while (i < target.length && stream <= n) {
            result.add("Push");
            
            if (stream == target[i]) {
                i++;
            } else {
                result.add("Pop");
            }
            stream++;
        }
        
        return result;
    }
}
