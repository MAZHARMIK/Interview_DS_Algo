/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=wiJaMH1CMhw
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/minimum-cost-to-convert-string-ii
*/


/************************************************************ C++ ************************************************/
//Approach (Using Dijkstra's Algorithm and DP with Power of Memoization for both)
/*
N = length of sourceStr / targetStr
M = number of conversion rules (original.size())
L = number of distinct substring lengths
(L = lengthSet.size())
V = number of unique strings appearing in original and changed
E = number of edges in graph (E = M)
T.C : O(
          M                           // graph build
          + M log L                     // lengthSet
          + N² × L                      // DP overhead
          + M² × (V + E) log V          // Dijkstra
        )
  S.C : O(M² + V + E + N)
*/
class Solution {
public:
    typedef long long ll;
    typedef pair<ll, string> P;
    ll BIG_VALUE = 1e10;
    unordered_map<string, vector<pair<string, ll>>> adj; //Graph

    //start -> end -> anser
    unordered_map<string, unordered_map<string, ll>> dijkstraMemo;

    vector<ll> dpMemo;

    string sourceStr;
    string targetStr;
    set<int> validLengths;
    
    ll dijkstra(string& start, string& end) {

        if(dijkstraMemo[start].count(end)) {
            return dijkstraMemo[start][end];
        }

        //{cost, string}
        priority_queue<P, vector<P>, greater<P>> pq;
        //vector<int> result(n, INT_MAX)
        unordered_map<string, ll> result; //source to string ka cost stored
        result[start] = 0;
        pq.push({0, start});

        while(!pq.empty()) {
            ll currCost = pq.top().first;
            string node = pq.top().second;
            pq.pop();

            if(node == end) {
                break;
            }

            for(auto &edge : adj[node]) {
                string adjNode = edge.first;
                ll edgeCost = edge.second;

                if(!result.count(adjNode) || currCost + edgeCost < result[adjNode]) {
                    result[adjNode] = currCost + edgeCost;
                    pq.push({currCost+edgeCost, adjNode});
                }
            }
        }

        ll finalCost = result.count(end) ? result[end] : BIG_VALUE;

        return dijkstraMemo[start][end] = finalCost;

    }

    ll solve(int idx) {
        if(idx >= sourceStr.length())
            return 0;
        if(dpMemo[idx] != -1)
            return dpMemo[idx];

        ll minCost = BIG_VALUE;

        if(sourceStr[idx] == targetStr[idx])
            minCost = solve(idx+1);
        
        for(auto &len : validLengths) {
            if(idx + len > sourceStr.length()) {
                break;
            }

            string srcSub = sourceStr.substr(idx, len);
            string tgtSub = targetStr.substr(idx, len);

            if(!adj.count(srcSub)) {
                continue;
            }

            ll minPathCost = dijkstra(srcSub, tgtSub);
            if(minPathCost == BIG_VALUE)
                continue;
            
            minCost = min(minCost, minPathCost + solve(idx+len));
        }

        return dpMemo[idx] = minCost;
    }

    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        sourceStr = source;
        targetStr = target;

        dpMemo.assign(10001, -1);

        for(int i = 0; i < original.size(); i++) {
            adj[original[i]].push_back({changed[i], cost[i]});
        }

        for(auto &s : original) {
            validLengths.insert(s.length());
        }

        ll result = solve(0);

        return result == BIG_VALUE ? -1 : result;
    }
};




/************************************************************ JAVA ************************************************/
//Approach (Using Dijkstra's Algorithm and DP with Power of Memoization for both)
/*
N = length of sourceStr / targetStr
M = number of conversion rules (original.size())
L = number of distinct substring lengths
(L = lengthSet.size())
V = number of unique strings appearing in original and changed
E = number of edges in graph (E = M)
T.C : O(
          M                           // graph build
          + M log L                     // lengthSet
          + N² × L                      // DP overhead
          + M² × (V + E) log V          // Dijkstra
        )
  S.C : O(M² + V + E + N)
*/
class Solution {

    static class Pair {
        long cost;
        String node;

        Pair(long cost, String node) {
            this.cost = cost;
            this.node = node;
        }
    }

    long BIG_VALUE = (long) 1e10;

    Map<String, List<Pair>> adj = new HashMap<>();

    // start -> end -> shortest cost
    Map<String, Map<String, Long>> dijkstraMemo = new HashMap<>();

    long[] dpMemo;

    String sourceStr, targetStr;
    TreeSet<Integer> validLengths = new TreeSet<>();

    long dijkstra(String start, String end) {

        if (dijkstraMemo.containsKey(start) &&
            dijkstraMemo.get(start).containsKey(end)) {
            return dijkstraMemo.get(start).get(end);
        }

        PriorityQueue<Pair> pq =
                new PriorityQueue<>(Comparator.comparingLong(p -> p.cost));

        Map<String, Long> result = new HashMap<>();
        result.put(start, 0L);
        pq.offer(new Pair(0, start));

        while (!pq.isEmpty()) {

            Pair curr = pq.poll();
            long currCost = curr.cost;
            String node = curr.node;

            if (node.equals(end))
                break;

            if (!adj.containsKey(node))
                continue;

            for (Pair edge : adj.get(node)) {
                String adjNode = edge.node;
                long edgeCost = edge.cost;

                long newCost = currCost + edgeCost;
                if (!result.containsKey(adjNode) || newCost < result.get(adjNode)) {
                    result.put(adjNode, newCost);
                    pq.offer(new Pair(newCost, adjNode));
                }
            }
        }

        long finalCost = result.getOrDefault(end, BIG_VALUE);

        dijkstraMemo
            .computeIfAbsent(start, k -> new HashMap<>())
            .put(end, finalCost);

        return finalCost;
    }

    long solve(int idx) {
        if (idx >= sourceStr.length())
            return 0;

        if (dpMemo[idx] != -1)
            return dpMemo[idx];

        long minCost = BIG_VALUE;

       
        if (sourceStr.charAt(idx) == targetStr.charAt(idx)) {
            minCost = solve(idx + 1);
        }

        
        for (int len : validLengths) {

            if (idx + len > sourceStr.length())
                break;

            String srcSub = sourceStr.substring(idx, idx + len);
            String tgtSub = targetStr.substring(idx, idx + len);

            if (!adj.containsKey(srcSub))
                continue;

            long pathCost = dijkstra(srcSub, tgtSub);
            if (pathCost == BIG_VALUE)
                continue;

            minCost = Math.min(minCost, pathCost + solve(idx + len));
        }

        return dpMemo[idx] = minCost;
    }

    public long minimumCost(
            String source,
            String target,
            String[] original,
            String[] changed,
            int[] cost) {

        sourceStr = source;
        targetStr = target;

        dpMemo = new long[10001];
        Arrays.fill(dpMemo, -1);

        for (int i = 0; i < original.length; i++) {
            adj.computeIfAbsent(original[i], k -> new ArrayList<>())
               .add(new Pair(cost[i], changed[i]));
            validLengths.add(original[i].length());
        }

        long result = solve(0);
        return result == BIG_VALUE ? -1 : result;
    }
}
