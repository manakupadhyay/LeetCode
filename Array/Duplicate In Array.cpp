/* Problem Statement
You are given an array ‘ARR’ of size ‘N’ containing each number between 1 
and ‘N’ - 1 at least once. There is a single integer value that is present in the array 
twice. Your task is to find the duplicate integer value present in the array. 

Sample Input 1:

5
4 2 1 3 1
Sample Output :
1

7
6 3 1 5 4 3 2
Sample Output :
3
*/

#include <iostream>
using namespace std;
int main() {
    int arr[7] = {6, 3, 1, 5 ,4 ,3, 2};
    int size = 7;
    int sum = ((size-1) * ((size-1)+1))/2;
    int sumarr = 0;
    for(int i=0;i<7;i++){
		sumarr += arr[i];
    }
    cout <<  sumarr-sum << endl;
    return 0;
}