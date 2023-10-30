/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=2owpaafBIgw
      Company Tags                : AMAZON
      Leetcode Link               : https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits
*/

/***************************************************************** C++ *****************************************************************/
//Approach-1 (Using self written countBits function inside lambda)
//T.C : O(n*logn * log(num)) 
//The countOneBits loop iterates for the number of bits in the input number, which is log₂(n)
//sort takes nlogn
class Solution {
public:
    int countOneBits(int num) {
        
        int count = 0;
        while (num) {
            
            count += num & 1;
            
            num >>= 1;
        }
        
        return count;
        
    }
    vector<int> sortByBits(vector<int>& arr) {
        
        auto lambda = [&](int &a, int &b) {
            
            int count_a = countOneBits(a);
            int count_b = countOneBits(b);
            
            if(count_a == count_b)
                return a<b;
            
            return count_a < count_b;
            
        };
        
        sort(begin(arr), end(arr), lambda);
        
        return arr;
    }
};


//Approach-2 (using inbuilt function)
//T.C : __builtin_popcount calculates the number of set bits (1 bits) in an integer in constant time, not depending on the size of the integer.
//So, overall T.C : O(nlogn) by sorting
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        
        auto lambda = [&](int &a, int &b) {
            
            int count_a = __builtin_popcount(a);
            int count_b = __builtin_popcount(b);
            
            if(count_a == count_b)
                return a<b;
            
            return count_a < count_b;
            
        };
        
        sort(begin(arr), end(arr), lambda);
        
        return arr;
    }
};


/***************************************************************** JAVA *****************************************************************/
//Approach-1 (Using self written countBits function inside lambda)
//T.C : O(n*logn * log(num)) 
//The countOneBits loop iterates for the number of bits in the input number, which is log₂(n)
//sort takes nlogn
class Solution {
    public int countOneBits(int num) {
        int count = 0;
        while (num != 0) {
            count += num & 1;
            num >>= 1;
        }
        return count;
    }

    public int[] sortByBits(int[] arr) {
        Integer[] boxedArr = new Integer[arr.length];
        for (int i = 0; i < arr.length; i++) {
            boxedArr[i] = arr[i];
        }

        Arrays.sort(boxedArr, (a, b) -> {
            int countA = countOneBits(a);
            int countB = countOneBits(b);

            if (countA == countB) {
                return a.compareTo(b);
            }

            return Integer.compare(countA, countB);
        });

        for (int i = 0; i < arr.length; i++) {
            arr[i] = boxedArr[i];
        }

        return arr;
    }
}


//Approach-2 (using inbuilt function)
//T.C : Integer.bitCount calculates the number of set bits (1 bits) in an integer in constant time, not depending on the size of the integer.
//So, overall T.C : O(nlogn) by sorting
import java.util.Arrays;

class Solution {
    public int[] sortByBits(int[] arr) {
        Integer[] boxedArr = new Integer[arr.length];
        for (int i = 0; i < arr.length; i++) {
            boxedArr[i] = arr[i];
        }

        Arrays.sort(boxedArr, (a, b) -> {
            int countA = Integer.bitCount(a);
            int countB = Integer.bitCount(b);

            if (countA == countB) {
                return a.compareTo(b);
            }

            return Integer.compare(countA, countB);
        });

        for (int i = 0; i < arr.length; i++) {
            arr[i] = boxedArr[i];
        }

        return arr;
    }
}
