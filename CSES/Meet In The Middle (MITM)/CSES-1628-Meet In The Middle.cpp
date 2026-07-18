/*     Scroll below to see JAVA code as well    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=YWKib1hflGg
    What is Meet In The Middle  : https://www.youtube.com/watch?v=NCr27WYjCH4
    Company Tags                : Google
    CSES Link                   : https://cses.fi/problemset/task/1628/
*/


/******************************************************************************* C++ ************************************************************************************************/
//Approach (Using MITM)
//T.C : O(n · 2^(n/2))
//S.C : O(2^(n/2))
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
    int n;
    long long x;
    cin >> n >> x;
 
    vector<long long> t(n);
    for (int i = 0; i < n; i++) cin >> t[i];
 
    int n1 = n / 2;
    int n2 = n - n1;
 
    vector<long long> sumsA(1LL << n1);
    for (int mask = 0; mask < (1 << n1); mask++) {
        long long s = 0;
        for (int i = 0; i < n1; i++)
            if (mask & (1 << i)) s += t[i];
        sumsA[mask] = s;
    }
 
    vector<long long> sumsB(1LL << n2);
    for (int mask = 0; mask < (1 << n2); mask++) {
        long long s = 0;
        for (int i = 0; i < n2; i++)
            if (mask & (1 << i)) s += t[n1 + i];
        sumsB[mask] = s;
    }
 
    sort(sumsB.begin(), sumsB.end());
 
    long long count = 0;
    for (long long s : sumsA) {
        long long need = x - s;
        auto lo = lower_bound(sumsB.begin(), sumsB.end(), need);
        auto hi = upper_bound(sumsB.begin(), sumsB.end(), need);
        count += (hi - lo);
    }
 
    cout << count << endl;
    return 0;
}



/******************************************************************************* JAVA ************************************************************************************************/
//Approach (Using MITM)
//T.C : O(n · 2^(n/2))
//S.C : O(2^(n/2))
import java.util.*;
import java.io.*;
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        long x = Long.parseLong(st.nextToken());

        long[] t = new long[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) t[i] = Long.parseLong(st.nextToken());

        int n1 = n / 2;
        int n2 = n - n1;

        long[] sumsA = new long[1 << n1];
        for (int mask = 0; mask < (1 << n1); mask++) {
            long s = 0;
            for (int i = 0; i < n1; i++)
                if ((mask & (1 << i)) != 0) s += t[i];
            sumsA[mask] = s;
        }

        long[] sumsB = new long[1 << n2];
        for (int mask = 0; mask < (1 << n2); mask++) {
            long s = 0;
            for (int i = 0; i < n2; i++)
                if ((mask & (1 << i)) != 0) s += t[n1 + i];
            sumsB[mask] = s;
        }

        Arrays.sort(sumsB);

        long count = 0;
        for (long s : sumsA) {
            long need = x - s;
            int lo = lowerBound(sumsB, need);
            int hi = upperBound(sumsB, need);
            count += (hi - lo);
        }

        System.out.println(count);
    }

    // First index with sumsB[idx] >= key  (equivalent to C++ lower_bound)
    static int lowerBound(long[] a, long key) {
        int lo = 0, hi = a.length;
        while (lo < hi) {
            int mid = (lo + hi) >>> 1;
            if (a[mid] < key) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }

    // First index with sumsB[idx] > key   (equivalent to C++ upper_bound)
    static int upperBound(long[] a, long key) {
        int lo = 0, hi = a.length;
        while (lo < hi) {
            int mid = (lo + hi) >>> 1;
            if (a[mid] <= key) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
}
