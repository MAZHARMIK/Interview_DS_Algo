/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=OVLW_XnOUQ4
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/avoid-flood-in-the-city/description/
*/



/****************************************************************** C++ ******************************************************************/
//Approach (Binary search along with map and set and greedy)
//T.C : O(n*logn)
//S.C : O(n)
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();

        unordered_map<int, int> map;   // lake -> last day it was filled
        set<int> dryDays;              // indices of dry days (rains[day] == 0)
        vector<int> ans(n, 1);         // default all dry days to dry lake 1

        for (int day = 0; day < n; day++) {
            int lake = rains[day];

            if (lake == 0) {
                dryDays.insert(day);                     // record this dry day
            } else {
                ans[day] = -1;                           // raining day — can't dry any lake

                if (map.count(lake)) {
                    // lake already filled previously
                    auto it = dryDays.lower_bound(map[lake] + 1);   // next dry day after it was last filled

                    if (it == dryDays.end()) {
                        // no dry day available to empty this lake before raining again → flood
                        return {};
                    }

                    ans[*it] = lake;                     // use this dry day to dry the lake
                    dryDays.erase(it);
                }

                map[lake] = day;                         // record latest day this lake was filled
            }
        }

        return ans;
    }
};


/****************************************************************** JAVA ******************************************************************/
//Approach (Binary search along with map and set and greedy)
//T.C : O(n*logn)
//S.C : O(1)
class Solution {
    public int[] avoidFlood(int[] rains) {
        int n = rains.length;
        Map<Integer, Integer> map = new HashMap<>();   // lake -> last day it was filled
        TreeSet<Integer> dryDays = new TreeSet<>();    // indices of dry days (rains[i] == 0)
        int[] ans = new int[n];
        Arrays.fill(ans, 1);                           // default all dry days to dry lake 1

        for (int i = 0; i < n; i++) {
            int lake = rains[i];

            if (lake == 0) {
                dryDays.add(i);                        // record this dry day
            } else {
                ans[i] = -1;                           // raining day — can't dry any lake

                if (map.containsKey(lake)) {
                    // lake already filled previously
                    Integer dryDay = dryDays.higher(map.get(lake));  // next dry day after it was last filled

                    if (dryDay == null) {
                        // no dry day available to empty this lake before raining again → flood
                        return new int[0];
                    }

                    ans[dryDay] = lake;                // use this dry day to dry the lake
                    dryDays.remove(dryDay);
                }

                map.put(lake, i);                      // record latest day this lake was filled
            }
        }

        return ans;
    }
}
