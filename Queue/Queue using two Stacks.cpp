#include <iostream>
#include <stack>
using namespace std;
stack<int> s1,s2;
void push(int ele)
{
    s1.push(ele);
}
int pop()
{
    if(s1.empty())
        return -1;
    while(s1.size() != 1)
    {
        s2.push(s1.top());
        s1.pop();
    }
    int front = s1.top();
    s1.pop();
    while(!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
    return front;
}
int main() 
{
    int choice = 1;
    int option;
    while(choice!=0)
    {
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cin >> option;
        switch(option)
        {
            case 1: cout << "Enter element: ";
            cin >> option;
            push(option);
            break;
            case 2: option = pop();
            if(option==-1)
                cout << "Queue is Empty" << endl;
            else
                cout << option << endl;
            break;

        }
        cout << "Enter 1 for again 0 for exit: ";
        cin >> choice;
    }
    return 0;
}