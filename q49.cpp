class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, size_t> pos_map;
    vector<vector<string>> result;

    for (size_t i = 0; i < strs.size(); ++i) {
      string sorted_str = convert(strs[i]);
      if (pos_map.count(sorted_str) > 0) {
	result[pos_map[sorted_str]].push_back(strs[i]);
      } else {
	vector<string> new_group(1, strs[i]);
	size_t size = result.size();
	pos_map[sorted_str] = size;
	result.push_back(new_group);
      }
    }

    return result;
  }

  string convert (const string& str) {
    vector<int> storage(26,0);
    string sorted_str;
    
    for (size_t i = 0; i < str.size(); ++i) {
      ++storage[str[i] - 'a'];
    }
    
    for (size_t i = 0; i < 26; ++i) {
      sorted_str.resize(sorted_str.size() + storage[i], 'a' + i);
    }

    return sorted_str;
  }
};
