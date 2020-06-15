/*
Write a function to delete a node (except the tail) in a singly linked list, given only access to 
that node.
*/

void deleteNode(ListNode *node)
{
    ListNode *nextt = node->next;
    node->val = nextt->val;
    node->next = nextt->next;
    delete nextt;
}