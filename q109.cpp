/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  TreeNode* sortedListToBST(ListNode* head) {
    vector<int> vec = List2vec(head);
    if (vec.empty()) {
      return nullptr;
    }
    return sorted_vec_to_BST(vec, 0, vec.size() - 1);
  }
  

  vector<int> List2vec (ListNode* first_node) {
    vector<int> result;
    ListNode* cur_node = first_node;
    while (cur_node) {
      result.push_back(cur_node->val);
      cur_node = cur_node->next;
    }

    return result;
  }

  TreeNode* sorted_vec_to_BST (const vector<int>& vec, const size_t& start_pos, const size_t& end_pos) {
    // assume end_pos >= star_pos;
    size_t mid = start_pos + (end_pos - start_pos) / 2;
    // new node with value vec[mid];
    TreeNode* cur_node = new TreeNode(vec[mid]);
    // start_pos, mid - 1; (mid - 1 >= start_pos );
    if (mid > start_pos) {
      cur_node->left = sorted_vec_to_BST(vec, start_pos, mid - 1);
    }
    // mid + 1, end_pos; (mid + 1 <= end_pos)
    if (mid < end_pos) {
      cur_node->right = sorted_vec_to_BST(vec, mid + 1, end_pos);
    }
    return cur_node;
  }
};
