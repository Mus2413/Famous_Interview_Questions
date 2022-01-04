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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* st=head,*t1=NULL,*t2=NULL;
        int size=0;
        while(st!=NULL)
        {
            size++;
            st=st->next;
        }
        if(size<k)
            return head;
        st=head;
        int count=0;
        while(st!=NULL && count<k)
        {
            t2=st->next;
            st->next=t1;
            t1=st;
            st=t2;
            count++;
        }
        if(st!=NULL)
        {
            head->next=reverseKGroup(t2,k);
        }
        return t1;
        
    }
};