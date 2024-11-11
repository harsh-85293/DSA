    //DOUBLY LINKED LIST
    #include <bits/stdc++.h>
    using namespace std;

    class Node
    {
        public:
            Node* prev;
            int data;
            Node* next;

            Node(int value)
            {
                this->data=value;
                this->next=NULL;
                this->prev=NULL;
            }
    };

    void printdll(Node* head)
    {
        Node* temp=head;
        while(temp!=NULL)
        {
            cout << temp->data << "->";
            temp=temp->next;
        }
        cout << "NULL" << endl;
    }

    void printreversedll(Node* tail)
    {
        Node*temp =tail;

        while(temp!=NULL)
        {
            cout << temp->data << "->";
            temp=temp->prev;
        }
        cout << "NULL" << endl; 
    }

    int getlen(Node* head)
    {
        Node* temp=head;
        int len=0;
        while(temp!=NULL)
        {
            len++;
            temp=temp->next;
        }
        return len;
    }

    void insertathead(int value, Node* &head,Node* &tail)
    {
        //2 cases
        //ll is empty
        if(head==NULL && tail==NULL)
        {
            Node* newnode=new Node(value);
            head=newnode;
            tail=newnode;
            return;
        }
        //ll is not empty
        else
        {
            Node* newnode=new Node(value);
            newnode->next=head;
            head->prev=newnode;
            head=newnode;
            return;
        }
    }

    void insertattail(int value, Node* &head, Node* &tail)
    {
        //2 cases
        //ll is empty
        if(head==NULL && tail==NULL)
        {
            Node* newnode=new Node(value);
            head=newnode;
            tail=newnode;
            return;
        }
        //ll is not empty
        else
        {
            Node* newnode=new Node(value);
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
    }

    void insertatpos(int pos, int value, Node* &head, Node* &tail)
    {
        int n=getlen(head); 
        
        if (pos < 1 || pos > n + 1)
        {
            cout << "Invalid position!" << endl;
            return;
        }

        else if(pos==1)
        {
            insertathead(value, head, tail);
            return;
        }

        else if(pos==n+1)
        {
            insertattail(value, head, tail);
            return;
        }

        else
        {
            Node* newnode=new Node(value);
            Node* temp=head;
            for(int i=0; i<pos-2; i++)
            {
                temp=temp->next;
            }
            Node* forward=temp->next;

            temp->next=newnode;
            newnode->prev=temp;
            newnode->next=forward;
            forward->prev=newnode;
            return;
        }
    }
     
    void deleteatpos(int pos, Node* &head, Node* &tail)
    {
        int n=getlen(head);

        if(head==NULL && tail==NULL)
        {
            cout << "No nodes to delete" << endl;
        }

        else if(head==tail)
        {
            Node* temp=head;
            head=NULL;
            tail=NULL;
            delete temp;
        }

        else if(pos==1)
        {
            Node* temp=head;
            head=head->next;
            head->prev=NULL;
            temp->next=NULL;
            delete temp;
        }

        else if(pos==n)
        {
            Node* temp=tail;
            tail=temp->prev;
            tail->next=NULL;
            temp->prev=NULL;
            delete temp;
        }

        else
        {
            Node*   backward=head;
            for(int i=0; i<pos-2; i++)
            {
                backward=backward->next;
            }
            Node* curr =backward->next;
            Node* forward=curr->next;

            backward->next=forward;
            forward->prev=backward;
            curr->prev=NULL; 
            curr->next=NULL;
            delete curr;
        }
    } 

    bool search(Node* &head, int target)
    {
        bool ans=false;//maan liya ki nhi mila
        Node* temp=head;
        while(temp!=NULL)
        {
            if(temp->data == target)
            {
                ans=true;
                break;
            }
            temp=temp->next;
        }
        return ans;
    }

    int main()
    {
        Node* head=NULL;
        Node* tail=NULL;

        insertathead(10, head, tail);
        insertathead(20, head, tail);
        insertathead(30, head, tail);
        // 30->20->NULL
        printdll(head);
        printreversedll(tail);

        insertattail(40, head, tail);
        insertattail(50, head, tail);
        insertattail(60, head, tail);
        //30->20->10->40->50->60->NULL
        printdll(head);

        insertatpos(3, 420, head, tail);
        //30->20->420->10->40->50->60->NULL
        printdll(head);

        cout << search(head, 30) << endl;

        deleteatpos(4,head,tail);
        //30->20->10->40->50->60->NULL
        printdll(head);
        return 0;
    } 