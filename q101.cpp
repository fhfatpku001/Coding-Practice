class Solution {
public:
  bool isSymmetric(TreeNode* root) {
    return is_mirror(root, root);
  }

  bool is_mirror(TreeNode* tl, TreeNode* tr) {
    if ((tl && !tr) || ( tr && !tl)) {
      return false;
    } else if (!tl && !tr) {
      return true;
    }

    if (tl->val != tr->val) {
      return false;
    }

    return (is_mirror(tl->left, tr->right) && is_mirror(tl->right, tr->left))? true : false;
  }
};
