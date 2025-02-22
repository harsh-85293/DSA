    #include <bits/stdc++.h>
    using namespace std;
    
    class ListNode
    {
        public:
            int val;
            ListNode* next;
        
        ListNode(int value)
        {
            this->val=value;
            this->next=NULL;
        }   
    };
    
    class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* left, ListNode* right) {
            if(left==NULL)
            {
                return right;
            }
            if(right==NULL)
            {
                return left;
            }
            ListNode* ans=new ListNode(-1); 
            ListNode* mptr=ans;
            while(left!=NULL && right!=NULL)
            {
                if(left->val<=right->val)
                {
                    mptr->next=left;
                    mptr=left;
                    left=left->next;
                }
                else
                {
                    mptr->next=right;
                    mptr=right;
                    right=right->next;
                }
            }

            if(left!=NULL)
            {
                mptr->next=left;
            }
            if(right!=NULL)
            {
                mptr->next=right;
            }

            return ans->next;
        }
    };
    int main()
    {
        return 0;
    } 