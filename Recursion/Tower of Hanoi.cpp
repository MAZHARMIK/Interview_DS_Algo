/*						Scroll Down to see JAVA code also							*/
/*
	MY YOUTUBE VIDEON ON THIS Qn : https://www.youtube.com/watch?v=FfUE6gtqOB4
    	Company Tags 		     : OYO Rooms, Samsung, Goldman Sachs
    	Qn Link      		     : https://practice.geeksforgeeks.org/problems/tower-of-hanoi/0 
*/

/*************************************************************** C++ ********************************************************/
//T.C : O(2^n)
//S.C : O(n) - Recursion Stack Space
class Solution{
    public:
    // You need to complete this function

    // avoid space at the starting of the string in "move disk....."
    long long toh(int n, int from, int to, int aux) {
        if(n == 1) {
            cout << "move disk " << n << " from rod " << from << " to rod " << to << endl;
            return 1;
        }
        
	int count = toh(n-1, from, aux, to);
        
        cout << "move disk " << n << " from rod " << from << " to rod " << to << endl;
        count++;
        
        count += toh(n-1, aux, to, from);
        
        return count;
    }

};


/*************************************************************** JAVA ********************************************************/
//T.C : O(2^n)
//S.C : O(n) - Recursion Stack Space
class Hanoi {

    public long toh(int N, int from, int to, int aux) {
        if (N == 1) {
            System.out.println("move disk " + N + " from rod " + from + " to rod " + to);
            return 1;
        }

        long count = toh(N - 1, from, aux, to);

        System.out.println("move disk " + N + " from rod " + from + " to rod " + to);
        count++;

        count += toh(N - 1, aux, to, from);

        return count;
    }
}
