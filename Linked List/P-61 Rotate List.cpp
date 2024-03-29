/*
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
*/

ListNode *rotateRight(ListNode *head, int k)
{
    if (k == 0 || head == NULL || head->next == NULL)
        return head;
    ListNode *tail = head;
    ListNode *newHead = NULL;
    int len = 1;
    while (tail->next)
    {
        tail = tail->next;
        len++;
    }
    tail->next = head;
    if (k = k % len)
    {
        for (int i = 1; i <= len - k; i++)
        {
            tail = tail->next;
        }
    }
    newHead = tail->next;
    tail->next = NULL;
    return newHead;
}