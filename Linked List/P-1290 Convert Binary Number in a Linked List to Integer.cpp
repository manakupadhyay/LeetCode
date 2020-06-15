/*
Given head which is a reference node to a singly-linked list. The value of each node in the linked 
list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.
Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10
*/

int getDecimalValue(ListNode *head)
{
    ListNode *temp = head;
    int len = 0;
    while (temp)
    {
        temp = temp->next;
        len++;
    }
    int i = len - 1;
    temp = head;
    long long ans = 0;
    while (temp)
    {
        ans += (temp->val * pow(2, i));
        temp = temp->next;
        i--;
    }
    return ans;
}