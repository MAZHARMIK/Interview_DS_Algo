/*     Scroll below to see JAVA code    */
/*
    MY YOUTUBE VIDEO ON THIS Qn                : 
    Company Tags                               : will soon update
    Leetcode Link                              : https://leetcode.com/problems/count-number-of-trapezoids-ii
    
*/

/****************************************************** C++ **************************************************************/
//Approach - Maths counting but also removing dupplicates in case of parallelogram
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();

        //slope -> {intercepts}
        unordered_map<float, vector<float>> slopeIntercpts;

        unordered_map<int, vector<float>> midPointMap;

        int result = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int dx = x2-x1;
                int dy = y2-y1;

                float slope, intercept;
                if(x2 == x1) { //dx == 0
                    slope     = 1e9+7; //10000007
                    intercept = x1;
                } else {
                    slope = (float)(y2-y1)/(x2-x1);
                    intercept = (float) (y1*dx - x1*dy) / dx;
                }

                int midPointKey = (x1+x2)*10000 + (y1+y2);

                slopeIntercpts[slope].push_back(intercept);
                midPointMap[midPointKey].push_back(slope);
            }
        }

        for(auto &it : slopeIntercpts) {
            if(it.second.size() <= 1)
                continue;

            map<float, int> mp; //intercept -> count
            for(float intercept : it.second) {
                mp[intercept]++;
            }

            int prevHorizLines = 0;
            for(auto &it : mp) {
                int count = it.second;
                result += count * prevHorizLines; //counting duplicates also

                prevHorizLines += count;
            }
        }

        for(auto &it : midPointMap) {
            if(it.second.size() <= 1)
                continue;
                
            map<float, int> mp;
            for(float slope : it.second) {
                mp[slope]++;
            }

            int prevHorizLines = 0;
            for(auto &it : mp) {
                int count = it.second;
                result -= count * prevHorizLines; //removing duplicates

                prevHorizLines += count;
            }
        }

        return result;
    }
};




/****************************************************** JAVA **************************************************************/
//Approach - Maths counting but also removing dupplicates in case of parallelogram
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
    public int countTrapezoids(int[][] points) {
        int n = points.length;
        double INF = 1e9 + 7;

        // slope -> intercept list
        Map<Double, List<Double>> slopeIntercpts = new HashMap<>();

        // midpoint -> slope list
        Map<Integer, List<Double>> midPointMap = new HashMap<>();

        int result = 0;

        for (int i = 0; i < n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];

            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];

                int dx = x1 - x2;
                int dy = y1 - y2;

                double slope;
                double intercept;

                if (x1 == x2) {
                    // vertical line
                    slope = INF;
                    intercept = x1; 
                } else {
                    slope = 1.0 * (y2 - y1) / (x2 - x1);
                    intercept = 1.0 * (y1 * dx - x1 * dy) / dx;
                }

                // normalize negative zero
                if (slope == -0.0) slope = 0.0;
                if (intercept == -0.0) intercept = 0.0;

                int midPointKey = (x1 + x2) * 10000 + (y1 + y2);

                slopeIntercpts
                    .computeIfAbsent(slope, k -> new ArrayList<>())
                    .add(intercept);

                midPointMap
                    .computeIfAbsent(midPointKey, k -> new ArrayList<>())
                    .add(slope);
            }
        }

        // Count trapezoids (parallel lines with different intercepts)
        for (List<Double> interceptList : slopeIntercpts.values()) {
            if (interceptList.size() <= 1) continue;

            TreeMap<Double, Integer> freq = new TreeMap<>();
            for (double b : interceptList)
                freq.put(b, freq.getOrDefault(b, 0) + 1);

            int prefix = 0;
            for (int count : freq.values()) {
                result += prefix * count;
                prefix += count;
            }
        }

        // Remove parallelogram duplicates
        for (List<Double> slopeList : midPointMap.values()) {
            if (slopeList.size() <= 1) continue;

            TreeMap<Double, Integer> freq = new TreeMap<>();
            for (double s : slopeList)
                freq.put(s, freq.getOrDefault(s, 0) + 1);

            int prefix = 0;
            for (int count : freq.values()) {
                result -= prefix * count;
                prefix += count;
            }
        }

        return result;
    }
}
