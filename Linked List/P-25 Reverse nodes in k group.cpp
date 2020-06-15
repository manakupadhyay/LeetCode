/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
k is a positive integer and is less than or equal to the length of the linked list. If the number 
of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:
Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5

*/

ListNode* reverseKGroup(ListNode* head, int k) {
       if(head==NULL)
            return head;
        int len=0;
        ListNode* curr = head;
        while(curr){
            curr=curr->next;
            len++;
            if(len>=k)
                break;
        }
        if(len<k)
            return head;
        curr=head;
        ListNode* forward;
        ListNode* prev = NULL;
        int count = k;
        while( count && curr!=NULL){
            forward = curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            count--;
        }
        if(head!=NULL)
            head->next=reverseKGroup(forward,k);
        return prev;
}