    #include <bits/stdc++.h>
    using namespace std;

    class Node
    {
        public:
            int data;
            Node* next;
        
        //constructor
        Node(int value)
        {
            this->data=value;
            this->next=NULL;
        }
    };
    
    class Solution 
    {
    public:
    Node* reversell(Node* &head)
    {
        Node* prev=NULL;
        Node* curr=head;
        while(curr!=NULL)
        {
            Node* forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
            
    }
    
    Node* addOne(Node* head) 
    {
            // Your Code here
            // return head of list after adding one
            //step1 : reverse ll
            head=reversell(head);
            
            //step 2:add one
            int carry=1;
            Node* temp=head;
            while(temp!=NULL)
            {
                int sum=carry+temp->data;
            
                //step3:reverse ll
                int digit=sum%10;
                carry=sum/10;
                
                temp->data=digit;
                
                if(temp->next==NULL && carry!=0)
                {
                    Node* newnode=new Node(carry);
                    temp->next=newnode;
                    temp=newnode;
                }
                temp=temp->next;
            }
            head=reversell(head);
            return head;
    }
    
    };
    int main()
    {
        return 0;
    } 