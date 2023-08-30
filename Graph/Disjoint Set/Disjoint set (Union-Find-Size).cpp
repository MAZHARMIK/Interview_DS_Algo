/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=kGv33AiGhdc
    Company Tags                : Google, Facebook, Apple, Amazon, Netflix, Flipkart
*/

#include <bits/stdc++.h>
using namespace std;
class DSU {
    vector<int> parent;
	vector<int> size;
public:
    DSU(int n) {
    	parent.resize(n);
        size.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int x) {
        if (x == parent[x])
            return x;
            
        return parent[x] = find(parent[x]);
    }

    void Union (int x, int y) {
	    int x_parent = find(x);
	    int y_parent = find(y);
	
	    if (x_parent == y_parent) 
	        return;
	
	    if(size[x_parent] > size[y_parent]) {
	        parent[y_parent] = x_parent;
	        size[x_parent]  += size[y_parent];
	    } else if(size[x_parent] < size[y_parent]) {
	        parent[x_parent] = y_parent;
	        size[y_parent]  += size[x_parent];
	    } else {
	        parent[x_parent] = y_parent;
	        size[y_parent]  += size[x_parent];
	    }
	}
};
int main() {
    DSU dsu(6);
    dsu.Union(0, 1);
    dsu.Union(0, 2);
    
    // if 0 and 3 are not on same Component yet
    if (dsu.find(0) == dsu.find(3)) {
        cout << "In same component" << endl;
    } else {
    	cout << "Not in same component" << endl;
    }
    
    //Now we will Union 0 and 3
    dsu.Union(0, 3);
    if (dsu.find(0) == dsu.find(3)) {
        cout << "In same component" << endl;
    } else {
    	cout << "Not in same component" << endl;
    }
}
