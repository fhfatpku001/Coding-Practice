
class Solution {
public:
  vector<int> preorderTraversal(TreeNode* root) {
    if (!root) {
      return {};
    }

    
    // we do in-order traversal;
    stack<TreeNode*> st;
    unordered_set<TreeNode*> visited;
    st.push(root);
    vector<int> result;
    
    while (!st.empty()) {
      if (visited.count(st.top()) == 0) {
	result.push_back(st.top()->val);
	visited.insert(st.top());
      }

      TreeNode* temp = st.top();

      // push left;
      if (temp->left && visited.count(temp->left) == 0) {
	st.push(temp->left);
	continue;
      } 
      // visit middle;

      if (temp->right && visited.count(temp->right)== 0) {
	st.push(temp->right);
	continue;
      }

      st.pop(); 
    }

    return result;
  }
};
