class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    if (s1.empty()) {
      return (s2 == s3) ? true : false;
    } else if (s2.empty()) {
      return (s1 == s3) ? true : false; 
    }
          
    if (s1.size() + s2.size() != s3.size()) {
      return false;
    } 

    vector<vector<bool>> board(s1.size() + 1, vector<bool>(s2.size() + 1, false));

    for (size_t i = 1; i < board.size(); ++i) {
      if (s1[i - 1] == s3[i - 1]) {
	board[i][0] = true;
      } else {
	break;
      }
    }

    for (size_t j = 1; j < board[0].size(); ++j) {
      if (s2[j - 1] == s3[j - 1]) {
	board[0][j] = true;
      } else {
	break;
      }
    }

    
    for (size_t i = 1; i < board.size(); ++i) {
      for (size_t j = 1; j < board[i].size(); ++j) {
	if ((board[i - 1][j] && s1[i - 1] == s3[i + j -1]) || (board[i][j - 1] && s2[j - 1] == s3[i + j -1])) {
	  board[i][j] = true;
	}
      }
    }
 
    return board.back().back();
  }
};
