class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) {
      return "";
    }
    
    int count = 0;
    string s;

    while (1) {
      for (size_t i = 0; i < strs.size(); ++i) {
	if (count + 1 > strs[i].size()) {
	  return s;
	}

	if (i > 0 && strs[i][count] != strs[i - 1][count]) {
	  return s;
	}
      }
      s.push_back(strs[0][count]);
      ++count;
    }

    return s;
  }
};
