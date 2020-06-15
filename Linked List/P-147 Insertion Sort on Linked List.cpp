/*
    Sort a linked list using insertion sort.
    Example 1:

    Input: 4->2->1->3
    Output: 1->2->3->4
*/

ListNode *insertionSortList(ListNode *head)
{
    // if list is empty or has only one node
    if (head == NULL || head->next == NULL)
        return head;
    // make an empty list
    ListNode *newList = NULL;

    ListNode *current = head;

    while (current != NULL)
    {

        // store current's next in a variable
        ListNode *nextt = current->next;

        // insert current in correct position is new list.
        if (newList == NULL || newList->val >= current->val)
        {
            ListNode *temp = newList;
            newList = current;
            newList->next = temp;
        }
        else
        {
            ListNode *temp = newList;
            while (temp && temp->next && temp->next->val <= current->val)
            {
                temp = temp->next;
            }
            ListNode *t = temp->next;
            temp->next = current;
            temp->next->next = t;
        }
        // go the the next node
        current = nextt;
    }
    return newList;
}