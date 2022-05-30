/*
    Company Tags : Microsoft (Puzzle Round)
    Question :
    Given an integer, write a function that calculates ⌈7n/8⌉ (ceiling of 7n/8) without using division and multiplication operators.
*/

#include <iostream>
using namespace std;

/*
    What you need to know to solve such a quesntion.
    1) n << x = n * 2^x (Left Shift)
    2) n >> x = n/2^x   (Right Shift)
    3) 7n/8 = (8n - n)/8 = (2^3 * n  -  n)/2^3
    So, To calculate 2^3 * n , we will simply do (n << 3) . Let it be 'H'
    So, we then find (H-n) = Z
    And to calculate Z/2^3  , we will simply do (Z >> x)
*/

int main() {
    int n = 9;

    int H = (n << 3);
    int Z = H-n;

    cout << ((((n << 3) - n)) >> 3) << endl;
    cout << "7*n/8 = " << (Z >> 3);

    return 0;
}
