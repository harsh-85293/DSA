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
#include <bits/stdc++.h>
    using namespace std;

    class ListNode
    {
        public:
            int data;
            ListNode* next;
        
        //constructor
        ListNode(int value)
        {
            this->data=value;
            this->next=NULL;
        }
    };
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans={-1,-1};//store min distance and maximum distance
        ListNode* prev=head;
        if(prev==NULL)
        {
            return ans;
        }
        ListNode* curr=head->next;
        if(curr==NULL)
        {
            return ans;
        }
        ListNode* nxt=head->next->next;
        if(nxt==NULL)
        {
            return ans;
        }
        int firstcp=-1;
        int lastcp=-1;
        int mindistance=INT_MAX;
        int i=1;
        while(nxt!=NULL)
        {
    bool iscp= ( (curr->val > prev->val) && (curr->val > nxt->val) )|| ( (curr->val < prev->val) && (curr->val < nxt->val) )?true:false;
            if(iscp && firstcp==-1)
            {
                firstcp=i;
                lastcp=i;
            }
            else if(iscp)
            {
                mindistance=min(mindistance,i-lastcp);
                lastcp=i;
            }
            i++;
            prev=prev->next;
            curr=curr->next;
            nxt=nxt->next;
        }
        if(lastcp==firstcp)
        {
            return ans;
        }
        else
        {
            ans[0]=mindistance;
            ans[1]=lastcp-firstcp;
        }
        return ans;
    }
};