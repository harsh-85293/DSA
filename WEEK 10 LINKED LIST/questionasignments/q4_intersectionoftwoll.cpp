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

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        unordered_map<ListNode*,int>mp;
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        
        while(temp1!=NULL)
        {
            mp[temp1]++;
            temp1=temp1->next;
        }

       while(temp2!=NULL)
       {
            if(mp.find(temp2) != mp.end())
            {
                return temp2;
            }
            temp2=temp2->next;
       }
        return NULL;
    }
    int main()
    {
        return 0;
    } 