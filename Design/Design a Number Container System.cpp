/*        Scroll below to see JAVA code also        */
/*
    MY YOUTUBE VIDEO IN THIS QN : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/design-a-number-container-system/description/
*/


/***************************************************************** C++ *****************************************************************/
//Approach-1 (Using two maps : map of int, int and map of int, set)
//T.C : O(log(n))
//S.C : O(n)
class NumberContainers {
public:
    //Space : O(n)
    unordered_map<int, int> idxToNum;
    unordered_map<int, set<int>> numToIdx;

    NumberContainers() {
        //do nothing    
    }
    
    void change(int index, int number) {
        if(idxToNum.count(index)) { //O(1)
            int prevNum = idxToNum[index];
            numToIdx[prevNum].erase(index); //O(log(n))
            if(numToIdx[prevNum].empty()) {
                numToIdx.erase(prevNum); //O(1)
            }
        }


        idxToNum[index] = number;
        numToIdx[number].insert(index); //O(log(n))

    }
    
    int find(int number) {
        if(numToIdx.count(number)) { //O(1)
            return *numToIdx[number].begin(); //O(1)
        }

        return -1;    
    }
};



//Approach-2 (Using two maps : map of int, int and map of int, min-heap)
//T.C : O(log(n) + k*logn)
//S.C : O(n)
class NumberContainers {
public:
    //Space : O(n)
    unordered_map<int, int> idxToNum;
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> numToIdx;

    NumberContainers() {
        //do nothing    
    }
    
    void change(int index, int number) {
        idxToNum[index] = number; //O(1)

        numToIdx[number].push(index); //O(log(n))
    }
    
    int find(int number) {
        if(!numToIdx.count(number)) {
            return -1;
        }

        auto& pq = numToIdx[number];

        while(!pq.empty()) { //O(k * logn)
            int idx = pq.top(); //O(1)

            if(idxToNum[idx] == number) {
                return idx;
            }

            pq.pop(); //O(log(n))
        }

        return -1;
    }
};



/***************************************************************** Java *****************************************************************/
//Approach-1 (Using two maps : map of int, int and map of int, set)
//T.C : O(log(n))
//S.C : O(n)
class NumberContainers {
    // Space : O(n)
    private Map<Integer, Integer> idxToNum;
    private Map<Integer, TreeSet<Integer>> numToIdx;

    public NumberContainers() {
        idxToNum = new HashMap<>();
        numToIdx = new HashMap<>();
    }
    
    public void change(int index, int number) {
        if(idxToNum.containsKey(index)) { // O(1)
            int prevNum = idxToNum.get(index);
            numToIdx.get(prevNum).remove(index); // O(log(n))
            if(numToIdx.get(prevNum).isEmpty()) {
                numToIdx.remove(prevNum); // O(1)
            }
        }

        idxToNum.put(index, number);
        numToIdx.putIfAbsent(number, new TreeSet<>());
        numToIdx.get(number).add(index); // O(log(n))
    }
    
    public int find(int number) {
        if(numToIdx.containsKey(number)) { // O(1)
            return numToIdx.get(number).first(); // O(1)
        }
        return -1;
    }
}


//Approach-2 (Using two maps : map of int, int and map of int, min-heap)
//T.C : O(log(n) + k*logn)
//S.C : O(n)
class NumberContainers {
    // Space : O(n)
    private Map<Integer, Integer> idxToNum;
    private Map<Integer, PriorityQueue<Integer>> numToIdx;

    public NumberContainers() {
        idxToNum = new HashMap<>();
        numToIdx = new HashMap<>();
    }
    
    public void change(int index, int number) {
        idxToNum.put(index, number); // O(1)
        numToIdx.putIfAbsent(number, new PriorityQueue<>());
        numToIdx.get(number).offer(index); // O(log(n))
    }
    
    public int find(int number) {
        if (!numToIdx.containsKey(number)) {
            return -1;
        }

        PriorityQueue<Integer> pq = numToIdx.get(number);

        while (!pq.isEmpty()) { // O(k * logn)
            int idx = pq.peek(); // O(1)
            if (idxToNum.get(idx) == number) {
                return idx;
            }
            pq.poll(); // O(log(n))
        }
        return -1;
    }
}
