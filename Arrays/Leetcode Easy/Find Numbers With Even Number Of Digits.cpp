/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Zhzgik_hAdk
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/find-numbers-with-even-number-of-digits/description/
*/

/*********************************************************** C++ **************************************************/
//Approach-1 (Using simple loop and counting digits)
//T.C : O(n * log10m)
//S.C : O(1)
class Solution {
public:
    bool hasEvenDigits(int num) {
        int digitCount = 0;
        while (num) {
            digitCount++;
            num /= 10;
        }
        return (digitCount % 2) == 0;
    }

    int findNumbers(vector<int>& nums) {
        int result = 0;

        for (int num : nums) {
            if (hasEvenDigits(num))
                result++;
        }

        return result;
    }
};


//Approach-2 (converting to string)
//T.C : O(n * log10m)
//S.C : O(1)
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int result = 0;

        for (int num : nums) {
            string str = to_string(num);
            if (str.length() % 2 == 0)
                result++;
        }

        return result;
    }
};


//Approach-3 (Using floor)
//T.C : O(n), assuming floor(log10(num)) function takes constant time
//S.C : O(1)
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int result = 0;

        for (int &num : nums) {
            int digitCount = floor(log10(num)) + 1;
            
            if (digitCount % 2 == 0)
                result++;
        }

        return result;
    }
};


//Approach-4 (Using ceil)
//T.C : O(n), assuming ceil(log10(num)) function takes constant time
//S.C : O(1)
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int result = 0;

        for (int &num : nums) {
            int digitCount = ceil(log10(num+1));

            if (digitCount % 2 == 0)
                result++;
        }

        return result;
    }
};



//Approach-5 (making use of given constraints )
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();

        int result = 0;

        for(int i = 0; i < n; i++) {
            if((nums[i] >= 10 && nums[i] <= 99) || 
               (nums[i] >= 1000 && nums[i] <= 9999) ||
               (nums[i] == 100000)) {
                result++;
               }
        }

        return result;

    }
};


/*********************************************************** Java **************************************************/
//Approach-1 (Using simple loop and counting digits)
//T.C : O(n * log10m)
//S.C : O(1)
class Solution {
    public boolean hasEvenDigits(int num) {
        int digitCount = 0;
        while (num != 0) {
            digitCount++;
            num /= 10;
        }
        return (digitCount % 2) == 0;
    }

    public int findNumbers(int[] nums) {
        int result = 0;
        for (int num : nums) {
            if (hasEvenDigits(num)) {
                result++;
            }
        }
        return result;
    }
}


//Approach-2 (converting to string)
//T.C : O(n * log10m)
//S.C : O(1)
class Solution {
    public int findNumbers(int[] nums) {
        int result = 0;
        for (int num : nums) {
            String str = Integer.toString(num);
            if (str.length() % 2 == 0) {
                result++;
            }
        }
        return result;
    }
}


//Approach-3 (Using floor)
//T.C : O(n), assuming floor(log10(num)) function takes constant time
//S.C : O(1)
class Solution {
    public int findNumbers(int[] nums) {
        int result = 0;
        for (int num : nums) {
            int digitCount = (int)Math.floor(Math.log10(num)) + 1;
            if (digitCount % 2 == 0) {
                result++;
            }
        }
        return result;
    }
}


//Approach-4 (Using ceil)
//T.C : O(n), assuming ceil(log10(num)) function takes constant time
//S.C : O(1)
class Solution {
    public int findNumbers(int[] nums) {
        int result = 0;
        for (int num : nums) {
            int digitCount = (int)Math.ceil(Math.log10(num + 1));
            if (digitCount % 2 == 0) {
                result++;
            }
        }
        return result;
    }
}


//Approach-5 (making use of given constraints )
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int findNumbers(int[] nums) {
        int n = nums.length;
        int result = 0;
        for (int i = 0; i < n; i++) {
            if ((nums[i] >= 10 && nums[i] <= 99) ||
                (nums[i] >= 1000 && nums[i] <= 9999) ||
                (nums[i] == 100000)) {
                result++;
            }
        }
        return result;
    }
}
