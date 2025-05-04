/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/number-of-equivalent-domino-pairs
*/


/************************************************************ C++ *****************************************************/
//Approach-1 (Using map of pair)
//T.C : O(n * logn) , note that we are using ordered_map here and insertion in it is log(n)
//S.C : O(n)
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int, int>, int> mp;

        for(auto &d : dominoes) {
            if(d[0] > d[1]) { //(2, 1) ---- (1, 2)
                swap(d[0], d[1]);
            }

            mp[{d[0], d[1]}]++;
        }

        int result = 0;

        for(auto &it : mp) {
            int freq = it.second;

            result += freq * (freq-1)/2; //freqC2
        }

        return result;

    }
};


//Approach-2 (constant space)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> vec(100);

        int result = 0;

        for(auto &d : dominoes) {
            if(d[0] > d[1]) {
                swap(d[0], d[1]);
            }

            int num = d[0]*10 + d[1]; //(a, b) --> a*10 + b;

            result += vec[num];

            vec[num]++;
        }

        return result;
    }
};


/************************************************************ JAVA *****************************************************/
//Approach-1 (Using map of pair)
//T.C : O(n * logn) , note that we are using ordered_map here and insertion in it is log(n)
//S.C : O(n)
public class Solution {
    public int numEquivDominoPairs(int[][] dominoes) {
        Map<String, Integer> map = new HashMap<>();

        for (int[] d : dominoes) {
            int a = d[0], b = d[1];
            if (a > b) {
                int temp = a;
                a = b;
                b = temp;
            }
            String key = a + "," + b;
            map.put(key, map.getOrDefault(key, 0) + 1);
        }

        int result = 0;
        for (int freq : map.values()) {
            result += freq * (freq - 1) / 2;
        }

        return result;
    }
}


//Approach-2 (constant space)
//T.C : O(n)
//S.C : O(1)
public class Solution {
    public int numEquivDominoPairs(int[][] dominoes) {
        int[] count = new int[100];
        int result = 0;

        for (int[] d : dominoes) {
            int a = d[0], b = d[1];
            if (a > b) {
                int temp = a;
                a = b;
                b = temp;
            }
            int num = a * 10 + b;
            result += count[num];
            count[num]++;
        }

        return result;
    }
}
