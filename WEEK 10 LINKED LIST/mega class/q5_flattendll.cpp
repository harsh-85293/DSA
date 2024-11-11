    /*
    // Definition for a Node.
    class Node {
    public:
        int val;
        Node* prev;
        Node* next;
        Node* child;
    };
    */
    #include <bits/stdc++.h>
        using namespace std;

        class Node 
        {
        public:
            int data;
            Node* next;
            Node* child;
            Node* prev;

            // constructor
            Node(int value) 
            {
                this->data = value;
                this->next = NULL;
            }
        };
    class Solution 
    {
    public:
        Node* solve(Node* head)
        {
            if(head==NULL)//if(!head)
            {
                return head;
            }
            auto it=head;
            auto tail=it;
            while(it)
            {
                if(it->child)
                {
                    auto childtail=solve(it->child);
                    auto temp=it->next;
                    it->next=it->child;
                    it->next->prev=it;
                    childtail->next=temp;
                    if(temp!=NULL)
                    {
                        temp->prev=childtail;
                    }
                    it->child=nullptr;
                }
                tail=it;
                it=it->next;
            }
            return tail;
        }
        Node* flatten(Node* head) 
        {
            solve(head);
            return head;
        }
    };
    int main()
    {
        return 0;
    } 