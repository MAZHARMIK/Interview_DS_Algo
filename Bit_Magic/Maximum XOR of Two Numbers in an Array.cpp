/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=JS48Hp2_Z4I
    Company Tags                : Microsoft
    Leetcode Link               : https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
*/


/******************************************************** C++ ****************************************************************/
//T.C : O(32*n)
class Solution {
public:
    struct trieNode {
        trieNode* left;
        trieNode* right;
    };
    
    void insert(trieNode* head, int& num) {
        trieNode* pCrawl = head;
        for(int i = 31; i>=0; i--) {
            int ith_bit = (num>>i)&1;
            if(ith_bit == 0) {
                if(!pCrawl->left) {
                    pCrawl->left = new trieNode();
                }
                pCrawl = pCrawl->left;
            } else {
                if(!pCrawl->right) {
                    pCrawl->right = new trieNode();
                }
                pCrawl = pCrawl->right;
            }
        }
    }
    
    int maxXor(trieNode* head, int &num) {
        int maxXor = 0;
        trieNode* pCrawl = head;
        //I am moving from left most bit(MSB) to right most(LSB) to get max answer so as to get set bit 1 in left most position (MSB) to get large decimal value
        for(int i = 31; i>=0; i--) {
            int ith_bit = (num>>i)&1;
            //I want maximum one in my result of xor
            //so, if I have current bit of 'num' = 1, I will select path where I get 0 in some other number
            if(ith_bit == 1) {
                if(pCrawl->left) {
                    maxXor += pow(2, i); //if I am able to go to left, I can get 1 as XOR result of ith bit of both numbers (which is required)
                    pCrawl =  pCrawl->left;
                } else {

                    pCrawl =  pCrawl->right;
                }
            } else {
                if(pCrawl->right) {
                    maxXor += pow(2, i); //if I am able to go to right, I can get 1 as XOR result of ith bit of both numbers (which is required)
                    pCrawl=  pCrawl->right;
                } else {
                    pCrawl=  pCrawl->left;
                }
            }
        }
        return maxXor;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        trieNode* root = new trieNode();
        for(int &x: nums) {
            insert(root, x);
        }

        int result = 0;

        for(int &x : nums) {
            result = max(result, maxXor(root, x));
        }
        return result;
    }
};



/******************************************************** JAVA ****************************************************************/
//T.C : O(32*n)
public class Solution {
    static class TrieNode {
        TrieNode left;
        TrieNode right;
    }

    public void insert(TrieNode head, int num) {
        TrieNode pCrawl = head;
        for (int i = 31; i >= 0; i--) {
            int ithBit = (num >> i) & 1;
            if (ithBit == 0) {
                if (pCrawl.left == null) {
                    pCrawl.left = new TrieNode();
                }
                pCrawl = pCrawl.left;
            } else {
                if (pCrawl.right == null) {
                    pCrawl.right = new TrieNode();
                }
                pCrawl = pCrawl.right;
            }
        }
    }

    public int maxXor(TrieNode head, int num) {
        int maxXor = 0;
        TrieNode pCrawl = head;
        //I am moving from left most bit(MSB) to right most(LSB) to get max answer so as to get set bit 1 in left most position (MSB) to get large decimal value
        for (int i = 31; i >= 0; i--) {
            int ithBit = (num >> i) & 1;
            if (ithBit == 1) {
                if (pCrawl.left != null) {
                    maxXor += Math.pow(2, i);
                    pCrawl = pCrawl.left;
                } else {
                    pCrawl = pCrawl.right;
                }
            } else {
                if (pCrawl.right != null) {
                    maxXor += Math.pow(2, i);
                    pCrawl = pCrawl.right;
                } else {
                    pCrawl = pCrawl.left;
                }
            }
        }
        return maxXor;
    }

    public int findMaximumXOR(int[] nums) {
        TrieNode root = new TrieNode();
        for (int x : nums) {
            insert(root, x);
        }

        int result = 0;

        for (int x : nums) {
            result = Math.max(result, maxXor(root, x));
        }
        return result;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums = {3, 10, 5, 25, 2, 8};
        System.out.println(solution.findMaximumXOR(nums));
    }
}
