    #include <bits/stdc++.h>
    using namespace std;
    
    class Node
    {
        public:
            int val;
            Node* next;
        
        Node(int value)
        {
            this->val=value;
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
    Node* doubleIt(Node* &head) 
    {
        Node* temp=head;
        int no=0;
        while(temp!=NULL)
        {
            no=no*10+temp->val;
            temp=temp->next;
        }
        cout << no << endl;
        int g=no*2;
        temp=head;
        while(temp->next!=NULL)
        {
            temp->val=g%10;
            temp=temp->next;
            g=g/10;
        }
        return head;
    }

    void printll(Node* &head)
    {
        Node* temp=head;
        while(temp!=NULL)
        {
            cout << temp->val << "->";
            temp=temp->next;
        }
        cout << "NULL" << endl;
    }
    
    Node* reverseLinkedList(Node* &head) 
    {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) 
    {
        next = current->next;  // Save the next node
        current->next = prev;  // Reverse the current node's pointer
        prev = current;        // Move 'prev' one step forward
        current = next;        // Move 'current' one step forward
    }

    // 'prev' will be the new head after the loop completes
    return prev;
    }
    int main()
    {
        Node* head=NULL;
        Node* tail=NULL;
        insertathead(9,head,tail);
        insertathead(8,head,tail);
        insertathead(1,head,tail);
        printll(head);
        head=doubleIt(head);
        head=reverseLinkedList(head);
        printll(head);
        return 0;
    } 