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
        ll row,col,max=0,ans;
        cin >> row >> col;
        ll matrix[row][col];
        for (ll i = 0; i < row; i++)
            for(ll j=0;j<col;j++)
                cin >> matrix[i][j];
        ll arr[col] = {0};
       for(ll i =0;i<row;i++)
       {
           for(ll j=0;j<col;j++)
            {
                if(matrix[i][j]==0)
                    arr[j]=0;
                else
                    arr[j]+=(matrix[i][j]);
            }
            ans = calculate(arr,col);
            if(ans>max)
                max=ans;
       }
        cout << max << endl;
    }
    return 0;
}