/*
    MY YUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=PnyxRdn-N9U
    Company Tags               : Microsoft, Goldman Sachs, Cisco
    Leetcode Link              : https://leetcode.com/problems/sort-an-array/
*/
/**************************************** C++ ****************************************/
//solving using Counting Sort (O(n+k))
//S.C :O(k)
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int minE = *min_element(begin(nums), end(nums));
        int maxE = *max_element(begin(nums), end(nums));
        
        unordered_map<int, int> mp;
        
        for(int &num : nums)
            mp[num]++;
        
        int i = 0;
        
        for(int num = minE; num <= maxE; num++) {
            
            while(mp[num] > 0) {
                nums[i] = num;
                i++;
                mp[num]--;
            }
            
        }
        
        return nums;
    }
};

/**************************************** JAVA ****************************************/
//solving using Counting Sort (O(n+k))
//S.C :O(k)
class Solution {
    public int[] sortArray(int[] nums) {
        int minE = Arrays.stream(nums).min().getAsInt();
        int maxE = Arrays.stream(nums).max().getAsInt();

        Map<Integer, Integer> mp = new HashMap<>();

        for (int num : nums) {
            mp.put(num, mp.getOrDefault(num, 0) + 1);
        }

        int i = 0;

        for (int num = minE; num <= maxE; num++) {
            while (mp.getOrDefault(num, 0) > 0) {
                nums[i] = num;
                i++;
                mp.put(num, mp.get(num) - 1);
            }
        }

        return nums;
    }
}
