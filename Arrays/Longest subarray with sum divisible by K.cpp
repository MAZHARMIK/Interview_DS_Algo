/*
    MY YOUTUBE VIDEO ON THIS Qn : (Same concept used another Qn Video Leetcode 974) https://www.youtube.com/watch?v=7Xeorb721LQ
    Company Tags                : Microsoft, Snapdeal
    GfG Link                    : https://www.geeksforgeeks.org/problems/longest-subarray-with-sum-divisible-by-k1259/1
*/

/*
  NOTE - Using same concept as Leetcode 974. Subarray Sums Divisible by K
         Video - https://www.youtube.com/watch?v=7Xeorb721LQ
*/

/****************************************************** C++ *************************************************************/
//T.C : O(n)
//S.C : O(n)
class Solution{
public:	
	int longSubarrWthSumDivByK(int nums[], int n, int k) {
        unordered_map<int, int> mp;
        int sum = 0;
        
        mp[0] = -1;
        
        int result = 0;
        
        for(int i = 0; i<n; i++) {
            sum += nums[i];
            
            int rem = sum%k;

            if(rem < 0) {
                rem += k;
            }
            
            if(mp.find(rem) != mp.end()) {
                result = max(result, i - mp[rem]); //1
            } else {
                mp[rem] = i;
            }
        }
        
        return result;
	}
};


/****************************************************** JAVA *************************************************************/
//T.C : O(n)
//S.C : O(n)
class Solution{
    int longSubarrWthSumDivByK(int a[], int n, int k) {
        // Complete the function
       Map<Integer, Integer> mp = new HashMap<>();
        int sum = 0;

        mp.put(0, -1);

        int result = 0;

        for (int i = 0; i < n; i++) {
            sum += a[i];

            int rem = sum % k;

            if (rem < 0) {
                rem += k;
            }

            if (mp.containsKey(rem)) {
                result = Math.max(result, i - mp.get(rem));
            } else {
                mp.put(rem, i);
            }
        }

        return result;
    }
 
}
