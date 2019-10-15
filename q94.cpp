class Solution {
public:
  vector<int> inorderTraversal(TreeNode* root) {
    if (!root) {
      return {};
    }
    // we do in-order traversal;
    stack<TreeNode*> st;
    unordered_set<TreeNode*> visited;
    st.push(root);
    vector<int> result;
    
    while (!st.empty()) {
      // push left;
      if (st.top()->left && visited.count(st.top()->left) == 0) {
	st.push(st.top()->left);
	continue;
      } 
      // visit middle;
      result.push_back(st.top()->val);

      visited.insert(st.top());
      TreeNode* temp = st.top();
      st.pop();

      if (temp->right && visited.count(temp->right)== 0) {
	st.push(temp->right);
      }
      
    }

    return result;
  }
};
