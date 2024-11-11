    //iterative way
    #include <bits/stdc++.h>
    using namespace std;

    class ListNode
    {
        public:
            int val;
            ListNode* next;
        
        //constructor
        ListNode(int value)
        {
            this->val=value;
            this->next=NULL;
        }
    };

    class Solution 
    {
        public:
            ListNode* iterative(ListNode* l1, ListNode* l2)
            {
                ListNode* ans=new ListNode(-1);
                ListNode* it=ans;
                int carry=0;
                while(l1 || l2 || carry)
                {
                    int a=l1 ? l1->val : 0;
                    int b=l2 ? l2->val : 0;
                    int sum=a+b+carry;
                    int digit=sum%10;
                    carry=sum/10;
                    it->next=new ListNode(digit);
                    it=it->next;
                    l1=l1 ? l1->next : nullptr;
                    l2=l2 ? l2->next : nullptr;
                }
                ListNode* finalans=ans->next;
                delete ans;
                return finalans;
        }
        ListNode* recursiveway(ListNode* l1, ListNode* l2 , int carry=0)
        {
            if(!l1 && !l2 && !carry)
            {
                return 0;
            }
            //ek case
            int a=l1 ? l1->val : 0;
            int b=l2 ? l2->val : 0;
            int sum=a+b+carry;
            int digit=sum%10;
            carry=sum/10;
            ListNode* ans=new ListNode(digit);
            ans->next=recursiveway(l1 ? l1->next :l1,l2 ? l2->next :l2,carry);
            return ans;
        }
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
        {
            return iterative(l1, l2);
        }
    };
    int main()
    {
        return 0;
    } 