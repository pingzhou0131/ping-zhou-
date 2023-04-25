/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=nullptr;ListNode* tail=nullptr;
        int next=0,sum,n1,n2;
        while(l1||l2){
            n1=l1?l1->val:0;
            n2=l2?l2->val:0;
            sum=n1+n2+next;
            if(!head){
                head=tail=new ListNode(sum%10);
                next=sum/10;
            }else{
                tail->next=new ListNode(sum%10);
                tail=tail->next;
                next=sum/10;
            }
            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
        }
        if(next)tail->next=new ListNode(next);
        return head;
    }
};
