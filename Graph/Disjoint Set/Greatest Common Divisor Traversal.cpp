/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=TI-xIXH4EnE
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/greatest-common-divisor-traversal/
*/


/********************************************************************** C++ **********************************************************************/
//T.C : O(N * sqrt(N) * alpha) where alpha is for Union Find operations. But it's small , so we can ignore it to O(1) as average --> O(N*sqrt(N))
//S.C : O(N)
class DSU {
    vector<int> parent;
    vector<int> size;
    int numberOfComponents;
    
public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n);
        numberOfComponents = n;
        
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
        
        numberOfComponents -= 1;
    }
    
    int maxSize() {
        return numberOfComponents;
    }
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        DSU dsu(n);
        
        int m = *max_element(nums.begin(), nums.end());
        
        vector<int> first(m+1, -1);

        for (int i = 0; i < n; ++i) {
            
            for (int prime = 2; prime * prime <= nums[i]; ++prime) {
                if (nums[i] % prime != 0)
                    continue;
                
                if (first[prime] != -1) 
                    dsu.Union(first[prime], i);
                else
                    first[prime] = i;
                
                while (nums[i] % prime == 0) 
                    nums[i] /= prime;
            }
            
            if (nums[i] > 1) {
                if (first[nums[i]] != -1) 
                    dsu.Union(first[nums[i]], i);
                else 
                    first[nums[i]] = i;
            }
            
        }

        return dsu.maxSize() == 1;
    }
};



/********************************************************************** JAVA **********************************************************************/
//T.C : O(N * sqrt(N) * alpha) where alpha is for Union Find operations. But it's small , so we can ignore it to O(1) as average --> O(N*sqrt(N))
//S.C : O(N)
class DSU {
    private int[] parent;
    private int[] size;
    private int numberOfComponents;

    public DSU(int n) {
        parent = new int[n];
        size = new int[n];
        numberOfComponents = n;

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    public int find(int x) {
        if (x == parent[x])
            return x;

        return parent[x] = find(parent[x]);
    }

    public void union(int x, int y) {
        int xParent = find(x);
        int yParent = find(y);

        if (xParent == yParent)
            return;

        if (size[xParent] > size[yParent]) {
            parent[yParent] = xParent;
            size[xParent] += size[yParent];
        } else if (size[xParent] < size[yParent]) {
            parent[xParent] = yParent;
            size[yParent] += size[xParent];
        } else {
            parent[xParent] = yParent;
            size[yParent] += size[xParent];
        }

        numberOfComponents -= 1;
    }

    public int maxSize() {
        return numberOfComponents;
    }
}

class Solution {
    public boolean canTraverseAllPairs(int[] nums) {
        int n = nums.length;
        DSU dsu = new DSU(n);

        int m = Arrays.stream(nums).max().orElse(0);
        int[] first = new int[m + 1];
        Arrays.fill(first, -1);

        for (int i = 0; i < n; ++i) {
            for (int prime = 2; prime * prime <= nums[i]; ++prime) {
                if (nums[i] % prime != 0)
                    continue;

                if (first[prime] != -1)
                    dsu.union(first[prime], i);
                else
                    first[prime] = i;

                while (nums[i] % prime == 0)
                    nums[i] /= prime;
            }

            if (nums[i] > 1) {
                if (first[nums[i]] != -1)
                    dsu.union(first[nums[i]], i);
                else
                    first[nums[i]] = i;
            }
        }

        return dsu.maxSize() == 1;
    }
}
