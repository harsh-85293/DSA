#include <bits/stdc++.h>
    using namespace std;
    /**
     * Definition for singly-linked list.
     * struct ListNode {
     *     int val;
     *     ListNode *next;
     *     ListNode(int x) : val(x), next(NULL) {}
     * };
     */
    class ListNode 
    {
    public:
        int data;
        ListNode* next;

        // constructor
        ListNode(int value) 
        {
            this->data = value;
            this->next = NULL;
        }
    };
    class Solution {
    public:
        ListNode *detectCycle(ListNode *head) 
        {
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* temp=nullptr;
        while(fast!=NULL)
        {
                fast=fast->next;
                if(fast!=NULL)
                {
                    slow=slow->next;
                    fast=fast->next;
                    if(slow==fast)
                    {
                        temp=slow;
                        break;
                    }   
                }
        }
        ListNode* finalans=nullptr;
        slow=head;
        while(slow!=NULL && temp!=NULL)
        {
                if(temp==slow)
                {
                    finalans=temp;
                    break;
                }
                slow=slow->next;
                temp=temp->next;
        }
        return finalans;
        }
    };

    int main()
    {
        return 0;
    } 