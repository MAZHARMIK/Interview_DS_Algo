/*                     Scroll below to see JAVA code also              /*
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=O5v9Tqv2ZDA
    Company Tags                : Amazon
    Leetcode Link               : https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals
*/


/************************************************************************ C++ ******************************************************/
//Approach-1 (Using Map and Sorting)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        
        for(int &x : arr) {
            mp[x]++;
        }

        vector<int> freq;
        
        for(auto &it : mp) {
            freq.push_back(it.second);
        }
        
        sort(begin(freq), end(freq));

        for(int i = 0; i < freq.size(); i++) {
            
            k -= freq[i];
            
            if(k < 0) {
                return freq.size() - i;
            }
        }
        
        return 0; //All were removed
    }
};


//Approach-2 (Using min-heap)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        
        for(int &x : arr) {
            mp[x]++;
        }

        priority_queue<int, vector<int>, greater<int>> pq; //min-heap
        for(auto &it : mp) {
            pq.push(it.second);
        }

        
        while(!pq.empty()) {
            
            k -= pq.top();
            
            
            if(k < 0) {
                return pq.size();
            }
            
            pq.pop();
        }
        
        return 0; //All were removed
    }
};


//Approach-3 (Using Counting Sort)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> mp;

        for(int &x : arr) {
            mp[x]++;
        }

        vector<int> freqCount(n+1);
        //freqCount[i] = number of elements (types) having frequency = i

        int uniqueTypes = mp.size();

        for(auto &it : mp) {
            int freq = it.second;
            freqCount[freq]++;
        }


        for(int freq = 1; freq <= n; freq++) {

            int typesICanDelete = min(k/freq, freqCount[freq]);

            k -= (typesICanDelete * freq);

            uniqueTypes -= typesICanDelete;

            if(k <= freq) {
                return uniqueTypes;
            }
        }

        return 0;


    }
};


/************************************************************************ C++ ******************************************************/
//Approach-1 (Using Map and Sorting)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
    public int findLeastNumOfUniqueInts(int[] arr, int k) {
        Map<Integer, Integer> mp = new HashMap<>();

        for (int x : arr) {
            mp.put(x, mp.getOrDefault(x, 0) + 1);
        }

        List<Integer> freq = new ArrayList<>();
        for (Map.Entry<Integer, Integer> entry : mp.entrySet()) {
            freq.add(entry.getValue());
        }

        Collections.sort(freq);

        for (int i = 0; i < freq.size(); i++) {
            k -= freq.get(i);

            if (k < 0) {
                return freq.size() - i;
            }
        }

        return 0; // All were removed
    }
}


//Approach-2 (Using min-heap)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
    public int findLeastNumOfUniqueInts(int[] arr, int k) {
        // Map to track the frequencies of elements
        Map<Integer, Integer> mp = new HashMap<>();
        for (int i : arr) {
            mp.put(i, mp.getOrDefault(i, 0) + 1);
        }

        // Min heap to track all the frequencies
        PriorityQueue<Integer> pq = new PriorityQueue<>(mp.values());

        // Tracking the number of elements removed
        int elementsRemoved = 0;

        // Traversing all frequencies
        while (!pq.isEmpty()) {
            // Removing the least frequent element
            elementsRemoved += pq.peek();

            // If the number of elements removed exceeds k, return
            // the remaining number of unique elements
            if (elementsRemoved > k) {
                return pq.size();
            }
            pq.poll();
        }

        // We have removed all elements, so no unique integers remain
        // Return 0 in this case
        return 0;
    }
}

//Approach-3 (Using Counting Sort)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public int findLeastNumOfUniqueInts(int[] arr, int k) {
        int n = arr.length;

        Map<Integer, Integer> mp = new HashMap<>();

        for (int x : arr) {
            mp.put(x, mp.getOrDefault(x, 0) + 1);
        }

        int[] freqCount = new int[n + 1];
        // freqCount[i] = number of elements having i frequency

        int uniqueElements = mp.size();

        for (int count : mp.values()) {
            freqCount[count]++;
        }

        for (int freq = 1; freq <= n; freq++) {
            int countUniqueElementsRemove = Math.min(k / freq, freqCount[freq]);
            // k/freq - I can remove at max this number of elements whose frequency = freq
            // freqCount[freq] - Actual Number of elements you have whose frequency = freq

            k -= (freq * countUniqueElementsRemove); // Each one of them has frequency = freq

            uniqueElements -= countUniqueElementsRemove;

            if (k <= freq) {
                return uniqueElements;
            }
        }

        return 0; // All were removed
    }
}
