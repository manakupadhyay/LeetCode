
/*
    Write a program to generate binary numbers upto k.
*/

#include <iostream>
#include <queue>
using namespace std;
int main() 
{
    int num;
    cin >> num;
    queue<string> q;
    q.push("1");
    while(num--)
    {
        string s = q.front();
        cout << s << " ";
        q.push(s+"0");
        q.push(s+"1");
        q.pop();
    }
    cout << endl;
    return 0;
}