/*
    Company Tags  : Google, Adboe, Netflix, Amazon, Microsoft, Apple, Facebook (wooooo dayuummmm)
    Leetcode Link : https://leetcode.com/problems/maximum-frequency-stack/
*/

class FreqStack {
public:
    priority_queue<pair<int, pair<int, int>>> pq;
    //max_heap of <pair<frequency_of_element, pair<pos, element>>
    //So that max frequency is always at tope
    //In tie of frequency, element having greater pos will be at top
    //and element with highest pos will be most frequent
    unordered_map<int, int> mp;
    //element->frequency
    int pos = 0;
    FreqStack() {
        
    }
    
    void push(int x) {
        auto val = make_pair(++mp[x], make_pair(++pos, x));
        pq.emplace(val);
    }
    
    int pop() {
        auto it = pq.top();
        pq.pop();
        int element = it.second.second; //always safe to call it (mentioned in the question)
        mp[element]--;
        return element;
    }
};
