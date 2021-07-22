/*
    Company Tags  : Google
    Leetcode Link : https://leetcode.com/problems/push-dominoes/
*/

//Approach-1 (O(n) time : Two Pointer Technique)
/*
	In this approach, you just need to find sections like this
	X .   .   .   . X
	i                j
	Where X can be 'R' or 'L' and in between there can be as many dots
	Now,
	- you know the length of mid part
	- If char[i] == char[j] == 'R', means all go towards right (R)
	-  char[i]  == char[j] == 'L', means all go towards Left (L)
	-  If char[i] = 'L' and char[j] = 'R', means middle part is not affected so the remain '.'
	-  If char[i] = 'R' and char[j] = 'L', then it will affect the middle part.
	   The middle_part/2 close to i will be affected by 'R' and middle_part/2 close to j will be   
	   effected by 'L'  and the last mid point (middle_part%2) will be unaffected due to equal  
	   force from left and right so it remains '.'
*/
class Solution {
public:
    string pushDominoes(string dominoes) {
        string s = "L" + dominoes + "R";
        int n    = s.length();
        string result = "";
        for(int i = 0, j = 1; j<n; j++) {
            if(s[j] == '.') continue;
            
            int midPartLength = j-i-1;
            if(i > 0)
                result.push_back(s[i]);
            
            if(s[i] == s[j])
                result += string(midPartLength, s[i]);
            else if(s[i] == 'L' && s[j] == 'R')
                result += string(midPartLength, '.');
            else
                result += string(midPartLength/2, 'R') + string(midPartLength%2, '.') + string(midPartLength/2, 'L');
            i = j;
        }
        
        return result;
    }
};

//Approach-2 (O(n) time : Finding closest 'L' and closest 'R')
class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        
        vector<int> rightClosestL(n);
        vector<int> leftClosestR(n);
        
        //Moving right to left to find rightClosestL
        for(int i = n-1; i>=0; i--) {
            if(dominoes[i] == 'L')
                rightClosestL[i] = i; //L starts from me
            else if(dominoes[i] == '.')
                rightClosestL[i] = i < n-1 ? rightClosestL[i+1] : -1;
            else
                rightClosestL[i] = -1;
        }
        
        //Moving left to right to find leftClosestR
        for(int i = 0; i<n; i++) {
            if(dominoes[i] == 'R')
                leftClosestR[i] = i; //R starts from me
            else if(dominoes[i] == '.')
                leftClosestR[i] = i > 0 ? leftClosestR[i-1] : -1;
            else
                leftClosestR[i] = -1;
        }
        
        string result(n, ' ');
        
        for(int i = 0; i<n; i++) {
            int distRightL = abs(i-rightClosestL[i]); //distance from 'R' towards my left direction
            int distLeftR  = abs(i-leftClosestR[i]);  //distance from 'L' towards my right direction
            
            if(rightClosestL[i] == leftClosestR[i])
                result[i] = '.';
            else if(rightClosestL[i] == -1)  //No force from right direction towards left, so move R
                result[i] = 'R';
            else if(leftClosestR[i] == -1)   //No force from left direction towards right, so move L
                result[i] = 'L';
            else if(distLeftR == distRightL) //Equal force from left and right
                result[i] = '.';
            else
                result[i] = distRightL < distLeftR ? 'L': 'R'; //which ever force is greater (either from left by 'R' or from right by 'L')
        }
        
        return result;
    }
};

//Approach-3 (O(n) time : Using Force Simulation)
class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        
        vector<int> forces(n);
        
        //Move from left to right and look for right force 'R'
        int force = 0; //initially
        for(int i = 0; i<n; i++) {
            if(dominoes[i] == 'R')
                force = n; //My max power towards Right starts from here and it will decrease as I progress
            else if(dominoes[i] == 'L')
                force = 0; //I can't give force towards Right :-(
            else
                force = max(force-1, 0); //I told ya, my power decreases as I progress and hit a '.'
            
            forces[i] = force;
        }
        
        //Move from right to left and look for left force 'L'
        force = 0; //initially
        for(int i = n-1; i>=0; i--) {
            if(dominoes[i] == 'L')
                force = n; //My max power towards Left starts from here and it will decrease as I progress
            else if(dominoes[i] == 'R')
                force = 0; //I can't give force towards Left :-(
            else
                force = max(force-1, 0); //I told ya, my power decreases as I progress and hit a '.'
            
            forces[i] -= force; //resultant force (that's why I am subtracting)
        }
        
        //Now I will find resultant direction on each domino basis of resultant force on them
        string result(n ,'.');
        for(int i = 0; i<n; i++) {
            if(forces[i] < 0)
                result[i] = 'L';
            else if(forces[i] > 0)
                result[i] = 'R';
        }
        return result;
        
    }
};
