/*
Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
*/

 ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head==NULL || head->next==NULL || n==m)
            return head;
        ListNode* temp = head;
        ListNode* p = new ListNode(-1);
        ListNode* newHead = p;
        p->next = head;
        for(int i = 1; i<m;i++){
            p = p->next;
            temp = temp->next;
        }
        int count = n-m;
        while(temp && count){
            ListNode* nextt = temp->next->next;
            temp->next->next = p->next;
            p->next = temp->next;
            temp->next=nextt;
            count--;
        }
        return newHead->next;
    }