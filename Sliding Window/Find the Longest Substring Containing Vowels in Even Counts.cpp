/*        Scroll below to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=6Xf5LfM-ciI
    Company Tags                : Yogiyo (Food delivering app)
    Leetcode Link               : https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/
*/

/*
    NOTE : Why sliding window is not a feasible for this ?
    Example : "leetcodeisgreat"
    When i is at index 1 and j is at index 5, you don't know if we should move i to right or ignore jth character.
*/

/**************************************************** C++ ****************************************************/
//Approach-1 (Using map to store states)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<string, int> mp;
    
        // Initialize an array to track the count of each vowel
        vector<int> vowelCount(5, 0); // Count of 'a', 'e', 'i', 'o', 'u'

        string currentState = "00000";  // Initial state where all vowels have even counts
        mp[currentState] = -1;
        
        int maxLength = 0;

        for (int i = 0; i < s.length(); ++i) {
            // Update count for the vowel encountered
            if (s[i] == 'a')      vowelCount[0] = (vowelCount[0] + 1) % 2;
            else if (s[i] == 'e') vowelCount[1] = (vowelCount[1] + 1) % 2;
            else if (s[i] == 'i') vowelCount[2] = (vowelCount[2] + 1) % 2;
            else if (s[i] == 'o') vowelCount[3] = (vowelCount[3] + 1) % 2;
            else if (s[i] == 'u') vowelCount[4] = (vowelCount[4] + 1) % 2;

            // Create a string representing the current parity state of vowels
            currentState = "";
            for (int j = 0; j < 5; ++j) {
                currentState += to_string(vowelCount[j]);
            }

            // Check if we've seen this state before
            if (mp.find(currentState) != mp.end()) {
                // Calculate the length of the substring
                maxLength = max(maxLength, i - mp[currentState]);
            } else {
                // Store the first occurrence of this state
                mp[currentState] = i;
            }
        }

        return maxLength;
    }
};


//Approach-2 (Using map to store states and using XOR to make states)
//T.C : O(n)
//S.C ; O(1)
class Solution {
public:
    int findTheLongestSubstring(string s) {
        // Map to store the first occurrence of a state of vowel parities
        unordered_map<string, int> mp;
        
        // Initialize an array to track the parity of each vowel
        vector<int> state(5, 0); // [a, e, i, o, u] initialized to 0 (even count)

        string currentState = "00000";  // Start with all vowels having an even count
        mp[currentState] = -1;
        
        int maxLength = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            // Update state based on the vowel encountered
            if (s[i] == 'a') state[0] ^= 1;  // Flip between even/odd for 'a'
            else if (s[i] == 'e') state[1] ^= 1; // Flip for 'e'
            else if (s[i] == 'i') state[2] ^= 1; // Flip for 'i'
            else if (s[i] == 'o') state[3] ^= 1; // Flip for 'o'
            else if (s[i] == 'u') state[4] ^= 1; // Flip for 'u'

            // Create a string representation of the current state
            currentState = "";
            for (int j = 0; j < 5; ++j) {
                currentState += to_string(state[j]);
            }

            // Check if we've seen this state before
            if (mp.find(currentState) != mp.end()) {
                // Calculate the length of the substring
                maxLength = max(maxLength, i - mp[currentState]);
            } else {
                // Store the first occurrence of this state
                mp[currentState] = i;
            }
        }

        return maxLength;
    }
};

//Approach-3 (using Mask and Xor property
//T.C : O(n)
//S.C : O(32) ~ O(1) - Maximum 2^5 states possible
//This belongs to Bit_Magic repository as well (You will find the link to this question in Bit_magic repository as well)
class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> mp;
        int mask = 0;
        mp[mask] = -1;
        int maxL = 0;
        for(int i = 0; i<s.length(); i++) {
            int val = 0;
            if (s[i] == 'a')      val  = (1 << 0);
            else if (s[i] == 'e') val = (1 << 1);
            else if (s[i] == 'i') val = (1 << 2);
            else if (s[i] == 'o') val = (1 << 3);
            else if (s[i] == 'u') val = (1 << 4);
            
            mask = mask^val; //xor nikala
            
            if(!mp.count(mask)) //agar past me nahi dekha to map me daaldo
                mp[mask] = i;
            
            maxL = max(maxL, i - mp[mask]); //maxL nikaal lo
        }
        return maxL;
    }
};




