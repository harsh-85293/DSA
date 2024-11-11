    #include <bits/stdc++.h>
    using namespace std;

    class ListNode
    {
        public:
            int val;
            ListNode* next;
        
        //constructor
        ListNode(int value)
        {
            this->val=value;
            this->next=NULL;
        }
    };

    ListNode* mergeNodes(ListNode* head) 
    {
        vector<int>ans;
        ListNode* temp=head;
        int count=0;
        int sum=0;
        while(temp!=NULL)
        {
            if(temp->val==0)
            {
                count++;
            }
            if(count>0 && count <2)
            {
                sum+=temp->val;
            }
            if(count==2)
            {
                ans.push_back(sum);
                count=1;
                sum=0;
            }
            temp=temp->next;
        }
        for(auto it:ans)
        {
            cout << it << endl;
        }
    }

    ListNode* InsertatHead(int value, ListNode* &head, ListNode* &tail)
    {
        //LL is empty -> hed and tail are empty
        //it means we are creating first node of the linked list
        if(head == NULL && tail == NULL)
        {
            //step 1:create a new node
            ListNode* newNode = new ListNode(value);

            //step2:head ko node par laga do
            head = newNode;

            //step3:
            tail = newNode;
        }
        else
        {
            //linked ist is not empty

            //step 1:create a new node
            ListNode* newNode = new ListNode(value);

            //step 2:convert this newnode to head node
            newNode->next=head;

            //step 3:update the node
            head=newNode;
        }
        return head;
    }
    void printll(ListNode* head)
    {
        ListNode* temp=head;
        //jab tak null nahi aa jata chalte raho
        while(temp != NULL)
        {
            cout << temp->val << "->";
            temp=temp->next;
        }
        cout << "NULL"<< endl;
    }
    int main()
    {
        ListNode* head=NULL;
        ListNode* tail=NULL;
        head = InsertatHead(0, head, tail);
        head = InsertatHead(2, head, tail);
        head = InsertatHead(5, head, tail);
        head = InsertatHead(4, head, tail);
        head = InsertatHead(0, head, tail);
        head = InsertatHead(1, head, tail);
        head = InsertatHead(3, head, tail);
        head = InsertatHead(0, head, tail);
        printll(head);
        mergeNodes(head);
        return 0;
    }