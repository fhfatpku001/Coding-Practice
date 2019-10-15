class Solution {
private:
  struct ListNode {
    int val; 
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {};
  };
  
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (!head) {
      return nullptr;
    }

    ListNode* fast = head;
    
    for (int i = 0; i < n; ++i) {
      if (fast) {
	fast = fast->next;
      }
    }

    if (!fast) {
      return head->next;
    }

    ListNode* slow = head;
    
    while (fast && fast->next) {
      fast = fast->next;
      slow = slow->next;
    }

    slow->next = slow->next->next;
    return head;
  }
};
