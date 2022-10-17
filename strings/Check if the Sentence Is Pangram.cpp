/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=rMM8Brb-lko
    Company Tags                : Zoho, Snapdeal
    Leetcode Link               : https://leetcode.com/problems/check-if-the-sentence-is-pangram/
    GfG Link                    : https://practice.geeksforgeeks.org/problems/pangram-strings3155/1
*/

//Approach-1 (In 2 traversals)
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
        
        
        return conut==26;
    }
};
