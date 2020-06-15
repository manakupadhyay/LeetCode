/*
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
*/

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *fast = head;
    ListNode *slow = head;
    for (int i = 0; i < n; i++)
        fast = fast->next;
    if (fast == NULL)
    {
        if (slow->next == NULL)
        {
            head = NULL;
            return head;
        }
        else
        {
            head = head->next;
            return head;
        }
    }
    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return head;
}