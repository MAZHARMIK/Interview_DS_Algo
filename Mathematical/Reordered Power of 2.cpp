/*     Scroll below to see JAVA code    */
/*
    MY YOUTUBE VIDEO ON THIS Qn                : https://www.youtube.com/watch?v=_Y8xqGvZu8M
    Company Tags                               : will soon update
    Leetcode Link                              : https://leetcode.com/problems/reordered-power-of-2
    
*/

/****************************************************** C++ **************************************************************/
//Approach-1 (Using sorting)
//T.C : O(dlogd), d = number of digits
//S.C : O(d)
class Solution {
public:
    string getSortedStr(int n) {
        string s = to_string(n);
        sort(begin(s), end(s));
        return s;
    }

    bool reorderedPowerOf2(int n) {
        string s = getSortedStr(n);

        //check all 2 powers and see if it matches with s
        //2^29
        for(int p = 0; p <= 29; p++) {
            if(s == getSortedStr(1 << p)) {
                return true;
            }
        }

        return false;
    }
};



//Approach-2 (Using preprocessing and storing in a set)
//T.C : O(dlogd), d = number of digits
//S.C : O(d)
class Solution {
public:
    unordered_set<string> st;
    void buildSet() {
        //2^p from p = 0 to 29
        //convert to string
        //sort it
        //store it in st
        for(int p = 0; p <= 29; p++) {
            string s = to_string(1 << p);
            sort(begin(s), end(s));
            st.insert(s);  
        }
    }

    bool reorderedPowerOf2(int n) {
        if(st.empty()) {
            buildSet(); //call only once (static)
        }

        string s = to_string(n);
        sort(begin(s), end(s));

        return st.count(s);
    }
};


//Approach-3 (count and store digits in a vector)
//T.C : O(d), d = number of digits
//S.C : O(1)
class Solution {
public:
    vector<int> getVectorCountFormat(int n) {
        vector<int> vec(10, 0);

        //256
        //256/10 = 25
        while(n) {
            vec[n%10]++;
            n /= 10;
        }

        return vec;
    }

    bool reorderedPowerOf2(int n) {
        vector<int> input = getVectorCountFormat(n);

        for(int p = 0; p <= 29; p++) {
            if(input == getVectorCountFormat(1 << p)) {
                return true;
            }
        }

        return false;
    }
};


//Approach-4 (count and store digits in a number)
//T.C : O(d), d = number of digits
//S.C : O(1)
class Solution {
public:
    int getVectorCountFormat(int n) {
        int num = 0;

        //256
        //256/10 = 25
        while(n) {
            num += pow(10, n%10);
            n /= 10;
        }

        return num;
    }

    bool reorderedPowerOf2(int n) {
        int input = getVectorCountFormat(n);

        for(int p = 0; p <= 29; p++) {
            if(input == getVectorCountFormat(1 << p)) {
                return true;
            }
        }

        return false;
    }
};




/****************************************************** JAVA **************************************************************/
//Approach-1 (Using sorting)
//T.C : O(dlogd), d = number of digits
//S.C : O(d)
class Solution {
    public String getSortedStr(int n) {
        char[] chars = String.valueOf(n).toCharArray();
        Arrays.sort(chars);
        return new String(chars);
    }

    public boolean reorderedPowerOf2(int n) {
        String sortedStr = getSortedStr(n);

        // Check all powers of 2 up to 2^29
        for (int p = 0; p <= 29; p++) {
            if (sortedStr.equals(getSortedStr(1 << p))) {
                return true;
            }
        }

        return false;
    }
}


//Approach-2 (Using preprocessing and storing in a set)
//T.C : O(dlogd), d = number of digits
//S.C : O(d)
class Solution {
    private HashSet<String> set = new HashSet<>();

    private void buildSet() {
        for (int p = 0; p <= 29; p++) {
            char[] chars = String.valueOf(1 << p).toCharArray();
            Arrays.sort(chars);
            set.add(new String(chars));
        }
    }

    public boolean reorderedPowerOf2(int n) {
        if (set.isEmpty()) {
            buildSet(); // Call once
        }

        char[] chars = String.valueOf(n).toCharArray();
        Arrays.sort(chars);
        return set.contains(new String(chars));
    }
}



//Approach-3 (count and store digits in a vector)
//T.C : O(d), d = number of digits
//S.C : O(1)
class Solution {
    private int[] getCountVector(int n) {
        int[] count = new int[10];
        while (n > 0) {
            count[n % 10]++;
            n /= 10;
        }
        return count;
    }

    public boolean reorderedPowerOf2(int n) {
        int[] inputCount = getCountVector(n);

        for (int p = 0; p <= 29; p++) {
            if (Arrays.equals(inputCount, getCountVector(1 << p))) {
                return true;
            }
        }

        return false;
    }
}


//Approach-4 (count and store digits in a number)
//T.C : O(d), d = number of digits
//S.C : O(1)
class Solution {
    private int getCountNumber(int n) {
        int num = 0;
        while (n > 0) {
            num += Math.pow(10, n % 10);
            n /= 10;
        }
        return num;
    }

    public boolean reorderedPowerOf2(int n) {
        int inputCount = getCountNumber(n);

        for (int p = 0; p <= 29; p++) {
            if (inputCount == getCountNumber(1 << p)) {
                return true;
            }
        }

        return false;
    }
}
