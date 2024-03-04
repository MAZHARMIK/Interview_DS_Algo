/*         Scroll below to see JAVA code also           */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=oJyl4fbfpM0
    Company Tags                : Microsoft, Amazon, MakeMyTrip, Paytm, Zoho, Goldman Sachs
    Leetcode Link               : https://leetcode.com/problems/largest-number/
    Similar GFG Problem         : https://www.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1
*/


/****************************************************** C++ ******************************************************/
//Leetcode Version
//T.C : O(nlogn)
//S.C : O(1) (I am ignoring the space taken by result of size n which we have to return
class Solution {
public:
    static bool myFunction(int a, int b) {
        string s1 = to_string(a);
        string s2 = to_string(b);
        
        return (s1+s2) > (s2+s1);
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), myFunction);
        
        
        if(nums[0] == 0)
            return "0";
        string result = "";
        for(int i:nums)
            result += to_string(i);
        return result;
        
    }
};


//GFG Version
//T.C : O(nlogn)
//S.C : O(1) (I am ignoring the space taken by result of size n which we have to return
class Solution{
public:
	string printLargest(int n, vector<string> &arr) {
	    
	    auto myComparator = [](string &s1, string &s2) {
	        if(s1+s2 > s2+s1) {
	            return true;
	        }
	        return false;
	    };
	    
	    sort(begin(arr), end(arr), myComparator);
	    
	    string result = "";
	    for(string &s : arr) {
	        result += s;
	    }
	    
	    return result;
	}
};



/****************************************************** JAVA ******************************************************/
//Leetcode Version
//T.C : O(nlogn)
//S.C : O(1) (I am ignoring the space taken by result of size n which we have to return
public class Solution {
    public String largestNumber(int[] nums) {
        Integer[] numsAsInteger = Arrays.stream(nums).boxed().toArray(Integer[]::new);

        Arrays.sort(numsAsInteger, (a, b) -> {
            String s1 = Integer.toString(a);
            String s2 = Integer.toString(b);
            return (s2 + s1).compareTo(s1 + s2);
        });

        if (numsAsInteger[0] == 0) {
            return "0";
        }

        StringBuilder result = new StringBuilder();
        for (int num : numsAsInteger) {
            result.append(num);
        }

        return result.toString();
    }
}


//GFG Version
//T.C : O(nlogn)
//S.C : O(1) (I am ignoring the space taken by result of size n which we have to return
class Solution {
    String printLargest(int n, String[] arr) {
        Comparator<String> myComparator = (s1, s2) -> (s2 + s1).compareTo(s1 + s2);
        
        Arrays.sort(arr, myComparator);

        StringBuilder result = new StringBuilder();
        for (String s : arr) {
            result.append(s);
        }

        return result.toString();
    }
}
