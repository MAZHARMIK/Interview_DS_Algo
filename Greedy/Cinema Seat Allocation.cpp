/*         Scroll down to see JAVA code also                    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/cinema-seat-allocation/
*/


/********************************************************************* C++ ****************************************************************/
//Approach-1 (Greedy Pick using map)
//T.C : O(N), N = reservedSeats.size()
//S.C : O(N), for storing reswerved seats in map (in form of unordered_set)
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> mp; //row -> seats in each row booked

        for(auto& reservedSeat : reservedSeats) {
            int row  = reservedSeat[0];
            int seat = reservedSeat[1];

            mp[row].insert(seat);
        }

        int result = (n - mp.size()) * 2;

        for(auto& [row, bookedSeats] : mp) {

            auto isAvailable = [&](int seat) {
                return bookedSeats.find(seat) == bookedSeats.end();
            };

            bool graupA = isAvailable(2) && isAvailable(3) && isAvailable(4) & isAvailable(5);
            bool graupB = isAvailable(4) && isAvailable(5) && isAvailable(6) & isAvailable(7);
            bool graupC = isAvailable(6) && isAvailable(7) && isAvailable(8) & isAvailable(9);

            if(graupA && graupC)
                result += 2;
            else if(graupA || graupB || graupC)
                result += 1;

        }

        return result;
    }
};


//Approach-2 (Greedy Pick using bit mask)
//T.C : O(N), N = reservedSeats.size()
//S.C : O(N), for storing reswerved seats in the form of mask
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp; //row -> seats in each row booked

        for(auto& reservedSeat : reservedSeats) { //O(10^4)
            int row  = reservedSeat[0];
            int seat = reservedSeat[1];

            mp[row] |= (1 << seat); //set bits are the booked seats
        }

        int result = (n - mp.size()) * 2;

        int maskA = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5); //set bits are the ones which I need empty for Group A
        int maskB = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7); //set bits are the ones which I need empty for Group B
        int maskC = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9); //set bits are the ones which I need empty for Group C

        for(auto& [row, bookedSeatsMask] : mp) { //min(10*n, 10^4)
            bool graupA = (bookedSeatsMask & maskA) == 0;
            bool graupB = (bookedSeatsMask & maskB) == 0;
            bool graupC = (bookedSeatsMask & maskC) == 0;

            if(graupA && graupC)
                result += 2;
            else if(graupA || graupB || graupC)
                result += 1;

        }

        return result;
    }
};



/********************************************************************* JAVA ****************************************************************/
//Approach-1 (Greedy Pick using map)
//T.C : O(N), N = reservedSeats.length
//S.C : O(N), for storing reserved seats in map (in form of HashSet)
class Solution {
    public int maxNumberOfFamilies(int n, int[][] reservedSeats) {
        Map<Integer, Set<Integer>> mp = new HashMap<>(); //row -> seats booked in each row

        for(int[] reservedSeat : reservedSeats) {
            int row  = reservedSeat[0];
            int seat = reservedSeat[1];
            mp.computeIfAbsent(row, k -> new HashSet<>()).add(seat);
        }

        int result = (n - mp.size()) * 2;

        for(Map.Entry<Integer, Set<Integer>> entry : mp.entrySet()) {
            Set<Integer> bookedSeats = entry.getValue();

            boolean groupA = !bookedSeats.contains(2) && !bookedSeats.contains(3) && !bookedSeats.contains(4) && !bookedSeats.contains(5);
            boolean groupB = !bookedSeats.contains(4) && !bookedSeats.contains(5) && !bookedSeats.contains(6) && !bookedSeats.contains(7);
            boolean groupC = !bookedSeats.contains(6) && !bookedSeats.contains(7) && !bookedSeats.contains(8) && !bookedSeats.contains(9);

            if(groupA && groupC)
                result += 2;
            else if(groupA || groupB || groupC)
                result += 1;
        }

        return result;
    }
}



//Approach-2 (Greedy Pick using bit mask)
//T.C : O(N), N = reservedSeats.length
//S.C : O(N), for storing reserved seats in the form of mask
class Solution {
    public int maxNumberOfFamilies(int n, int[][] reservedSeats) {
        Map<Integer, Integer> mp = new HashMap<>(); //row -> bitmask of booked seats

        for(int[] reservedSeat : reservedSeats) { //O(10^4)
            int row  = reservedSeat[0];
            int seat = reservedSeat[1];
            mp.merge(row, (1 << seat), (a, b) -> a | b); //set bits are the booked seats
        }

        int result = (n - mp.size()) * 2;

        int maskA = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5); //set bits are the ones I need empty for Group A
        int maskB = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7); //set bits are the ones I need empty for Group B
        int maskC = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9); //set bits are the ones I need empty for Group C

        for(Map.Entry<Integer, Integer> entry : mp.entrySet()) { //min(10*n, 10^4)
            int bookedSeatsMask = entry.getValue();

            boolean groupA = (bookedSeatsMask & maskA) == 0;
            boolean groupB = (bookedSeatsMask & maskB) == 0;
            boolean groupC = (bookedSeatsMask & maskC) == 0;

            if(groupA && groupC)
                result += 2;
            else if(groupA || groupB || groupC)
                result += 1;
        }

        return result;
    }
}
