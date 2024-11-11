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
    class Solution {
    public:
        int getlen(ListNode* head)
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

        ListNode* solve(ListNode* &head, int k)
        {
            if(head==NULL || k==0)
            {
                return head;
            }
            int l=getlen(head);
            int m=k%l;
            while(m!=0)
            {
                ListNode* last=head;
                ListNode* secondlast=NULL;
                
                while(last->next!=NULL)
                {
                    secondlast=last;
                    last=last->next;
                }
                last->next=head;
                secondlast->next=NULL;
                head=last;
                m--;
            }
            return head;
        }
        ListNode* rotateRight(ListNode* head, int k) {
            ListNode* newhead=solve(head,k);
            return newhead;
        }
    };
    int main()
    {
        Node* head=NULL;
        Node* tail=NULL;

        head = InsertatHead(5, head, tail);
        head = InsertatHead(4, head, tail);
        head = InsertatHead(3, head, tail);
        head = InsertatHead(2, head, tail);
        head = InsertatHead(1, head, tail);
        printll(head);
        int k=2;
        head=solve(head,k);
        printll(head);
        
        return 0;
    } 