/*
    Company Tags  : Microsoft
    Question Link : https://practice.geeksforgeeks.org/problems/pairs-which-are-divisible-by-4/0#
    Another Variation to this Question -
    (Leetcode - 1010 - https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Pairs%20of%20Songs%20With%20Total%20Durations%20Divisible%20by%2060)
*/

#include<iostream>
#include<vector>
using namespace std;
int main()
 {
	int T;
	cin >> T;
	while(T--) {
	    int n;
	    int a;
	    cin >> n;
	    vector<int> mod(4, 0);
	    for(int i = 0; i<n; i++) {
	        cin >> a;
	        mod[a%4]++;
	    }
	    int count = 0;
	    
	    count += mod[0]*(mod[0]-1)/2;
	    count += mod[2]*(mod[2]-1)/2;
	    count += mod[1]*mod[3];
	    cout << count << endl;
	}
	return 0;
}
