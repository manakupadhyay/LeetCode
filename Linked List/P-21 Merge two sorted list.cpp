/*
Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode* head = new ListNode(-1);
        ListNode* answer = head;
         int a=INT_MAX,b=INT_MAX;
        while(l1 || l2){
            if(l1)
                a = l1->val;
            if(l2)
                b = l2->val;
            if(a<=b){
                head->next= new ListNode(a);
                l1=l1->next;
                a=INT_MAX;b=INT_MAX;
            }else{
                head->next= new ListNode(b);
                l2=l2->next;
                a=INT_MAX;b=INT_MAX;
            }
            head=head->next;
        }
        return answer->next;

    }