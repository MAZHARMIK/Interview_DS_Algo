/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=AsAdKHkITBQ
    Company Tags                : Google, Facebook, Apple, Amazon, Netflix, Flipkart
    GfG Link                    : https://practice.geeksforgeeks.org/problems/disjoint-set-union-find/1
*/

/*Complete the functions below*/
int find(int A[],int x)
{
       if(A[x] == x)
        return x;
        
        return A[x] = find(A, A[x]); //This is Path compression
}
void unionSet(int A[],int X,int Z)
{
	int x = find(A, X);
	int y = find(A, Z);
	
	if(x == y)
	    return;
	
	A[x] = y;
}
