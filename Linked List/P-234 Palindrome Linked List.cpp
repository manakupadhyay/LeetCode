/*
Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
*/

bool isPalindrome(ListNode *head)
{
    ListNode *sHead;
    ListNode *slow = head;
    ListNode *fast = head;
    // get to the middle
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // reverse the second half of linked list
    ListNode *temp = slow;
    ListNode *prev = NULL;
    while (temp)
    {
        ListNode *nextt = temp->next;
        temp->next = prev;
        prev = temp;
        temp = nextt;
    }
    // sHead points to the head of reversed second half
    // slow points to the head of first linked list
    sHead = prev;
    slow = head;
    while (sHead)
    {
        if (sHead->val == slow->val)
        {
            sHead = sHead->next;
            slow = slow->next;
        }
        else
            return false;
    }
    return true;
}