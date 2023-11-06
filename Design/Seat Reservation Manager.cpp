/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=fjwHZNvbr7g
    Company Tags                : META
    Leetcode Link               : https://leetcode.com/problems/seat-reservation-manager/
*/

/*************************************************************** C++ ***************************************************************/
//Approach-1 (Brute Force) - T.L.E
//T.C : O(m * n) , where m = number of calls and n = time taken to reserve
//S.C : O(n)
class SeatManager {
public:
    vector<int> t;
    int N;
    SeatManager(int n) {
        N = n;
        t.resize(n+1, -1); //Unreserved
    }
    
    int reserve() {
        for(int i = 1; i<N+1; i++) {
            if(t[i] == -1) {
                t[i] = 1; // Reserved
                return i;
            }
        }
        return -1;
    }
    
    void unreserve(int seatNumber) {
        t[seatNumber] = -1;
    }
};

//Approach-2 - Reducing the time taken by reserve (Accepted)
//T.C : O((m+n) * logn)
//S.C : O(n)
class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    SeatManager(int n) {
        for(int i = 1; i<=n; i++) {
            pq.push(i); //nlogn
        }
    }
    
    int reserve() {
        int seat = pq.top(); 
        pq.pop(); //logn
        return seat;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber); //logn
    }
};

//Approach-3 (Improving Approach-2) - Avoiding pre-initialising of heap
//T.C : O(m* log(n)) , where m = number of reserve calls
//S.C : O(n)
class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int seat_marker;
    SeatManager(int n) {
        seat_marker = 1;
    }
    
    int reserve() {
        if(!pq.empty()) {
            int seat = pq.top();
            pq.pop(); //log(n)
            return seat;
        }
        
        int seat = seat_marker;
        seat_marker++;
        return seat;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};


/*************************************************************** JAVA ***************************************************************/
//Approach-1 (Brute Force) - T.L.E
//T.C : O(m * n) , where m = number of calls and n = time taken to reserve
//S.C : O(n)
class SeatManager {
    private int[] t;
    private int N;

    public SeatManager(int n) {
        N = n;
        t = new int[n + 1];
        Arrays.fill(t, -1); // Unreserved
    }

    public int reserve() {
        for (int i = 1; i < N + 1; i++) {
            if (t[i] == -1) {
                t[i] = 1; // Reserved
                return i;
            }
        }
        return -1;
    }

    public void unreserve(int seatNumber) {
        t[seatNumber] = -1;
    }
}

//Approach-2 - Reducing the time taken by reserve (Accepted)
//T.C : O((m+n) * logn)
//S.C : O(n)
class SeatManager {
    private PriorityQueue<Integer> pq;

    public SeatManager(int n) {
        pq = new PriorityQueue<>();
        for (int i = 1; i <= n; i++) {
            pq.add(i);
        }
    }

    public int reserve() {
        int seat = pq.poll();
        return seat;
    }

    public void unreserve(int seatNumber) {
        pq.add(seatNumber);
    }
}


//Approach-3 (Improving Approach-2) - Avoiding pre-initialising of heap
//T.C : O(m* log(n)) , where m = number of reserve calls
//S.C : O(n)
class SeatManager {
    private PriorityQueue<Integer> pq;
    private int seatMarker;

    public SeatManager(int n) {
        pq = new PriorityQueue<>();
        seatMarker = 1;
    }

    public int reserve() {
        if (!pq.isEmpty()) {
            int seat = pq.poll();
            return seat;
        }

        int seat = seatMarker;
        seatMarker++;
        return seat;
    }

    public void unreserve(int seatNumber) {
        pq.add(seatNumber);
    }
}
