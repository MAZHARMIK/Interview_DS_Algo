/*
    Company Tags  : Facebook, Google (This qn was asked with variation : Leetcode-1641)
    Leetcode Link : https://leetcode.com/problems/count-sorted-vowel-strings/
    
    Similar Qn    : https://leetcode.com/problems/count-sorted-vowel-strings/
*/

//Approach-1 (Top Down - Recursion + Memo) Time : O(n)
class Solution {
public:
    int M = 1e9+7;
    int a = 0, e = 1, i = 2, o = 3, u = 4;
    vector<vector<long long>> t;
    
    /*
        Accoring to question : 
        a -> e
        e -> a, i
        i -> a, e, o, u
        o -> i, u
        u -> a
        So, count of strings of length n ending at 'a' ?
            We can have vowels 'e', 'i' & 'u' in which we can have ending vowel as 'a'
        So,         count of strings of length n ending at 'a'  = count of strings of length (n-1) ending at 'e', 'i', 'u'.
        
        similarly,  We can have vowels 'a' & 'i' in which we can have ending vowel as 'e'
                    We can have vowels 'e' & 'o' in which we can have ending vowel as 'i'
                    We can have vowels i' in which we can have ending vowel as 'o'
                    We can have vowels 'i' & 'o' in which we can have ending vowel as 'u'
        And in this fashion, we find the count recursively
    */
    int count(int n, int vowel) {
        if(t[n][vowel] != -1)
            return t[n][vowel];
        
        /*
            When n is 0, why dowe return 1 ?
            Let's look at the caller function countVowelPermutation()
            If n = 1, we would call 
            count(n-1, a) + count(n-1, e) + count(n-1, i) + count(n-1, o) + count(n-1, u)
            and for n = 1, we know that count is 5
            So, only if we return 1 from here, we will be able to get 5.
            This is how I found 
        */
        if(n == 0)
            return 1;
        
        if(vowel == a) {
            return t[n][vowel] = ((count(n-1, e) + count(n-1, i))%M + count(n-1, u))%M;
        } else if(vowel == e) {
            return t[n][vowel] = ((count(n-1, a) + count(n-1, i)))%M;
        } else if(vowel == i) {
            return t[n][vowel] = ((count(n-1, e) + count(n-1, o)))%M;
        } else if(vowel == o) {
            return t[n][vowel] = count(n-1, i);
        } else if(vowel == u) {
            return t[n][vowel] = ((count(n-1, i) + count(n-1, o)))%M;
        }
        
        return -1;
    }
    
    int countVowelPermutation(int n) {
        t.resize(n, vector<long long>(5, -1));
        long long result = 0;
        
        result = (result + count(n-1, a)) %M; //count(x, v) = # of strings of length x which ends at vowel v
        result = (result + count(n-1, e)) %M;
        result = (result + count(n-1, i)) %M;
        result = (result + count(n-1, o)) %M;
        result = (result + count(n-1, u)) %M;
        
        return result;
        
    }
};

//Approach-2 (Top Down DP : Just iterative version of Approach-1) Time : O(n)
class Solution {
public:
    int M = 1e9+7;
    int a = 0, e = 1, i = 2, o = 3, u = 4;
    
    int countVowelPermutation(int n) {
        long long t[n+1][5];
        //t[i][j] = # strings of length i ending with vowel j
        
        for(int vowel = a; vowel<=u; vowel++) {
            t[1][vowel] = 1;
        }
        
        for(int len = 2; len<=n; len++) {
            t[len][a] = ((t[len-1][e] + t[len-1][i])%M + t[len-1][u])%M;
            
            t[len][e] = (t[len-1][a] + t[len-1][i])%M;
            
            t[len][i] = (t[len-1][e] + t[len-1][o])%M;
            
            t[len][o] = t[len-1][i];
            
            t[len][u] = (t[len-1][i] + t[len-1][o])%M;
        }
        

        long long count = 0;
        for(int vowel = a; vowel <= u; vowel++) {
            count = (count+t[n][vowel])%M;
        }
        
        return count;
    }
};


//Approach-3 (We can apply approach-1 in same way asked in question)
/*
Instead of considering the string 'ending with vowel v', we consider strings 'starting with vowel v'
just as mentioned in the question. It's more intuitive
*/

class Solution {
public:
    int M = 1e9+7;
    int a = 0, e = 1, i = 2, o = 3, u = 4;
    vector<vector<long long>> t;
    
    /*
        Accoring to question : 
        a -> e
        e -> a, i
        i -> a, e, o, u
        o -> i, u
        u -> a
        So, count of strings of length n starting at 'a' ?
            We can have vowel 'e' after 'a'
        So, count of strings of length n starting at 'a'  = count of strings of length (n-1) starting at 'e' and so on.    
        And in this fashion, we find the count recursively
    */
    
    long long count(int n, int vowel) {
        if(t[n][vowel] != -1)
            return t[n][vowel];
        if(n == 0)
            return 1;
        
        if(vowel == a) {
            return t[n][vowel] = (count(n-1, e))%M;
        } else if(vowel == e) {
            return t[n][vowel] = ((count(n-1, a) + count(n-1, i)))%M;
        } else if(vowel == i) {
            return t[n][vowel] = (count(n-1, a) + count(n-1, e) + count(n-1, o) + count(n-1, u))%M;
        } else if(vowel == o) {
            return t[n][vowel] = (count(n-1, i) + count(n-1, u))%M;
        } else if(vowel == u) {
            return t[n][vowel] = (count(n-1, a))%M;
        }
        
        return 0;
    }
    
    int countVowelPermutation(int n) {
        t.resize(n, vector<long long>(5, -1));
        long long result = 0;
        
        result = (result + count(n-1, a)) %M; //count(x, v) = # of strings of length x which ends at vowel v
        result = (result + count(n-1, e)) %M;
        result = (result + count(n-1, i)) %M;
        result = (result + count(n-1, o)) %M;
        result = (result + count(n-1, u)) %M;
        
        return result;
        
    }
};
