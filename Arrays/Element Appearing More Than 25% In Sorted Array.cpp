/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=6BoymP9R9MM
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/
*/


/************************************************************ C++ ************************************************************************/
//Approach-1 (Using map)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        
        unordered_map<int, int> mp;
        
        int freq = n / 4;
        
        for (int &num : arr) {
            mp[num]++;
            if (mp[num] > target) {
                return num;
            }
        }

        return -1;
    }
};


//Approach-2 (Using sorted property) - Equal elements will occur together
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int freq = n/4;
        
        for(int i = 0; i<n-freq; i++) {
          
            if(arr[i] == arr[i+freq]) {
                return arr[i];
            }   
          
        }
        return -1;
    }
};


//Approach-3 (Using Binary Search) - Array is sorted
//T.C : O(3*logn) ~ O(log(n)
//S.C : O(1)
class Solution {
public:
    
    int firstOccur(int target, int l, int r, vector<int>& arr) {
        
        int result = -1;
        
        while(l <= r) {
            int mid = l + (r-l)/2;
            
            if(arr[mid] == target) {
                result = mid;
                r = mid-1;
            } else if(arr[mid] < target) {
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        
        return result;
        
    }
    
    int lastOccur(int target, int l, int r, vector<int>& arr) {
        
        int result = -1;
        
        while(l <= r) {
            int mid = l + (r-l)/2;
            
            if(arr[mid] == target) {
                result = mid;
                l = mid+1;
            } else if(arr[mid] < target) {
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        
        return result;
        
    }
    
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        
        int freq = n/4;
        
        vector<int> candidates{arr[n/4], arr[n/2], arr[3*n/4]};
        
        for(int &candidate : candidates) {
            
            int left = firstOccur(candidate, 0, n-1, arr);
            int right = lastOccur(candidate, 0, n-1, arr);
            
            
            if(right-left+1 > freq) {
                return candidate;
            }
        }
        
        return -1;
        
    }
};



/************************************************************ JAVA ************************************************************************/
//Approach-1 (Using map)
//T.C : O(n)
//S.C : O(n)
public class Solution {
    public int findSpecialInteger(int[] arr) {
        int n = arr.length;
        int freq = n / 4;

        for (int i = 0; i < n - freq; i++) {
            if (arr[i] == arr[i + freq]) {
                return arr[i];
            }
        }

        return -1;
    }
}


//Approach-2 (Using sorted property) - Equal elements will occur together
//T.C : O(n)
//S.C : O(1)
public class Solution {
    public int findSpecialInteger(int[] arr) {
        int n = arr.length;

        HashMap<Integer, Integer> map = new HashMap<>();
        int target = n / 4;

        for (int num : arr) {
            map.put(num, map.getOrDefault(num, 0) + 1);
            if (map.get(num) > target) {
                return num;
            }
        }

        return -1;
    }

}



//Approach-3 (Using Binary Search) - Array is sorted
//T.C : O(3*logn) ~ O(log(n)
//S.C : O(1)
import java.util.Arrays;
import java.util.List;

public class Solution {
    private int firstOccur(int target, int l, int r, int[] arr) {
        int result = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (arr[mid] == target) {
                result = mid;
                r = mid - 1;
            } else if (arr[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return result;
    }

    private int lastOccur(int target, int l, int r, int[] arr) {
        int result = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (arr[mid] == target) {
                result = mid;
                l = mid + 1;
            } else if (arr[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return result;
    }

    public int findSpecialInteger(int[] arr) {
        int n = arr.length;

        int freq = n / 4;

        List<Integer> candidates = Arrays.asList(arr[n / 4], arr[n / 2], arr[3 * n / 4]);

        for (int candidate : candidates) {
            int left = firstOccur(candidate, 0, n - 1, arr);
            int right = lastOccur(candidate, 0, n - 1, arr);

            if (right - left + 1 > freq) {
                return candidate;
            }
        }

        return -1;
    }
}


