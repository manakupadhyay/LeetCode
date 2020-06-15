/*Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
*/

ListNode *removeElements(ListNode *head, int val)
{
    if (head == NULL)
        return head;
    ListNode *newList = new ListNode(-1);
    ListNode *newHead = newList;
    while (head)
    {
        if (head->val != val)
        {
            newList->next = head;
            newList = newList->next;
        }
        head = head->next;
    }
    newList->next = NULL;
    return newHead->next;
}