/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update soon
    Leetcode Link               : https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
*/


/**************************************************************** C++ ****************************************************************/
//Approach - Greedily pick them first having maximum proft/weight ratio
//T.C : O(nlogn) due to sorting
//S.C : O(n)
class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        double result = 0.0;
        
        vector<pair<int, int>> vec(n);
        
        for(int i = 0; i < n; i++) {
            vec[i] = {val[i], wt[i]};
        }
        
        auto lambda = [](pair<int, int> &p1, pair<int, int> &p2) {
            return (1.0*p1.first)/p1.second > (1.0*p2.first)/p2.second;
        };
        
        sort(begin(vec), end(vec), lambda);
        
        for(int i = 0; i < n; i++) {
            if(vec[i].second <= capacity) {
                result += vec[i].first;
                capacity -= vec[i].second;
            } else {
                result += (1.0 * vec[i].first/vec[i].second) * capacity;
                break;
            }
        }
        
        return result;
        
    }
};




/**************************************************************** JAVA ****************************************************************/
//Approach - Greedily pick them first having maximum proft/weight ratio
//T.C : O(nlogn) due to sorting
//S.C : O(n)
class Item {
    int value, weight;
    Item(int value, int weight) {
        this.value = value;
        this.weight = weight;
    }
}

class Solution {
    public double fractionalKnapsack(int[] val, int[] wt, int capacity) {
        int n = val.length;
        List<Item> items = new ArrayList<>();
        
        // Step 1: Store items
        for (int i = 0; i < n; i++) {
            items.add(new Item(val[i], wt[i]));
        }
        
        // Step 2: Sort by profit/weight ratio in descending order
        Collections.sort(items, (a, b) -> {
            double r1 = (1.0 * a.value) / a.weight;
            double r2 = (1.0 * b.value) / b.weight;
            return Double.compare(r2, r1); // sort descending
        });
        
        double result = 0.0;
        
        // Step 3: Pick items greedily
        for (Item item : items) {
            if (item.weight <= capacity) {
                result += item.value;
                capacity -= item.weight;
            } else {
                result += (1.0 * item.value / item.weight) * capacity;
                break;
            }
        }
        
        return result;
    }
}
