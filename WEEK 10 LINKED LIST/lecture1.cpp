    //SINGLY LINKED LIST
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

    //returns the head of new linked list
    Node* InsertatHead(int value, Node* &head, Node* &tail)
    {
        //LL is empty -> hed and tail are empty
        //it means we are creating first node of the linked list
        if(head == NULL && tail == NULL)
        {
            //step 1:create a new node
            Node* newNode = new Node(value);

            //step2:head ko node par laga do
            head = newNode;

            //step3:
            tail = newNode;
        }
        else
        {
            //linked ist is not empty

            //step 1:create a new node
            Node* newNode = new Node(value);

            //step 2:convert this newnode to head node
            newNode->next=head;

            //step 3:update the node
            head=newNode;
        }
        return head;
    }

    Node* Insertattail(int value, Node* &head, Node* &tail)
    {
        //LL is empty
        if(head == NULL && tail == NULL)
        {
            //step 1:create a new node
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode; 
        }

        //LL is not empty    
        else
        {
            //step1:create a node
            Node* newnode=new Node(value);
            
            //step2:tail node ko next se connect karo
            tail->next=newnode;  

            //step3:tail ko update karo
            tail=newnode;
        }
        return head;
    }

    void Insertatposition(int pos,int value,Node* &head, Node* &tail)
    {
        int length=getlen(head);
        //invalid positions
        if (pos < 1 || pos > length + 1)
        {
            cout << "Invalid position!" << endl;
            return;
        }
        else if(pos==1)
        {
            head=InsertatHead(value,head,tail);
        }
        else if(pos==length+1)
        {
            head=Insertattail(value,head,tail);
            return;
        }

        //valid positions
        else
        {
            Node* temp=head;
            for(int i=0;i<pos-2;i++)
            {
                temp=temp->next;
            }

            Node* newnode=new Node(value);
            newnode->next=temp->next;
            temp->next=newnode;
        }
    }

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
    
    bool search(int target,Node* &head)
    {
        bool ans=false;

        Node* temp=head;

        while(temp!=NULL)
        {
            if(temp->data==target)
            {
                ans=true;
                break;
            }
            temp=temp->next;
        }

        return ans;
    }

    void deleteinll(int pos, Node* &head, Node* &tail)
    {
        int length=getlen(head);

        //if LL is empty than we cannot delete anything
        if(head==NULL && tail==NULL)
        {
            cout << "Linked list is empty";
            return;
        }

        //single node
        else if(head==tail)
        {
            Node* temp=head;
            head=NULL;
            tail=NULL;
            delete temp;
            return;
        }

        //multiple nodes
        else
        {
            //2 cases hai total

            //first case
            if(pos == 1)
            {
                Node* temp=head;
                head=temp->next;
                temp->next=NULL;
                delete temp;
            }

            else
            {
                //any other nodeexcept one position
                Node* prev=head;
                for(int i=0;i<pos-2;i++)
                {
                    prev=prev->next;
                }
                Node* curr=prev->next;
                prev->next=curr->next;
                curr->next=NULL;
                delete curr;
                return;
            }
        }
    }

    void deleteactovalue(int value, Node* &head, Node* &tail)
    {
        if(head==NULL && tail==NULL)
        {
            cout << "Linked list is empty";
            return;
        }
       
        //single node
        if(head->data == value)
        {
            Node* temp=head;
            head=temp->next;
            temp->next=NULL;
            delete temp;
        }

        else
        {
            Node*prev=head;
            while(prev->next->data != value)
            {
                prev=prev->next;
            }
            Node* curr = prev->next;
            prev->next=curr->next;
            curr->next=NULL;
            delete curr;
            return;
        }
    }

    int main()
    {
        // //stack
        // Node first;
        
        //pehle se node present hai
        //insert at head
        //dynamic memory allocation
        // Node* first =new Node(10);

        Node* head=NULL;
        Node* tail=NULL;

        head = InsertatHead(10, head, tail);
        head = InsertatHead(20, head, tail);
        head = InsertatHead(30, head, tail);
        head = Insertattail(90,head,tail);

        Insertatposition(4,42,head,tail);
        
        printll(head);

        cout << search(25,head) << endl;

        // deleteinll(1, head, tail);
        deleteactovalue(30, head, tail);
        printll(head);
        return 0;
    } 