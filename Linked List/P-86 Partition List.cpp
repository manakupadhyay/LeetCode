/*
Given a linked list and a value x, partition it such that all nodes less than x come before 
nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example:

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
*/

ListNode *partition(ListNode *head, int x)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *newHead = new ListNode(-1);
    ListNode *h = newHead;
    ListNode *list2 = new ListNode(-1);
    ListNode *hlist2 = list2;
    while (head)
    {
        if (head->val < x)
        {
            newHead->next = head;
            newHead = newHead->next;
        }
        else
        {
            list2->next = head;
            list2 = list2->next;
        }
        head = head->next;
    }
    list2->next = NULL;
    newHead->next = hlist2->next;
    return h->next;
}