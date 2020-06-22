/*
    SORT A STACK USING ANOTHER STACK
    ALGO:    
    1.Create a temporary stack say tmpStack.
    2.While input stack is NOT empty do this:
        -Pop an element from input stack call it temp
        -while temporary stack is NOT empty and top of temporary stack is greater than temp,
        pop from temporary stack and push it to the input stack
        -push temp in temporary stack
    3.The sorted numbers are in tmpStack

*/

#include <iostream>
#include <stack>
using namespace std;
void printstack(stack<int> s)
{
    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
int main()
{
    stack<int> stk;
    int i=1;
    while(i!=-1)
    {
        cin >> i;
        stk.push(i);
        cin >> i;
    }
    printstack(stk);
    stack<int> s2;
    while(!stk.empty())
    {
        int temp = stk.top();
        stk.pop();
        if(s2.empty())
            s2.push(temp);
        else
        {
            while(!s2.empty() && s2.top() > temp)
            {
                stk.push(s2.top());
                s2.pop();
            }
            s2.push(temp);
        }
        
    }
    printstack(s2);
    return 0;
}