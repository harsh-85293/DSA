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
        bool hasCycle(ListNode *head) 
        {
            unordered_map<ListNode*, bool>m;
            ListNode* temp=head;
                
            //breaing condition
            while(temp!=NULL)
            {
                if(m[temp]==true)
                {
                    //pehle se true hai cycle present hai
                    return true;
                }
                else
                {
                    //cycle present nahi hai
                    //to mark as true kar raha hu
                    m[temp]=true;
                }
                temp=temp->next;
            }
            //puri ll traverse ho gayi aur null mil gaya to no cycle present
            return false;
        }
    };
    int main()
    {
        return 0;
    } 