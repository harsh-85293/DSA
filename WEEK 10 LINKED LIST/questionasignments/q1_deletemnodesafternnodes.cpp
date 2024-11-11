    #include <bits/stdc++.h>
    using namespace std;

    class Node
    {
        public:
            int data;
            Node* next;
        
        Node(int value)
        {
            this->data=value;
            this->next=NULL;
        }   
    };
    
    void insertathead(int val,Node* &head, Node* &tail)
    {
        if(head==NULL && tail==NULL)
        {
            Node* newnode=new Node(val);
            head=newnode;
            tail=newnode;
        }

        else
        {
            Node* newnode=new Node(val);
            newnode->next=head;
            head=newnode;
        }
    }

    void printll(Node* &head)
    {
        Node* temp=head;
        while(temp!=NULL)
        {
            cout << temp->data << "->";
            temp=temp->next;
        }
        cout << "NULL" << endl;
    }
    Node* deletell(Node* &head, int n, int m) 
    {
        // Base case: if head is NULL, return
        if (head == NULL) 
        {
            return head;
        }

        // Skip `m` nodes
        Node* temp = head;
        for (int i = 1; i < m && temp != NULL; i++) 
        {
            temp = temp->next;
        }

        // If we reach the end of the list, return
        if (temp == NULL || temp->next == NULL) 
        {
            return head;
        }

        // Start deleting `n` nodes after skipping `m` nodes
        Node* curr = temp->next;
        for (int i = 0; i < n && curr != NULL; i++) 
        {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }

        // Connect the remaining part of the list
        temp->next = curr;

        // Recursively call for the next part of the list
        deletell(curr, n, m);

        return head;
    }
    int main()
    {
        Node* head=NULL;
        Node* tail=NULL;
        insertathead(10,head,tail);
        insertathead(9,head,tail);
        insertathead(8,head,tail);
        insertathead(7,head,tail);
        insertathead(6,head,tail);
        insertathead(5,head,tail);
        insertathead(4,head,tail);
        insertathead(3,head,tail);
        insertathead(2,head,tail);
        insertathead(1,head,tail);
        printll(head);
        cout << endl;
        int n=1;//delete 
        int m=2;//skip
        head=deletell(head,n,m);
        printll(head);
        return 0;
    } 