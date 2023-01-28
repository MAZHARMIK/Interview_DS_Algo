/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Lh0PXb3Hqik
      Company Tags                : AMAZON
      Leetcode Link               : https://leetcode.com/problems/data-stream-as-disjoint-intervals/
*/


//Approach-1 : O(nlogn) - Using Ordered Set and sorting the array nums
class SummaryRanges {
public:
    unordered_set<int> st;
    SummaryRanges() {
        st.clear();
    }
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<int> nums(begin(st), end(st));
        sort(begin(nums), end(nums));
        
        vector<vector<int>> result;
        
        int n = nums.size();
        
        for(int i = 0; i<n; i++) {
            int start = nums[i];
            
            while(i < n-1 && nums[i]+1 == nums[i+1]) {
                i++;
            }
            result.push_back({start, nums[i]});
        }
        
        return result;
    }
};


//Approach-2 : O(nlogn) - Using Set(which takes log(n) to insert elements)
class SummaryRanges {
public:
    set<int> st;
    SummaryRanges() {
        st.clear();
    }
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<int> nums(begin(st), end(st));
        
        vector<vector<int>> result;
        
        int n = nums.size();
        
        for(int i = 0; i<n; i++) {
            int start = nums[i];
            
            while(i < n-1 && nums[i]+1 == nums[i+1]) {
                i++;
            }
            result.push_back({start, nums[i]});
        }
        
        return result;
    }
};


//Approach-3 - (Using ordered map) - O(logn)
class SummaryRanges {
    map<int, int> intervals;

public:
    SummaryRanges() {}

    void addNum(int value) {
        int left  = value;
        int right = value;
        auto just_greater = intervals.upper_bound(value);
        
        if (just_greater != intervals.begin()) {
            
            auto ek_peeche = just_greater;
            --ek_peeche;
            
            if (ek_peeche->second >= value) {
                return;
            }
            if (ek_peeche->second == value - 1) {
                left = ek_peeche->first;
            }
        }
        if (just_greater != intervals.end() && just_greater->first == value + 1) {
            right = just_greater->second;
            intervals.erase(just_greater);
        }
        intervals[left] = right;
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> result;
        
        for (const auto& p : intervals) {
            result.push_back({p.first, p.second});
        }
        
        return result;
    }
};
