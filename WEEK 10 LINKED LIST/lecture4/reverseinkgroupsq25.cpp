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
        
        //constructor
        ListNode(int value)
        {
            this->data=value;
            this->next=NULL;
        }
    };

    class Solution 
    {
    public:
        int getlength(ListNode* head)
        {
            int len=0;
            ListNode* temp=head;
            while(temp!=NULL)
            {
                len++;
                temp=temp->next;
            }    
            return len;
        }
        ListNode* reverseKGroup(ListNode* head, int k) 
        {
            //ll is empty or has 1 node
            if(head==NULL || head->next==NULL)
            {
                return head;
            }
            //ek case hum karenge baaki recursion sambhal lega
            //ek case hum karenge k ke l iye
            ListNode* prev=NULL;
            ListNode* curr=head;
            int position=0;
            int length=getlength(head);
            if(length<k)
            {
                return head;
            }
            while(position<k)
            {
                ListNode* forward=curr->next;
                curr->next=prev;
                prev=curr;
                curr=forward;
                position++;
            }
            //baaki recursion sambhal lega
            if(curr!=NULL)
            {
                ListNode* recursionkahead=reverseKGroup(curr, k);
                head->next=recursionkahead;
            }
            return prev;
        }
    };
    int main()
    {
        return 0;
    } 