/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=ixzhJ8OoA6Q
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/
*/


/****************************************************************** C++ ******************************************************************/
//Approach-1 (Using simple iteration)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int mod = 1e9 + 7;
    
    int numberOfWays(string corridor) {
        vector<int> pos_seats;
        
        for (int i = 0; i < corridor.size(); i++) {
            if (corridor[i] == 'S') {
                pos_seats.push_back(i);
            }
        }
        
        if (pos_seats.size() % 2 || pos_seats.size() == 0)
            return 0;
        
        long long result = 1;
        int prev         = pos_seats[1]; //End index of the starting subarray having 2 seats
        
        for (int i = 2; i < pos_seats.size(); i += 2) {
            int length = pos_seats[i] - prev;
            result     = (result * length) % mod;
            
            prev = pos_seats[i + 1];
        }
        
        return result;
    }
};


//Approach-2 (DP) -> Will soon updat


/****************************************************************** JAVA ******************************************************************/
//Approach-1 (Using simple iteration)
//T.C : O(n)
//S.C : O(n)
public class Solution {
    int mod = 1000000007;

    public int numberOfWays(String corridor) {
        ArrayList<Integer> posSeats = new ArrayList<>();

        for (int i = 0; i < corridor.length(); i++) {
            if (corridor.charAt(i) == 'S') {
                posSeats.add(i);
            }
        }

        if (posSeats.size() % 2 != 0 || posSeats.size() == 0) {
            return 0;
        }

        long result = 1;
        int prev = posSeats.get(1); // End index of the starting subarray having 2 seats

        for (int i = 2; i < posSeats.size(); i += 2) {
            int length = posSeats.get(i) - prev;
            result = (result * length) % mod;

            prev = posSeats.get(i + 1);
        }

        return (int) result;
    }
}
