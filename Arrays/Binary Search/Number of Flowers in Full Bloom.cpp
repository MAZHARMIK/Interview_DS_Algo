/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=9L7258j-enE
    Company Tags                : META
    Leetcode Link               : https://leetcode.com/problems/number-of-flowers-in-full-bloom/
*/

/******************************************* C++ *******************************************/
//Approach-1 (Brute Force) - TLE
//T.C : O(m*n)
//S.C : O(1)
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int m = flowers.size();
        int n = people.size();
        
        vector<int> result(n);
        
        for(int i = 0; i<n; i++) {
            
            for(int j = 0; j<m; j++) {
                int start = flowers[j][0];
                int end   = flowers[j][1];
                
                if(people[i] >= start && people[i] <= end) {
                    result[i]++;
                }
                
            }
            
        }
        
        return result;
    }
};


//Approach-2 (Using Binary Search)
//T.C : O((m+n) * log(n))
//S.C : O(m)
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int m = flowers.size();
        int n = people.size();
        
        vector<int> result(n);
        
        vector<int> start_time(m);
        vector<int> end_time(m);
        
        for(int i = 0; i<m; i++) {
            start_time[i] = flowers[i][0];
            end_time[i]   = flowers[i][1];
        }
        
        sort(begin(start_time), end(start_time));
        sort(begin(end_time), end(end_time));
        
        for(int i = 0; i<n; i++) {
            //NOTE : If you want to see my custom lower_bound and upper_bound, see my JAVA code below
            int bloomed_already = upper_bound(begin(start_time), end(start_time), people[i]) - begin(start_time);
            
            int died_already    = lower_bound(begin(end_time), end(end_time), people[i]) - begin(end_time);

            result[i] = bloomed_already - died_already;
            
        }
        
        return result;
    }
};

/******************************************* JAVA *******************************************/
//Approach-1 (Brute Force) - TLE
//T.C : O(m*n)
//S.C : O(1)
class Solution {
    public List<Integer> fullBloomFlowers(List<List<Integer>> flowers, List<Integer> people) {
        int m = flowers.size();
        int n = people.size();
        
        List<Integer> result = new ArrayList<>(n);
        
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < m; j++) {
                int start = flowers.get(j).get(0);
                int end = flowers.get(j).get(1);
                
                if (people.get(i) >= start && people.get(i) <= end) {
                    count++;
                }
            }
            result.add(count);
        }
        
        return result;
    }
}



//Approach-2 (Using Binary Search)
//T.C : O((m+n) * log(n))
//S.C : O(m)
class Solution {
    public int[] fullBloomFlowers(int[][] flowers, int[] people) {
        int m = flowers.length;
        int n = people.length;

        int[] result = new int[n];

        int[] start_time = new int[m];
        int[] end_time = new int[m];

        for (int i = 0; i < m; i++) {
            start_time[i] = flowers[i][0];
            end_time[i] = flowers[i][1];
        }

        Arrays.sort(start_time);
        Arrays.sort(end_time);

        for (int i = 0; i < n; i++) {
            int bloomed_already = binarySearchUpperBound(start_time, people[i]);
            int died_already = binarySearchLowerBound(end_time, people[i]);
            result[i] = bloomed_already - died_already;
        }

        return result;
    }

    private int binarySearchUpperBound(int[] arr, int target) {
        int left = 0;
        int right = arr.length-1;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if(arr[mid] > target) {
                result = mid;
                right = mid-1;
            } else {
                left = mid+1;
            }
        }

        return result == -1 ? arr.length : result;
    }

    private int binarySearchLowerBound(int[] arr, int target) {
        int left = 0;
        int right = arr.length-1;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if(arr[mid] < target) {
                left = mid+1;
            } else {
                result = mid;
                right = mid-1;
            }
            
        }
  
        return result == -1 ? arr.length : result;
    }
}
