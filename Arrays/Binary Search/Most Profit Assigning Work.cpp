/*     Scroll below to see JAVA code  also      */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=_HptwlLP8sI
    Comoany Tags                : Netease Games
    Leetcode Link               : https://leetcode.com/problems/most-profit-assigning-work/description/
*/


/****************************************************************** C++ *******************************************************/
//Approach-1 (Using max-heap)
//T.C : O(nlogn + mlogn)
//S.C : O(n)
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();

        priority_queue<pair<int, int>> pq; //max heap of pairs

        for(int i = 0; i < n; i++) {
            int diff = difficulty[i];
            int prof = profit[i];

            pq.push({prof, diff});
        }

        sort(begin(worker), end(worker), greater<int>()); //descending order

        int i = 0;
        int totalProfit = 0;
        while(i < m && !pq.empty()) {
            if(pq.top().second > worker[i]) {
                pq.pop();
            } else {
                totalProfit += pq.top().first;
                i++;
            }
        }

        return totalProfit;
        
    }
};


//Approach-2 (Using Binary Search)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();

        vector<pair<int, int>> vec;
        for(int i = 0; i < n; i++) {
            vec.push_back({difficulty[i], profit[i]});
        }

        sort(begin(vec), end(vec));

        //Pre-processing to find the maximum profit till index i at constant time
        for(int i = 1; i < vec.size(); i++) {
            vec[i].second = max(vec[i].second, vec[i-1].second);
        }


        int totalProfit = 0;
        for(int i = 0; i < m; i++) {

            int workerDiffLevel = worker[i];

            //apply b.search on vec
            int l = 0, r = vec.size()-1;
            int maxProfit = 0;
            while(l <= r) {
                int mid = l + (r-l)/2;
                if(vec[mid].first <= workerDiffLevel) {
                    maxProfit = max(maxProfit, vec[mid].second);
                    l = mid+1;
                } else {
                    r = mid-1;
                }
            }

            totalProfit += maxProfit;

        }

        return totalProfit;
    }
};


//Approach-3 (Using simple iteration and sorting)
//T.C : O(nlogn + mlogm + m + n)
//S.C : O(n)
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();
        
        vector<pair<int, int>> vec;
        for(int i = 0; i < n; i++) {
            vec.push_back({difficulty[i], profit[i]});
        }

        sort(begin(vec), end(vec));

        sort(begin(worker), end(worker));

        int totalProfit = 0;
        int j = 0; //pointing to vec
        int maxProfit = 0;
    
        for(int i = 0; i < m; i++) {
            
            while(j < n && worker[i] >= vec[j].first) {
                maxProfit = max(maxProfit, vec[j].second);
                j++;
            }

            totalProfit += maxProfit;

        }

        return totalProfit;
    }
};



/****************************************************************** JAVA   **********************************************************/
//Approach-1 (Using max-heap)
//T.C : O(nlogn + mlogn)
//S.C : O(n)
class Solution {
    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        int n = difficulty.length;
        int m = worker.length;

        // Create a max-heap using a priority queue
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[0] - a[0]); // Max-heap by profit

        for (int i = 0; i < n; i++) {
            int diff = difficulty[i];
            int prof = profit[i];

            pq.offer(new int[]{prof, diff});
        }

        // Sort worker array in descending order
        Arrays.sort(worker);
        for (int i = 0; i < worker.length / 2; i++) {
            int temp = worker[i];
            worker[i] = worker[worker.length - 1 - i];
            worker[worker.length - 1 - i] = temp;
        }

        int i = 0;
        int totalProfit = 0;
        while (i < m && !pq.isEmpty()) {
            if (pq.peek()[1] > worker[i]) {
                pq.poll();
            } else {
                totalProfit += pq.peek()[0];
                i++;
            }
        }

        return totalProfit;
    }
}


//Approach-2 (Using Binary Search)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        int n = difficulty.length;
        int m = worker.length;

        List<int[]> vec = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            vec.add(new int[]{difficulty[i], profit[i]});
        }

        // Sort the vector based on difficulty
        Collections.sort(vec, (a, b) -> Integer.compare(a[0], b[0]));

        // Pre-processing to find the maximum profit till index i at constant time
        for (int i = 1; i < vec.size(); i++) {
            vec.get(i)[1] = Math.max(vec.get(i)[1], vec.get(i - 1)[1]);
        }

        int totalProfit = 0;
        for (int i = 0; i < m; i++) {
            int workerDiffLevel = worker[i];

            // Apply binary search on vec
            int l = 0, r = vec.size() - 1;
            int maxProfit = 0;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (vec.get(mid)[0] <= workerDiffLevel) {
                    maxProfit = Math.max(maxProfit, vec.get(mid)[1]);
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            totalProfit += maxProfit;
        }

        return totalProfit;
    }
}


//Approach-3 (Using simple iteration and sorting)
//T.C : O(nlogn + mlogm + m + n)
//S.C : O(n)
class Solution {
    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        int n = difficulty.length;
        int m = worker.length;

        // Create an array of pairs to hold difficulty and profit
        int[][] vec = new int[n][2];
        for (int i = 0; i < n; i++) {
            vec[i][0] = difficulty[i];
            vec[i][1] = profit[i];
        }

        // Sort the array based on difficulty
        Arrays.sort(vec, (a, b) -> Integer.compare(a[0], b[0]));

        // Sort the worker array
        Arrays.sort(worker);

        int totalProfit = 0;
        int j = 0; // Pointer to vec array
        int maxProfit = 0;

        for (int i = 0; i < m; i++) {
            while (j < n && worker[i] >= vec[j][0]) {
                maxProfit = Math.max(maxProfit, vec[j][1]);
                j++;
            }
            totalProfit += maxProfit;
        }

        return totalProfit;
    }
}
