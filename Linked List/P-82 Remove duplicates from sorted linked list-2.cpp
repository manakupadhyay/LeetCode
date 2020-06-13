/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct 
numbers from the original list.

Return the linked list sorted as well.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
*/

 if(head==NULL || head->next==NULL)
            return head;
        bool flag=true,loop=false;
        ListNode* newHead= NULL;
        ListNode* h = newHead;
        ListNode* prev=head;
        ListNode* curr=head->next;
        while(curr){
        if(prev->val==curr->val){
            while(curr && curr->val==prev->val ){
                curr=curr->next;
                prev=prev->next;
                flag=false;
            }
        }else{
            loop=true;
            if(flag){
                if(newHead==NULL){
                    newHead=prev;
                    h=newHead;   
                }
                else{
                    newHead->next=prev;
                    newHead = newHead->next;
                }
                    
            }
            curr=curr->next;
            prev=prev->next;
            flag=true;
        }
        }
        if(flag&&loop)
            if(newHead==NULL)
            {
                
            }
        else
            if(newHead)
            newHead->next=NULL;
        return h;