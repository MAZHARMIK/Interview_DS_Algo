/*     Scroll below to see JAVA code also    */
/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=3WN6qHE4K_E
      Company Tags                : will update later
      Leetcode Link               : https://leetcode.com/problems/count-mentions-per-user
*/


/********************************************************************** C++ ********************************************************/
//Approach - Simply sort and simulate
//T.C : O(E log E + E * N), N = number of users , E = number of events
//S.C : O(N + E)
class Solution {
public:
    void applyMessageEvent(vector<string>event, vector<int>&mentionCount, vector<int>&offlineTime){

        int timestamp = stoi(event[1]);

        vector<string> ids;

        stringstream ss(event[2]);

        string token;
        while(ss >> token){
            ids.push_back(token);
        }

        //Process all IDs
        for(string id : ids) {
            if(id == "ALL") {
                for(int i = 0; i<mentionCount.size(); i++) {
                    mentionCount[i]++;
                }
            } else if(id == "HERE") {
                for(int i = 0; i < mentionCount.size(); i++){
                    if(offlineTime[i] == 0 || offlineTime[i] + 60 <= timestamp){
                        mentionCount[i]++;
                    }
                }
            } else {
                mentionCount[stoi(id.substr(2))]++; //fetch id value i.e. x from idx (id0, id1 etc)
            }
        }

    }

    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int>mentionCount(numberOfUsers);
        vector<int>offlineTime(numberOfUsers);

        auto lambda=[](vector<string>& vec1, vector<string>& vec2) {
            int t1 = stoi(vec1[1]);
            int t2 = stoi(vec2[1]);

            if(t1 == t2) {
                return vec1[0][1] > vec2[0][1]; //comparing 'O' of "OFFLINE" with 'M' of "MESSAGE"
                //OFFLINE should come first
            }

            return t1 < t2;
        };

        sort(events.begin(), events.end(), lambda);

        for(vector<string>event: events){
            if(event[0] == "MESSAGE") {
                applyMessageEvent(event, mentionCount, offlineTime);
            }
            else if(event[0] == "OFFLINE") {
                int timestamp = stoi(event[1]);
                int id = stoi(event[2]);
                offlineTime[id] = timestamp;
            }
        }

        return mentionCount;
    }
};



/********************************************************************** JAVA ********************************************************/
//Approach - Simply sort and simulate
//T.C : O(E log E + E * N), N = number of users , E = number of events
//S.C : O(N + E)
class Solution {

    public int[] countMentions(int numberOfUsers, List<List<String>> events) {
        int[] mentionCount = new int[numberOfUsers];
        int[] offlineTime = new int[numberOfUsers];

        Collections.sort(events, (a, b) -> {

            int t1 = Integer.parseInt(a.get(1));
            int t2 = Integer.parseInt(b.get(1));

            if (t1 == t2) {
                char c1 = a.get(0).charAt(1);
                char c2 = b.get(0).charAt(1);

                if (c1 > c2) return -1;
                if (c1 < c2) return 1;
                return 0;
            }

            return Integer.compare(t1, t2);
        });

        for (List<String> event : events) {
            if (event.get(0).equals("MESSAGE")) {
                applyMessageEvent(event, mentionCount, offlineTime);

            } else if (event.get(0).equals("OFFLINE")) {
                int timestamp = Integer.parseInt(event.get(1));
                int id = Integer.parseInt(event.get(2));
                offlineTime[id] = timestamp;
            }
        }

        return mentionCount;
    }

    private void applyMessageEvent(List<String> event, int[] mentionCount, int[] offlineTime) {
        int timestamp = Integer.parseInt(event.get(1));
        String[] ids = event.get(2).split(" ");

        for (String id : ids) {

            if (id.equals("ALL")) {
                for (int i = 0; i < mentionCount.length; i++) {
                    mentionCount[i]++;
                }

            } else if (id.equals("HERE")) {
                for (int i = 0; i < mentionCount.length; i++) {
                    if (offlineTime[i] == 0 || offlineTime[i] + 60 <= timestamp) {
                        mentionCount[i]++;
                    }
                }

            } else {
                int userId = Integer.parseInt(id.substring(2));
                mentionCount[userId]++;
            }
        }
    }
}
