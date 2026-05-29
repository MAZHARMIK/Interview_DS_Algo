/*    Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=h56PqNa5stI
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/minimum-pair-removal-to-sort-array-ii
*/


/*************************************************************************** C++ ******************************************************************************************/
//Approach (Using hashset and prevIndex and nextIndex to avoid rase time complexity)
//T.C : O(n * logn)
//S.C : O(n)
class Solution {
public:
    typedef long long ll;

    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();

        //{a, b, c, d} --> {a, b+c, d}
        vector<ll> temp(n);
        for(int i = 0; i < n; i++)
            temp[i] = nums[i];

        set<pair<ll, int>> minPairSet;

        vector<int> nextIndex(n);
        vector<int> prevIndex(n);

        for(int i = 0; i < n; i++) {
            nextIndex[i] = i+1;
            prevIndex[i] = i-1;
        }

        int badPairs = 0;
        for(int i = 0; i < n-1; i++) {
            if(temp[i] > temp[i+1]) {
                badPairs++;
            }
            minPairSet.insert({temp[i] + temp[i+1], i});
        }

        int operations = 0;

        while(badPairs > 0) {
            int first  = minPairSet.begin()->second;
            int second = nextIndex[first];

            int first_left   = prevIndex[first];
            int second_right = nextIndex[second];


            minPairSet.erase(begin(minPairSet));

            if(temp[first] > temp[second]) {
                badPairs--;
            }

            //{d, (a, b)}
            if(first_left >= 0) {
                if(temp[first_left] > temp[first] &&
                temp[first_left] <= temp[first] + temp[second]) {
                    badPairs--;
                } 
                else if(temp[first_left] <= temp[first] &&
                temp[first_left] > temp[first] + temp[second]) {
                    badPairs++;
                }
            }

            //{(a, b), d}
            if (second_right < n) {
                if (temp[second_right] >= temp[second] &&
                    temp[second_right] < temp[first] + temp[second]) {
                    badPairs++;
                }
                else if (temp[second_right] < temp[second] &&
                         temp[second_right] >= temp[first] + temp[second]) {
                    badPairs--;
                }
            }

            if(first_left >= 0) {
                minPairSet.erase({temp[first_left] + temp[first], first_left});
                minPairSet.insert({temp[first_left] + temp[first] + temp[second], first_left});
            }

            if(second_right < n) {
                minPairSet.erase({temp[second] + temp[second_right], second});
                minPairSet.insert({temp[first] + temp[second] + temp[second_right], first});
                prevIndex[second_right] = first;
            }

            nextIndex[first] = second_right;
            temp[first] += temp[second];

            operations++;
        }

        return operations;
    }
};



/*************************************************************************** JAVA ******************************************************************************************/
//Approach (Using hashset and prevIndex and nextIndex to avoid rase time complexity)
//T.C : O(n * logn)
//S.C : O(n)
class Solution {

    static class Pair {
        long sum;
        int idx;

        Pair(long sum, int idx) {
            this.sum = sum;
            this.idx = idx;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (!(o instanceof Pair)) return false;
            Pair p = (Pair) o;
            return sum == p.sum && idx == p.idx;
        }

        @Override
        public int hashCode() {
            return Objects.hash(sum, idx);
        }
    }

    public int minimumPairRemoval(int[] nums) {
        int n = nums.length;

        // {a, b, c, d} -> {a, b+c, d}
        long[] temp = new long[n];
        for (int i = 0; i < n; i++) {
            temp[i] = nums[i];
        }

        TreeSet<Pair> minPairSet = new TreeSet<>(
            (a, b) -> {
                if (a.sum != b.sum) return Long.compare(a.sum, b.sum);
                return Integer.compare(a.idx, b.idx);
            }
        );

        int[] nextIndex = new int[n];
        int[] prevIndex = new int[n];

        for (int i = 0; i < n; i++) {
            nextIndex[i] = i + 1;
            prevIndex[i] = i - 1;
        }

        int badPairs = 0;
        for (int i = 0; i < n - 1; i++) {
            if (temp[i] > temp[i + 1]) {
                badPairs++;
            }
            minPairSet.add(new Pair(temp[i] + temp[i + 1], i));
        }

        int operations = 0;

        while (badPairs > 0) {

            Pair cur = minPairSet.first();
            minPairSet.remove(cur);

            int first = cur.idx;
            int second = nextIndex[first];

            int first_left = prevIndex[first];
            int second_right = nextIndex[second];

            if (temp[first] > temp[second]) {
                badPairs--;
            }

            // {d, (a, b)}
            if (first_left >= 0) {
                if (temp[first_left] > temp[first] &&
                    temp[first_left] <= temp[first] + temp[second]) {
                    badPairs--;
                }
                else if (temp[first_left] <= temp[first] &&
                         temp[first_left] > temp[first] + temp[second]) {
                    badPairs++;
                }
            }

            // {(a, b), d}
            if (second_right < n) {
                if (temp[second_right] >= temp[second] &&
                    temp[second_right] < temp[first] + temp[second]) {
                    badPairs++;
                }
                else if (temp[second_right] < temp[second] &&
                         temp[second_right] >= temp[first] + temp[second]) {
                    badPairs--;
                }
            }

            if (first_left >= 0) {
                minPairSet.remove(
                    new Pair(temp[first_left] + temp[first], first_left)
                );
                minPairSet.add(
                    new Pair(temp[first_left] + temp[first] + temp[second], first_left)
                );
            }

            if (second_right < n) {
                minPairSet.remove(
                    new Pair(temp[second] + temp[second_right], second)
                );
                minPairSet.add(
                    new Pair(temp[first] + temp[second] + temp[second_right], first)
                );
                prevIndex[second_right] = first;
            }

            nextIndex[first] = second_right;
            temp[first] += temp[second];

            operations++;
        }

        return operations;
    }
}
