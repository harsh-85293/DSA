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
        Node* insertattail(Node* &tomove, Node* &head, Node* &tail)
        {
            if(head==NULL && tail==NULL)
            {
                head=tomove;
                tail=tomove;
            }
            else
            {
                tail->next=tomove;    
                tail=tomove;
            }
            
        }
        // Function to sort a linked list of 0s, 1s and 2s.
        Node* segregate(Node* head) 
        {
            // Add code here
            Node* onehead=NULL;
            Node* zerohead=NULL;
            Node* twohead=NULL;
            Node* zerotail=NULL;
            Node* onetail=NULL;
            Node* twotail=NULL;
            
            
            //link list pe traverse karke 3 ll taiyyar karenge
            Node* temp=head;
            while(temp!=NULL)
            {
                Node* tomove=temp;
                temp=temp->next;
                tomove->next=NULL;
                
                if(tomove->data == 0)
                {
                    insertattail(tomove, zerohead, zerotail);
                }
                else if(tomove->data == 1)
                {
                    insertattail(tomove, onehead, onetail);
                }
                else if(tomove->data == 2)
                {
                    insertattail(tomove, twohead, twotail);
                }
            }
            
            //ab merge karenge
            //niche wali line importat
            //possible hai empty ho o wali ll ya one wali ll ya 2 wali ll
            if(zerohead!=NULL)
            {
                if(onehead!=NULL)
                {
                    zerotail->next=onehead;
                    onetail->next=twohead;
                    
                }
                else
                {
                    //onelist is empty
                    zerotail->next=twohead;
                }
                return zerohead;
            }
            
            else
            {
                if(onehead!=NULL)
                {
                    onetail->next=twohead;
                    return onehead;
                }
                else
                {
                    return twohead;
                }
            }
            
        }
    };
    int main()
    {
        return 0;
    } 