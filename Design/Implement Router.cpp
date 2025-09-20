/*        Scroll below to see JAVA code also        */
/*
    MY YOUTUBE VIDEO IN THIS QN : https://www.youtube.com/watch?v=cZ2XgOV_M3A
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/implement-router
*/


/***************************************************************** C++ *****************************************************************/
//Approach (Queue for FIFO, Map for quick retrieval and sorted vector for binary search)
// T.C. : 
// addPacket()       -> O(k) worst-case (due to forwardPacket() + vector erase at front)
// forwardPacket()   -> O(k) worst-case (erase from vector front for destination timestamps)
// getCount()        -> O(log k) per query (binary search in vector)
// k = number of packets for a particular destination

// S.C. : 
// O(MAX_SIZE) total
// packetStore     -> O(MAX_SIZE)
// que             -> O(MAX_SIZE * key length)
// destTimestamps  -> O(MAX_SIZE)
class Router {
private:
    int MAX_SIZE;  // memory limit
    unordered_map<string, vector<int>> packetStore;  // key -> packet [source, dest, timestamp]
    unordered_map<int, vector<int>> destTimestamps;  // destination -> sorted timestamps
    queue<string> que;  // FIFO order

    string makeKey(int source, int destination, int timestamp) {
        return to_string(source) + "#" + to_string(destination) + "#" + to_string(timestamp);
    }

public:
    Router(int memoryLimit) {
        MAX_SIZE = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp) {
        string key = makeKey(source, destination, timestamp);

        if (packetStore.find(key) != packetStore.end()) {
            return false;  // duplicate
        }

        if ((int)packetStore.size() >= MAX_SIZE) { //remove the oldest packet
            forwardPacket();
        }

        packetStore[key] = {source, destination, timestamp};
        que.push(key);
        destTimestamps[destination].push_back(timestamp);

        return true;
    }

    vector<int> forwardPacket() {
        if (packetStore.empty())
            return {}; //If there are no packets to forward, return an empty array.

        string key = que.front(); 
        que.pop();

        vector<int> packet = packetStore[key];
        packetStore.erase(key);

        int dest = packet[1];
        destTimestamps[dest].erase(destTimestamps[dest].begin()); // remove earliest timestamp

        return packet;
    }

    int getCount(int destination, int startTime, int endTime) {
        auto it = destTimestamps.find(destination);
        if (it == destTimestamps.end() || it->second.empty())
            return 0;

        int i = lower_bound(begin(it->second), end(it->second), startTime) - begin(it->second);//log(size of vec)
        int j = upper_bound(begin(it->second), end(it->second), endTime) - begin(it->second); //log(size of vec)

        return rightIdx - leftIdx;
    }
};



/***************************************************************** JAVA *****************************************************************/
//Approach (Queue for FIFO, Map for quick retrieval and sorted vector for binary search)
// T.C. : 
// addPacket()       -> O(k) worst-case (due to forwardPacket() + vector erase at front)
// forwardPacket()   -> O(k) worst-case (erase from vector front for destination timestamps)
// getCount()        -> O(log k) per query (binary search in vector)
// k = number of packets for a particular destination

// S.C. : 
// O(MAX_SIZE) total
// packetStore     -> O(MAX_SIZE)
// que             -> O(MAX_SIZE * key length)
// destTimestamps  -> O(MAX_SIZE)
class Router {

    private int MAX_SIZE;  // memory limit
    private Map<String, int[]> packetStore;          // key -> packet {source, dest, timestamp}
    private Map<Integer, ArrayList<Integer>> destTimestamps;  // destination -> timestamps
    private Map<Integer, Integer> startIndex;        // destination -> index of first valid timestamp
    private Queue<String> que;                       // FIFO queue for packets

    public Router(int memoryLimit) {
        MAX_SIZE = memoryLimit;
        packetStore = new HashMap<>();
        destTimestamps = new HashMap<>();
        startIndex = new HashMap<>();
        que = new LinkedList<>();
    }

    private String makeKey(int source, int destination, int timestamp) {
        return source + "#" + destination + "#" + timestamp;
    }

    public boolean addPacket(int source, int destination, int timestamp) {
        String key = makeKey(source, destination, timestamp);

        if (packetStore.containsKey(key)) return false; // duplicate

        if (packetStore.size() >= MAX_SIZE) {
            forwardPacket(); // evict oldest
        }

        packetStore.put(key, new int[]{source, destination, timestamp});
        que.offer(key);

        destTimestamps.putIfAbsent(destination, new ArrayList<>());
        destTimestamps.get(destination).add(timestamp);

        startIndex.putIfAbsent(destination, 0);

        return true;
    }

    public int[] forwardPacket() {
        if (packetStore.isEmpty()) return new int[0];

        String key = que.poll();
        int[] packet = packetStore.get(key);
        packetStore.remove(key);

        int dest = packet[1];
        int idx = startIndex.get(dest);
        startIndex.put(dest, idx + 1); // move start index forward instead of removing from list

        return packet;
    }

    public int getCount(int destination, int startTime, int endTime) {
        if (!destTimestamps.containsKey(destination)) return 0;

        ArrayList<Integer> list = destTimestamps.get(destination);
        int idx = startIndex.get(destination);
        int left = lowerBound(list, startTime, idx);
        int right = upperBound(list, endTime, idx);

        return right - left;
    }

    // binary search for first index >= target, starting from startIdx
    private int lowerBound(ArrayList<Integer> list, int target, int startIdx) {
        int low = startIdx, high = list.size();
        while (low < high) {
            int mid = (low + high) / 2;
            if (list.get(mid) >= target) high = mid;
            else low = mid + 1;
        }
        return low;
    }

    // binary search for first index > target, starting from startIdx
    private int upperBound(ArrayList<Integer> list, int target, int startIdx) {
        int low = startIdx, high = list.size();
        while (low < high) {
            int mid = (low + high) / 2;
            if (list.get(mid) > target) high = mid;
            else low = mid + 1;
        }
        return low;
    }
}
