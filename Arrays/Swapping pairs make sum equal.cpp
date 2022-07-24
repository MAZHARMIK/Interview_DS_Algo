/*
    Company Tags : Amazon
    GfG Link     : https://practice.geeksforgeeks.org/problems/swapping-pairs-make-sum-equal4142/1?page=1&curated[]=1&sortBy=submissions
*/

/*
    Easy Math behind this : 

    A = {a, ….., b, ….., c}
    B = {d, ….., e, ….., z}

    S1 = sum of A elements
    S2 = sum of B elements

    Suppose (b, e) on swap will make S1 = S2

    i.e. 
    S1-b+e = S2-e+b
    S1-S2 = 2*(b-e)
    (S1-S2)/2 = (b-e)

    So, if (b-e) is not divisible by 2, then return -1. 
    And if (b-e) is divisible by 2
    
    Then, 
    find an element in B i.e. (e) which is equal to
    A[i]-{(S1-S2)/2} (where A[i] = b)
*/

//Approach-1 (Using Binary Search and Maths)
class Solution{

	public:
	int findSwapValues(int A[], int n, int B[], int m)
	{
        int sum_A = 0;
        int sum_B = 0;
        sort(B, B+m);
        
        for(int i = 0; i<n; i++) {
            sum_A += A[i];
        }
        
        for(int i = 0; i<m; i++) {
            sum_B += B[i];
        }
        
        int diff = (sum_A - sum_B);

        if(diff%2 == 1)
            return -1;
        
        diff = diff/2;
        
        for(int i = 0; i<n; i++) {
            int search = (A[i] - diff);
            int l = 0, h = m-1;
            while(l < h) {
                int mid = l + (h-l)/2;
                if(B[mid] == search) {
                    return 1;
                } else if(B[mid] > search) {
                    h = mid-1;
                } else {
                    l = mid+1;
                }
            }
        }
        
        return -1;
	}
 

};


//Approach-2 (Using set Data Structure and Maths)
class Solution{

	public:
	int findSwapValues(int A[], int n, int B[], int m)
	{
        int sum_A = 0;
        int sum_B = 0;
        unordered_set<int> st;
        for(int i = 0; i<n; i++) {
            sum_A += A[i];
        }
        
        for(int i = 0; i<m; i++) {
            sum_B += B[i];
            st.insert(B[i]);
        }
        
        int diff = (sum_A - sum_B);

        if(diff%2 == 1)
            return -1;
        
        diff = diff/2;
        
        for(int i = 0; i<n; i++) {
            int search = (A[i] - diff);
            if(st.find(search) != st.end())
                return 1;
        }
        
        return -1;
	}
 

};
