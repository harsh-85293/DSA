ListNode* dummy = new ListNode(0);
ListNode* current = dummy;
for(auto it : ans) {
    current->next = new ListNode(it);
    current = current->next;
}
return dummy->next;