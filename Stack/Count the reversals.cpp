#include<iostream>
#include<stack>
using namespace std;
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        string s;
        cin >> s;
        stack<char> stk;
        int len = s.size();
        if(len % 2)
        {
            cout << -1 << endl;
            continue;
        }
        for(int i=0;i<len;i++)
        {
            if(s[i]=='{')
                stk.push(s[i]);
            else
            {
                if(!stk.empty() && stk.top() == '{')
                    stk.pop();
                else
                    stk.push(s[i]);
            }
        }
        int unbalanced = stk.size();
        int n = 0;
        while(!stk.empty() && stk.top() == '{')
        {
            stk.pop();
            n++;
        }
        cout << unbalanced/2 + n%2;
    }
    return 0;
}