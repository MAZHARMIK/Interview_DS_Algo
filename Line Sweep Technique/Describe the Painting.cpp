/*     Scroll below to see JAVA code as well    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/describe-the-painting
*/


/******************************************************************************* C++ ************************************************************************************************/
//Approach (Using Line Sweep)
//T.C : O(n * logn), where n = number of segments
//S.C : O(n) to store events in map
class Solution {
public:
    typedef long long ll;

    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<int, ll> events;

        for(auto& segment : segments) {
            int start = segment[0];
            int end   = segment[1];
            int color = segment[2];

            events[start] += color;
            events[end]   -= color;
        }

        vector<vector<ll>> result;

        auto it = events.begin();
        int start = it->first;
        ll sum = it->second;

        it++;
        while(it != events.end()) {
            if(sum > 0)
                result.push_back({start, it->first, sum});
            
            start = it->first;
            sum  += it->second;
            it++;
        }

        return result;
        
    }
};



/******************************************************************************* JAVA ************************************************************************************************/
//Approach (Using Line Sweep)
//T.C : O(n * logn), where n = number of segments
//S.C : O(n) to store events in map
class Solution {
    public List<List<Long>> splitPainting(int[][] segments) {
        TreeMap<Integer, Long> events = new TreeMap<>();

        for (int[] seg : segments) {
            int start = seg[0];
            int end   = seg[1];
            int color = seg[2];

            events.put(start, events.getOrDefault(start, 0L) + color);
            events.put(end,   events.getOrDefault(end, 0L) - color);
        }

        List<List<Long>> result = new ArrayList<>();

        long sum = 0;
        Integer prev = null;

        for (Map.Entry<Integer, Long> entry : events.entrySet()) {
            int point = entry.getKey();

            if (prev != null && sum > 0) {
                result.add(Arrays.asList((long) prev, (long) point, sum));
            }

            sum += entry.getValue();
            prev = point;
        }

        return result;
    }
}
