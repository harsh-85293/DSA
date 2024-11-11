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
    class Solution 
    {
    public:
        void sanitizemap(ListNode* curr, unordered_map<int, ListNode*>&mpp, int csum)
        {
            int temp=csum;
            while(true)
            {
                temp+=curr->val;
                if(temp==csum)
                {
                    break;
                }
                mpp.erase(temp);
                curr=curr->next;
            }
        }
        ListNode* removeZeroSumSublists(ListNode* head) 
        {
            if(!head || (!head->next && head->val==0))
            {
                return nullptr;
            }
            unordered_map<int, ListNode*>mpp;
            auto it=head;
            int csum=0;
            while(it)
            {
                csum+=it->val;
                if(csum==0)
                {
                    head=it->next;
                    mpp.clear();
                }
                else if(mpp.find(csum)!=mpp.end())//pehle se entry hai
                {
                    sanitizemap(mpp[csum]->next, mpp, csum);
                    mpp[csum]->next=it->next;
                }
                else
                {
                    mpp[csum]=it;
                }
                it=it->next;
            }
            return head;
        }
    };
    int main()
    {
        return 0;
    } 