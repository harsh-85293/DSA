    #include <bits/stdc++.h>
    using namespace std;
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
        ListNode* getmiddle(ListNode* head, ListNode* &middlekaprev)
        {
            ListNode* slow=head;
            ListNode* fast=head;

            while(fast!=NULL)
            {
                fast=fast->next;
                if(fast!=NULL)
                {
                    fast=fast->next;
                    middlekaprev=slow;
                    slow=slow->next;
                }
            }
            return slow;
        }

        ListNode* reversell(ListNode* &prev, ListNode* &curr)
        {
            while(curr!=NULL)
            { 
                ListNode* forward=curr->next;
                curr->next=prev;
                prev=curr;
                curr=forward;
            }
            return prev;
        }
        
        bool isPalindrome(ListNode* head) 
        {
            if(head==NULL || head->next==NULL)
            {
                return true;
            }
            //3 parts
            //travel till middle node and break ll in 2 parts
            ListNode* firsthalfhead=head;
            ListNode* middlekaprev=NULL;
            ListNode* middle=getmiddle(head,middlekaprev);
            middlekaprev->next=NULL;

            //reverse the second half
            ListNode* prev=NULL;
            ListNode* curr=middle;
            ListNode* secondhalfhead=reversell(prev, curr);

            //compare both halves and decide t/f
            //even case e length equal hai
            //odd wale case mai secondhalf ki length ek badi hai
            ListNode* temphead1=firsthalfhead;
            ListNode* temphead2=secondhalfhead;
            while(temphead1!=NULL)
            {
                if(temphead1->val!=temphead2->val)
                {
                    return false;
                }
                else
                {
                    temphead1=temphead1->next;
                    temphead2=temphead2->next;
                }
            }
            return true;
        }
    };
    
    int main()
    {
        return 0;
    } 