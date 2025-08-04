/*			Scroll below to see JAVA code also			*/
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=QBi5_btsse4
    Company Tag                 : will update later
    Leetcode Link               : https://leetcode.com/problems/fruit-into-baskets/description/
*/


/*************************************************************** C++ *************************************************/
//Approach (Sliding Window using map)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        unordered_map<int, int> mp;

        int i = 0;
        int j = 0;
        int count = 0;

        while(j < n) {
            mp[fruits[j]]++;

            if(mp.size() <= 2) {
                count = max(count, j-i+1);
            } else {
                mp[fruits[i]]--;
                if(mp[fruits[i]] == 0)
                    mp.erase(fruits[i]);
                i++;
            }

            j++;
        }
        return count;
    }
};



/*************************************************************** JAVA *************************************************/
//Approach (Sliding Window using map)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public int totalFruit(int[] fruits) {
        int n = fruits.length;
        HashMap<Integer, Integer> fruitMap = new HashMap<>();

        int i = 0; // Left pointer
        int j = 0; // Right pointer
        int count = 0; // Maximum number of fruits collected

        while (j < n) {
            // Add the fruit at the right pointer to the map
            fruitMap.put(fruits[j], fruitMap.getOrDefault(fruits[j], 0) + 1);

            // While more than 2 types of fruits are in the map, move the left pointer
            if (fruitMap.size() > 2) {
                fruitMap.put(fruits[i], fruitMap.get(fruits[i]) - 1);
                if (fruitMap.get(fruits[i]) == 0) {
                    fruitMap.remove(fruits[i]);
                }
                i++; // Move the left pointer to the right
            }

            // Calculate the maximum count of fruits collected
            count = Math.max(count, j - i + 1);

            // Move the right pointer to the right
            j++;
        }
        return count;
    }
}
