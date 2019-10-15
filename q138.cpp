class Solution {
public:
  struct Node {
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }

  };
  
  Node* copyRandomList(Node* head) {
    if (!head) {
      return nullptr;
    }

    size_t pos = 0;
    Node* cur_node = head;
    unordered_map<Node*, size_t> pos_map;
    vector<Node*> new_seq_nodes;
    
    while (cur_node) {
      pos_map[cur_node] = pos;
      Node* copied_node = new Node(cur_node->val, nullptr, cur_node->random); 
      new_seq_nodes.push_back(copied_node);
      ++pos;
      cur_node = cur_node->next;
    }

    

    
    for (size_t i = 0; i + 1 < new_seq_nodes.size(); ++i) {
      new_seq_nodes[i]->next = new_seq_nodes[i + 1];
      if (new_seq_nodes[i]->random) {
	new_seq_nodes[i]->random = new_seq_nodes[pos_map[new_seq_nodes[i]->random]];
      }
    }

    if (new_seq_nodes.back()->random) {
      new_seq_nodes.back()->random = new_seq_nodes[pos_map[new_seq_nodes.back()->random]];
    }
    
    return new_seq_nodes[0];
  }
};
