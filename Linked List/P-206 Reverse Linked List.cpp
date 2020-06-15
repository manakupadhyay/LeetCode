/*
Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
*/

ListNode *reverseList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *prev = NULL;
    while (head)
    {
        ListNode *nextt = head->next;
        head->next = prev;
        prev = head;
        head = nextt;
    }
    return prev;
}