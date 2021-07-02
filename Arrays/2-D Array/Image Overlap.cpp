/*
    Company Tags  : Google
    Leetcode Link : https://leetcode.com/problems/image-overlap/
*/

//Approach-1
class Solution {
public:
    int countOverlaps(vector<vector<int>>& A, vector<vector<int>>& B, int rowOff, int colOff) {
        int n = A.size();
        int count = 0;
        
        /*
            Uncomment these to see how the matrix is moving. For ease, take example : 
            [[0,1],[0,0]]
            [[0,0],[1,0]]
            
            cout << "\n----------------------------\n";
            cout << "Checking for rowOff = " << rowOff << ", collOff = " << colOff << endl;
        */
        
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < n; col++) {
                if(row+rowOff < 0 || row+rowOff >= n || col+colOff < 0 || col+colOff >= n)
                    continue;
                
                /*
                    cout << "A[" << row << "][" << col << "] = " << A[row][col] << ", ";
                    cout  << "B[" << row+rowOff << "][" << col+colOff << "] = " << B[row+rowOff][col+colOff] << endl;
                */
                
                count += A[row][col]*B[row+rowOff][col+colOff];
            }
        }
        
        /*
            cout << "\n----------------------------\n";
        */
        
        return count;
    }
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();
        
        int maxOverlap = 0;
        
        /*
            For ease take this example :
            [[0,1],[0,0]]
            [[0,0],[1,0]]
            
            So, we are basically having rowOffsets from (-n+1) to (n-1). Why ? Read all the comments to know
            For example : n = 2
            rowOff will have values -1, 0, 1
            colOff will have values -1, 0, 1
            
            Based on this rowOff,colOff, we will move B over A starting from "bottom left"
            1) rowOff  = -1, colOff = -1, means B is at bottom left overlapping with A[row][col] and B[row+rowOff][col+colOff]
            i.e. A[row][col] = A[1][1]
            i.e. B[row+rowOff][col+colOff] = B[0][0]
            
            2) For rowOff = -1 , we will have colOff -1, 0, 1 which means we are moving the window B towards right till we cross boundary
            
            Similarly we move ahead with rowOff  = 0, and then 1.....
        */
        
        for(int rowOff = -n+1; rowOff<n; rowOff++) {
            for(int collOff = -n+1; collOff<n; collOff++) {
                maxOverlap = max(maxOverlap, countOverlaps(A, B, rowOff, collOff));
            }
        }
        
        return maxOverlap;
    }
};

//Approach-2 (Why it's wrong ? Read the comment)
//This earlier solution fails because it doesn't check all possible moves. It only checks right/down and left/up but NOT right/up and left/down.
//Earlier it passed because of weak test cases on Leetcode. But I have still kept this solution because it teaches a very good concept of shifting coordinates
class Solution {
public:
    int maxOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();
        int count = 0;
        for(int x_shift = 0; x_shift<n; x_shift++) {
            for(int y_shift = 0; y_shift<n; y_shift++) {
                int temp = 0;
                for(int i = y_shift; i<n; i++) { //because y-shift changes row
                    for(int j = x_shift; j<n; j++) { //because x-shift changes column
                        if(A[i][j] == 1 && B[i-y_shift][j-x_shift] == 1)
                            temp++;
                    }
                }
                count = max(count, temp);
            }
        }
        return count;
    }
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        return max(maxOverlap(A, B), maxOverlap(B, A));
    }
};
