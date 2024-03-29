/*
You are given two non-empty linked lists representing two non-negative integers. The digits are 
stored in reverse order and each of their nodes contain a single digit. Add the two numbers and 
return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *head = new ListNode(0);
    ListNode *answer = head;
    int sum = 0;
    while (l1 || l2)
    {
        sum = sum / 10;
        if (l1)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2)
        {
            sum += l2->val;
            l2 = l2->next;
        }
        answer->next = new ListNode(sum % 10);
        answer = answer->next;
    }
    if (sum / 10 != 0)
        answer->next = new ListNode(sum / 10);
    return head->next;
}