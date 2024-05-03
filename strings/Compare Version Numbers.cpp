/*        Scroll below to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Mmy9hdPXwRc
    Company Tags                : Apple, Microsoft (They check how easily you are able to manage strict corner cases)
    Leetcode Link               : https://leetcode.com/problems/compare-version-numbers/
*/


/****************************************************************** C++ ******************************************************************/
//Approach (Using stringstream tokenizer in C++)
//T.C : O(m+n)
//S.C : O(m+n)
class Solution {
public:
    vector<string> getTokens(string version) {
        stringstream v(version);
        string token_v = "";
        vector<string> version_tokens;
        while(getline(v, token_v, '.')) {
            version_tokens.push_back(token_v);
        }
        return version_tokens;
    }
    int compareVersion(string version1, string version2) {

        vector<string> v1 = getTokens(version1);
        vector<string> v2 = getTokens(version2);  
        
        int m = v1.size();
        int n = v2.size();
            
        int  i = 0;
        while(i < m || i < n) {
            
            int a = i < m ? stoi(v1[i]) : 0 ;
            int b = i < n ? stoi(v2[i])  : 0 ;
            
            if(a > b)
                return 1;
            else if(b > a)
                return -1;
            else
                i++;
        }
        return 0;
    }
};


/****************************************************************** JAVA ******************************************************************/
//Approach-1 (Using StringTokenizer Class in JAVA)
//T.C : O(m+n)
//S.C : O(m+n)
import java.util.StringTokenizer;
class Solution {
    public int compareVersion(String version1, String version2) {
        List<String> v1 = getTokens(version1);
        List<String> v2 = getTokens(version2);
        
        int m = v1.size();
        int n = v2.size();
        
        int i = 0;
        while (i < m || i < n) {
            int a = i < m ? Integer.parseInt(v1.get(i)) : 0;
            int b = i < n ? Integer.parseInt(v2.get(i)) : 0;
            
            if (a > b)
                return 1;
            else if (b > a)
                return -1;
            else
                i++;
        }
        return 0;
    }
    
    private List<String> getTokens(String version) {
        StringTokenizer tokenizer = new StringTokenizer(version, ".");
        List<String> versionTokens = new ArrayList<>();
        while (tokenizer.hasMoreTokens()) {
            versionTokens.add(tokenizer.nextToken());
        }
        return versionTokens;
    }
}



//Approach-2 (Using split() method in JAVA)
//T.C : O(m+n)
//S.C : O(m+n)
class Solution {
    public int compareVersion(String version1, String version2) {
        List<String> v1 = getTokens(version1);
        List<String> v2 = getTokens(version2);
        
        int m = v1.size();
        int n = v2.size();
        
        int i = 0;
        while (i < m || i < n) {
            int a = i < m ? Integer.parseInt(v1.get(i)) : 0;
            int b = i < n ? Integer.parseInt(v2.get(i)) : 0;
            
            if (a > b)
                return 1;
            else if (b > a)
                return -1;
            else
                i++;
        }
        return 0;
    }
    
    private List<String> getTokens(String version) {
        String[] tokens = version.split("\\.");
        List<String> versionTokens = new ArrayList<>();
        for (String token : tokens) {
            versionTokens.add(token);
        }
        return versionTokens;
    }
}
