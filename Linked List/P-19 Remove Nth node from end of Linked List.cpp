/*
Given a linked list, remove the n-th node from the end of list and return its
head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
*/

/* Naive Approach */
/*
 ListNode* removeNthFromEnd(ListNode* head, int n) {
    int length = 0;
    ListNode *temp = head;
    while(temp){
        length++;
        temp = temp->next;
    }
    int k = length - n;
    temp = head;
    if(k == 0){
        ListNode* temp2 = head;
        head= head->next;
        delete temp2;
        return head;
    }
    for(int i = 1;i<k;i++){
        temp = temp->next;
    }
    ListNode *nodeToRemove = temp->next;
    ListNode *nextNode = nodeToRemove->next;
    temp->next = nextNode;
    delete nodeToRemove;
    return head;

    }
*/

/* My Code */
ListNode *removeNthFromEnd(ListNode *head, int n) {
  ListNode *fast = head;
  ListNode *slow = head;
  for (int i = 0; i < n; i++)
    fast = fast->next;
  if (fast == NULL) {
    if (slow->next == NULL) {
      head = NULL;
      return head;
    } else {
      head = head->next;
      return head;
    }
  }
  while (fast->next != NULL) {
    fast = fast->next;
    slow = slow->next;
  }
  slow->next = slow->next->next;
  return head;
}

/* Two pointer */
ListNode *removeNthFromEnd(ListNode *head, int n) {
  ListNode *slow = head;
  ListNode *fast = head;
  for (int i = 0; i < n; i++) {
    fast = fast->next;
  }
  if (!fast) {
    return head->next;
  }
  while (fast->next) {
    slow = slow->next;
    fast = fast->next;
  }
  slow->next = slow->next->next;
  return head;
}