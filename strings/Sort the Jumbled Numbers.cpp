/*     Scroll below to see JAVA code also  */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=BXHWgX4UX04
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/sort-the-jumbled-numbers
*/

/**************************************************** C++ ****************************************************/
//Approach-1 (Converting to string)
//T.C : O(n*d + nlogn) , Here, n is the size of the nums vector, and d is the average number of digits in the numbers.
//S.C : O(n+d)
class Solution {
public:

    string getMappedNum(string &num, vector<int>& mapping) {
        string mappedNum = "";
        for(int i = 0; i < num.length(); i++) {
            char ch   = num[i];
            mappedNum += to_string(mapping[ch-'0']);
        }
        return mappedNum;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> vec;

        for(int i = 0; i < n; i++) {
            string numStr     = to_string(nums[i]);
            
            string mappedStr  = getMappedNum(numStr, mapping);

            int mappedNum     = stoi(mappedStr);

            vec.push_back({mappedNum, i});
        }

        sort(begin(vec), end(vec));
        vector<int> result;

        for(auto &p : vec) {
            int originalNumIdx = p.second;
            result.push_back(nums[originalNumIdx]);
        }
        return result;
    }
};



//Approach-2 (Without Converting to string)
//T.C : O(n*d + nlogn) , Here, n is the size of the nums vector, and d is the average number of digits in the numbers.
//S.C : O(n)
class Solution {
public:

    int getMappedNum(int num, vector<int>& mapping) {
        if(num < 10) {
            return mapping[num];
        }

        int mappedNum  = 0;
        int plaveValue = 1;

        while(num) {
            int lastDigit   = num%10;
            int mappedDigit = mapping[lastDigit];
            mappedNum      += plaveValue * mappedDigit;

            plaveValue *= 10;
            num       /= 10;
        }

        return mappedNum;

    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> vec;

        for(int i = 0; i < n; i++) {
            int mappedNum = getMappedNum(nums[i], mapping);

            vec.push_back({mappedNum, i});
        }

        sort(begin(vec), end(vec));
        vector<int> result;

        for(auto &p : vec) {
            int originalNumIdx = p.second;
            result.push_back(nums[originalNumIdx]);
        }
        return result;
    }
};


/**************************************************** JAVA ****************************************************/
//Approach-1 (Converting to string)
//T.C : O(n*d + nlogn) , Here, n is the size of the nums vector, and d is the average number of digits in the numbers.
//S.C : O(n+d)
class Solution {
    public int[] sortJumbled(int[] mapping, int[] nums) {
        int n = nums.length;
        List<Pair> vec = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            String numStr = Integer.toString(nums[i]);
            String mappedStr = getMappedNum(numStr, mapping);
            int mappedNum = Integer.parseInt(mappedStr);
            vec.add(new Pair(mappedNum, i));
        }

        Collections.sort(vec, (a, b) -> Integer.compare(a.mappedNum, b.mappedNum));
        int[] result = new int[n];

        for (int i = 0; i < n; i++) {
            int originalNumIdx = vec.get(i).originalIdx;
            result[i] = nums[originalNumIdx];
        }

        return result;
    }

    private String getMappedNum(String num, int[] mapping) {
        StringBuilder mappedNum = new StringBuilder();
        for (char ch : num.toCharArray()) {
            mappedNum.append(mapping[ch - '0']);
        }
        return mappedNum.toString();
    }

    private static class Pair {
        int mappedNum;
        int originalIdx;

        Pair(int mappedNum, int originalIdx) {
            this.mappedNum = mappedNum;
            this.originalIdx = originalIdx;
        }
    }
}


//Approach-2 (Without Converting to string)
//T.C : O(n*d + nlogn) , Here, n is the size of the nums vector, and d is the average number of digits in the numbers.
//S.C : O(n)
class Solution {
    public int[] sortJumbled(int[] mapping, int[] nums) {
        int n = nums.length;
        List<Pair> vec = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            int mappedNum = getMappedNum(nums[i], mapping);
            vec.add(new Pair(mappedNum, i));
        }

        Collections.sort(vec, (a, b) -> Integer.compare(a.mappedNum, b.mappedNum));
        int[] result = new int[n];

        for (int i = 0; i < n; i++) {
            int originalNumIdx = vec.get(i).originalIdx;
            result[i] = nums[originalNumIdx];
        }

        return result;
    }

    private int getMappedNum(int num, int[] mapping) {
        if (num < 10) {
            return mapping[num];
        }

        int mappedNum = 0;
        int placeValue = 1;

        while (num > 0) {
            int lastDigit = num % 10;
            int mappedDigit = mapping[lastDigit];
            mappedNum += placeValue * mappedDigit;

            placeValue *= 10;
            num /= 10;
        }

        return mappedNum;
    }

    private static class Pair {
        int mappedNum;
        int originalIdx;

        Pair(int mappedNum, int originalIdx) {
            this.mappedNum = mappedNum;
            this.originalIdx = originalIdx;
        }
    }
}
