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
    class Solution 
    {
    public:
        bool hasCycle(ListNode *head) 
        {
            ListNode* slow=head;
            ListNode* fast=head;
            ListNode* temp=head;

            while(fast!=NULL)
            {
                fast=fast->next;
                if(fast!=NULL)
                {
                    slow=slow->next;
                    fast=fast->next;
                }
                if(slow==fast)
                {
                    return true;
                }
            }
            return false;
        }
    };
    int main()
    {
        return 0;
    } 