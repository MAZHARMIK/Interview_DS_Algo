/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=iH67r9BLpAw
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/coupon-code-validator
*/



/************************************************************ C++ *****************************************************/
//Approach (Using map and sorting)
//T.C : O(n*l + nlogn) where n = code.size() and l = average length of codes
//S.C : O(n)
class Solution {
public:
    bool checkValidCode(string &code) {
        if(code.empty())
            return false;

        for(char &ch : code) {
            if(!isalnum(ch) && ch != '_') {
                return false;
            }
        }

        return true;
    }

    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        
        unordered_map<string, int> mp = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };

        vector<pair<int, string>> temp; //{businessLineIntegerValue, code}

        for (int i = 0; i < code.size(); i++) {
            if (isActive[i] &&
                mp.count(businessLine[i]) &&
                checkValidCode(code[i])) {

                temp.push_back({mp[businessLine[i]], code[i]});
            }
        }

        sort(begin(temp), end(temp));
        vector<string> result;

        for(auto &it : temp) {
            result.push_back(it.second);
        }

        return result;
    }
};





/************************************************************ JAVA *****************************************************/
//Approach (Using map and sorting)
//T.C : O(n*l + nlogn) where n = code.size() and l = average length of codes
//S.C : O(n)
class Solution {

    private boolean checkValidCode(String code) {
        if (code == null || code.isEmpty()) {
            return false;
        }

        for (char ch : code.toCharArray()) {
            if (!Character.isLetterOrDigit(ch) && ch != '_') {
                return false;
            }
        }
        return true;
    }

    public List<String> validateCoupons(String[] code, String[] businessLine, boolean[] isActive) {

        Map<String, Integer> mp = new HashMap<>();
        mp.put("electronics", 0);
        mp.put("grocery", 1);
        mp.put("pharmacy", 2);
        mp.put("restaurant", 3);

        // stores {businessLineOrder, code}
        List<Pair> temp = new ArrayList<>();

        for (int i = 0; i < code.length; i++) {
            if (isActive[i]
                    && mp.containsKey(businessLine[i])
                    && checkValidCode(code[i])) {

                temp.add(new Pair(mp.get(businessLine[i]), code[i]));
            }
        }

        // sort by businessLineOrder, then by code (same as C++ pair sorting)
        Collections.sort(temp);

        List<String> result = new ArrayList<>();
        for (Pair p : temp) {
            result.add(p.code);
        }

        return result;
    }

    // Helper class to mimic pair<int, string>
    private static class Pair implements Comparable<Pair> {
        int order;
        String code;

        Pair(int order, String code) {
            this.order = order;
            this.code = code;
        }

        @Override
        public int compareTo(Pair other) {
            if (this.order != other.order) {
                return Integer.compare(this.order, other.order);
            }
            return this.code.compareTo(other.code);
        }
    }
}
