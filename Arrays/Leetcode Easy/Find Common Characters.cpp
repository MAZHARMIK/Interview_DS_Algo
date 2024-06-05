/*     Scroll below to see JAVA code also    */
/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=0sMVPGsY84w
      Company Tags                : will update soon
      Leetcode Link               : https://leetcode.com/problems/find-common-characters
*/


/************************************************************************ C++ ********************************************************/
//Approach (Simple iteration)
//T.C : O(n*w) , w = average length of each word. and n = number of words
//S.C : O(1)
class Solution {
public:
    void fillCountArray(string &word, int count[26]) {
        for(char &ch : word) {
            count[ch-'a']++;
        }
    }
    vector<string> commonChars(vector<string>& words) {
        vector<string> result;
        
        int n = words.size();
        
        int count[26] = {0};
        
        fillCountArray(words[0], count);

        for(int i = 1; i<n; i++) {
            int temp[26] = {0};
            
            fillCountArray(words[i], temp);

            for(int i = 0; i<26; i++) {
                if(count[i] != temp[i])
                    count[i] = min(count[i], temp[i]);
            }
            
        }
        
        for(int i = 0; i<26; i++) {
            if(count[i] != 0) {
                int c = count[i];
                while(c--) {
                    result.push_back(string(1, i+'a'));
                }
            }
        }
        
        return result;
    }
};


/************************************************************************ JAVA ********************************************************/
//Approach (Simple iteration)
//T.C : O(n*w) , w = average length of each word. and n = number of words
//S.C : O(1)
class Solution {
    public void fillCountArray(String word, int[] count) {
        for (char ch : word.toCharArray()) {
            count[ch - 'a']++;
        }
    }

    public List<String> commonChars(String[] words) {
        List<String> result = new ArrayList<>();

        int n = words.length;
        
        // Initialize the count array for the first word
        int[] count = new int[26];
        fillCountArray(words[0], count);

        // Iterate through the rest of the words and update the count array
        for (int i = 1; i < n; i++) {
            int[] temp = new int[26];
            fillCountArray(words[i], temp);

            for (int j = 0; j < 26; j++) {
                count[j] = Math.min(count[j], temp[j]);
            }
        }

        // Collect the common characters based on the count array
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                for (int j = 0; j < count[i]; j++) {
                    result.add(String.valueOf((char) (i + 'a')));
                }
            }
        }

        return result;
    }
}
