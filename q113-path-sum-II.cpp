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
  vector<int> convert (vector<TreeNode*> vec) {
    vector<int> result;
    for (auto it : vec) {
      result.push_back(it->val);
    }
    return result;
  }
  
  vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> result;
    if (!root) return result;

    vector<TreeNode*> st;
    vector<int> temp;
    bool isLeaf = true;
    TreeNode* pos = root;
    TreeNode* tpos;
    st.push_back(root);
    int size;

    int cursum = root->val;
    
    while (st.size() != 0) {
     
      if (pos->left) {
	tpos = pos;
	pos = pos->left;
	st.push_back(pos);
	isLeaf = true;
	tpos->left = NULL;
	cursum += pos->val;
      } else if (pos->right) {
	tpos = pos;
	pos = pos->right;
	st.push_back(pos);
	isLeaf = true;
	tpos->right = NULL;
	cursum += pos->val;
      } else {
	if (isLeaf && cursum == sum) {
	  temp = convert(st);
	  result.push_back(temp);
	}
	cursum -= pos->val;
	isLeaf = false;
	st.pop_back();
	size = st.size();
	if (size >0) pos = st[size - 1];
      }
    }

    return result;
  }
};
