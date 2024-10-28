/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Xpj6GQgP7og
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/longest-square-streak-in-an-array
*/


/************************************************************ C++ ************************************************/
//Approach-1 (Using sorting and map)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<int, int> mp;

        sort(begin(nums), end(nums));

        int maxStreak = 0;

        for(int &num : nums) { //2, 4 
            //check if this number is a perfect square
            int root = (int)sqrt(num);

            if(root*root == num && mp.find(root) != mp.end()) {
                mp[num] = mp[root] + 1;
            } else {
                mp[num] = 1;
            }

            maxStreak = max(maxStreak, mp[num]);

        }

        return maxStreak < 2 ? -1 : maxStreak;
    }
};


//Approach-2 (Using set)
//T.C : O(n) ///Note : O(n) because while loop will run max 5 times. So if constraint is given, then saying O(n) time complexity is fine.
//S.C : O(n)
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> st(begin(nums), end(nums));

        int maxStreak = 0;

        for(int &num : nums) {
            int streak = 0;
            long long curr = num;

            while(st.find(curr) != st.end()) {
                streak++;

                if(curr*curr > 1e5) {
                    break;
                }

                curr = curr*curr; //square
            }

            maxStreak = max(maxStreak, streak);
        }

        return maxStreak < 2 ? -1 : maxStreak;
    }
};




/************************************************************ JAVA ************************************************/
//Approach-1 (Using sorting and map)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
    public int longestSquareStreak(int[] nums) {
        Map<Integer, Integer> mp = new HashMap<>();
        Arrays.sort(nums);
        
        int maxStreak = 0;

        for (int num : nums) {
            int root = (int) Math.sqrt(num);

            if (root * root == num && mp.containsKey(root)) {
                mp.put(num, mp.get(root) + 1);
            } else {
                mp.put(num, 1);
            }

            maxStreak = Math.max(maxStreak, mp.get(num));
        }

        return maxStreak < 2 ? -1 : maxStreak;
    }
}


//Approach-2 (Using set)
//T.C : O(n) ///Note : O(n) because while loop will run max 5 times. So if constraint is given, then saying O(n) time complexity is fine.
//S.C : O(n)
class Solution {
    public int longestSquareStreak(int[] nums) {
        Set<Integer> st = new HashSet<>();
        for (int num : nums) {
            st.add(num);
        }

        int maxStreak = 0;

        for (int num : nums) {
            int streak = 0;
            long curr = num;

            while (st.contains((int) curr)) {
                streak++;

                if (curr * curr > 1e5) {
                    break;
                }

                curr = curr * curr; // square
            }

            maxStreak = Math.max(maxStreak, streak);
        }

        return maxStreak < 2 ? -1 : maxStreak;
    }
}
