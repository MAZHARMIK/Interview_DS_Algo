/*        Scroll below to see JAVA code also        */
/*
    MY YOUTUBE VIDEO IN THIS QN : https://www.youtube.com/watch?v=3yL6gQz4vTc
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/finding-pairs-with-a-certain-sum
*/


/***************************************************************** C++ *****************************************************************/
//Approach (Using map and approach similar to Two Sum Problem)
//T.C : O(m+n) for FindSumPairs(), O(1) for add() and O(n) for count()
//S.C : O(m+n) for vec1 and vec2
class FindSumPairs {
public:
    vector<int> vec1, vec2;
    unordered_map<int, int> mp;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        vec1 = nums1;
        vec2 = nums2;
        for(int &x : vec2) {
            mp[x]++;
        }
    }
    
    void add(int index, int val) {
        mp[vec2[index]]--;
        vec2[index] += val;
        mp[vec2[index]]++;
    }
    
    int count(int tot) {
        int c = 0;
        for(int &x : vec1) {
            c += mp[tot-x];
        }

        return c;
    }
};



/***************************************************************** JAVA *****************************************************************/
//Approach (Using map and approach similar to Two Sum Problem)
//T.C : O(m+n) for FindSumPairs(), O(1) for add() and O(n) for count()
//S.C : O(m+n) for vec1 and vec2
class FindSumPairs {
    private List<Integer> nums1;
    private List<Integer> nums2;
    private Map<Integer, Integer> frequencyMap;

    public FindSumPairs(int[] nums1, int[] nums2) {
        this.nums1 = new ArrayList<>();
        for (int num : nums1) {
            this.nums1.add(num);
        }

        this.nums2 = new ArrayList<>();
        for (int num : nums2) {
            this.nums2.add(num);
        }

        frequencyMap = new HashMap<>();
        for (int num : nums2) {
            frequencyMap.put(num, frequencyMap.getOrDefault(num, 0) + 1);
        }
    }

    public void add(int index, int val) {
        int oldVal = nums2.get(index);
        frequencyMap.put(oldVal, frequencyMap.get(oldVal) - 1);
        if (frequencyMap.get(oldVal) == 0) {
            frequencyMap.remove(oldVal);
        }

        int newVal = oldVal + val;
        nums2.set(index, newVal);
        frequencyMap.put(newVal, frequencyMap.getOrDefault(newVal, 0) + 1);
    }

    public int count(int tot) {
        int count = 0;
        for (int num : nums1) {
            int complement = tot - num;
            count += frequencyMap.getOrDefault(complement, 0);
        }
        return count;
    }
}
