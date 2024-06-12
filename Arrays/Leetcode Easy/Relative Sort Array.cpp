/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Yz202siZDHA
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/relative-sort-array
*/

/******************************************************************************** C++ ************************************************************/
//Approach-1 (Using counting sort)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> mp;

        for(int &num : arr1) {
            mp[num]++;
        }

        int i = 0;
        for(int &num : arr2) {
            while(mp[num]-- > 0) {
                arr1[i++] = num;
            }
        }

        for(auto &it : mp) {
            int freq = it.second;
            while(freq > 0) {
                arr1[i++] = it.first;
                freq--;
            }
        }

        return arr1;
    }
};


//Approach-2 (Using lambda)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mp;

        for(int i = 0; i < arr2.size(); i++) {
            mp[arr2[i]] = i;
        }

        for(int &num : arr1) {
            if(!mp.count(num)) {
                mp[num] = 1e9;
            }
        }

        auto lambda = [&](int &num1, int &num2){
            if(mp[num1] == mp[num2]) { //1e9
                return num1 < num2;
            }

            return mp[num1] < mp[num2];
        };

        sort(begin(arr1), end(arr1), lambda);

        return arr1;
    }
};



/******************************************************************************** C++ ************************************************************/
//Approach-1 (Using counting sort)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        // Create a map to count the occurrences of each number in arr1
        Map<Integer, Integer> countMap = new HashMap<>();
        for (int num : arr1) {
            countMap.put(num, countMap.getOrDefault(num, 0) + 1);
        }

        // Create a list to store the result
        List<Integer> result = new ArrayList<>();

        // Add elements of arr2 to the result list in the order and number of times they appear in arr1
        for (int num : arr2) {
            if (countMap.containsKey(num)) {
                for (int i = 0; i < countMap.get(num); i++) {
                    result.add(num);
                }
                // Remove the element from the map after adding to result list
                countMap.remove(num);
            }
        }

        // Add the remaining elements from arr1 (those not in arr2) in ascending order
        List<Integer> remaining = new ArrayList<>();
        for (int num : countMap.keySet()) {
            for (int i = 0; i < countMap.get(num); i++) {
                remaining.add(num);
            }
        }
        Collections.sort(remaining);
        result.addAll(remaining);

        // Convert the result list to an array
        int[] resultArray = new int[result.size()];
        for (int i = 0; i < result.size(); i++) {
            resultArray[i] = result.get(i);
        }

        return resultArray;
    }
}


//Approach-2 (Using lambda)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        // Create a map to store the index of each element in arr2
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < arr2.length; i++) {
            map.put(arr2[i], i);
        }

        // Mark elements not in arr2 with a large value (to be sorted at the end)
        int largeValue = 1000000000; // 1e9 equivalent in Java
        for (int i = 0; i < arr1.length; i++) {
            if (!map.containsKey(arr1[i])) {
                map.put(arr1[i], largeValue);
            }
        }

        // Define the comparator using a lambda expression
        Comparator<Integer> comparator = (num1, num2) -> {
            int index1 = map.get(num1);
            int index2 = map.get(num2);
            if (index1 == index2) {
                return Integer.compare(num1, num2);
            }
            return Integer.compare(index1, index2);
        };

        // Convert arr1 to a list for sorting
        List<Integer> arr1List = new ArrayList<>();
        for (int num : arr1) {
            arr1List.add(num);
        }

        // Sort the list using the defined comparator
        Collections.sort(arr1List, comparator);

        // Convert the sorted list back to an array
        int[] sortedArray = new int[arr1.length];
        for (int i = 0; i < arr1.length; i++) {
            sortedArray[i] = arr1List.get(i);
        }

        return sortedArray;
    }
}
