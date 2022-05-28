/*
    Company Tags  : Not known yet but it's a wonderful concept
    Leetcode Link : https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/
*/


//Using Meet In The Middle Technique
class Solution {
public:
    
    void printVector(vector<vector<int> >& vec, int& N ) {
        for(int size = 0; size < N+1; size++) {
            cout << "For size = " << size << " : ";
            for(int j = 0; j<vec[size].size(); j++) {
                cout << vec[size][j] << ", ";
            }
            cout << "\n";
        }
        cout << "\n-------\n";
    }
    
    int minimumDifference(vector<int>& nums) {
    int n = nums.size();
        
    int N = n/2;
    int totalSum = accumulate(begin(nums), end(nums), 0);
    vector<vector<int> > left(N+1), right(N+1);
        
    //left[i] = {} ; //sum of subset of size i from left array
    //right[i] = {} ; //sum of subset of size i from right array
    for(int mask = 0; mask < (1 << N); mask++) {
        int size = 0, leftSum = 0, rigthSum = 0;
        for(int index = 0; index < N; index++) {
            if(mask & (1 << index)) {
                //index bit in mask is set (1), so take nums[index] element for left and nums[index+N] for right
                size++;
                leftSum  += nums[index];
                rigthSum += nums[index+N];
            }
        }

        left[size].push_back(leftSum);
        right[size].push_back(rigthSum);
    }
    //printVector(left, N);
    //printVector(right, N);

    //You take a subset from left of size  = leftSize; leftSum = a;
    //You will have to take a subset from right of size = N-leftSize; rightSum = b;
    //So, you got one subset (Part1) after choosing i.e.
    // Part1Sum = a + b
    // size of Part1 = N;

    //Similarly we do for Part2 i.e. Part2Sum

    //Now, we want minimum abs diff for : abs(Part1Sum - Part2Sum) ---------- Eqn(1)
    //Also, we know Part2Sum = TotalSum - Part1Sum --------- Eqn(2)
    //Put Eqn(2) in Eqn(1)
    //we want minimum abs diff for : abs(Part1Sum - (TotalSum-Part1Sum))
    //or, abs(TotalSum - 2*Part1Sum)  =  abs(TotalSum - 2*(a+b));
    /*
        If we take an 'a' from left , we can binary search for 'b' in right (after sorting right)
    */
        for (auto &arr : right) {
           sort(begin(arr), end(arr));
       }
        

       int minDiff = min(abs(totalSum-2*left[N][0]), abs(totalSum-2*right[N][0]));
       for(int leftSize = 1; leftSize < N; leftSize++) {
           for(auto &a : left[leftSize]) {
                int rightSize = N-leftSize;

                int b         = (totalSum - (2*a))/2; //rightSum

                //Now, binary search for 'b' in right
                std::vector<int>::iterator itr = lower_bound(begin(right[rightSize]), end(right[rightSize]), b);

                if(itr != right[rightSize].end()) {
                    minDiff = min(minDiff, abs(totalSum - 2*(a + *itr)));
                }

                //since lower_bound returns the first element greater than or equal to
                //if it was greater than the element, we should check the left left to it as well.
                /*
                    For example : I searched for 6 in {1, 2, 4, 10}
                    I will get 10
                    But, abs(10-6) = 4
                    And abs()
                */
               
           }

       }
        
        return minDiff;
        
    }
};
