class Solution {
public:
  bool isValidBST(TreeNode* root) {
    if (!root) {
      return true;
    }

    // we do in-order traversal;
    stack<TreeNode*> st;
    unordered_set<TreeNode*> visited;
    st.push(root);
    bool is_first = true;
    int prev;
    
    while (!st.empty()) {
      // push left;
      if (st.top()->left && visited.count(st.top()->left) == 0) {
	st.push(st.top()->left);
        continue;
      } 
      // visit middle;
      if (is_first) {
	prev = st.top()->val;
	is_first = false;
      } else {
	if (prev >= st.top()->val) {
	  return false;
	} else {
	  prev = st.top()->val;
	}
      }

      visited.insert(st.top());
      TreeNode* temp = st.top();
      st.pop();

      if (temp->right && visited.count(temp->right)== 0) {
	st.push(temp->right);
      }
      
    }

    return true;
  }
};
