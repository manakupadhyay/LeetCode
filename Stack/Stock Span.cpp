#include <iostream>
#include <stack>
using namespace std;
void calculate(int arr[], int size)
{
    stack<int> stk;
    int span = 1;
    cout << span << " ";
    stk.push(0);
    for (int i = 1; i < size; i++)
    {
        while (!stk.empty() && arr[stk.top()] <= arr[i])
            stk.pop();
        if (stk.empty())
            span = i + 1;
        else
            span = i - stk.top();
        cout << span << " ";
        stk.push(i);
    }
    cout << endl;
}
int main()
{
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    calculate(arr, size);
    return 0;
}