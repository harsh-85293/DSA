    #include <bits/stdc++.h>
    using namespace std;

    class Node
    {
        public:
            int val;
            Node* next;
            Node* random;
        
        Node(int value)
        {
            this->val=value;
            this->next=NULL;
        }   
    };

    class Solution {
    public:
        Node* helper(Node* head, unordered_map<Node*,Node*> &mp)
        {
            if(head==NULL)
            {
                return head;
            }
            Node* newhead=new Node(head->val);
            mp[head]=newhead;
            newhead->next=helper(head->next,mp);
            if(head->random)
            {
                newhead->random=mp[head->random];
            }
            return newhead;
        }

        Node* copyRandomList(Node* head) {
            unordered_map<Node*,Node*>mp;//old node se new node ki mapping
            return helper(head,mp);
        }
    };
    int main()
    {
        return 0;
    } 