class Solution {
public:
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode* cur_pos = head;
    if (!head) return nullptr;      
    
    while (cur_pos->next) {
      if (cur_pos->val == cur_pos->next->val) {
	cur_pos->next = cur_pos->next->next;
      } else {
	cur_pos = cur_pos->next;
      }
    }  
    
    return head;
  }
};
