/*   Scroll below to see JAVA code also  */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=lVDSn737vfY
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/binary-watch/submissions/1909541136/
*/


/******************************************************* C++ *******************************************************/
//Approach (Simple enumeration)
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;

        for (int HH = 0; HH <= 11; HH++) {

            for (int MM = 0; MM <= 59; MM++) {
                
                if (__builtin_popcount(HH) + __builtin_popcount(MM) == turnedOn) {
                    string hour   = to_string(HH);
                    string minute = (MM < 10 ? "0" : "") + to_string(MM);
                    
                    result.push_back(hour + ":" + minute);
                }
            }
        }
        return result;
    }
};




/******************************************************* JAVA *******************************************************/
//Approach (Simple enumeration)
//T.C : O(1)
//S.C : O(1)
class Solution {
    public List<String> readBinaryWatch(int turnedOn) {
        List<String> result = new ArrayList<>();

        for (int hh = 0; hh <= 11; hh++) {
            for (int mm = 0; mm <= 59; mm++) {

                if (Integer.bitCount(hh) + Integer.bitCount(mm) == turnedOn) {
                    String hour = String.valueOf(hh);
                    String minute = (mm < 10 ? "0" : "") + mm;
                    result.add(hour + ":" + minute);
                }

            }
        }

        return result;
    }
}
