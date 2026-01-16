/*    Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
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
        sort(begin(hFences), end(hFences));
        sort(begin(vFences), end(vFences));

        unordered_set<int> horDiff;
        unordered_set<int> verDiff;
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        for(int i = 0; i < hFences.size(); i++) {
            for(int j = i+1; j < hFences.size(); j++) {
                int diff = abs(hFences[i] - hFences[j]);
                horDiff.insert(diff);
            }
        }

        int side = 0;
        for(int i = 0; i < vFences.size(); i++) {
            for(int j = i+1; j < vFences.size(); j++) {
                int diff = abs(vFences[i] - vFences[j]);

                if(horDiff.find(diff) != horDiff.end()) {
                    side = max(side, diff);
                }
            }
        }

        return side == 0 ? -1 : (1LL * side*side) % M;
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

        Arrays.sort(hFences);
        Arrays.sort(vFences);

        List<Integer> hList = new ArrayList<>();
        List<Integer> vList = new ArrayList<>();

        for (int x : hFences) hList.add(x);
        for (int x : vFences) vList.add(x);

        // add boundaries
        hList.add(1);
        hList.add(m);
        vList.add(1);
        vList.add(n);

        Set<Integer> horDiff = new HashSet<>();

        // all horizontal differences
        for (int i = 0; i < hList.size(); i++) {
            for (int j = i + 1; j < hList.size(); j++) {
                horDiff.add(Math.abs(hList.get(i) - hList.get(j)));
            }
        }

        int side = 0;

        // match vertical differences
        for (int i = 0; i < vList.size(); i++) {
            for (int j = i + 1; j < vList.size(); j++) {
                int diff = Math.abs(vList.get(i) - vList.get(j));
                if (horDiff.contains(diff)) {
                    side = Math.max(side, diff);
                }
            }
        }

        if (side == 0) return -1;

        long area = (long) side * side;
        return (int) (area % M);
    }
}
