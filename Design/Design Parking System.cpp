/*
    MY YOUTUBE VIDEO ON THIS Qn : <soon>
    Company Tags                : Google
    Leetcode Link               : https://leetcode.com/problems/design-parking-system/
*/

class ParkingSystem {
public:
    int b, m, s;
    ParkingSystem(int big, int medium, int small) {
        b = big;
        m = medium;
        s = small;
    }
    
    bool addCar(int carType) {
        
        if(carType == 1 && b == 0)
            return false;
        if(carType == 2 && m == 0)
            return false;
        if(carType == 3 && s == 0)
            return false;
        
        
        if(carType == 1) 
            b--;
        if(carType == 2) 
            m--;
        if(carType == 3) 
            s--;
        
        return true;
    }
};
