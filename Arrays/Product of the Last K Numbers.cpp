/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/product-of-the-last-k-numbers
*/


/************************************************************ C++ *****************************************************/
//Approach-1 (Brute Force)
//T.C : add() - O(1), getProduct() - O(k)
//S.C : O(n) for the stream
class ProductOfNumbers {
public:
    vector<int> nums;
    int n;
    ProductOfNumbers() {
        nums.clear();
        n = 0;
    }
    
    void add(int num) {
        nums.push_back(num);
    }
    
    int getProduct(int k) {
        int prod = 1;
        int n = nums.size();
        
        for(int i = n-k; i < n; i++) {
            prod *= nums[i];
        }

        return prod;
    }
};


//Approach-2 (Follow up optimal in O(1))
//T.C : O(1) for both methods
//S.C : O(n) for the stream
class ProductOfNumbers {
public:
    vector<int> nums; //cumulative prod store karenge
    int n;

    ProductOfNumbers() {
        nums.clear();
        n = 0;
    }
    
    void add(int num) {
        if(num == 0) {
            nums = {};
            n = 0;
        } else {
            if(nums.empty()) {
                nums.push_back(num);
            } else {
                nums.push_back(nums[n-1] * num);
            }
            n++; //increasing size by 1
        }
    }
    
    int getProduct(int k) {
        if(k > n) {
            return 0;
        } else if(k == n) {
            return nums[n-1];
        }

        return nums[n-1] / nums[n-k-1];
    }
};
