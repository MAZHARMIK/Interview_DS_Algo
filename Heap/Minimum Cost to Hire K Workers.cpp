/*     Scroll below to see JAVA code also     */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=kxR52OB_I8k
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/minimum-cost-to-hire-k-workers
*/

/********************************************************************* C++ *********************************************************************/
//Approach-1 (Brute Force - Heap + Math) - TLE
//T.C : O(n * (n + klogk))
//S.C : O(n+k)
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& min_wage, int k) {
        int n = quality.size();

        double result = DBL_MAX; //std::numeric_limits<double>::max()
        //maximum representable finite floating-point (double) number

        for(int manager = 0; manager < n; manager++) {
            
            double managerRatio = (double)min_wage[manager]/quality[manager];

            vector<double> group;
            for(int worker = 0; worker < n; worker++) {
                double worker_wage = quality[worker] * managerRatio;
                if(worker_wage >= min_wage[worker]) {
                    group.push_back(worker_wage);
                }
            }

            if(group.size() < k)
                continue;
            
            priority_queue<double, vector<double>> pq;
            double sum = 0;

            for(double &wage : group) {
                sum += wage;
                pq.push(wage);

                if(pq.size() > k) {
                    sum -= pq.top();
                    pq.pop();
                }
            }

            result = min(result, sum);

        }

        return result;
    }
};


//Approach-2 (Improved Brute Force - Heap + Math) - TLE
//T.C : O(nlogn + n * (n + klogk)) - This is worst case when no one got eliminated 
//S.C : O(n+k)
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& min_wage, int k) {
        int n = quality.size();

        double result = DBL_MAX; //std::numeric_limits<double>::max()
        //maximum representable finite floating-point (double) number

        vector<pair<double, int>> worker_ratio(n);
        for(int worker = 0; worker < n; worker++) {
            worker_ratio[worker] = make_pair((double)min_wage[worker]/quality[worker], quality[worker]);
        }

        sort(begin(worker_ratio), end(worker_ratio));

        for(int manager = k-1; manager < n; manager++) {
            
            double managerRatio = worker_ratio[manager].first;

            vector<double> group;
            for(int worker = 0; worker <= manager; worker++) {
                double worker_wage = worker_ratio[worker].second * managerRatio;
                group.push_back(worker_wage);
            }

            priority_queue<double, vector<double>> pq;
            double sum = 0;

            for(double &wage : group) {
                sum += wage;
                pq.push(wage);

                if(pq.size() > k) {
                    sum -= pq.top();
                    pq.pop();
                }
            }

            result = min(result, sum);

        }

        return result;
    }
};


//Approach-3 (Optimal)
//T.C : O(nlogn + klogk + n*log(k))
//S.C : O(n+k)
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& min_wage, int k) {
        int n = quality.size();

        vector<pair<double, int>> worker_ratio(n);
        for(int worker = 0; worker < n; worker++) {
            worker_ratio[worker] = make_pair((double)min_wage[worker]/quality[worker], quality[worker]);
        }
        sort(begin(worker_ratio), end(worker_ratio));

        priority_queue<int, vector<int>> pq;
        
        double sum_quality = 0;
        for(int i = 0; i < k; i++) { 
            pq.push(worker_ratio[i].second); //push all qualities in max-heap
            sum_quality += worker_ratio[i].second; //Find sum of qualities
        }

        double managerRatio = worker_ratio[k-1].first; 
        double result       = managerRatio * sum_quality;

        for(int manager = k; manager < n; manager++) {
            
            managerRatio = worker_ratio[manager].first;

            pq.push(worker_ratio[manager].second); //push all qualities in max-heap
            sum_quality += worker_ratio[manager].second; //Find sum of qualities

            if(pq.size() > k) {
                sum_quality -= pq.top();
                pq.pop();
            }

            result = min(result, managerRatio*sum_quality);

        }

        return result;
    }
};


