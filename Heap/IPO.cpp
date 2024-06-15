/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=b12SZXrZF9I
    Company Tags                : MICROSOFT
    Leetcode Link               : https://leetcode.com/problems/ipo/description/
*/


/**************************************************************** C++ ********************************************************/
//Using heap and greedily picking up projects
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    int findMaximizedCapital(int k, int paissa, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        
        vector<pair<int, int>> vec(n);
        
        for (int i = 0; i < n; i++) {
            vec[i] = {capital[i], profits[i]};
        }

        sort(vec.begin(), vec.end());

        int i = 0;

        priority_queue<int> pq;

        while (k--) {
            while (i < n && vec[i].first <= paissa) {
                pq.push(vec[i].second);
                i++;
            }
            if (pq.empty())
                break;
            paissa += pq.top();
            pq.pop();
        }
        return paissa;
    }
};


/**************************************************************** JAVA ********************************************************/
//Using heap and greedily picking up projects
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
    public int findMaximizedCapital(int k, int w, int[] profits, int[] capital) {
        int n = profits.length;

        List<int[]> projects = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            projects.add(new int[]{capital[i], profits[i]});
        }

        projects.sort(Comparator.comparingInt(a -> a[0]));

        PriorityQueue<Integer> maxProfitHeap = new PriorityQueue<>(Collections.reverseOrder());

        int i = 0;

        while (k-- > 0) {
            while (i < n && projects.get(i)[0] <= w) {
                maxProfitHeap.add(projects.get(i)[1]);
                i++;
            }
            if (maxProfitHeap.isEmpty()) {
                break;
            }
            w += maxProfitHeap.poll();
        }
        return w;
    }
}
