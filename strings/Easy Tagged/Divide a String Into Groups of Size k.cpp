/*     Scroll below to see JAVA code as well      */
/*
    MY YOUTUBE VIDEO ON THIS QN : https://www.youtube.com/watch?v=uCtxwHoPhkY
    Company Tags                : Uber
    Leetcode Link               : https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/description/
*/

/*************************************************************************** C++ ***************************************************************************/
//Approach (Simple iterating and generating)
//T.C : O(n)
//S.C : O(k)
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result;
        int n = s.length();

        int i = 0;
        while(i < n) {
            int j       = (i + k - 1 >= n) ? n-1 : (i + k - 1);
            string temp = s.substr(i, j-i+1);

            if(j-i+1 < k) {
                int remain = k - (j-i+1);
                temp += string(remain, fill);
            }
            result.push_back(temp);

            i += k;
        }

        return result;
    }
};




/*************************************************************************** JAVA ***************************************************************************/
//Approach (Simple iterating and generating)
//T.C : O(n)
//S.C : O(k)
class Solution {
    public String[] divideString(String s, int k, char fill) {
        List<String> res = new ArrayList<>();

        for (int i = 0; i < s.length(); i += k) {
            int end = Math.min(i + k, s.length());
            StringBuilder group = new StringBuilder(s.substring(i, end));

            // Fill with 'fill' character if needed
            while (group.length() < k) {
                group.append(fill);
            }

            res.add(group.toString());
        }
        return res.toArray(new String[0]);
    }
}
