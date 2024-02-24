/*                       Scroll down to see JAVA code also             */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=hxEWwnJJKcY
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/find-all-people-with-secret/
*/


/********************************************************************** C++ **********************************************************************/
//Approach-1 (Most basic approach that can come to mind)
//T.C : ~O(M*(M+N)) where M = number of meetings and N = number of people
//S.C : O(M+N)
class Solution {
public:
    typedef pair<int, int> P;
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {

        map<int, vector<P>> timeMeetings;
        
        for(vector<int>& meeting : meetings) {
            int person1 = meeting[0];
            int person2 = meeting[1];
            int time    = meeting[2];
            
            timeMeetings[time].push_back({person1, person2});
        }
        
        vector<bool> knowsSecret(n, false);
        knowsSecret[0]           = true;
        knowsSecret[firstPerson] = true;
        
        //Solve in increasing time meetings
        for(auto &it : timeMeetings) {
            
            int t           = it.first;
            vector<P> meets = it.second;
            
            unordered_map<int, vector<int>> adj;
            queue<int> que;
            unordered_set<int> alreadyAdded;

            for(auto& [person1, person2] : meets) {
                adj[person1].push_back(person2);
                adj[person2].push_back(person1);
                
                if(knowsSecret[person1] && alreadyAdded.find(person1) == alreadyAdded.end()) {
                    que.push(person1);
                    alreadyAdded.insert(person1);
                }
                if(knowsSecret[person2] && alreadyAdded.find(person2) == alreadyAdded.end()) {
                    que.push(person2);
                    alreadyAdded.insert(person2);
                }
            }
                
            //Now I know who meet who based on increasing time
            //Let's hit the BFS to spread the secret
            
            while(!que.empty()) {
                int person = que.front();
                que.pop();
                
                for(auto &nextPerson : adj[person]) {
                    if(!knowsSecret[nextPerson]) {
                        knowsSecret[nextPerson] = true;
                        que.push(nextPerson);
                    }
                }
            }
        }
        
        vector<int> result;
        for(int i = 0; i < n; i++) {
            if(knowsSecret[i] == true) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};

//Approach-2 (Using BFS Graph Traversal)
//T.C : O(M * (M+N)) -> M = Number of meetings, N = number of people, there can be at most N+M elements in the queue and a person may have M neighbours
//S.C : O(M+N)
class Solution {
public:
    typedef pair<int, int> P;
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        unordered_map<int, vector<P>> adj;
        
        for(vector<int>& meeting : meetings) {
            int person1 = meeting[0];
            int person2 = meeting[1];
            int time    = meeting[2];
            
            adj[person1].push_back({person2, time});
            adj[person2].push_back({person1, time});
        }
        
        queue<P> que;
        que.push({0, 0});
        que.push({firstPerson, 0});
        vector<int> earlySecretTime(n, INT_MAX);
        earlySecretTime[0] = 0;
        earlySecretTime[firstPerson] = 0;
        
        while(!que.empty()) {
            auto [person, time] = que.front();
            
            que.pop();
            
            for(auto& ngbr : adj[person]) {
                int nextPerson = ngbr.first;
                int t          = ngbr.second;
                
                if(t >= time && earlySecretTime[nextPerson] > t) {
                    earlySecretTime[nextPerson] = t;
                    que.push({nextPerson, t});
                }
            }
        }
        
        vector<int> result;
        for(int i = 0; i < n; i++) {
            if(earlySecretTime[i] != INT_MAX) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};


//Approach-3 (Using DFS Graph Traversal)
//T.C : O(M * (M+N)) -> M = Number of meetings, N = number of people (Although it's a DFS, but we also revisit some nodes again with better secret knowing time)
//S.C : O(M+N)
class Solution {
public:
    typedef pair<int, int> P;
    
    void dfs(int person, int time, unordered_map<int, vector<P>>& adj, vector<int>& earlySecretTime) {
        for(auto& ngbr : adj[person]) {
            int nextPerson = ngbr.first;
            int t          = ngbr.second;

            if(t >= time && earlySecretTime[nextPerson] > t) {
                earlySecretTime[nextPerson] = t;
                dfs(nextPerson, t, adj, earlySecretTime);
            }
        }
    }
    
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        unordered_map<int, vector<P>> adj;
        
        for(vector<int>& meeting : meetings) {
            int person1 = meeting[0];
            int person2 = meeting[1];
            int time    = meeting[2];
            
            adj[person1].push_back({person2, time});
            adj[person2].push_back({person1, time});
        }

        vector<int> earlySecretTime(n, INT_MAX);
        earlySecretTime[0] = 0;
        earlySecretTime[firstPerson] = 0;

        // Do DFS
        dfs(0, 0, adj, earlySecretTime);
        dfs(firstPerson, 0, adj, earlySecretTime);

        vector<int> result;
        for(int i = 0; i < n; i++) {
            if(earlySecretTime[i] != INT_MAX) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};


//Approach-4 (Using min-heap to fetch earliest time)
//T.C : ~O((N+M) * (log(M+N) + M)) 
//S.C : O(N+M)
class Solution {
public:
    typedef pair<int, int> P;
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        unordered_map<int, vector<P>> adj;
        
        for(vector<int>& meeting : meetings) {
            int person1 = meeting[0];
            int person2 = meeting[1];
            int time    = meeting[2];
            
            adj[person1].push_back({person2, time});
            adj[person2].push_back({person1, time});
        }
        
        priority_queue<P, vector<P>, greater<P>> pq; //I need the ones first having min time
        pq.push({0, 0});
        pq.push({0, firstPerson});
        
        vector<bool> visited(n, false);
        
        while(!pq.empty()) {
            auto [time, person] = pq.top();
            pq.pop();
            
            if(visited[person] == true) {
                continue;
            }
            visited[person] = true;
            
            for(auto& ngbr : adj[person]) {
                int nextPerson = ngbr.first;
                int t          = ngbr.second;
                
                if(t >= time && !visited[nextPerson]) {
                    pq.push({t, nextPerson});
                }
            }
        }
        
        vector<int> result;
        for(int i = 0; i < n; i++) {
            if(visited[i] == true) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};


/********************************************************************** JAVA **********************************************************************/
//Approach-1 (Most basic approach that can come to mind)
//T.C : ~O(M*(M+N)) where M = number of meetings and N = number of people
//S.C : O(M+N)
class Solution {
    public List<Integer> findAllPeople(int n, int[][] meetings, int firstPerson) {

        // Group Meetings in increasing order of time
        Map<Integer, List<int[]>> timeMeetings = new TreeMap<>();
        for (int[] meeting : meetings) {
            int x = meeting[0], y = meeting[1], t = meeting[2];
            timeMeetings.computeIfAbsent(t, k -> new ArrayList<>()).add(new int[]{x, y});
        }
        
        // Boolean Array to mark if a person knows the secret or not
        boolean[] knowsSecret = new boolean[n];
        knowsSecret[0] = true;
        knowsSecret[firstPerson] = true;

        // Process in increasing order of time
        for (int t : timeMeetings.keySet()) {
            // For each person, save all the people whom he/she meets at time t
            Map<Integer, List<Integer>> meet = new HashMap<>();
            for (int[] meeting : timeMeetings.get(t)) {
                int x = meeting[0], y = meeting[1];
                meet.computeIfAbsent(x, k -> new ArrayList<>()).add(y);
                meet.computeIfAbsent(y, k -> new ArrayList<>()).add(x);
            }

            // Start traversal from those who already know the secret at time t
            // Set to avoid redundancy
            Set<Integer> start = new HashSet<>();
            for (int[] meeting : timeMeetings.get(t)) {
                int x = meeting[0], y = meeting[1];
                if (knowsSecret[x]) {
                    start.add(x);
                }
                if (knowsSecret[y]) {
                    start.add(y);
                }
            }
            
            // Do BFS
            Queue<Integer> q = new LinkedList<>(start);
            while (!q.isEmpty()) {
                int person = q.poll();
                for (int nextPerson : meet.getOrDefault(person, new ArrayList<>())) {
                    if (!knowsSecret[nextPerson]) {
                        knowsSecret[nextPerson] = true;
                        q.offer(nextPerson);
                    }
                }
            }
        }
        
        // List of people who know the secret
        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            if (knowsSecret[i]) {
                result.add(i);
            }
        }
        return result;
    }
}


//Approach-2 (Using BFS Graph Traversal)
//T.C : O(M * (M+N)) -> M = Number of meetings, N = number of people, there can be at most N+M elements in the queue and a person may have M neighbours
//S.C : O(M+N)
class Solution {
    public List<Integer> findAllPeople(int n, int[][] meetings, int firstPerson) {
        Map<Integer, List<int[]>> adj = new HashMap<>();

        for (int[] meeting : meetings) {
            int person1 = meeting[0];
            int person2 = meeting[1];
            int time = meeting[2];

            adj.computeIfAbsent(person1, k -> new ArrayList<>()).add(new int[]{person2, time});
            adj.computeIfAbsent(person2, k -> new ArrayList<>()).add(new int[]{person1, time});
        }

        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{0, 0});
        queue.offer(new int[]{firstPerson, 0});
        int[] earlySecretTime = new int[n];
        Arrays.fill(earlySecretTime, Integer.MAX_VALUE);
        earlySecretTime[0] = 0;
        earlySecretTime[firstPerson] = 0;

        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int person = current[0];
            int time = current[1];

            for (int[] ngbr : adj.getOrDefault(person, Collections.emptyList())) {
                int nextPerson = ngbr[0];
                int t = ngbr[1];

                if (t >= time && earlySecretTime[nextPerson] > t) {
                    earlySecretTime[nextPerson] = t;
                    queue.offer(new int[]{nextPerson, t});
                }
            }
        }

        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (earlySecretTime[i] != Integer.MAX_VALUE) {
                result.add(i);
            }
        }

        return result;
    }
}


//Approach-3 (Using DFS Graph Traversal)
//T.C : O(M * (M+N)) -> M = Number of meetings, N = number of people (Although it's a DFS, but we also revisit some nodes again with better secret knowing time)
//S.C : O(M+N)
class Solution {
    public List<Integer> findAllPeople(int n, int[][] meetings, int firstPerson) {
        Map<Integer, List<int[]>> adj = new HashMap<>();

        for (int[] meeting : meetings) {
            int person1 = meeting[0];
            int person2 = meeting[1];
            int time = meeting[2];

            adj.computeIfAbsent(person1, k -> new ArrayList<>()).add(new int[]{person2, time});
            adj.computeIfAbsent(person2, k -> new ArrayList<>()).add(new int[]{person1, time});
        }

        int[] earlySecretTime = new int[n];
        Arrays.fill(earlySecretTime, Integer.MAX_VALUE);
        earlySecretTime[0] = 0;
        earlySecretTime[firstPerson] = 0;

        // Do DFS
        dfs(0, 0, adj, earlySecretTime);
        dfs(firstPerson, 0, adj, earlySecretTime);

        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (earlySecretTime[i] != Integer.MAX_VALUE) {
                result.add(i);
            }
        }

