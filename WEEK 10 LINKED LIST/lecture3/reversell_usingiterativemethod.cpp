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

    void printll(Node* &head) 
    {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

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
     Node* reversell(Node* &prev, Node* &curr)
        {
            while(curr!=NULL)
            { 
                Node* forward=curr->next;
                curr->next=prev;
                prev=curr;
                curr=forward;
            }
            return prev;
        }
    int main()
    {
        
        Node* head = NULL;
        Node* tail = NULL;

        insertathead(40, head, tail);
        insertathead(30, head, tail);
        insertathead(20, head, tail);
        insertathead(10, head, tail);
        
        return 0;
    }  