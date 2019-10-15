class Solution {
public:
  string convert(const string& s, const int& row) {
    if (row < 2) {
      return s;
    }

    string result;
    // print the first row;
    for (size_t j = 0; 2 * j * (row - 1) < s.size(); ++j) {
      result.push_back(s[2 * j * (row - 1)]);
    }
    // print the intermediate rows;

    for (size_t i = 1; i + 1 < row; ++i) {
      for (size_t j = 0; 2 * (row - 1) * j < s.size() + i; ++j) {
	if (2 * (row - 1) * j >= i) {
	  result.push_back(s[2 * (row - 1) * j - i]);
	}

	if (2 * (row - 1) * j + i< s.size()) {
	  result.push_back(s[2 * (row - 1) * j + i]);
	}
      }
    }

    // print the last row;
    for (size_t j = 0; (2 * j + 1) * (row - 1) < s.size(); ++j ) {
      result.push_back(s[(2 * j + 1) * (row - 1)]);
    }

    return result;
  }
};
