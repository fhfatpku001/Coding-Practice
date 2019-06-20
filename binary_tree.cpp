#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <list>
#include <cmath>
#include <sstream>
#include <climits>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class btree {
private:
  struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  };

public:
  /*Remark: we make all functions public except TreeNode struct*/

  /*Initialize*/
  
  TreeNode* root;
  
  btree(string str) {
    root = stringToTreeNode(str);
  };

  /*Question List*/
  
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;

    if (!root) {
      return result;
    }
    
    stack<TreeNode*> tst;
    unordered_set<TreeNode*> visited;

    tst.push(root);
    visited.insert(root);
    result.push_back(root -> val);
    
    TreeNode* pos;
    
    while (!tst.empty()) {
      pos = tst.top();
      if (pos -> left && visited.count(pos -> left) == 0) {
	tst.push(pos -> left);
	result.push_back(pos -> left -> val);
	visited.insert(pos -> left);
      } else if (pos -> right && visited.count(pos -> right) == 0) {
	tst.push(pos -> right);
	result.push_back(pos -> right -> val);
	visited.insert(pos -> right);
      } else {
	tst.pop();
      }
    }
    
    return result;
  }

  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    /*left -> root -> right*/

    if (!root) {
      return result;
    }
    
    stack<TreeNode*> tst;
    unordered_set<TreeNode*> visited;

    tst.push(root);
    visited.insert(root);
        
    TreeNode* pos;

    while (!tst.empty()) {
      pos = tst.top();
      if ((!pos->left || visited.count(pos->left)) && (visited.count(pos->right) == 0)) {
	result.push_back(pos->val);
      }
      
      if (pos -> left && visited.count(pos -> left) == 0) {
	tst.push(pos -> left);
	visited.insert(pos -> left);
      } else if (pos -> right && visited.count(pos -> right) == 0) {
	tst.push(pos -> right);
	visited.insert(pos -> right);
      } else {
	tst.pop();
      }
    }
    
    return result;
  }

  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    /*left -> right -> root*/

    if (!root) {
      return result;
    }
    
    stack<TreeNode*> tst;
    unordered_set<TreeNode*> visited;

    tst.push(root);
    visited.insert(root);
        
    TreeNode* pos;

    while (!tst.empty()) {
      pos = tst.top();
      if (pos -> left && visited.count(pos -> left) == 0) {
	tst.push(pos -> left);
	visited.insert(pos -> left);
      } else if (pos -> right && visited.count(pos -> right) == 0) {
	tst.push(pos -> right);
	visited.insert(pos -> right);
      } else {
	tst.pop();
	result.push_back(pos->val);
      }
    }
    
    return result;
  }

  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    
    if (!root) {
      return result;
    }

    vector<TreeNode*> cur_vec;
    cur_vec.push_back(root);
    int cur_level = 0;

    while (cur_vec.size() > 0) {
      vector<TreeNode*> next_vec;
      vector<int> level_ints(cur_vec.size(), 0);
      for (size_t i = 0; i < cur_vec.size(); ++i) {
	if (cur_vec[i]->left) {
	  next_vec.push_back(cur_vec[i]->left);
	}

	if (cur_vec[i]->right) {
	  next_vec.push_back(cur_vec[i]->right);
	}

		
	if (cur_level%2 == 0) {
	  level_ints[i] = cur_vec[i]->val;
	} else {
	  level_ints[cur_vec.size() - 1 - i] = cur_vec[i] -> val;
	}
      }

      result.push_back(level_ints);
      ++cur_level;
      cur_vec = next_vec;
    }

    return result;
    
  }

  bool isBalanced(TreeNode* root) {
    
    /*left -> right -> root*/

    if (!root) {
      return true;
    }

    unordered_set<TreeNode*> visited;
    unordered_map<TreeNode*, int> node_height;

    stack<TreeNode*> tst;
    
    tst.push(root);
    
    
        
    TreeNode* pos;

    while (!tst.empty()) {
      pos = tst.top();
      if (pos -> left && visited.count(pos -> left) == 0) {
	tst.push(pos -> left);
	visited.insert(pos->left);
      } else if (pos -> right && visited.count(pos -> right) == 0) {
	tst.push(pos -> right);
	visited.insert(pos->right);
      } else {
	tst.pop();
	if (!pos->left && !pos->right) {
	  node_height[pos] = 1;
	} else if (!pos->left && pos->right ){
	  if (node_height[pos->right] > 1) {
	    return false;
	  } else {
	    node_height[pos] = node_height[pos->right] + 1;
	  }
	} else if (pos->left && !pos->right ){
	  if (node_height[pos->left] > 1) {
	    return false;
	  } else {
	    node_height[pos] = node_height[pos->left] + 1;
	  }
	} else if (pos->left && pos->right ){
	  if (node_height[pos->left] - node_height[pos->right] < 2 && node_height[pos->left] - node_height[pos->right] > -2 ) {
	    node_height[pos] = max(node_height[pos->left], node_height[pos->right]) + 1;
	  } else {
	    return false;
	  }
	}
	
	
      }
    }
    
    return true;
  }

  /*Validate Binary Search Tree*/

  bool isValidBST(TreeNode* root) {
    // Inordertraversal => ascending sequence;
    if (!root) {
      return true;
    }

    unordered_set<TreeNode*> visited;
    stack<TreeNode*> tst;
    int cur_val;
    bool isfirst = true;
    
    tst.push(root);
    visited.insert(root);
    
    while (!tst.empty()) {
      TreeNode* pos = tst.top();
      
      if ((!pos->left || visited.count(pos->left) == 1) && (!pos->right || visited.count(pos->right) == 0)) {
	if (pos->val <= cur_val && !isfirst) {
	  return false;
	} else {
	  cur_val = pos->val;
	  isfirst = false;
	}
      }
      

      if (pos->left && visited.count(pos->left) == 0) {
	tst.push(pos->left);
	visited.insert(pos->left);
      } else if (pos->right && visited.count(pos->right) == 0) {
	  tst.push(pos->right);
	  visited.insert(pos->right);
      } else {
	  tst.pop();
      }
      
    }

    return true;
  }


  /* slow tbe*/
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

    if (!root) {
      return nullptr;
    }
    
    unordered_map<TreeNode*,TreeNode*> farther_map;
    farther_map[root] = nullptr;

    stack<TreeNode*> tst;
    tst.push(root);
    
    while (!tst.empty()) {
      TreeNode* pos = tst.top();

      if (pos->left && farther_map.count(pos->left) == 0) {
	tst.push(pos->left);
	farther_map[pos->left] = pos;
      } else if (pos->right && farther_map.count(pos->right) == 0) {
	tst.push(pos->right);
	farther_map[pos->right] = pos;
      } else {
	tst.pop();
      }
    }

    unordered_set<TreeNode*> precedents_p;
    TreeNode* pos = p;
    while (pos) {
      precedents_p.insert(pos);
      pos = farther_map[pos];
    }

    TreeNode* result = q;

    while (result) {
      if (precedents_p.count(result)) {
	return result;
      }

      result = farther_map[result];
    }

    return result;
    
    
  }

  /*TBE*/
  int kthSmallest(TreeNode* root, int k) {

    unordered_set<TreeNode*> visited;
    stack<TreeNode*> tst;
    tst.push(root);
    visited.insert(root);

    int count = k;

    while (!tst.empty()) {
      TreeNode* pos = tst.top();

      if ((!pos->left || visited.count(pos->left) == 1) && visited.count(pos->right) == 0) {
	if (count == 1) {
	  return pos->val;
	}
	--count;
      }

      if (pos->left && visited.count(pos->left) == 0) {
	tst.push(pos->left);
	visited.insert(pos->left);
      } else if (pos->right && visited.count(pos->right) == 0) {
	tst.push(pos->right);
	visited.insert(pos->right);
      } else {
	tst.pop();
      }
    }

    return 0;
  }
  
  ///////////////LeetCode template//////////////////
  
  string treeNodeToString(TreeNode* root) {
    if (root == nullptr) {
      return "[]";
    }

    string output = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
      TreeNode* node = q.front();
      q.pop();

      if (node == nullptr) {
	output += "null, ";
	continue;
      }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
  }


  
  void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
								     return !isspace(ch);
								   }));
  }

  void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
							return !isspace(ch);
						      }).base(), input.end());
  }

  TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
  }

  void prettyPrintTree(TreeNode* node, string prefix = "", bool isLeft = true) {
    if (node == nullptr) {
        cout << "Empty tree";
        return;
    }

    if(node->right) {
        prettyPrintTree(node->right, prefix + (isLeft ? "│   " : "    "), false);
    }

    cout << prefix + (isLeft ? "└── " : "┌── ") + to_string(node->val) + "\n";

    if (node->left) {
        prettyPrintTree(node->left, prefix + (isLeft ? "    " : "│   "), true);
    }
  }

  void ptree () {
    prettyPrintTree(root, "", true);
  }

  
  
};

 
int main()
{   
  string str = "[2,1,3]";
  btree* obj = new btree(str);
  obj -> ptree();

  cout << obj->root << endl;
  
  return 0;
}










 







