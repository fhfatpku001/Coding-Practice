class Solution {
public:
  bool isValidSudoku(const vector<vector<char>>& board) {
    for (size_t i = 0; i < 9; ++i) {
      if (!check_box(board, i, i + 1, 0, 9)) {
	return false;
      }
      
      if (!check_box(board, 0, 9, i, i + 1)) {
	return false;
      }
    }

    for (size_t i = 0; i < 3; ++i) {
      for (size_t j = 0; j < 3; ++j) {
	if (!check_box(board, 3*i, 3*i + 3, 3* j, 3*j + 3)) {
	  return false;
	}
      }
    }
    
    return true;
  }

  bool check_box (const vector<vector<char>>& board, size_t r_b, size_t r_e, size_t c_b, size_t c_e) {
    vector<bool> vec(9, 0);

    for (size_t i = r_b; i < r_e; ++i) {
      for (size_t j = c_b; j < c_e; ++j) {
	char c = board[i][j];
	if (c != '.') {
	  if (vec[c - '1']) {
	    return false;
	  } else {
	    vec[c - '1'] = true;
	  }
	} 
      }
    }
    
    return true;
  }
};
