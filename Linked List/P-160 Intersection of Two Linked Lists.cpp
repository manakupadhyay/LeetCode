ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *big = headA;
    ListNode *small = headB;
    int len1 = 1, len2 = 1;
    while (big)
    {
        big = big->next;
        len1++;
    }
    while (small)
    {
        small = small->next;
        len2++;
    }

    int diff;
    if (len1 > len2)
    {
        diff = len1 - len2;
        big = headA;
        small = headB;
    }
    else
    {
        diff = len2 - len1;
        big = headB;
        small = headA;
    }
    for (int i = 1; i <= diff; i++)
        big = big->next;
    while (big && small)
    {
        if (big == small)
            return small;
        big = big->next;
        small = small->next;
    }
    return NULL;