    #include <bits/stdc++.h>
    using namespace std;

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
            vector<ListNode*> splitListToParts(ListNode* head, int k) 
            {
                int n=0;
                auto it=head;
                while(it)
                {
                    n++;
                    it=it->next;
                }
                int partsize = n/k;
                int extranodes = n%k;

                vector<ListNode*>ans(k, nullptr);
                it=head;

                for(int i=0;i<k  && it;i++)
                { 
                    ans[i]=it;
                    int currentpartsize = partsize + ( extranodes-- > 0 ? 1 : 0 );

                    for(int j=0;j<currentpartsize-1;j++)
                    {
                        it=it->next;
                    }
                    
                    auto nextpartstarting = it->next;
                    it->next = nullptr;
                    it = nextpartstarting;
                
                }
                return ans;
            }
    };
    int main()
    {
        return 0;
    } 