/**************************************************** JAVA ****************************************************/
//Approach-1 (Using map to store states)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int findTheLongestSubstring(String s) {
        Map<String, Integer> mp = new HashMap<>();
        
        // Initialize an array to track the count of each vowel
        int[] vowelCount = new int[5]; // Count of 'a', 'e', 'i', 'o', 'u'

        String currentState = "00000";  // Initial state where all vowels have even counts
        mp.put(currentState, -1);
        
        int maxLength = 0;

        for (int i = 0; i < s.length(); ++i) {
            // Update count for the vowel encountered
            if (s.charAt(i) == 'a')      vowelCount[0] = (vowelCount[0] + 1) % 2;
            else if (s.charAt(i) == 'e') vowelCount[1] = (vowelCount[1] + 1) % 2;
            else if (s.charAt(i) == 'i') vowelCount[2] = (vowelCount[2] + 1) % 2;
            else if (s.charAt(i) == 'o') vowelCount[3] = (vowelCount[3] + 1) % 2;
            else if (s.charAt(i) == 'u') vowelCount[4] = (vowelCount[4] + 1) % 2;

            // Create a string representing the current parity state of vowels
            currentState = "";
            for (int j = 0; j < 5; ++j) {
                currentState += vowelCount[j];
            }

            // Check if we've seen this state before
            if (mp.containsKey(currentState)) {
                // Calculate the length of the substring
                maxLength = Math.max(maxLength, i - mp.get(currentState));
            } else {
                // Store the first occurrence of this state
                mp.put(currentState, i);
            }
        }

        return maxLength;
    }
}


//Approach-2 (Using map to store states and using XOR to make states)
//T.C : O(n)
//S.C ; O(1)
class Solution {
    public int findTheLongestSubstring(String s) {
        // Map to store the first occurrence of a state of vowel parities
        Map<String, Integer> mp = new HashMap<>();
        
        // Initialize an array to track the parity of each vowel
        int[] state = new int[5]; // [a, e, i, o, u] initialized to 0 (even count)

        String currentState = "00000";  // Start with all vowels having an even count
        mp.put(currentState, -1);
        
        int maxLength = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            // Update state based on the vowel encountered
            if (s.charAt(i) == 'a') state[0] ^= 1;  // Flip between even/odd for 'a'
            else if (s.charAt(i) == 'e') state[1] ^= 1; // Flip for 'e'
            else if (s.charAt(i) == 'i') state[2] ^= 1; // Flip for 'i'
            else if (s.charAt(i) == 'o') state[3] ^= 1; // Flip for 'o'
            else if (s.charAt(i) == 'u') state[4] ^= 1; // Flip for 'u'

            // Create a string representation of the current state
            currentState = "";
            for (int j = 0; j < 5; ++j) {
                currentState += state[j];
            }

            // Check if we've seen this state before
            if (mp.containsKey(currentState)) {
                // Calculate the length of the substring
                maxLength = Math.max(maxLength, i - mp.get(currentState));
            } else {
                // Store the first occurrence of this state
                mp.put(currentState, i);
            }
        }

        return maxLength;
    }
}



//Approach-3 (using Mask and Xor property
//T.C : O(n)
//S.C : O(32) ~ O(1) - Maximum 2^5 states possible
//This belongs to Bit_Magic repository as well (You will find the link to this question in Bit_magic repository as well)
class Solution {
    public int findTheLongestSubstring(String s) {
        Map<Integer, Integer> mp = new HashMap<>();
        int mask = 0;
        mp.put(mask, -1);
        int maxL = 0;
        for (int i = 0; i < s.length(); i++) {
            int val = 0;
            if (s.charAt(i) == 'a')      val = (1 << 0);
            else if (s.charAt(i) == 'e') val = (1 << 1);
            else if (s.charAt(i) == 'i') val = (1 << 2);
            else if (s.charAt(i) == 'o') val = (1 << 3);
            else if (s.charAt(i) == 'u') val = (1 << 4);

            mask ^= val; //xor nikala
            
            if (!mp.containsKey(mask)) //agar past me nahi dekha to map me daaldo
                mp.put(mask, i);
            
            maxL = Math.max(maxL, i - mp.get(mask)); //maxL nikaal lo
        }
        return maxL;
    }
}
