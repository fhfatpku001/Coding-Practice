class Solution {
public:
  vector<string> letterCombinations(const string& digits) {
    const vector<string> button_map ={"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> result;

    for (size_t i = 0; i < digits.size(); ++i) {
      const string& cur_str = button_map[digits[i] - '1'];
      const size_t size = result.size();
      
      if (size == 0) {
	for (size_t j = 0; j < cur_str.size(); ++j) {
	  string stemp(1, cur_str[j]);
	  result.push_back(stemp);
	}
      } else {
	for (size_t k = 0; k < size; ++k) {
	  for (size_t j = 1; j < cur_str.size(); ++j) {
	    string str = result[k];
	    str.push_back(cur_str[j]);
	    result.push_back(str);
	  }
	  result[k].push_back(cur_str[0]);
	}
      }
    }

    return result;
  }
};
