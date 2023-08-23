/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=E3lJDtIHwg4
    Company Tags                : Amazon
    Leetcode Link               : https://leetcode.com/problems/reorganize-string/
*/

************************************ C++ ************************************
//Approach-1 (Using Max-heap)
class Solution {
public:
    typedef pair<int, char> P;
    
    string reorganizeString(string s) {
        int n = s.length();
        
        vector<int> count(26, 0);
        for(char &ch : s) {
            count[ch-'a']++;

            if(count[ch-'a'] > (n+1)/2)
                return "";
        }
        
        priority_queue<P, vector<P>> pq;
        for(char ch = 'a'; ch <= 'z'; ch++) {
            if(count[ch-'a'] > 0) {
                pq.push({count[ch-'a'], ch});

            }
         }
        
        string result = "";
        
        while(pq.size() >= 2) {
            auto P1 = pq.top(); 
            pq.pop();
            
            auto P2 = pq.top();
            pq.pop();
            
            result.push_back(P1.second);
            result.push_back(P2.second);
            
            P1.first--;
            P2.first--;
            
            if(P1.first > 0)
                pq.push(P1);
            
            if(P2.first > 0)
                pq.push(P2);
        }
        
        if(!pq.empty())
            result.push_back(pq.top().second);
        
        return result;
    }
};


//Approach-2 (Using odd/even placement)
class Solution {
public:
    string reorganizeString(string s) {
        
        int n = s.length();
        
        vector<int> count(26, 0);
        int maxFreq   = 0;
        char maxFreqCh;
        for(char &ch : s) {
            count[ch-'a']++;
            
            if(count[ch-'a'] > maxFreq) {
                maxFreq = count[ch-'a'];
                maxFreqCh = ch;
            }
            
            if(count[ch-'a'] > (n+1)/2)
                return "";
        }

        string result = s;
        int index     = 0;

        // Place the most frequent letter
        while (count[maxFreqCh-'a'] != 0) {
            result[index] = maxFreqCh;
            index += 2;
            count[maxFreqCh-'a']--;
        }

        // Place rest of the letters in any order
        for (char ch = 'a'; ch <= 'z'; ch++) {
            
            while (count[ch-'a'] > 0) {
                if (index >= n) {
                    index = 1;
                }
                result[index] = ch;
                index += 2;
                count[ch-'a']--;
            }
        }

        return result;
    }
};



************************************ JAVA ************************************
//Approach-1 (Using Max-heap)
class Solution {
    public String reorganizeString(String S) {

        Map<Character, Integer> map = new HashMap<>();
        for (char c : S.toCharArray()) {
            int count = map.getOrDefault(c, 0) + 1;
         
            if (count > (S.length() + 1) / 2) 
                return "";
            
            map.put(c, count);
        }

        
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[0] - a[0]);
        for (char c : map.keySet()) {
            pq.add(new int[] {map.get(c), c});
        }
        
        // Build the result.
        StringBuilder sb = new StringBuilder();
        while (pq.size() >= 2) {
            int[] first  = pq.poll();
            int[] second = pq.poll();
            
            sb.append((char) first[1]);
            sb.append((char) second[1]);
            
            first[0]--;
            second[0]--;
            
            if(first[0] > 0)
                pq.add(first);
            
            if(second[0] > 0)
                pq.add(second);

        }
        if(!pq.isEmpty()) {
            int[] first  = pq.poll();
            
            sb.append((char) first[1]);
        }
        
        return sb.toString();
    }
}


//Approach-2 (Using odd/even placement)
class Solution {
    public String reorganizeString(String s) {
        //dont know where the life will take me !!
        int len = s.length();
        int[] charFreq = new int[26];
        char[] ans = new char[len];


        char maxocc = '#';
        int maxlen = 0 ;

        for(char el : s.toCharArray())
        {
            charFreq[el-'a']++;

            if(charFreq[el-'a'] > (len+1)/2) return "";

            if(charFreq[el-'a'] > maxlen) {
                maxlen = charFreq[el-'a'];
                maxocc = el;
            }
        }
        int j = 0 ;
        while(maxlen > 0)
        {
            ans[j] = maxocc;
            j+=2;
            maxlen--;
            charFreq[maxocc - 'a']--;
        }

        for(char i = 'a' ; i <= 'z' ;i++)
        {
           
            while(charFreq[i-'a'] > 0)
            {
                if(j > len-1) j = 1;
                ans[j] = i;
                j+=2;
                charFreq[i-'a']--;
            }
        }

        return new String(ans);
    }
}
