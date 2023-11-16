/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=8Cay8q3BOx4
      Company Tags                : Amazon, Meta, Google
      Leetcode Link               : https://leetcode.com/problems/find-unique-binary-string/
*/

/************************************************************** C++ **************************************************************/
//Approach-1 (Using simple conversion)
//T.C : O(n^2) - Iterating on each string and converting each character to integer
//S.C : O(n) - Using set
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> st;
        
        for(string &num : nums) {
            st.insert(stoi(num, 0, 2));
        }
        
        int n = nums.size();
        
        string result= "";
        
        for(int number = 0; number <= 65536; number++) {
            if(st.find(number) == st.end()) {
                result = bitset<16>(number).to_string();
                break;
            }
        }
        
        return result.substr(16-n);
        
    }
};


//Approach-2 (Improving above code)
//We no need to check from 0 to 65536. Only need to check from 0 to n
//T.C : O(n^2) - Iterating on each string and converting each character to integer
//S.C : O(n) - Using set
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> st;
        
        for(string &num : nums) {
            st.insert(stoi(num, 0, 2));
        }
        
        int n = nums.size();
        
        string result= "";
        
        for(int number = 0; number <= n; number++) {
            if(st.find(number) == st.end()) {
                result = bitset<16>(number).to_string();
                break;
            }
        }
        
        return result.substr(16-n);
        
    }
};


//Approach-3 (By discarding matching characters in each position)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        
        string result;
        
        for(int i = 0; i<n; i++) {
            char ch = nums[i][i];
            
            result += (ch == '0') ? "1" : "0";
        }
        
        return result;
    }
};


/************************************************************** JAVA **************************************************************/
//Approach-1 (Using simple conversion)
//T.C : O(n^2) - Iterating on each string and converting each character to integer
//S.C : O(n) - Using set
class Solution {
    public String findDifferentBinaryString(String[] nums) {
        HashSet<Integer> set = new HashSet<>();
        
        for (String num : nums) {
            set.add(Integer.parseInt(num, 2));
        }
        
        int n = nums.length;
        
        String result = "";
        
        for (int number = 0; number <= 65536; number++) {
            if (!set.contains(number)) {
                result = Integer.toBinaryString(number);
                while (result.length() < n) { //to make till length n
                    result = "0" + result;
                }

                return result;
            }
        }
        
        return "";
    }
}


//Approach-2 (Improving above code)
//We no need to check from 0 to 65536. Only need to check from 0 to n
//T.C : O(n^2) - Iterating on each string and converting each character to integer
//S.C : O(n) - Using set
class Solution {
    public String findDifferentBinaryString(String[] nums) {
        HashSet<Integer> set = new HashSet<>();
        
        for (String num : nums) {
            set.add(Integer.parseInt(num, 2));
        }
        
        int n = nums.length;
        
        String result = "";
        
        for (int number = 0; number <= n; number++) {
            if (!set.contains(number)) {
                result = Integer.toBinaryString(number);
                while (result.length() < n) { //to make till length n
                    result = "0" + result;
                }

                return result;
            }
        }
        
        return "";
    }
}


//Approach-3 (By discarding matching characters in each position)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public String findDifferentBinaryString(List<String> nums) {
        int n = nums.size();
        
        StringBuilder result = new StringBuilder();
        
        for (int i = 0; i < n; i++) {
            char ch = nums.get(i).charAt(i);
            
            result.append((ch == '0') ? '1' : '0');
        }
        
        return result.toString();
    }
}
