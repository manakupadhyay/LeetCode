/*
You are given two non-empty linked lists representing two non-negative integers. The most 
significant digit comes first and each of their nodes contain a single digit. Add the two numbers 
and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
*/

 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         ListNode* temp1=l1;
        ListNode* temp2=l2;
        stack<ListNode*> s1,s2;
        stack<int> s3;
        ListNode* newList = new ListNode(0);
        ListNode* newListHead = newList;
        while(temp1){
            s1.push(temp1);
            temp1=temp1->next;
        }
        while(temp2){
            s2.push(temp2);
            temp2=temp2->next;
        }
        int sum = 0;
        while(!s1.empty() || !s2.empty()){
            sum = sum/10;
            if(!s1.empty()){
                sum += s1.top()->val;
                s1.pop();
            }
            if(!s2.empty()){
                sum += s2.top()->val;
                s2.pop();
            }
           s3.push(sum%10);
        }
        if(sum/10 != 0){
            s3.push(sum/10);
        }
        while(!s3.empty()){
            newList->next = new ListNode(s3.top());
            newList = newList->next;
            s3.pop();
        }
        return newListHead->next;
    }