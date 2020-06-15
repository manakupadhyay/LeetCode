/*
Sort a linked list in O(n log n) time.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
*/

ListNode *merge(ListNode *a, ListNode *b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;
    if (a->val <= b->val)
    {
        a->next = merge(a->next, b);
        return a;
    }
    else
    {
        b->next = merge(a, b->next);
        return b;
    }
}
ListNode *sortList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = slow->next;
    slow->next = NULL;
    ListNode *l1 = sortList(head);
    ListNode *l2 = sortList(fast);
    return merge(l1, l2);
}