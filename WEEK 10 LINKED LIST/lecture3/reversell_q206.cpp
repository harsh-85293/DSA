    // Recursive way
    #include <bits/stdc++.h>
    using namespace std;

    class Node 
    {
    public:
        int data;
        Node* next;

        Node(int value) 
        {
            this->data = value;
            this->next = NULL;
        }
    };

    // Function to reverse the linked list
    Node* reverseList(Node* &prev, Node* &curr)
    {
        if(curr==NULL)
        {
            return prev;
        }
        Node* forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;

        return reverseList(prev,curr);
    } 
    
    Node* reverseList(Node* head) 
    {
        //base case
        Node* prev=NULL;
        Node* curr=head;

        Node* newhead=reverseList(prev, curr);
        return newhead;
    }

    // Function to print the linked list
    void printll(Node* &head) 
    {
        Node* temp = head;
        while (temp != NULL) 
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Function to insert a node at the head of the list
    void insertathead(int value, Node* &head, Node* &tail) 
    {
        Node* newnode = new Node(value);
        if (head == NULL) 
        {
            head = newnode;
            tail = newnode;
        } 
        else 
        {
            newnode->next = head;
            head = newnode;
        }
    }

    int main() 
    {
        Node* head = NULL;
        Node* tail = NULL;

        insertathead(40, head, tail);
        insertathead(30, head, tail);
        insertathead(20, head, tail);
        insertathead(10, head, tail);

        printll(head);  // Before reversal
        reverseList(head);
        printll(head);  // After reversal

        return 0;
    }
