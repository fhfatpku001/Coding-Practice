#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <list>
#include <cmath>
#include <sstream>
#include <climits>
using namespace std;


class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
  vector<int> preorder(Node* root) {
    if (!root) {
      return {};
    }

    vector<int> result;
    stack<Node*> st;
    unordered_map<Node*, size_t> cur_node_child_pos;
    st.push(root);
        
    while (!st.empty()) {
      Node* farther = st.top();

      if (cur_node_child_pos.count(farther) == 0) {
	cur_node_child_pos[farther] = 0;
      }

      if (cur_node_child_pos[farther] < farther->children.size()) {
	Node* cur_child = farther->children[cur_node_child_pos[farther]];
	if (cur_child) {
	  result.push_back(cur_child->val);
	  st.push(cur_child);
	}
	++cur_node_child_pos[farther];
      } else {
	
	st.pop();
      }
    }

    return result;
  }

    vector<int> postorder(Node* root) {
    if (!root) {
      return {};
    }

    vector<int> result;
    stack<Node*> st;
    unordered_map<Node*, size_t> cur_node_child_pos;
    st.push(root);
        
    while (!st.empty()) {
      Node* farther = st.top();

      if (cur_node_child_pos.count(farther) == 0) {
	cur_node_child_pos[farther] = 0;
      }

      if (cur_node_child_pos[farther] < farther->children.size()) {
	Node* cur_child = farther->children[cur_node_child_pos[farther]];
	if (cur_child) {
	  st.push(cur_child);
	}
	++cur_node_child_pos[farther];
      } else {
	result.push_back(farther->val);
	st.pop();
      }
    }

    return result;
  }

  vector<vector<int>> levelOrder(Node* root) {
    if (!root) {
      return {};
    }

    vector<vector<int>> result;
    vector<Node*> level_nodes(1,root);
    
    while (!level_nodes.empty()) {
      vector<int> level_vals;
      vector<Node*> next_level_nodes;

      for (size_t i = 0; i < level_nodes.size(); ++i) {
	level_vals.push_back(level_nodes[i]->val);
	for (size_t j = 0; j < level_nodes[i]->children.size(); ++j) {
	  if (level_nodes[i]->children[j]) {
	    next_level_nodes.push_back(level_nodes[i]->children[j]);
	  }
	}
      }

      level_nodes = next_level_nodes;
      result.push_back(level_vals);
    }

    return result;
  }

  int maxDepth(Node* root) {
    if (!root) {
      return 0;
    }

    int cur_depth = 1;
    int max_depth = 1;
    stack<Node*> st;
    unordered_map<Node*, size_t> cur_node_child_pos;
    st.push(root);
        
    while (!st.empty()) {
      Node* farther = st.top();

      if (cur_node_child_pos.count(farther) == 0) {
	cur_node_child_pos[farther] = 0;
      }

      if (cur_node_child_pos[farther] < farther->children.size()) {
	Node* cur_child = farther->children[cur_node_child_pos[farther]];
	if (cur_child) {
	  st.push(cur_child);
	  ++cur_depth;
	}
	++cur_node_child_pos[farther];
      } else {
	if (cur_depth > max_depth) {
	  max_depth = cur_depth;
	}
	st.pop();
	--cur_depth;
      }
    }

    return max_depth;
  }
};

 
int main()
{   
  Solution solve;

  
  return 0;
}










 

















 








 



 







