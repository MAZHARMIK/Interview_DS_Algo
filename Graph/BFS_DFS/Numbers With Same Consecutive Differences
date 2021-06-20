/*
    Company Tags  : Flipkart
    Leetcode Link : https://leetcode.com/problems/numbers-with-same-consecutive-differences/
*/

//Approach-1 (DFS) (Time : O(9*2^(n-1))
class Solution {
public:
    vector<int> result;
    void generate(int start, int n, int k, int len) {
        if(len > n)
            return;

        if(len == n) {
            result.push_back(start);
            return;
        }

        int remain = start%10;
        int temp;
        if(remain+k < 10) {
            temp = start;
            temp = (temp*10) + remain+k;
            generate(temp, n, k, len+1);
        }
        if(remain-k >= 0 && k != 0) {
            temp = start;
            temp= (temp*10) + remain-k;
            generate(temp, n, k, len+1);
        }
        
    }

    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i = 1; i<=9; i++) {
            generate(i, n, k, 1);
        }
        return result;
    }
};

//Approach-2 (BFS) (Time : O(9*2^(n-1))
class Solution {
public:
    vector<int> result;
    void generate(int n, int k) {
        queue<int> que;
        for(int i = 1; i<10; i++) {
            que.push(i);
        }
        
        int level = 1;
        while(level < n) { //Every level has (level) number of digits
            int len = que.size();
            while(len--) {
                int curr = que.front();
                que.pop();
                int remain = curr%10;
                
                if(remain - k >= 0) {
                    que.push((curr*10) + (remain-k));
                }
                if(remain + k <= 9 && k!= 0) {
                    que.push((curr*10) + (remain+k));
                }
            }
            level++;
        }
        
        while(!que.empty()) {
            result.push_back(que.front());
            que.pop();
        }
    }

    vector<int> numsSameConsecDiff(int n, int k) {
        generate(n, k);
        return result;
    }
};
