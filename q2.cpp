class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    bool sum_greater_than_ten = false;
    
    ListNode* new_list_start = new ListNode(0);
    ListNode* p1 = l1;
    ListNode* p2 = l2;
    ListNode* p = new_list_start;
    
    while (p) {
      int sum = 0;

      if (p1) {
	sum += p1->val;
	p1 = p1->next;
      }

      if (p2) {
	sum += p2->val;
	p2 = p2->next;
      }

      if (sum_greater_than_ten) {
	sum += 1;
      }

      p->val = sum % 10;
      sum_greater_than_ten = (sum > 9) ? true : false;

      if (p1 || p2 || sum_greater_than_ten) { // check if we have to construct a new node;
	ListNode* pn = new ListNode(0);
	p->next = pn;
      }

      p = p->next;
    }

    return new_list_start;
  }
};
