/*                                                                  Scroll down to see JAVA code also                                                                 */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=rMM8Brb-lko
    Company Tags                : Zoho, Snapdeal
    Leetcode Link               : https://leetcode.com/problems/check-if-the-sentence-is-pangram/
    GfG Link                    : https://practice.geeksforgeeks.org/problems/pangram-strings3155/1
*/

//Approach-1 (In 2 traversals)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> arr(26, 0);
        
        
        for(char &ch : sentence) {
            int index = ch - 'a';
            arr[index]++;
        }
        
        for(int &count : arr) {
            if(count == 0)
                return false;
        }
        
        
        return true;
    }
};


//Approach-2 (In 1 traversal)
//T.C : O(n) (1 Traversal)
//S.C : O(1)
class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> arr(26, 0);
        
        int count = 0;
        
        for(char &ch : sentence) {
            int index = ch - 'a';
            
            if(arr[index] == 0) {
                arr[index]++;
                count++;
            }
        }
        
        
        return count==26;
    }
};



/************************************************************************ JAVA ***************************************************************************/
//Approach-1 (In 2 traversals)
//T.C : O(n)
//S.C : O(1)
public class Solution {
    public boolean checkIfPangram(String sentence) {
        int[] arr = new int[26];

        for(char ch : sentence.toCharArray()) {
            int index = ch - 'a';
            arr[index]++;
        }

        for(int count : arr) {
            if(count == 0)
                return false;
        }

        return true;
    }
}


//Approach-2 (In 1 traversal)
//T.C : O(n) (1 Traversal)
//S.C : O(1)
public class Solution {
    public boolean checkIfPangram(String sentence) {
        int[] arr = new int[26];
        
        int count = 0;
        
        for(char ch : sentence.toCharArray()) {
            int index = ch - 'a';
            
            if(arr[index] == 0) {
                arr[index]++;
                count++;
            }
        }
        
        return count == 26;
    }
}