        return result;
    }

    private void dfs(int person, int time, Map<Integer, List<int[]>> adj, int[] earlySecretTime) {
        for (int[] ngbr : adj.getOrDefault(person, Collections.emptyList())) {
            int nextPerson = ngbr[0];
            int t = ngbr[1];

            if (t >= time && earlySecretTime[nextPerson] > t) {
                earlySecretTime[nextPerson] = t;
                dfs(nextPerson, t, adj, earlySecretTime);
            }
        }
    }
}


//Approach-4 (Using min-heap to fetch earliest time)
//T.C : ~O((N+M) * (log(M+N) + M)) 
//S.C : O(N+M)
class Solution {
    public List<Integer> findAllPeople(int n, int[][] meetings, int firstPerson) {
        // For every person, we store the meeting time and label of the person met.
        Map<Integer, List<int[]>> graph = new HashMap<>();
        for (int[] meeting : meetings) {
            int person1 = meeting[0];
            int person2 = meeting[1];
            int time    = meeting[2];
            graph.computeIfAbsent(person2, k -> new ArrayList<>()).add(new int[]{time, person1});
            graph.computeIfAbsent(person1, k -> new ArrayList<>()).add(new int[]{time, person2});
        }
        
        // Priority Queue for BFS. It will store (time of knowing the secret, person)
        // We will pop the person with the minimum time of knowing the secret.
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.offer(new int[]{0, 0});
        pq.offer(new int[]{0, firstPerson});

        // Visited array to mark if a person is visited or not.
        // We will mark a person as visited after it is dequeued
        // from the queue.
        boolean[] visited = new boolean[n];

        // Do BFS, but pop minimum.
        while (!pq.isEmpty()) {
            int[] timePerson = pq.poll();
            int time = timePerson[0], person = timePerson[1];
            if (visited[person]) {
                continue;
            }
            visited[person] = true;
            for (int[] nextPersonTime : graph.getOrDefault(person, new ArrayList<>())) {
                int t = nextPersonTime[0], nextPerson = nextPersonTime[1];
                if (!visited[nextPerson] && t >= time) {
                    pq.offer(new int[]{t, nextPerson});
                }
            }
        }
        
        // Since we visited only those people who know the secret
        // we need to return indices of all visited people.
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            if (visited[i]) {
                ans.add(i);
            }
        }
        return ans;
    }
}
