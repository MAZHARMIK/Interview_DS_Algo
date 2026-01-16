/*    Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=7H_tzns_G3M
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/maximum-square-area-by-removing-fences-from-a-field
*/


/*************************************************************************** C++ ******************************************************************************************/
//Approach (using hashset to store possible sides)
//T.C : O(h^2 + v^2 + hlogh + vlogv), h = hFences.size(), v = vFences.size()
//S.C : O(h+v)
class Solution {
public:
    int M = 1e9+7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);

        vFences.push_back(1);
        vFences.push_back(n);

        sort(begin(hFences), end(hFences)); 
        sort(begin(vFences), end(vFences));

        unordered_set<int> widths;
        unordered_set<int> heights;

        for(int i = 0; i < vFences.size(); i++) {
            for(int j = i+1; j < vFences.size(); j++) {
                int width = vFences[j] - vFences[i];
                widths.insert(width);
            }
        }

        int maxSide = 0;

        for(int i = 0; i < hFences.size(); i++) {
            for(int j = i+1; j < hFences.size(); j++) {
                int height = hFences[j] - hFences[i];
                if(widths.find(height) != widths.end()) { //found a square
                    maxSide = max(maxSide, height);
                }
            }
        }

        return maxSide == 0 ? -1 : (1LL * maxSide * maxSide) % M;

        
    }
};


/*************************************************************************** JAVA ******************************************************************************************/
//Approach (using hashset to store possible sides)
//T.C : O(h^2 + v^2 + hlogh + vlogv), h = hFences.size(), v = vFences.size()
//S.C : O(h+v)
import java.util.*;

class Solution {
    private static final int M = 1_000_000_007;

    public int maximizeSquareArea(int m, int n, int[] hFences, int[] vFences) {

        List<Integer> hList = new ArrayList<>();
        List<Integer> vList = new ArrayList<>();

        for (int x : hFences) hList.add(x);
        for (int x : vFences) vList.add(x);

        // add boundaries
        hList.add(1);
        hList.add(m);
        vList.add(1);
        vList.add(n);

        Collections.sort(hList);
        Collections.sort(vList);

        Set<Integer> widths = new HashSet<>();

        // all vertical widths
        for (int i = 0; i < vList.size(); i++) {
            for (int j = i + 1; j < vList.size(); j++) {
                widths.add(vList.get(j) - vList.get(i));
            }
        }

        int maxSide = 0;

        // check horizontal heights
        for (int i = 0; i < hList.size(); i++) {
            for (int j = i + 1; j < hList.size(); j++) {
                int height = hList.get(j) - hList.get(i);
                if (widths.contains(height)) {
                    maxSide = Math.max(maxSide, height);
                }
            }
        }

        if (maxSide == 0) 
            return -1;

        long area = (long) maxSide * maxSide;
        return (int) (area % M);
    }
}
