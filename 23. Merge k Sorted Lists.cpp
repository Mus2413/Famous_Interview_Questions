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
    ListNode* merge(ListNode* a,ListNode* b)
    {
        if(a==NULL && b==NULL)
            return NULL;
        if(a==NULL)
            return b;
        if(b==NULL)
            return a;
        if(a->val<=b->val)
        {
            a->next=merge(a->next,b);
            return a;
        }
        else
        {
            b->next=merge(a,b->next);
            return b;
        }
        return NULL;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>>pq;
        for(int i=0;i<lists.size();i++)
        {
            ListNode* t=lists[i];
            int size=0;
            while(t!=NULL)
            {
                size++;
                t=t->next;
            }
            if(size>0)
            pq.push({size,lists[i]});
        }
        while(pq.size()>1)
        {
            int n=pq.top().first;
            ListNode* a=pq.top().second;
            pq.pop();
            int m=pq.top().first;
            ListNode* b=pq.top().second;
            pq.pop();
            ListNode* ans=merge(a,b);
            pq.push({n+m,ans});
        }
        if(pq.size()>0)
        return pq.top().second;
        else
            return NULL;
    }
};