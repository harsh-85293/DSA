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
        int val;
        ListNode* next;

        // constructor
        ListNode(int value) 
        {
            this->val = value;
            this->next = NULL;
        }
    };
    class Solution 
    {
    public:
        ListNode* deleteDuplicates(ListNode* head) 
        {
            //1 case ->ll is empty or single node present
            if(head==NULL || head->next==NULL)
            {
                return head;
            }
            //2 case ->minimum 2 node
            ListNode* prev=head;
            ListNode* temp=head->next;

            while(temp!=NULL)
            {
                if((prev->val)==(temp->val))
                {
                    prev->next=temp->next;
                    temp->next=NULL;
                    delete temp;
                    temp=prev->next;//important point
                }
                else
                {
                    prev=temp;
                    temp=temp->next;
                }
            }
            return head;
        }
    };

    int main()
    {
        return 0;
    } 