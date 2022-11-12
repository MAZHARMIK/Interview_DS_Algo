/*
    MY YOUTUBE VIDEO ON THIS Qn : <soon>
    Company Tags                : Apple, AMAZON, VMWARE, GOOGLE, MICROSOFT, GOLDMAN SACHS, Adobe, Belzabar, SAP Labs, Yahoo,
                                  D-E-Shaw, Facebook, Flipkart, Google, Intuit, Microsoft, Morgan Stanley, Ola Cabs, Oracle, Samsung
    Leetcode Link               : https://leetcode.com/problems/find-median-from-data-stream/
*/

//Approach-1 (O(n^2) - TLE
class MedianFinder {
public:
    vector<int> vec;
    int i = 0;
    MedianFinder() {
        vec.resize(5*10000+1);
    }
    
    void addNum(int num) {
        if(i == 0) {
            vec[i++] = num;
            return;
        }
        int j = i-1;
        while(j >= 0 && vec[j] > num) {
            vec[j+1] = vec[j];
            j--;
        }
        vec[j+1] = num;
        i++;
    }
    
    double findMedian() {
        int n = i;
        if(n%2 == 0) {
            int l = n/2-1;
            int r = n/2;
            return (float)(vec[l]+vec[r])/2;
        }
        
        return vec[n/2];
    }
};

//Approach-2 (O(logn) insertion using priority_queue) - Accepeted
class MedianFinder {
public:
    priority_queue<int> left_max; //max_heap
    priority_queue<int, vector<int>, greater<int>> right_min; //min_heap
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left_max.empty() || num < left_max.top())
            left_max.push(num);
        else
            right_min.push(num);
        
        //Now, adjust the size
        //left_max can only be greater than right_min by 1 in size;
        if(left_max.size() > right_min.size()+1) {
            right_min.push(left_max.top());
            left_max.pop();
        } else if(left_max.size() < right_min.size()) {
            left_max.push(right_min.top());
            right_min.pop();
        }
    }
    
    double findMedian() {
        if(left_max.size() == right_min.size())
            return (double)(left_max.top()+right_min.top())/2;
        
        return left_max.top();
    }
};
