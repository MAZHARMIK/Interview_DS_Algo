/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Accolite, Amazon, Media.net
    GfG Link                    : https://www.geeksforgeeks.org/problems/top-k-numbers3425/1
*/


/***************************************************** C++ ******************************************************/
//Approach-1 (Using Array and map)
//T.C : O(n*k)
//S.C : O(n)
class Solution {
  public:
    vector<vector<int>> kTop(vector<int>& arr, int N, int K) {
        vector<vector<int>> result;
        unordered_map<int, int> mp;
        
        vector<int> top(K+1);
        //5, 2, 1, 3, 2
        for(int i = 0; i < N; i++) {
            int val = arr[i]; //5
            
            mp[val]++; //5 -> 1
            top[K] = val; //{0, 0, 0, 0, 5}
            
            int idx = K;
            
            for(int j = K-1; j >= 0; j--) {
                if(top[j] == val) {
                    idx = j;
                    break;
                }
            }
            
            for(int j = idx-1; j >= 0; j--) {
                if(mp[top[j]] < mp[top[j+1]]) {
                    swap(top[j], top[j+1]);
                } else if(mp[top[j]] == mp[top[j+1]] && (top[j] > top[j+1])) {
                    swap(top[j], top[j+1]);
                } else {
                    break;
                }
            }
            
            vector<int> temp;
            for (int j = 0; j < K && top[j] != 0; ++j) {
                temp.push_back(top[j]);
            }
                
            result.push_back(temp);
        }
        
        return result;
    }
};

//Approach-2 (Using Heap - For some reason, this is not getting submitted. No error is coming)
//T.C : O(nlog(n))
//S.C : O(n);
typedef pair<int, int> P;
class Solution
{
  public:
    struct compare {
        bool operator() (P& p1, P& p2) {
            if(p1.second == p2.second)
                return p1.first > p2.first;
                
            return p1.second < p2.second;
        }  
    };
    vector<int> kTop(int a[], int n, int k) 
    { 
        vector<int> result;
        unordered_map<int, int> mp;
        
        
        for(int i = 0; i<n; i++) {
            mp[a[i]]++;
            
            priority_queue<P, vector<P>, compare> pq(mp.begin(), mp.end());
            int n = k;
            while(!pq.empty() && n > 0) {
                auto curr = pq.top();
                result.push_back(curr.first);
                pq.pop();
                n--;
            }
        }
        
        return result;
    }
};

/***************************************************** JAVA ******************************************************/
//T.C : O(n*k)
//S.C : O(n)
//Will update soon


//Approach-2 (Using Heap - For some reason, this is not getting submitted. No error is coming)
//T.C : O(nlog(n))
//S.C : O(n);
class Solution {
    public static ArrayList<ArrayList<Integer>> kTop(int[] arr, int N, int K) {
        ArrayList<ArrayList<Integer>> result = new ArrayList<>();
        Map<Integer,Integer> map=new HashMap<>();
        
        for(int i:arr)
        {
            ArrayList<Integer> temp = new ArrayList<>();
            map.put(i,map.getOrDefault(i,0)+1);
            
            PriorityQueue<Integer> pq=new PriorityQueue<>((x,y)->{
                if(map.get(x) == map.get(y))
                    return x - y;
                return map.get(y) - map.get(x);
            });
            
            for(int key:map.keySet())
                pq.add(key);
            
            int count = 0;
            while(!pq.isEmpty())
            {
                if(count < K)
                {
                    temp.add(pq.peek());
                    count++;
                }
                pq.poll();
            }
            result.add(temp);
        }
        return result;
    }
}
