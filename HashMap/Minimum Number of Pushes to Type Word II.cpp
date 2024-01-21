/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=fX6sHghLCow
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/
*/


/******************************************************************** C++ ********************************************************************/
//Approach-1 (Using Map and doing as asked in Problem)
//T.C : O(n) + O(26log26) (for sorting)
//S.C : O(n)
class Solution {
public:
    //I am sorting to give priority to the char which has highest frequency
    //Because I would want it to come first in any button(key)
    void sortFunc(string &word) {
        unordered_map<char, int> mp;
        
        for(const char &ch : word) {
            mp[ch]++;
        }
        
        auto lambda=[&](const char &ch1, const char &ch2){
            return mp[ch1] > mp[ch2];
        };
        
        sort(begin(word), end(word), lambda);
    }
    
    int minimumPushes(string word) {
        if(word.length() <= 8) {
            return word.length();
        }
        sortFunc(word);
        unordered_map<int, unordered_set<char>> myMap;
        unordered_map<char, pair<int, int>> mp; //char is stored in which key in myMap and at what position it came
        
        int result = 0 ;
        int assign = 2;
        
        for(char &ch : word) {
            if(assign > 9) {
                assign = 2;
            }
            
            
            if(mp.find(ch) == mp.end()) {
                myMap[assign].insert(ch);
                mp[ch]            = {assign, (int)myMap[assign].size()};
                
                result += mp[ch].second;
                assign++;
            } else {
                result += mp[ch].second;
            }
        }
        
        return result;
        
    }
};


//Approach-2 (Simplifying and using same generic code as Part-1 of this problem)
//T.C : O(n) + O(26log26)
//S.C : O(1)
class Solution {
public:
    int minimumPushes(string word) {
        
        //Generic solution
        vector<int> mp(26, 0);
        for(char &ch: word)
            mp[ch - 'a']++; //Mentioned in qn, all letters will be distinct
    
        sort(begin(mp), end(mp), greater<int>()); //descending order of frequency
        
        int ans = 0;
        for(int i = 0; i < 26; i++){
            ans += mp[i]*((i/8) + 1);
        }
        return ans;
    }
};




/******************************************************************** JAVA ********************************************************************/
//Approach-1 (Using Map and doing as asked in Problem)
//T.C : O(n) + O(26log26) (for sorting)
//S.C : O(n)
public class Solution {
    // Sorting to give priority to the char which has the highest frequency
    // Because I would want it to come first in any button (key)
    private void sortFunc(StringBuilder word) {
        Map<Character, Integer> mp = new HashMap<>();

        for (char ch : word.toString().toCharArray()) {
            mp.put(ch, mp.getOrDefault(ch, 0) + 1);
        }

        word.chars()
                .distinct()
                .boxed()
                .sorted((ch1, ch2) -> mp.get(ch2) - mp.get(ch1))
                .forEachOrdered(ch -> word.setCharAt(0, (char) ch));
    }

    public int minimumPushes(String word) {
        if (word.length() <= 8) {
            return word.length();
        }

        StringBuilder sortedWord = new StringBuilder(word);
        sortFunc(sortedWord);

        Map<Integer, Set<Character>> myMap = new HashMap<>();
        Map<Character, int[]> mp = new HashMap<>(); // char is stored in which key in myMap and at what position it came

        int result = 0;
        int assign = 2;

        for (char ch : sortedWord.toString().toCharArray()) {
            if (assign > 9) {
                assign = 2;
            }

            if (!mp.containsKey(ch)) {
                myMap.computeIfAbsent(assign, k -> new HashSet<>()).add(ch);
                mp.put(ch, new int[]{assign, myMap.get(assign).size()});

                result += mp.get(ch)[1];
                assign++;
            } else {
                result += mp.get(ch)[1];
            }
        }

        return result;
    }
}


//Approach-2 (Simplifying and using same generic code as Part-1 of this problem)
//T.C : O(n) + O(26log26)
//S.C : O(1)
public class Solution {
    public int minimumPushes(String word) {
        int[] mp = new int[26];

        // Generic solution
        for (char ch : word.toCharArray()) {
            mp[ch - 'a']++; // Mentioned in the question, all letters will be distinct
        }

        // Descending order of frequency
        Integer[] mpInteger = Arrays.stream(mp).boxed().toArray(Integer[]::new);
        Arrays.sort(mpInteger, Comparator.reverseOrder());

        int ans = 0;
        for (int i = 0; i < 26; i++) {
            ans += mpInteger[i] * ((i / 8) + 1);
        }
        return ans;
    }
}
