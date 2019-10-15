class Solution {
public:
  bool isValid(string s) {
    vector<char> check;

    for (size_t i = 0; i < s.size(); ++i) {
      if (!check.empty() && check.back() < s[i] && s[i] - check.back() < 3) {
	check.pop_back();
      } else {
	check.push_back(s[i]);
      }
    }
    
    return (check.empty())? true : false;
  }
};
