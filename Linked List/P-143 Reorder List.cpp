/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.
*/

 void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return;
        ListNode* temp = head;
        stack<ListNode*> s;
        while(temp){
            s.push(temp);
            temp=temp->next;
        }
        temp=head;
        bool flag=false;
        while(temp!=s.top()){
            ListNode* f = temp->next;
            temp->next=s.top();
            s.pop();
            temp->next->next=f;
            if(temp->next==f){
                ListNode* af = temp->next;
                af->next=NULL;
                flag=true;
                break;
            }
            temp=f;
        }
        if(!flag)
        temp->next=NULL;
         
    }