/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//BRUTE APPROACH
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>hell;
        
        ListNode* temp = head;
        while(temp)
        {
            hell.push_back(temp->val);
            temp = temp->next;
        }
        vector<int>ans(hell.size(),0);
        for(int i=0; i < hell.size(); i++)
        {
            for(int j=i+1; j < hell.size(); j++)
            {
                if(hell[j] > hell[i])
                {
                    ans[i] = hell[j];
                    break;
                }
            }
        }
        return ans;
    }
};

//OPTIMAL APPROACH
//optimal approach
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>ll;
        while(head)
        {
            ll.push_back(head->val);
            head = head->next;
        }
        stack<int>st;
        vector<int>ans(ll.size(), 0);

        for(int i = 0; i < ll.size(); i++)
        {
            while(!st.empty() && ll[i] > ll[st.top()])
            {
                int kids = st.top();
                st.pop();
                ans[kids] = ll[i];
            }
            st.push(i);
        }
        return ans;
    }
};