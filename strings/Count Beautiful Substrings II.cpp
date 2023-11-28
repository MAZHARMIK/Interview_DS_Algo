/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Th4jtNqzyEc
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/count-beautiful-substrings-ii/
*/

/****************************************************************** C++ ******************************************************************/
//Approach-1 : (Using Simple Finding substrings)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    int beautifulSubstrings(string s, int k) {
        int n = s.length();
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            int vowels = 0;
            int consonants = 0;

            for (int j = i; j < n; j++) {
                if (isVowel(s[j])) {
                    vowels++;
                } else {
                    consonants++;
                }

                if (vowels == consonants && (vowels * consonants) % k == 0) {
                    count++;
                }
            }
        }
        
        return count;
    }
};


//Approach-2 (Using prefix Sum logic - Just like subarray sum finding)
//T.C :  O(n*k) where, k = avg size of mp[a-b]
//S.C : O(n) in worst case when a-b is always a new value (example : "aeiouaeiou" or "bhjklhjk")
class Solution {
public:
    #define ll long long

    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    long long beautifulSubstrings(string s, int k) {
        ll vowel = 0;
        ll consonant = 0;

        ll result = 0;

        unordered_map<ll, unordered_map<ll, ll>> mp; //key = (v-c) , value = map (vowel ka count past me -> count)
        mp[0][0] = 1;

        for(char &ch : s) {

            if(isVowel(ch)) {
                vowel++;
            } else {
                consonant++;
            }

            ll pSum = (vowel - consonant);

            for(auto &[pastVowelCount, count] : mp[pSum]) {
                
                //current substring vowewl count = vowel - pastVowelCount
                if((vowel%k - pastVowelCount) * (vowel%k - pastVowelCount) % k == 0) { //(a-b) * (a-b) % k -----> (a%k - b%k) * (a%k - b%k) %k
                    result += count;
                }

            }

            mp[pSum][vowel%k]++;
        }

        return result;
    }
};

/****************************************************************** JAVA ******************************************************************/
//Approach-1: (Using Simple Finding substrings)
//T.C : O(n^2)
//S.C : O(1)
public class Solution {
    public boolean isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    public int beautifulSubstrings(String s, int k) {
        int n = s.length();
        int count = 0;

        for (int i = 0; i < n; i++) {
            int vowels = 0;
            int consonants = 0;

            for (int j = i; j < n; j++) {
                if (isVowel(s.charAt(j))) {
                    vowels++;
                } else {
                    consonants++;
                }

                if (vowels == consonants && (vowels * consonants) % k == 0) {
                    count++;
                }
            }
        }

        return count;
    }
}


//Approach-2 (Using prefix Sum logic - Just like subarray sum finding)
//T.C :  O(n*k) where, k = avg size of mp[a-b]
//S.C : O(n) in worst case when a-b is always a new value (example : "aeiouaeiou" or "bhjklhjk")
public class Solution {

    private boolean isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    public long beautifulSubstrings(String s, int k) {
        long vowel = 0, cons = 0, result = 0;
        Map<Long, Map<Long, Long>> mp = new HashMap<>();
        mp.put(0L, new HashMap<>());
        mp.get(0L).put(0L, 1L);

        for (char ch : s.toCharArray()) {
            if (isVowel(ch)) {
                vowel++;
            } else {
                cons++;
            }

            long pSum = vowel - cons;
            for (Map.Entry<Long, Long> entry : mp.getOrDefault(pSum, new HashMap<>()).entrySet()) {
                long pastVowelCount = entry.getKey();
                long count = entry.getValue();
                if ((vowel % k - pastVowelCount) * (vowel % k - pastVowelCount) % k == 0) //(a-b) * (a-b) % k -----> (a%k - b%k) * (a%k - b%k) %k
                    result += count;
            }

            mp.computeIfAbsent(vowel - cons, key -> new HashMap<>()).merge(vowel % k, 1L, Long::sum);
        }

        return result;
    }
}
