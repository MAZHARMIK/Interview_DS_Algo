/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=4Tixc5mU-Pk
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies
*/


/************************************************************ C++ ************************************************************/
//Approach-1 - Brute Force
//T.C : (n^2 * m)
//S.C : O(n+S)
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        vector<string> result;

        unordered_set<string> st(begin(supplies), end(supplies));

        vector<bool> cooked(n, false);

        int count = n;
        while(count--) {

            for(int j = 0; j < n; j++) {
                if(cooked[j]) {
                    continue;
                }

                bool banpaega = true;
                for(int k = 0; k < ingredients[j].size(); k++) {
                    if(!st.count(ingredients[j][k])) {
                        banpaega = false;
                        break;
                    }
                }

                if(banpaega) {
                    st.insert(recipes[j]);
                    result.push_back(recipes[j]);
                    cooked[j] = true;
                }
            }
        }
        return result;
    }
};


//Approach-2 - Using Topological Sorting
//T.C : (n + m + S)
//S.C : O(n+S)
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        unordered_set<string> st(begin(supplies), end(supplies));

        //adj
        unordered_map<string, vector<int>> adj; //ing ---> recipe


        vector<int> indegree(n, 0);
        for(int i = 0; i < n; i++) {
            for(string& ing : ingredients[i]) {
                if(!st.count(ing)) {
                    adj[ing].push_back(i);
                    indegree[i]++;
                }
            }
        }

        queue<int> que;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                que.push(i);
            }
        }

        vector<string> result;
        while(!que.empty()) {
            int i = que.front();
            que.pop();
            string recipe = recipes[i];
            result.push_back(recipe);

            for(int &idx : adj[recipe]) {
                indegree[idx]--;
                if(indegree[idx] == 0) {
                    que.push(idx);
                }
            }
        }

        return result;
    }
};



/************************************************************ Java ************************************************************/
// Approach-1 - Brute Force
// T.C : (n^2 * m)
// S.C : O(n+S)
import java.util.*;

class Solution {
    public List<String> findAllRecipes(String[] recipes, List<List<String>> ingredients, String[] supplies) {
        int n = recipes.length;
        List<String> result = new ArrayList<>();
        Set<String> st = new HashSet<>(Arrays.asList(supplies));
        boolean[] cooked = new boolean[n];
        int count = n;
        
        while (count-- > 0) {
            for (int j = 0; j < n; j++) {
                if (cooked[j]) {
                    continue;
                }
                
                boolean canMake = true;
                for (String ing : ingredients.get(j)) {
                    if (!st.contains(ing)) {
                        canMake = false;
                        break;
                    }
                }
                
                if (canMake) {
                    st.add(recipes[j]);
                    result.add(recipes[j]);
                    cooked[j] = true;
                }
            }
        }
        
        return result;
    }
}

// Approach-2 - Using Topological Sorting
// T.C : (n + m + S)
// S.C : O(n+S)
import java.util.*;

class Solution {
    public List<String> findAllRecipes(String[] recipes, List<List<String>> ingredients, String[] supplies) {
        int n = recipes.length;
        Set<String> st = new HashSet<>(Arrays.asList(supplies));
        
        // adj
        Map<String, List<Integer>> adj = new HashMap<>(); // ing ---> recipe
        int[] indegree = new int[n];
        
        for (int i = 0; i < n; i++) {
            for (String ing : ingredients.get(i)) {
                if (!st.contains(ing)) {
                    adj.putIfAbsent(ing, new ArrayList<>());
                    adj.get(ing).add(i);
                    indegree[i]++;
                }
            }
        }
        
        Queue<Integer> que = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                que.add(i);
            }
        }
        
        List<String> result = new ArrayList<>();
        while (!que.isEmpty()) {
            int i = que.poll();
            String recipe = recipes[i];
            result.add(recipe);
            
            if (adj.containsKey(recipe)) {
                for (int idx : adj.get(recipe)) {
                    indegree[idx]--;
                    if (indegree[idx] == 0) {
                        que.add(idx);
                    }
                }
            }
        }
        
        return result;
    }
}
