/*     Scroll below to see JAVA code also    */
/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=QZI4TCVckpA
      Company Tags                : MICROSOFT
      Leetcode Link               : https://leetcode.com/problems/successful-pairs-of-spells-and-potions/
*/


/****************************************************************** C++ ******************************************************************/
//Approach-1 : Using lower_bound STL
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int m = spells.size();
        
        int n = potions.size();
        
        sort(begin(potions), end(potions));
        
        int maxPotion = potions[n-1];
        
        vector<int> answer;
        
        
        for(int i = 0; i<m; i++) {
            
            int spell = spells[i];
            
            long long minPotion = ceil((1.0*success)/spell);
            
            if(minPotion > maxPotion) {
                answer.push_back(0);
                continue;
            }
            
            int index = lower_bound(begin(potions), end(potions), minPotion) - begin(potions);
            
            answer.push_back(n-index);
            
        }
        
        return answer;
    }
};


//Approach-2 : Using self written Binary Search for lower bound
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    
    int BinarySearch(int l, int r, vector<int>& potions, int target) {
        
        //we have to find the index of first element greater than or equal to target (minPotion)
        
        int index = -1;
        int mid = 0;
        
        while(l <= r) {
            
            mid = l + (r-l)/2;
            
            if(potions[mid] >= target) {
                index = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
            
        }
        
        return index;
    }
    
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int m = spells.size();
        
        int n = potions.size();
        
        sort(begin(potions), end(potions));
        
        int maxPotion = potions[n-1];
        
        vector<int> answer;
        
        
        for(int i = 0; i<m; i++) {
            
            int spell = spells[i];
            
            long long minPotion = ceil((1.0*success)/spell);
            
            if(minPotion > maxPotion) {
                answer.push_back(0);
                continue;
            }
            
            int index = BinarySearch(0, n-1, potions, minPotion);//lower_bound(begin(potions), end(potions), minPotion) - begin(potions);
            
            answer.push_back(n-index);
            
        }
        
        return answer;
    }
};


//Approach-3 (Using 2 pointers - It will be posted in Two Pointer sub-repository)
//Two Pointer Sub-repo - https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Two%20Pointer/Successful%20Pairs%20of%20Spells%20and%20Potions.cpp




/****************************************************************** JAVA ******************************************************************/
//Approach : Using custom binary search for lower_bound
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
    public int[] successfulPairs(int[] spells, int[] potions, long success) {
        int m = spells.length;
        int n = potions.length;

        Arrays.sort(potions);
        int maxPotion = potions[n - 1];

        int[] answer = new int[m];

        for (int i = 0; i < m; i++) {
            int spell = spells[i];
            long minPotion = (long) Math.ceil((1.0 * success) / spell);

            if (minPotion > maxPotion) {
                answer[i] = 0;
                continue;
            }

            int index = lowerBound(potions, (int) minPotion);
            answer[i] = n - index;
        }

        return answer;
    }

    private int lowerBound(int[] arr, int target) {
        int l = 0, r = arr.length;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (arr[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return l;
    }
}
