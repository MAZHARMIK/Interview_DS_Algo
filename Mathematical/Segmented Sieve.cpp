/*
    Company Tags  : Not yet (But good for knowledge and helps in Competitve Coding)
    Question Link : https://www.geeksforgeeks.org/segmented-sieve/
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> sieve(int r) {
    vector<bool> isPrime(r+1, true);

    for(int i = 2; i <= r; i++) {
        if(isPrime[i] == true) {
            for(int j = i*i; j<=r; j+=i) {
                isPrime[j] = false;
            }
        }
    }    

    vector<int> primes;
    for(int i = 2; i<=r; i++) {
        if(isPrime[i])
            primes.push_back(i);
    }

    return primes;
}

void printPrimes(int l, int r, vector<int>& primes) {
    vector<bool> isPrime(r-l+1, true);
    // 2  3  4
    // 0  1  2
    //{T, T, T}

    //0 corresponds to l
    //1 corresponds to l+1 and so on...

    for(int &x : primes) {
        if(x*x > r) break;

        int base = (l/x) * x;
        if(base < l)
            base += x;

        for(int j = base; j<=r; j+=x) {
            isPrime[j-l] = false;
        }

        if(base == x) {
            isPrime[base-l] = true;
        }
    }

    for(int i = 0; i<=r-l; i++) {
        if(isPrime[i])
            cout << i+l << " ";
    }

}

int main() {
    int l, r;
    cin >> l >> r;
    if(l == 1)
        l++;
    int x = sqrt(r);
    vector<int> primes = sieve(x);

    printPrimes(l, r, primes);
}
