#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        ll size;
        cin >> size;
        ll arr[size], ans[size];
        for (int i = 0; i < size; i++)
            cin >> arr[i];
        stack<ll> s;
        for (ll i = size - 1; i >= 0; i--)
        {
            while (!s.empty() && s.top() <= arr[i])
                s.pop();
            if (s.empty())
                ans[i] = -1;
            else
                ans[i] = s.top();
            s.push(arr[i]);
        }
        for (ll i = 0; i < size; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}