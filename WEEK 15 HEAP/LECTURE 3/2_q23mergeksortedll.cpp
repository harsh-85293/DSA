   #include <bits/stdc++.h>
   using namespace std;
   struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

  class compare{
          public:
              bool operator()(ListNode* a, ListNode* b){
                  return a->val > b->val;//if < max heap
              }
  };

  class Solution {
  public:
      ListNode* mergeKLists(vector<ListNode*>& lists) {
          priority_queue<ListNode *, vector<ListNode*>, compare > pq;
          ListNode* head = NULL;
          ListNode* tail = NULL;
          
          //process first k elements
          //hr list ka pehla elements insert karna hai priority queue mai
          int totalrows = lists.size();
          
          for(int row = 0; row < totalrows; row++){
                  ListNode* temp = lists[row];
                  if(temp !=NULL){
                      //if its a valid node
                      pq.push(temp);
                  }
          }

          //main logic
          while(!pq.empty()){
              //front nikalo
              ListNode* front = pq.top();
              pq.pop();

              //ans nikalo
              if(head == NULL && tail == NULL){
                  //inserting first node in ll
                  head = front;
                  tail = front;
              }
              else{
                  tail->next = front;
                  tail = front;
              }
              //agar aage node hai to insert karo
              if(tail->next != NULL){
                  pq.push(tail->next);
              }
          }
          return head;
      }
  };
   int main()
   {
     return 0;
   }
