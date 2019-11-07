
class Solution {
public:
  vector<string> wordBreak(const string& s, const vector<string>& wordDict) {
    if (s.empty() || wordDict.empty()) {
      return {};
    }

    vector<vector<int>> breaktree(s.size());
    vector<string> result;
    break_helper(s, wordDict, breaktree);
    vector<int> cur_vec;

    for (auto it : breaktree.back()) {
      cur_vec.push_back(it);
      back_tracking(result, breaktree, s, cur_vec);
    }
    
    return result;
  }

  void back_tracking (vector<string>& result, const vector<vector<int>>& breaktree, const string& s, vector<int>& cur_vec) {
    if (!cur_vec.empty() && cur_vec.back() == -1) {
      for (auto it : cur_vec) {
	cout << it << " ";
      }
      cout << endl;
      
      string str = convert(cur_vec, s);
      result.push_back(str);
    } else if (!cur_vec.empty() ) {
      for (size_t i = 0; i < breaktree[cur_vec.back()].size(); ++i) {
	cur_vec.push_back(breaktree[cur_vec.back()][i]);
	back_tracking(result, breaktree, s, cur_vec);
      }
    }

    if (!cur_vec.empty()) {
      cur_vec.pop_back();
    }
    
  }

  string convert(vector<int>& cur_vec, const string& s) {
    string str;
    for (int i = cur_vec.size() - 2; i >= 0; --i) {
      str += s.substr(cur_vec[i + 1] + 1, cur_vec[i] - cur_vec[i + 1]) + " ";
    }

    str += s.substr(cur_vec[0] + 1, s.size() - cur_vec[0]);
    
    return str;
  } // can improve here. 
  
  
  
  void break_helper (const string& s, const vector<string>& wordDict, vector<vector<int>>& breaktree) {
    if (s.empty()) {
      return;
    }
    
    vector<bool> status(s.size(), false);

    for (size_t i = 0; i < s.size(); ++i) {
      for (size_t j = 0; j < wordDict.size(); ++j) {
	if (can_place(s, wordDict[j], i)) {
	  if (i + 1 == wordDict[j].size()) {
	    breaktree[i].push_back(-1);
	  } else if (i + 1 > wordDict[j].size() && !breaktree[i - wordDict[j].size()].empty()) {
	    breaktree[i].push_back(i - wordDict[j].size());
	  }
	}
      }
    }
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
