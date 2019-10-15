class Solution {
public:
  string countAndSay(const int& n) {
    if (n < 1) {
      return "";
    } if (n == 1) {
      return "1";
    }

    string result = "1";

    for (int i = 0; i < n - 1; ++i) {
      result = next_str(result);
    }

    return result;
  }

  string next_str (const string& s) {
    char store = s[0];
    int count = 1;
    string result;
        
    for (size_t i = 1; i < s.size(); ++i) {
      if (store == s[i]) {
	++count;
      } else {
	result += to_string(count) + store;
	store = s[i];
	count = 1;
      }
    }

    result += to_string(count) + store;

    return result;
  }
};
