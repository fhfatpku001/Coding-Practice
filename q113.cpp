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
	// use const vector<TreeNode*> &vec
  vector<int> convert (vector<TreeNode*> vec) {
    vector<int> result;
	  // use const auto &
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
	      // use nullptr
	tpos->left = NULL;
	cursum += pos->val;
      } else if (pos->right) {
	tpos = pos;
	pos = pos->right;
	st.push_back(pos);
	isLeaf = true;
	      // use nullptr
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


class Solution {
public:
  vector<vector<int>> pathSum(TreeNode* root, int sum) {
    if (!root) {
      return {};
    }

    vector<vector<int>> result;
    deque<TreeNode*> dq;
    int cur_sum = root->val;
    dq.push_back(root);
    unordered_set<TreeNode*> visited;
    visited.insert(root);
    visited.insert(nullptr);
    
    while (!dq.empty()) {
            
      if (visited.count(dq.back()->left) == 0) {
	cur_sum += dq.back()->left->val;
	visited.insert(dq.back()->left);
	dq.push_back(dq.back()->left);
      } else if (visited.count(dq.back()->right) == 0) {
	cur_sum += dq.back()->right->val;
	visited.insert(dq.back()->right);
	dq.push_back(dq.back()->right);
      } else {
	if (!dq.back()->left && !dq.back()->right && cur_sum == sum) {
	  vector<int> cand = dq2vec(dq);
	  result.push_back(cand);
	}
	
	cur_sum -= dq.back()->val;
	dq.pop_back();
      }
      
    }

    return result;
  }

  vector<int> dq2vec (deque<TreeNode*>& dq) {
    if (dq.empty()) {
      return {};
    }

    vector<int> vec;
    
    for (deque<TreeNode*>::iterator it = dq.begin(); it != dq.end() ; ++it) {
      vec.push_back((*it)->val);
    }

    return vec;
  }
};
