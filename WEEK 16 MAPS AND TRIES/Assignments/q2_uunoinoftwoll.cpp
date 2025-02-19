class Solution {
    public:
      struct Node* makeUnion(struct Node* head1, struct Node* head2) {
          set<int> unq;
  
          // Insert elements from both linked lists into the set
          while (head1 != NULL) {
              unq.insert(head1->data);
              head1 = head1->next;
          }
  
          while (head2 != NULL) {
              unq.insert(head2->data);
              head2 = head2->next;
          }
  
          // Create new linked list
          struct Node* head3 = NULL;
          struct Node* tail = NULL;
  
          for (int val : unq) {
              struct Node* newNode = new Node(val);
              if (head3 == NULL) {
                  head3 = newNode; // Set the head of the new list
                  tail = newNode;
              } else {
                  tail->next = newNode;
                  tail = tail->next;
              }
          }
  
          return head3;
      }
  };
  