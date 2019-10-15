class Solution {
public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* p1 = l1;
    ListNode* p2 = l2;
    ListNode* cur_pos;
    ListNode* head;
    
    if (!p1 && !p2) {
      return l1;
    }  
      
    if (!l2 || (l1 && l1->val <= l2->val)) {
      head = l1;
      p1 = p1->next;
    } else {
      head = l2;
      p2 = p2->next;
    }

    cur_pos = head;

    while (p1 && p2) {
      if (p1->val < p2->val) {
	cur_pos->next = p1;
	cur_pos = p1;
	p1 = p1->next;
      } else {
	cur_pos->next = p2;
	cur_pos = p2;
	p2 = p2->next;
      }
    }

    if (p1 && !p2) {
      cur_pos->next = p1;
    } else if (!p1 && p2) {
      cur_pos->next = p2;
    }

    return head;
  }
};
