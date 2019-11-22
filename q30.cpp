class Solution {
public:
  vector<int> findSubstring(const string& s, vector<string>& words) {
    if (s.empty() || words.empty() || words[0].empty()) {
      return {};
    }

    unordered_map<string, int> pos_map;
    vector<string> unique_words;
    vector<int> count_words;
    
    for (int i = 0; i < words.size(); ++i) {
      if (pos_map.count(words[i]) == 0) {
	pos_map[words[i]] = (int) unique_words.size();
	unique_words.push_back(words[i]);
	count_words.push_back(1);
      } else {
	++count_words[pos_map[words[i]]];
      }
    }
    
    vector<int> result;
    int num_words = (int) words.size();
    for (int i = 0; i + num_words * words[0].size() <= s.size() ; ++i) {
      vector<int> cur_target = count_words;
      int num_rem_words = num_words;
      
      if (can_find(i, cur_target, s, unique_words, num_rem_words, pos_map)) {
	result.push_back(i);
      }
      
    }

    
    return result;
  }

  bool can_find (int start_pos, vector<int>& cur_target, const string& s, const vector<string>& unique_words, int& num_rem_words, unordered_map<string,int>& pos_map) {
    string str = s.substr(start_pos, unique_words[0].size());

    if (num_rem_words == 0) {
      return true;
    }
    
    if (pos_map.count(str) == 0 || cur_target[pos_map[str]] == 0 ) {
      return false;
    } 

    --cur_target[pos_map[str]];
    --num_rem_words;

    return can_find(start_pos + (int) unique_words[0].size(), cur_target, s, unique_words, num_rem_words, pos_map);
  }
};
