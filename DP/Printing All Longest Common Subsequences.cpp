class Solution
{
	public:
        int lcs(string& s1, string& s2, int& m, int& n, vector< vector<int> >& t) {
            for(int i = 0; i<m+1; i++) {
                for(int j = 0; j<n+1; j++) {
                    if(i == 0 || j == 0)
                        t[i][j] = 0;
                    else if(s1[i-1] == s2[j-1])
                        t[i][j] = 1 + t[i-1][j-1];
                    else
                        t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
            return t[m][n];
        }

        unordered_set<string> findLCS(string& s1, string& s2, int i, int j, vector< vector<int> >& t) {
            unordered_set<string> st;

            if(i == 0 || j == 0) {
                st.insert("");
                return st;
            }

            if(s1[i-1] == s2[j-1]) {
                unordered_set<string> temp = findLCS(s1, s2, i-1, j-1, t);
                for(string s : temp) {
                    st.insert(s + s1[i-1]);
                }
            } else {
                unordered_set<string> temp;

                if(t[i-1][j] >= t[i][j-1]) {
                    temp = findLCS(s1, s2, i-1, j, t);
                    st.insert(begin(temp), end(temp));
                }

                if(t[i-1][j] <= t[i][j-1]) {
                    temp = findLCS(s1, s2, i, j-1, t);
                    st.insert(begin(temp), end(temp));
                }
            }

            return st;
        }
	vector<string> all_longest_common_subsequences(string s1, string s2) {
	    int m     = s1.length();
	    int n     = s2.length();
	    vector< vector<int> > t(m+1, vector<int>(n+1));
	    lcs(s1, s2, m, n, t);

	    set<string> st = findLCS(s1, s2, m, n, t);
	    vector<string> result(begin(st), end(st));

	    return result;
	}
};
