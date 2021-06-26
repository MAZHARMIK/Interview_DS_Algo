/*
    Company Tags  : Palantir, Palantir Technologies, Airbnb
    Leetcode Link : https://leetcode.com/problems/contains-duplicate-iii/
*/

//Approach-1 (Sorting - Time : O(nlogn))
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        
        vector<pair<int, int>> vec(n);
        
        for(int i = 0; i<nums.size(); i++) {
            vec[i] = make_pair(nums[i], i);
        }
        
        auto lambda = [](const pair<int, int>& p1, const pair<int, int>& p2) {
            if(p1.first == p2.first)
                return p1.second < p2.second;
            return p1.first < p2.first;
        };
        
        sort(begin(vec), end(vec), lambda);
        
        for(int i = 0; i<n; i++) {
            int j = i+1;
            while(j < n) {
                if(abs((long long)vec[j].first - (long long)vec[i].first) > t)
                    break;
                if(abs(vec[j].second - vec[i].second)<= k)
                    return true;
                j++;
            }
        }
        return false;
    }
};

//Approach-2 (Using Hashset - Time O(nlogk)) -
//Just Like "Sliding Window" - So, it falls under Sliding Window catergory as well (https://github.com/MAZHARMIK/Interview_DS_Algo/tree/master/Sliding%20Window)
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        
        set<long long> st;
        
        for(int i = 0; i<n; i++) {
            if(st.size() > k) {
                st.erase(nums[i-k-1]);
            }
            long long element = (long long)nums[i] - (long long)t;
            auto it = st.lower_bound(element);
            if(it != end(st) && abs((long long)nums[i] - (long long)(*it)) <= t) {
                return true;
            }
            st.insert(nums[i]);
        }
        
        return false;
    }
};
