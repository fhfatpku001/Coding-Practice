/*STL: Priority Queue Solution*/

class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> pqueue;
    for (auto it : nums) {
      pqueue.push(it);
    }
    
    for (int i = 0; i < k-1; ++i) {
      pqueue.pop();
    }

    return pqueue.top();
  }
};
