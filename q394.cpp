class Solution {
public:
  string decodeString(const string& s) {
    if (s.empty()) {
      return "";
    }
    
    stack<pair<string, int>> st;
    st.push({"", 1});

    for (size_t i = 0; i < s.size(); ++i) {
      if (is_char(s[i])) {
	st.top().first += s[i];
      } else if (s[i] != ']') {
	size_t j = i + 1;

	while (s[j] != '[' && j < s.size()) {
	  ++j;
	}

	st.push({"", stoi(s.substr(i, j - i))});
	i = j;
      } else {
	// s[i] == ']';
	string temp;
	for (size_t j = 0; j < st.top().second; ++j) {
	  temp += st.top().first;
	}

	st.pop();
	st.top().first += temp;
      }
    }

    return st.top().first;
  }

  bool is_char (const char& c) {
    return ((c - 'a' >= 0 && c - 'a' < 26) || (c - 'A' >= 0 && c - 'A' < 26)) ? true : false;
  }
  
};
