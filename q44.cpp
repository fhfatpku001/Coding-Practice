class Solution {
public:
  bool isMatch(string s, string p) {
    // s, string, p pattern;
    vector<vector<bool>> match_card(p.size() + 1, vector<bool>(s.size() + 1, false));

    for (size_t i = 0; i < p.size(); ++i) {
      for (size_t j = 0; j < s.size() + 1; ++j) {
	if (j < s.size()) {
	  match_card[i][j] = is_same(p[i], s[j]);
	} else if (j == s.size() && p[i] == '*') {
	  match_card[i][j] = true;
	}
      }
    }

    match_card.back().back() = true;
    
    
    vector<vector<bool>> path_card(p.size() + 1, vector<bool>(s.size() + 1, false));

    if (p[0] == '*') {
      for (size_t j = 0; j < s.size() + 1; ++j) {
	path_card[0][j] = true;
	if (!p.empty() && match_card[1][j]) {
	  path_card[1][j] = true;
	}
      }
    } else {
      path_card[0][0] = match_card[0][0];
      if (!p.empty() && !s.empty() && match_card[0][0] && match_card[1][1]) {
	path_card[1][1] = true;
      }
    }


    for (size_t i = 1; i < p.size(); ++i) {
      for (size_t j = 0; j < s.size(); ++j) {
	if (p[i] == '*' && path_card[i][j]) {
	  path_card[i][j + 1] = true;
	  if (match_card[i + 1][j]) {
	    path_card[i + 1][j] = true;
	  }
	 
	} else if (path_card[i][j] && match_card[i+1][j+1]) {
	  path_card[i + 1][j + 1] = true;
	}
      }

      if (p[i] == '*' && path_card[i].back()) {
	path_card[i + 1].back() = true;
      }
    }


    
    return path_card.back().back();
  }

  bool is_same(char a, char b) {
    return (a == b || a == '?' || a == '*') ? true : false;
  }
};
