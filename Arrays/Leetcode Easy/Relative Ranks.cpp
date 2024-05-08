/*  Scroll below to see JAVA code also  */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=0UFVdlS2nwI
    Company Tags                : AMAZON
    Leetcode Link               : https://leetcode.com/problems/relative-ranks/
*/

/******************************************************************* C++ ***************************************************************************/
//Approach-1 (Using map and sorting or vector of pair and sorting)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        
        vector<string> result(n);
        
        unordered_map<int, int> mp;
        
         
        for(int i = 0; i < n; i++) {
            mp[score[i]] = i; //ith athelete
        }
        
        sort(begin(score), end(score), greater<int>()); //descending
        
        
        for(int i = 0; i < n; i++) {
            
            if(i == 0) { //1st Rank wala athelete
                int ath = mp[score[i]];
                result[ath] = "Gold Medal";
            } else if(i == 1) {
                int ath = mp[score[i]];
                result[ath] = "Silver Medal";
            } else if(i == 2) {
                int ath = mp[score[i]];
                result[ath] = "Bronze Medal";
            } else {
                int ath = mp[score[i]];
                result[ath] = to_string(i+1);
            }
            
        }
        
        return result;
        
    }
};


//Approach-2 (Using max heap)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> result(n);
        
        priority_queue<pair<int, int>> pq; //max-heap
        
        for(int i = 0; i < n; i++) {
            pq.push({score[i], i});
        }
        
        
        int rank = 1;
        
        while(!pq.empty()) {
            int idx = pq.top().second;
            pq.pop();
            
            if(rank == 1) {
                result[idx] = "Gold Medal";
            } else if(rank == 2) {
                result[idx] = "Silver Medal";
            } else if(rank == 3) {
                result[idx] = "Bronze Medal";
            } else {
                result[idx] = to_string(rank);
            }
            
            rank++;
        }
        
        return result;
        
        
    }
};


//Approach-3 (Using max heap)
//T.C : O(n)
//S.C : O(max_score)
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> result(n);
        
        int M = *max_element(begin(score), end(score));
        
        vector<int> mp(M+1, -1);
        
        for(int i = 0; i < n; i++) {
            mp[score[i]] = i;
        }
        
        
        int rank = 1;
        
        for(int s = M; s >= 0; s--) {
            
            if(mp[s] != -1) {
                int athlete = mp[s];
                
                if(rank == 1) {
                    result[athlete] = "Gold Medal";
                } else if(rank == 2) {
                    result[athlete] = "Silver Medal";
                } else if(rank == 3) {
                    result[athlete] = "Bronze Medal";
                } else {
                    result[athlete] = to_string(rank);
                }
                
                rank++;
            }
            
        }
        
        return result;
        
        
    }
};


/******************************************************************* JAVA ***************************************************************************/
//Approach-1 (Using map and sorting or vector of pair and sorting)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
    public String[] findRelativeRanks(int[] score) {
        int n = score.length;
        
        String[] result = new String[n];
        
        HashMap<Integer, Integer> mp = new HashMap<>();
        
        for (int i = 0; i < n; i++) {
            mp.put(score[i], i); // ith athlete
        }
        
        Arrays.sort(score); // ascending
        
        for (int i = n - 1; i >= 0; i--) {
            int ath = mp.get(score[i]);
            if (i == n - 1) {
                result[ath] = "Gold Medal";
            } else if (i == n - 2) {
                result[ath] = "Silver Medal";
            } else if (i == n - 3) {
                result[ath] = "Bronze Medal";
            } else {
                result[ath] = String.valueOf(n - i);
            }
        }
        
        return result;
    }
}

//Approach-2 (Using max heap)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
    public String[] findRelativeRanks(int[] score) {
        int n = score.length;
        String[] result = new String[n];
        
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[0] - a[0]); // max-heap
        
        for (int i = 0; i < n; i++) {
            pq.offer(new int[]{score[i], i});
        }
        
        int rank = 1;
        
        while (!pq.isEmpty()) {
            int[] athlete = pq.poll();
            int idx = athlete[1];
            
            if (rank == 1) {
                result[idx] = "Gold Medal";
            } else if (rank == 2) {
                result[idx] = "Silver Medal";
            } else if (rank == 3) {
                result[idx] = "Bronze Medal";
            } else {
                result[idx] = String.valueOf(rank);
            }
            
            rank++;
        }
        
        return result;
    }
}

//Approach-3 (Using max heap)
//T.C : O(n)
//S.C : O(max_score)
class Solution {
    public String[] findRelativeRanks(int[] score) {
        int n = score.length;
        String[] result = new String[n];
        
        int M = Arrays.stream(score).max().getAsInt();
        
        int[] mp = new int[M + 1];
        Arrays.fill(mp, -1);
        
        for (int i = 0; i < n; i++) {
            mp[score[i]] = i;
        }
        
        int rank = 1;
        
        for (int s = M; s >= 0; s--) {
            if (mp[s] != -1) {
                int athlete = mp[s];
                if (rank == 1) {
                    result[athlete] = "Gold Medal";
                } else if (rank == 2) {
                    result[athlete] = "Silver Medal";
                } else if (rank == 3) {
                    result[athlete] = "Bronze Medal";
                } else {
                    result[athlete] = String.valueOf(rank);
                }
                rank++;
            }
        }
        
        return result;
    }
}
