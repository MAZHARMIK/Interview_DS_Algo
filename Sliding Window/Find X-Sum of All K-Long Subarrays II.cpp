/*			Scroll below to see JAVA code also			*/
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tag                 : will update later
    Leetcode Link               : https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-ii/
*/


/*************************************************************** C++ *************************************************/
//Approach (Sliding Window using map)
//T.C : O(nlogn)
//S.C : O(k)
class Solution {
public:
    long long sum = 0; //maintains sum of top x elements from main set
    set<pair<int, int>> main; //contains top-x freq, elements
    set<pair<int, int>> sec; //contains remaining freq, leements

    void insertInSet(const pair<int, int>& p, int x) {
        if(main.size() < x || p > *main.begin()) {
            sum += 1LL * p.first * p.second;
            main.insert(p);

            if(main.size() > x) {
                auto smallest = *main.begin();
                sum -= 1LL * smallest.first * smallest.second;
                main.erase(smallest);
                sec.insert(smallest);
            }
        } else {
            sec.insert(p);
        }
    }

    void removeFromSet(const pair<int, int>& p, int x) {
        if(main.find(p) != main.end()) {
            sum -= 1LL * p.first * p.second;
            main.erase(p);

            if(!sec.empty()) {
                auto largest = *sec.rbegin();
                sec.erase(largest);
                main.insert(largest);
                sum += 1LL * largest.first * largest.second;
            }
        } else {
            sec.erase(p);
        }
    }

    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        sum = 0;

        vector<long long> result;
        
        unordered_map<int, int> mp; //element -> freq

        int i = 0;
        int j = 0;
        while(j < n) {
            if(mp[nums[j]] > 0) {
                removeFromSet({mp[nums[j]], nums[j]}, x);
            }

            mp[nums[j]]++; //new freq
            insertInSet({mp[nums[j]], nums[j]}, x);

            if(j - i + 1 == k) {
                result.push_back(sum);

                removeFromSet({mp[nums[i]], nums[i]}, x);
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                } else {
                    insertInSet({mp[nums[i]], nums[i]}, x);
                }
                i++;
            }

            j++;
        }

        return result;
    }
};




/*************************************************************** JAVA *************************************************/
//Approach (Sliding Window using map)
//T.C : O(nlogn)
//S.C : O(k)
class Solution {
    long sum = 0; //maintains sum of top x elements from main set
    TreeSet<int[]> main; //contains top-x freq, elements
    TreeSet<int[]> sec;  //contains remaining freq, elements
    Map<Integer, Integer> freq; //element -> frequency

    public long[] findXSum(int[] nums, int k, int x) {
        int n = nums.length;
        sum = 0;
        freq = new HashMap<>();

        // Comparator to sort by freq first, then by val (both ascending)
        Comparator<int[]> comp = (a, b) -> {
            if (a[0] != b[0]) return Integer.compare(a[0], b[0]);
            return Integer.compare(a[1], b[1]);
        };

        main = new TreeSet<>(comp);
        sec = new TreeSet<>(comp);

        List<Long> resultList = new ArrayList<>();

        int i = 0;
        int j = 0;
        while (j < n) {
            int num = nums[j];

            // If already present, remove old (freq, val)
            if (freq.getOrDefault(num, 0) > 0) {
                removeFromSet(new int[]{freq.get(num), num}, x);
            }

            // Increase frequency
            freq.put(num, freq.getOrDefault(num, 0) + 1);

            // Insert updated pair
            insertInSet(new int[]{freq.get(num), num}, x);

            // When window size becomes k
            if (j - i + 1 == k) {
                resultList.add(sum);

                // Remove outgoing element
                int outNum = nums[i];
                removeFromSet(new int[]{freq.get(outNum), outNum}, x);
                freq.put(outNum, freq.get(outNum) - 1);

                if (freq.get(outNum) == 0) {
                    freq.remove(outNum);
                } else {
                    insertInSet(new int[]{freq.get(outNum), outNum}, x);
                }

                i++;
            }

            j++;
        }

        // Convert List<Long> to long[]
        long[] result = new long[resultList.size()];
        for (int idx = 0; idx < resultList.size(); idx++) {
            result[idx] = resultList.get(idx);
        }
        return result;
    }

    void insertInSet(int[] p, int x) {
        if (main.size() < x || comparePairs(p, main.first()) > 0) {
            sum += 1L * p[0] * p[1];
            main.add(p);

            if (main.size() > x) {
                int[] smallest = main.first();
                sum -= 1L * smallest[0] * smallest[1];
                main.remove(smallest);
                sec.add(smallest);
            }
        } else {
            sec.add(p);
        }
    }

    void removeFromSet(int[] p, int x) {
        if (main.contains(p)) {
            sum -= 1L * p[0] * p[1];
            main.remove(p);

            if (!sec.isEmpty()) {
                int[] largest = sec.last();
                sec.remove(largest);
                main.add(largest);
                sum += 1L * largest[0] * largest[1];
            }
        } else {
            sec.remove(p);
        }
    }

    // Helper comparison to mimic pair comparison from C++
    int comparePairs(int[] a, int[] b) {
        if (a[0] != b[0]) return Integer.compare(a[0], b[0]);
        return Integer.compare(a[1], b[1]);
    }
}
