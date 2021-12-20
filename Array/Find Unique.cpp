/* 
You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1].
Now, in the given array/list, 'M' numbers are present twice and one number is 
present only once. You need to find and return that number which is 
unique in the array/list. 

Sample Input 1:
1
7
2 3 1 6 3 6 2
ANS: 1
*/

int findUnique(int *arr, int size)
{
    int ans = 0;
    for(int i=0;i<size;i++) {
		ans = ans ^ arr[i];
    }
    return ans;
}

/* 
APPROACH: XOR
Since the repated elements are present twice, so we can loop through the array and apply XOR.
This will cancel out all the repeated elements and we will get the unique element.
*/