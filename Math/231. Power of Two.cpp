/* Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.

Example 1:
Input: n = 1
Output: true
Explanation: 20 = 1

Example 2:
Input: n = 16
Output: true
Explanation: 24 = 16 */

class Solution {
public:
    bool isPowerOfTwo(int n) {
        while(n){
            int temp = n & 1;
            if(temp == 1){
                n = n >> 1;
                if(n==0)
                    return 1;
                else 
                    return 0;
            }
            n = n >> 1;
        }
        return 0;
    }
};


// TIME COMPLEXITY : O(1)

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && ((n & (n-1)) == 0) ;
    }
};