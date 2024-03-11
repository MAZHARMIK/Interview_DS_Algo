/*		Scroll down to see JAVA code also		*/
/*
	MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=oGPfmp71Zm4
    	Company Tags  		    : Facebook, Amazon
    	Leetcode Link 		    : https://leetcode.com/problems/custom-sort-string/
*/

/*
	INTUITION : 
	The question is actually testing if we know about comparators in sorting.
	It just wants us to sort the string "str" but the ordering of characters must be in order
	of their indices they occur in string "order"
	
	It's similar to what I have shown below example :
	Example : 
	order = "cba"
	str      = "abcd"
	
	Assign numbers to characters of "order"
	c -> 0
	b -> 1
	a  -> 2
	
	Now, put those numbers in characters in "str"
	We get,
	a   b   c    d
	2   1   0   INF   (If a char is not present in "order" assign it the largest value)
	
	Now , we are sorting {2, 1, 0, INF} in ascending order
	{0, 1, 2, INF}
	correspnding characters are :
	{c, b, a, d}
	
	This is just the intuition about the approach.
	The actualy solution is just imply applying the comparator and it will be done.
*/

/********************************************************************* C++ *********************************************************************/
//Approach-1 (Just making use of frequency of each char) : 
//T.C : O(str.length())
//S.C : O(26) ~ O(1)
class Solution {
public:
    string customSortString(string order, string str) {
        int count[26] = {0};
        
        for(char &x : str)
            count[x-'a']++;
        
        string result = "";
        for(char &ch : order) {
            while(count[ch-'a']--) {
                result.push_back(ch);
            }
        }
        
        //Add the characters which are not present in 'order'
        for(char &ch : str) {
            if(count[ch-'a'] > 0) {
                result.push_back(ch);
            }
        }
        
        return result;
    }
};

//Approach-2 (Using comparator)
//T.C : O(nlogn)
//S.C : O(26) ~ O(1)
class Solution {
public:
    string customSortString(string order, string str) {
        vector<int> index(26, -1);
        
        for(int i = 0; i<order.length(); i++)
            index[order[i]-'a'] = i;
        
        
        auto lambda = [&index](char &ch1, char &ch2) {
            return index[ch1-'a'] < index[ch2-'a'];
        };
        
        sort(begin(str), end(str), lambda);
        return str;
        
    }
};

/*What was actually asked in Facebook :
FOLLOW UP NOTE : The original questions that was asked by Facebook was similar to
this but there was one small variation that "The characters which don't
occur in "str" must be sorted as per English Alphabet order".  In that case
one slight change will do the job in comparator function below :
*/
class Solution {
public:
    string customSortString(string order, string str) {
        vector<int> index(26, INT_MAX);
        
        for(int i = 0; i<order.length(); i++)
            index[order[i]-'a'] = i;
        
        
        auto lambda = [&](char &ch1, char &ch2) {
            if(index[ch1-'a'] == index[ch2-'a'])
                return ch1 < ch2;
            
            return index[ch1-'a'] < index[ch2-'a'];
        };
        
        sort(begin(str), end(str), lambda);
        return str;
        
    }
};



/********************************************************************* JAVA *********************************************************************/
//Approach-1 (Just making use of frequency of each char) : 
//T.C : O(str.length())
//S.C : O(26) ~ O(1)
public class Solution {
    public String customSortString(String order, String str) {
        int[] count = new int[26];

        for (char x : str.toCharArray())
            count[x - 'a']++;

        StringBuilder result = new StringBuilder();
        for (char ch : order.toCharArray()) {
            while (count[ch - 'a']-- > 0) {
                result.append(ch);
            }
        }

        // Add the characters which are not present in 'order'
        for (char ch : str.toCharArray()) {
            if (count[ch - 'a'] > 0) {
                result.append(ch);
            }
        }

        return result.toString();
    }
}

//Approach-2 (Using comparator)
//T.C : O(nlogn)
//S.C : O(26) ~ O(1)
public class Solution {
    public String customSortString(String order, String str) {
        Integer[] index = new Integer[26];
        Arrays.fill(index, -1);

        // Map characters to their positions in 'order'
        for (int i = 0; i < order.length(); i++)
            index[order.charAt(i) - 'a'] = i;

        Comparator<Character> lambda = (ch1, ch2) -> index[ch1 - 'a'].compareTo(index[ch2 - 'a']);

        Character[] charArray = new Character[str.length()];
        for (int i = 0; i < str.length(); i++) {
            charArray[i] = str.charAt(i);
        }

        Arrays.sort(charArray, lambda);

        // Convert Character array back to String
        StringBuilder result = new StringBuilder(charArray.length);
        for (char ch : charArray) {
            result.append(ch);
        }

        return result.toString();
    }
}
