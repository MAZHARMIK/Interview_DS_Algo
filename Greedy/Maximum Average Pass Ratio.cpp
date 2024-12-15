/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Will update soon
    Leetcode Link               : 
*/


/************************************************************ C++ ************************************************/
//Approach-1 : (Chossing class with max delta/improvement everytime) - Will give TLE/MLE
//T.C : O(extraStudents * n)
//S.C : O(n)
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();

        vector<double> PR(n);
        for(int i = 0; i < n; i++) {
            double ratio = (double)classes[i][0]/classes[i][1];
            PR[i] = ratio;
        }

        while(extraStudents--) { //O(n)
            //student 0

            vector<double> updatedPR(n);
            for(int i = 0; i < n; i++) {
                double newRatio = (double)(classes[i][0]+1)/(classes[i][1]+1);
                updatedPR[i] = newRatio;
            }

            int bestClassIdx = 0;
            double bestDelta = 0;

            for(int i = 0; i < n; i++) { //O(n)
                double delta = updatedPR[i] - PR[i];
                if(delta > bestDelta) {
                    bestDelta = delta;
                    bestClassIdx = i;
                }
            }

            PR[bestClassIdx] = updatedPR[bestClassIdx];
            classes[bestClassIdx][0]++;
            classes[bestClassIdx][1]++;
        }

        double result = 0.0; //AR
        for(int i = 0; i < n; i++) {
            result += PR[i];
        }

        return result/n;
    }
};



//Approach-2 : (Chossing class with max delta/improvement everytime - Improving with max heap)
//T.C : O(extraStudents * log(n))
//S.C : O(n)
class Solution {
public:
    #define P pair<double, int>
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();

        priority_queue<P> pq; //max-heap  -  //{max-delta, idx}

        for(int i = 0; i < n; i++) {
            double current_PR = (double)classes[i][0]/classes[i][1];
            double new_PR = (double)(classes[i][0]+1)/(classes[i][1]+1);
            double delta = new_PR - current_PR;
            pq.push({delta, i});
        }
        
        //O(extraStudents * log(n))
        while(extraStudents--) { //O(k)
            auto curr = pq.top(); //log(n)
            pq.pop();

            double delta = curr.first;
            int idx = curr.second;

            classes[idx][0]++; //incremeent total passing students in the class
            classes[idx][1]++; //increment total students oin the class

            double current_PR = (double)classes[idx][0]/classes[idx][1];
            double new_PR = (double)(classes[idx][0]+1)/(classes[idx][1]+1);
            delta = new_PR - current_PR;
            pq.push({delta, idx}); //log(n)
        }

        double result = 0.0;
        for(int i = 0; i < n; i++) {
            result += (double)classes[i][0]/classes[i][1];
        }

        return result/n;
    }
};



/************************************************************ JAVA ************************************************/
//Approach-1 : (Chossing class with max delta/improvement everytime)
//T.C : O(extraStudents * n)
//S.C : O(n)
class Solution {
    public double maxAverageRatio(int[][] classes, int extraStudents) {
        int n = classes.length;

        // Array to store the current pass ratio for each class
        double[] PR = new double[n];
        for (int i = 0; i < n; i++) {
            double ratio = (double) classes[i][0] / classes[i][1];
            PR[i] = ratio;
        }

        while (extraStudents-- > 0) {
            // Array to store the updated pass ratio for each class
            double[] updatedPR = new double[n];
            for (int i = 0; i < n; i++) {
                double newRatio = (double) (classes[i][0] + 1) / (classes[i][1] + 1);
                updatedPR[i] = newRatio;
            }

            // Find the class that has the maximum improvement in pass ratio
            int bestClassIdx = 0;
            double bestDelta = 0;

            for (int i = 0; i < n; i++) {
                double delta = updatedPR[i] - PR[i];
                if (delta > bestDelta) {
                    bestDelta = delta;
                    bestClassIdx = i;
                }
            }

            // Update the best class with an extra student
            PR[bestClassIdx] = updatedPR[bestClassIdx];
            classes[bestClassIdx][0]++;
            classes[bestClassIdx][1]++;
        }

        // Calculate the final average pass ratio
        double result = 0.0;
        for (int i = 0; i < n; i++) {
            result += PR[i];
        }

        return result / n;
    }
}



//Approach-2 : (Chossing class with max delta/improvement everytime - Improving with max heap)
//T.C : O(extraStudents * log(n))
//S.C : O(n)
import java.util.PriorityQueue;

class Solution {
    public double maxAverageRatio(int[][] classes, int extraStudents) {
        int n = classes.length;

        // Priority queue to act as a max-heap, storing pairs of {max-delta, index}
        PriorityQueue<double[]> pq = new PriorityQueue<>((a, b) -> Double.compare(b[0], a[0]));

        // Initialize the priority queue with the delta values and indices
        for (int i = 0; i < n; i++) {
            double currentPR = (double) classes[i][0] / classes[i][1];
            double newPR = (double) (classes[i][0] + 1) / (classes[i][1] + 1);
            double delta = newPR - currentPR;
            pq.offer(new double[]{delta, i});
        }

        // Allocate extra students
        while (extraStudents-- > 0) {
            // Extract the class with the maximum delta
            double[] curr = pq.poll();
            int idx = (int) curr[1];

            // Update the class with an extra student
            classes[idx][0]++;
            classes[idx][1]++;

            // Recalculate the delta for this class
            double currentPR = (double) classes[idx][0] / classes[idx][1];
            double newPR = (double) (classes[idx][0] + 1) / (classes[idx][1] + 1);
            double delta = newPR - currentPR;

            // Push the updated delta and index back into the priority queue
            pq.offer(new double[]{delta, idx});
        }

        // Calculate the final average pass ratio
        double result = 0.0;
        for (int i = 0; i < n; i++) {
            result += (double) classes[i][0] / classes[i][1];
        }

        return result / n;
    }
}
