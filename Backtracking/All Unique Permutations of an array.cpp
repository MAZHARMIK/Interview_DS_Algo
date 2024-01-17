/*
    MY YOUTUBE VIDEO ON THIS Qn : will soon come
    Company Tags                : Google
    GfG Link                    : https://www.geeksforgeeks.org/problems/all-unique-permutations-of-an-array/1
*/


/********************************************************************* C++ *********************************************************************/
//Approach-1
//T.C : O(n*n!)
//S.C : O(n*n!)
class Solution {
  public:
    unordered_set<string> st;
    vector<vector<int>> result;
    int N;
    
    
    void solve(vector<int> &arr, vector<int>& temp, vector<bool>& used) {
        if(temp.size() == N) {
            string s = "";
            for(int &x : temp) {
                s += to_string(x);
            }
            if(st.find(s) == st.end()) {
                result.push_back(temp);
                st.insert(s);
            }
            return;
        }
        
        
        for(int i = 0; i < N; i++) {
            if(used[i] == false) {
                temp.push_back(arr[i]);
                used[i] = true;
                
                solve(arr, temp, used);
                
                used[i] = false;
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        N = n;
        
        vector<bool> used(n, false);
        vector<int> temp;
        sort(begin(arr), end(arr));
        solve(arr, temp, used);
        
        return result;
    }
};


//Approach-2
//T.C : O(n*n!)
//S.C : O(n*n!)
class Solution {
  public:
    vector<vector<int>> result;
    int N;
    
    void solve(vector<int> &arr, vector<bool>& used, vector<int>& temp, string tempString) {
        if(temp.size() == N) {
            result.push_back(temp);
            return;
        }
        //1, 1, 2
        //tempString = "112"
        for(int i = 0; i < N; i++) {
            
            if(used[i] == true || (i > 0 && arr[i] == arr[i-1] && used[i-1] == true)) {
                continue;
            }
            
            used[i] = true;
            temp.push_back(arr[i]);
            
            
            solve(arr, used, temp,tempString);
            
            temp.pop_back();
            used[i] = false;
            
        }
    }
    
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        sort(begin(arr), end(arr));
        
        vector<int> temp;
        string tempString="";
        vector<bool> used(n, false);
        N = n;
        
        solve(arr, used, temp,tempString);
        
        return result;
        
    }
};


/********************************************************************* JAVA *********************************************************************/
//Approach-1
//T.C : O(n*n!)
//S.C : O(n*n!)
class Solution {
    private HashSet<String> st;
    private ArrayList<ArrayList<Integer>> result;
    private int N;

    private void solve(ArrayList<Integer> arr, ArrayList<Integer> temp, boolean[] used) {
        if (temp.size() == N) {
            StringBuilder s = new StringBuilder();
            for (int x : temp) {
                s.append(x);
            }
            if (!st.contains(s.toString())) {
                result.add(new ArrayList<>(temp));
                st.add(s.toString());
            }
            return;
        }

        for (int i = 0; i < N; i++) {
            if (!used[i]) {
                temp.add(arr.get(i));
                used[i] = true;

                solve(arr, temp, used);

                used[i] = false;
                temp.remove(temp.size() - 1);
            }
        }
    }

    public ArrayList<ArrayList<Integer>> uniquePerms(ArrayList<Integer> arr, int n) {
        N = n;

        boolean[] used = new boolean[n];
        ArrayList<Integer> temp = new ArrayList<>();
        result = new ArrayList<>();
        st = new HashSet<>();

        arr.sort(null);
        solve(arr, temp, used);

        return result;
    }
}


//Approach-2
//T.C : O(n*n!)
//S.C : O(n*n!)
class Solution {
    static ArrayList<ArrayList<Integer>> uniquePerms(ArrayList<Integer> arr, int n) {
        arr.sort(null);

        ArrayList<ArrayList<Integer>> result = new ArrayList<>();
        ArrayList<Integer> temp = new ArrayList<>();
        boolean[] used = new boolean[n];

        solve(arr, used, temp, result);

        return result;
    }

    private static void solve(ArrayList<Integer> arr, boolean[] used, ArrayList<Integer> temp, ArrayList<ArrayList<Integer>> result) {
        if (temp.size() == arr.size()) {
            result.add(new ArrayList<>(temp));
            return;
        }

        for (int i = 0; i < arr.size(); i++) {
            if (used[i] || (i > 0 && arr.get(i).equals(arr.get(i - 1)) && used[i - 1])) {
                continue;
            }

            used[i] = true;
            temp.add(arr.get(i));

            solve(arr, used, temp, result);

            temp.remove(temp.size() - 1);
            used[i] = false;
        }
    }
}
