#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of string: ";
    cin >> n;
    vector<long long> ans;
    int temp = 0;
    cout << "Enter the string: ";
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        ans.push_back(temp);
    }

    vector<long long> v;
    stack<long long> s;

    for (int i = 0; i < n; i++)
    {
        if (s.size() == 0)
        {
            v.push_back(-1);
        }
        else if (s.size() > 0 && s.top() < ans[i])
        {
            v.push_back(s.top());
        }
        else if (s.size() > 0 && s.top() >= ans[i])
        {
            while (s.size() > 0 && s.top() >= ans[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(s.top());
            }
        }
        s.push(ans[i]);
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
}