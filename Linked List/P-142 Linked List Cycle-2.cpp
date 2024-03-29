/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

To represent a cycle in the given linked list, we use an integer pos which represents the
 position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no 
 cycle in the linked list.

Note: Do not modify the linked list.

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
*/

ListNode *detectCycle(ListNode *head)
{
    if (head == NULL)
        return head;
    ListNode *fast = head;
    ListNode *slow = head;
    ListNode *entry = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            while (slow != entry)
            {
                slow = slow->next;
                entry = entry->next;
            }
            return entry;
        }
    }
    return NULL;
}