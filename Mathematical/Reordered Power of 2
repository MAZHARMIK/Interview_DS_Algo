/*
    Company Tags  : Amazon (Modified version)
    Leetcode Link : https://leetcode.com/problems/reordered-power-of-2/
*/

class Solution {
public:
    vector<int> counter(int N) {
        vector<int> res(10);
        //Or, long res = 0;
        while(N) {
            res[N%10]++;
            //Or, res += pow(10, N%10);
            N/=10;
        }
        return res;
    }
    bool reorderedPowerOf2(int N) {
        vector<int> res = counter(N);
        for (int i = 0; i < 31; i++) {
            int num_pow_2 = (1<<i);
            if(res == counter(num_pow_2))
                return true;
        }
        return false;
    }
};
