 #include <bits/stdc++.h>
    using namespace std;

    class ListNode
    {
        public:
            int val;
            ListNode* next;
            ListNode* random;
        
        ListNode(int value)
        {
            this->val=value;
            this->next=NULL;
        }   
    };
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
    int getlen(ListNode* head)
    {
        int len=0;
        ListNode* temp=head;
        while(temp->next!=NULL)
        {
            len++;
            temp=temp->next;
        }
        return len;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* first=head;
        ListNode* second=head;

        int l=getlen(head);
        int m=l-k+2;
        int c=1;
        int y=1;

        while(first!=NULL && c!=k)
        {
            first=first->next;
            c++;
        }
        while(second!=NULL && y!=m)
        {
            second=second->next;
            y++;
        }

        swap(first->val,second->val);
        return head;
    }
};