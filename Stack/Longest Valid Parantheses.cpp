#include <iostream>
#include <bits/stdc++.h>
#include <stack>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int result = 0;
    stack<int> stk;
    stk.push(-1);
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            stk.push(i);
        else
        {
            stk.pop();
            if (!stk.empty())
                result = max(result, i - stk.top());
            else
                stk.push(i);
        }
    }
    cout << result << endl;
    return 0;
}