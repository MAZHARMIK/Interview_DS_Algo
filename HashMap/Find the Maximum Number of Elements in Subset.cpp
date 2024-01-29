/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/find-the-maximum-number-of-elements-in-subset/description/
*/

/*************************************************************** C++ ***************************************************************/
//T.C : O(n*logn(n))
//S.C : O(n)
public class Solution {
    public int maximumLength(int[] nums) {
        long result = 0;

        Map<Integer, Integer> mp = new HashMap<>();
        
        // Why ordered map?
        // We want to start from smallest to largest
        // Example: [14,14,196,196,38416,38416]
        for (int num : nums)
            mp.put(num, mp.getOrDefault(num, 0) + 1);

        for (Map.Entry<Integer, Integer> entry : mp.entrySet()) {
            int val = entry.getKey();
            int freq = entry.getValue();

            long length = 0;

            // Handling 1 separately because its square will be 1 only
            // example: [1,1,1,1,1,1,1,1,1,1,2,4,8,16,32,64,128,256,512,1024]
            if (val == 1) {
                length += freq;
                mp.put(val, 0);
            }

            while (val <= 1e9 && mp.get(val) > 0) {
                length += 2;

                if (mp.get(val) == 1) // We need at least 2
                    break;

                mp.put(val, 0); // set to zero, so that we do not check for this sequence again

                val = val * val;
            }

            if (length % 2 == 0) // Series length will be odd example: {2, 4, 2}, {2, 4, 16, 4, 2}
                length--;

            result = Math.max(result, length);
        }
        return (int) result;
    }
}


/*************************************************************** JAVA ***************************************************************/
//T.C : O(n*logn(n))
//S.C : O(n)
//Will soon update
