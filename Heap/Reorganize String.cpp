/*
    MY YOUTUBE VIDEO ON THIS Qn : 
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
