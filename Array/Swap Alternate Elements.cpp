/* WAP to swap alternate elements of an array  */

#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    for(int i=0;i<size;i++)
        cout << arr[i] <<  " ";
    cout << endl;
}
void swapAlternate(int arr[],int size) {
    for(int i=0;i<size-1;i+=2) {
        swap(arr[i],arr[i+1]);
    }
}
int main () {
    int even[8] = {2,6,11,3,10,6,7,10};
    int odd[7] = {2,6,11,3,10,6,7};
    
    swapAlternate(even, 8);
    swapAlternate(odd, 7);    
    printArray(even, 8);
    printArray(odd, 7);
}