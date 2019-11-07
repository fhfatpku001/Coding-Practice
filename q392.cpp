class Solution {
public:
  bool isSubsequence(string s, string t) {
    if (s.empty()) {
      return true;
    } else {
      if (t.empty()) {
	return false;
      }
    }

    size_t i = 0;
    
    for (size_t j = 0; j < t.size(); ++j) {
      if (s[i] == t[j]) {
	++i;
	if (i == s.size()) {
	  return true;
	}
      }
    }
    
    return false;
  }
};
