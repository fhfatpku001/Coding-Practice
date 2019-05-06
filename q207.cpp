class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    // we use BFS to find loops. If a loop is detected, then we can't finish;
   
    if (numCourses == 0) return true;

    // map nodes to list of edges.
    unordered_map<int,vector<int>> node_to_edges_pos_map;
    int node;
    
    for (int i = 0; i < prerequisites.size(); ++i) {
      node = prerequisites[i][0];
      if (node_to_edges_pos_map.count(node)==0) {
	vector<int> temp;
	temp.push_back(i);
	node_to_edges_pos_map[node] = temp;
      } else {
	node_to_edges_pos_map[node].push_back(i);
      }
    }

    /*We use BFS find the loops*/
    int target_node;
    
    for (int i = 0; i < numCourses; ++i) {
      unordered_set<int> visited_nodes;
      // BFS from i;
      queue<int> q_BFS;
      q_BFS.push(i);
      visited_nodes.insert(i);
      
      while (!q_BFS.empty()) {
	int cur_node = q_BFS.front();
	if (node_to_edges_pos_map.count(cur_node)>0) {
	  vector<int>& temp = node_to_edges_pos_map[cur_node];
	  for (int j = 0; j < temp.size(); ++j) {
	    // target position= temp [j];
	    target_node = prerequisites[temp[j]][1];
	    if (i == target_node) return false;
	    if (target_node < i) continue;
	    if (visited_nodes.count(target_node) == 0) {
	      q_BFS.push(target_node);
	      visited_nodes.insert(target_node);
	    }
	  }
	}
	q_BFS.pop();
      }
      
    }

    return true;
  }
};
/* DFS*/

class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    // we use DFS to find loops. If a loop is detected, then we can't finish;
   
    if (numCourses == 0) return true;

    // map nodes to list of edges.
    unordered_map<int,vector<int>> node_to_edges_pos_map;
    int node;
   
    for (int i = 0; i < prerequisites.size(); ++i) {
      node = prerequisites[i][0];
      if (node_to_edges_pos_map.count(node)==0) {
	vector<int> temp;
	temp.push_back(i);
	node_to_edges_pos_map[node] = temp;
      } else {
	node_to_edges_pos_map[node].push_back(i);
      }
    }

    /*We use DFS find the loops*/
    int target_node;
    unordered_set<int> checked_nodes;
    unordered_set<int> path_nodes;
    for (int i = 0; i < numCourses; ++i) {
      if (checked_nodes.count(i) > 0) continue;
      int cur_node = i;
      stack<int> st;
      st.push(cur_node);
      path_nodes.insert(cur_node);
      while (!st.empty()) {
	cur_node = st.top();
	
	vector<int> &edges= node_to_edges_pos_map[cur_node];
	if (edges.size()==0) {
	  checked_nodes.insert(cur_node);
	  path_nodes.erase(cur_node);
	  st.pop();
	} else {
	  int pos = edges.size()-1;
	  target_node = prerequisites[edges[pos]][1];
	  if (path_nodes.count(target_node)>0) {
	    return false;
	  } else {
	    path_nodes.insert(target_node);
	    st.push(target_node);
	  }
	  edges.pop_back();
	}
      }
    }

    return true;
  }
};
