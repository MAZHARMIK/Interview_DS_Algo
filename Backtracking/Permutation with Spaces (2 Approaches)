/*
    Company Tags : Amazon
    Qn Link      : https://practice.geeksforgeeks.org/problems/permutation-with-spaces/0
*/

//////////////APPROACH-1  :  (START)//////////////////
#include<bits/stdc++.h>
using namespace std;

void generate(string input, string output) {
    if(input.length() == 0) {
        cout << "(" + output + ")" ;
        return;
    }

    string op1 = output + input[0];
    string op2 = output + " " + input[0];
    generate(input.substr(1), op2);
    generate(input.substr(1), op1);

}

int main() {
	int T;
	cin >> T;
	while(T--) {
	    string s;
	    cin >> s;

	    string output = string(1, s[0]);
	    generate(s.substr(1), output);
	    cout << endl;
	}
	return 0;
}
//////////////APPROACH-1  :  (END)//////////////////


//////////////APPROACH-2  :  (START)//////////////////
#include <bits/stdc++.h>
using namespace std;

void generate(string curr,string s,int i,int n)
{
    curr.push_back(s[i]);
    if (i==n-1)
    {
        cout << "(" << curr << ")";
        return ;
    }
    curr.push_back(' ');
    generate(curr,s,i+1,n);
    curr.pop_back();
    generate(curr,s,i+1,n);
}

int main() {
	int T;
	cin>>T;
	string s;
	while(T--)
	{
	    cin>>s;
	    string curr;
	    generate(curr,s,0,s.size());
	    cout<<endl;
	}
	return 0;
}

//////////////APPROACH-2  :  (END)//////////////////
