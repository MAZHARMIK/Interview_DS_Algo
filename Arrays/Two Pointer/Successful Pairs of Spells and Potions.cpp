/*
      MY YOUTUBE VIDEO ON THIS Qn : <soon>
      Company Tags                : MICROSOFT
      Leetcode Link               : https://leetcode.com/problems/successful-pairs-of-spells-and-potions/
*/

//Approach-1 : Using lower_bound STL
//In my Binary Search sub-repo - https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Binary%20Search/Successful%20Pairs%20of%20Spells%20and%20Potions.cpp


//Approach-2 : Using self written Binary Search for lower bound
//In my Binary Search sub-repo - https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Binary%20Search/Successful%20Pairs%20of%20Spells%20and%20Potions.cpp

//Approach-3 (Using 2 pointers)
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<pair<int,int>> sortedSpells;
        for (int i = 0; i< spells.size(); ++i) {
            sortedSpells.push_back({ spells[i], i });
        }

        // Sort the 'spells with index' and 'potions' array in increasing order.
        sort(sortedSpells.begin(), sortedSpells.end());
        sort(potions.begin(), potions.end());

        vector<int> answer(spells.size());
        int m = potions.size();
        int potionIndex = m - 1;
        
        // For each 'spell' find the respective 'minPotion' index.
        for (const auto& [spell, index] : sortedSpells) {
          
            while (potionIndex >= 0 && (long long) spell * potions[potionIndex] >= success) {
                potionIndex -= 1;
            }
            answer[index] = m - (potionIndex + 1);
          
        }
        
        return answer;
    }
};