/********************************************************************* JAVA *********************************************************************/
// Approach-1 (Brute Force - Heap + Math) - TLE
// T.C : O(n * (n + klogk))
// S.C : O(n+k)
class Solution {
    public double mincostToHireWorkers(int[] quality, int[] min_wage, int k) {
        int n = quality.length;

        double result = Double.MAX_VALUE; // maximum representable finite floating-point (double) number

        for (int manager = 0; manager < n; manager++) {
            double managerRatio = (double) min_wage[manager] / quality[manager];

            // Create a group of workers whose wage-to-quality ratio is greater than or equal to the manager's ratio
            double[] group = new double[n];
            int groupSize = 0;
            for (int worker = 0; worker < n; worker++) {
                double worker_wage = quality[worker] * managerRatio;
                if (worker_wage >= min_wage[worker]) {
                    group[groupSize++] = worker_wage;
                }
            }

            if (groupSize < k)
                continue;

            PriorityQueue<Double> pq = new PriorityQueue<>(groupSize, Collections.reverseOrder());
            double sum = 0;

            // Calculate the sum of wages for the selected group of workers
            for (int i = 0; i < groupSize; i++) {
                sum += group[i];
                pq.offer(group[i]);

                if (pq.size() > k) {
                    sum -= pq.poll();
                }
            }

            result = Math.min(result, sum);
        }

        return result;
    }
}


// Approach-2 (Improved Brute Force - Heap + Math) - TLE
// T.C : O(nlogn + n * (n + klogk)) - This is worst case when no one got eliminated 
// S.C : O(n+k)
class Solution {
    public double mincostToHireWorkers(int[] quality, int[] min_wage, int k) {
        int n = quality.length;

        double result = Double.MAX_VALUE; // maximum representable finite floating-point (double) number

        // Calculate the wage-to-quality ratio for each worker and store in a pair
        double[][] worker_ratio = new double[n][2];
        for (int worker = 0; worker < n; worker++) {
            worker_ratio[worker][0] = (double) min_wage[worker] / quality[worker];
            worker_ratio[worker][1] = quality[worker];
        }

        // Sort the workers based on their wage-to-quality ratio
        Arrays.sort(worker_ratio, (a, b) -> Double.compare(a[0], b[0]));

        for (int manager = k - 1; manager < n; manager++) {
            double managerRatio = worker_ratio[manager][0];

            // Create a group of workers whose wage-to-quality ratio is less than or equal to the current manager's ratio
            double[] group = new double[manager + 1];
            for (int worker = 0; worker <= manager; worker++) {
                double worker_wage = worker_ratio[worker][1] * managerRatio;
                group[worker] = worker_wage;
            }

            PriorityQueue<Double> pq = new PriorityQueue<>(group.length, Collections.reverseOrder());
            double sum = 0;

            // Calculate the sum of wages for the selected group of workers
            for (double wage : group) {
                sum += wage;
                pq.offer(wage);

                if (pq.size() > k) {
                    sum -= pq.poll();
                }
            }

            result = Math.min(result, sum);
        }

        return result;
    }
}


// Approach-3 (Optimal)
// T.C : O(nlogn + klogk + n*log(k))
// S.C : O(n+k)
class Solution {
    public double mincostToHireWorkers(int[] quality, int[] min_wage, int k) {
        int n = quality.length;

        // Calculate the wage-to-quality ratio for each worker and store in a pair
        double[][] worker_ratio = new double[n][2];
        for (int worker = 0; worker < n; worker++) {
            worker_ratio[worker][0] = (double) min_wage[worker] / quality[worker];
            worker_ratio[worker][1] = quality[worker];
        }
        // Sort the workers based on their wage-to-quality ratio
        Arrays.sort(worker_ratio, (a, b) -> Double.compare(a[0], b[0]));

        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        double sum_quality = 0;
        for (int i = 0; i < k; i++) {
            pq.offer((int) worker_ratio[i][1]); // Push all qualities in max-heap
            sum_quality += worker_ratio[i][1]; // Find sum of qualities
        }

        double managerRatio = worker_ratio[k - 1][0];
        double result = managerRatio * sum_quality;

        for (int manager = k; manager < n; manager++) {
            managerRatio = worker_ratio[manager][0];

            pq.offer((int) worker_ratio[manager][1]); // Push all qualities in max-heap
            sum_quality += worker_ratio[manager][1]; // Find sum of qualities

            if (pq.size() > k) {
                sum_quality -= pq.poll();
            }

            result = Math.min(result, managerRatio * sum_quality);
        }

        return result;
    }
}
