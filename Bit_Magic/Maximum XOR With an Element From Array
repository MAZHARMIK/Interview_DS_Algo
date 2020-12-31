/*
    Asked in Leetcode Weekly Contest : https://leetcode.com/contest/weekly-contest-221
    Company Tags  : NIL (Please let me know if you get it :-) )
    Leetcode Link : https://leetcode.com/problems/maximum-xor-with-an-element-from-array/
*/

class Solution {
public:
    struct trieNode{
        trieNode* left;
        trieNode* right;
    };
    
    void insert(trieNode* root, int num) {
        trieNode* pCrawl = root;
        
        for(int i = 31; i>=0; i--) {
            int bit = ((num>>i)&1);
            if(bit == 0) {
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
    
    int find(trieNode* root, int num) {
        int val = 0;
        trieNode* pCrawl = root;
        for(int i = 31; i>=0; i--) {
            int bit = (num>>i)&1;
            if(bit == 1) {
                //to maximize I would want to go to left
                if(pCrawl->left) {
                    val += pow(2, i);
                    pCrawl = pCrawl->left;
                } else {
                    pCrawl = pCrawl->right;
                }
            } else {
                //to maximize I would want to go to left
                if(pCrawl->right) {
                    val += pow(2, i);
                    pCrawl = pCrawl->right;
                } else {
                    pCrawl = pCrawl->left;
                }
            }
        }
        return val;
    }
    
    static bool myFunction(vector<int>& v1, vector<int>& v2) {
        return v1[1] < v2[1];
    }
    
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        trieNode* root = new trieNode();
        //How to preserve index of queries ?
        //keep one more value in the query i.e. index
        for(int i = 0; i<queries.size(); i++) {
            queries[i].push_back(i); //saving index
        }
        sort(nums.begin(), nums.end()); //[0,1,2,3,4]
        sort(queries.begin(), queries.end(), myFunction); //[[3,1],[1,3],[5,6]]
        vector<int> result(queries.size());
        int i = 0;
        int n = nums.size();
        for(vector<int> vec:queries) {
            
            for(;i<n; i++) {
                if(nums[i] > vec[1])
                    break;
                insert(root, nums[i]);
            }
            
            if(i == 0)
                result[vec[2]] = -1; //remember we saved the index above. That's why vec[2]
            else
                result[vec[2]] = find(root, vec[0]);
        }
        
        return result;
    }
};
