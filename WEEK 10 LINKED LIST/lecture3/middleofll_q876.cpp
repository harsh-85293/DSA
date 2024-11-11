    #include <bits/stdc++.h>
    using namespace std;

    class ListNode 
    {
    public:
        int data;
        ListNode* next;

        // constructor
        ListNode(int value) 
        {
            this->data = value;
            this->next = NULL;
        }
    };

    // Insert a new node at the head of the linked list
    void insertathead(int value, ListNode* &head, ListNode* &tail) 
    {
        ListNode* newnode = new ListNode(value);
        if (head == NULL) 
        {
            head = newnode;
            tail = newnode;
        } else 
        {
            newnode->next = head;
            head = newnode;
        }
    }

    int main() 
    {
        // Initialize head and tail
        ListNode* head = NULL;
        ListNode* tail = NULL;

        // Insert some nodes into the list
        insertathead(10, head, tail);
        insertathead(20, head, tail);
        insertathead(30, head, tail);

        // Finding the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL) 
        {
            fast = fast->next;
            // null check
            if (fast != NULL) 
            {
                fast = fast->next;
                // move slow one step forward
                slow = slow->next;
            }
        }

        cout << "Middle of the list is: " << slow->data << endl;

        return 0;
    }
