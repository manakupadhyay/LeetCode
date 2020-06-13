/*Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
*/

ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* prev=head;
        ListNode* curr = head->next;
        while(curr){
            if(prev->val == curr->val){
                prev->next = curr->next;
                curr=curr->next;
            }else{
                prev = prev->next;
                curr=curr->next;
            }
        }
        return head;
    }