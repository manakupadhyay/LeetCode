/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
*/

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.empty())
        return NULL;
    else
    {
        while (lists.size() > 1)
        {
            lists.push_back(merge(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
    }
    return lists.front();
}
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