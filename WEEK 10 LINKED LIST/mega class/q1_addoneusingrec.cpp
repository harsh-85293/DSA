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

    void printll(Node* head)
    {
        Node* temp=head;
        //jab tak null nahi aa jata chalte raho
        while(temp != NULL)
        {
            cout << temp->data << "->";
            temp=temp->next;
        }
        cout << "NULL"<< endl;
    }

    void solve(Node* &head, int &carry)
    {
        if(head==NULL)
        {
            return ;
        }

        solve(head->next,carry);
        int sum=head->data + carry;
        int digit=sum%10;
        carry=sum/10;
        head->data=digit;
    }

    Node* addll(Node* head,int &carry)
    {
        solve(head,carry);
        if(carry!=0)
        {
            Node* newhead=new Node(carry);
            newhead->next=head;
            head=newhead;
        }
        return head;
    }
    
    int main()
    {
        Node* head=new Node(9);
        head->next=new Node(9);
        head->next->next=new Node(9);
        int carry=1;
        printll(head);
        head=addll(head, carry);
        printll(head);
        return 0;
    } 