/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=ZfoOyJkD-lo
    Company Tags                : Google, HCL, IBM, HCL, Accenture
    Leetcode Link               : https://leetcode.com/problems/find-original-array-from-doubled-array/
*/

//Approach-1 (Using sorting and map)
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        
        //odd length
        if(n%2 != 0) {
            return {};
        }
        
        sort(begin(changed), end(changed));
        
        map<int, int> mp;
        
        //store frequency of each number
        for(int &num : changed) {
            mp[num]++;
        }
        
        vector<int> result;
        
        for(int &num : changed) {
            int twice = 2*num;
            
            if(mp[num] == 0) continue; //skip
            
            if(mp.find(twice) == mp.end() || mp[twice] == 0) {
                return {};
            }
            
            result.push_back(num);
            
            mp[num]--;
            mp[twice]--;
        }
        
        return result;
    }
};


//Approach-2 (Using sorting and Binary Search)
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        vector<int> result;
        
        sort(begin(changed), end(changed));
		/*
			Since I have sorted the array, so I will find the twice of a number
			If I get it, well and good, check further
			else, return {}
		*/
        for(int i = 0; i<n; i++) {
            int num = changed[i];
            if(num < 0) continue;
            
            auto idx = lower_bound(begin(changed)+i+1, end(changed), 2*num);
            
            if(idx != end(changed) && *idx == 2*num) {
                *idx = -1; //mark it
                result.push_back(num); //found it
            } else {
                return {}; //oooops
            }
        }
        
        return result;
    }
};
