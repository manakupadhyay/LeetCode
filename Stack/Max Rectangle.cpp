#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll calculate(ll arr[], ll size)
{
    stack<ll> s;
    ll i = 0;
    ll area = 0, maxArea = 0;
    while (i < size)
    {
        if (s.empty() || arr[s.top()] <= arr[i])
            s.push(i++);
        else
        {
            ll top = s.top();
            s.pop();
            if (s.empty())
                area = arr[top] * i;
            else
                area = arr[top] * (i - s.top() - 1);
            if (maxArea < area)
                maxArea = area;
        }
    }
    while (!s.empty())
    {
        ll top = s.top();
        s.pop();
        if (s.empty())
            area = arr[top] * i;
        else
            area = arr[top] * (i - s.top() - 1);
        if (maxArea < area)
            maxArea = area;
    }
    return maxArea;
}
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        ll size;
        cin >> size;
        ll arr[size];
        for (ll i = 0; i < size; i++)
            cin >> arr[i];
        ll max = calculate(arr, size);
        cout << max << endl;
    }
    return 0;
}