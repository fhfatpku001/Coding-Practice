class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    if (s.empty()) {
      return true;
    }
    
    vector<bool> status(s.size(), false);

    for (size_t i = 0; i < s.size(); ++i) {
      for (size_t j = 0; j < wordDict.size(); ++j) {
	if (can_place(s, wordDict[j], i)) {
	  if (i + 1 == wordDict[j].size()) {
	    status[i] = true;
	    break;
	  } else if (i + 1 > wordDict[j].size() && status[i - wordDict[j].size()]) {
	    status[i] = true;
	    break;
	  }
	}
      }
    }

    return status.back();
  }

  bool can_place (const string& s, const string& word, size_t pos) {
    if (pos + 1 < word.size()) {
      return false;
    }

    for (int i = 0; i < word.size(); ++i) {
      if (word[word.size() - 1 -i] != s[pos - i]) {
	return false;
      }
    }

    return true;
  }
};
