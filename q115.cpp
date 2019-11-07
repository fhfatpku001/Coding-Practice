class Solution {
public:
  int numDistinct(string s, string t) {
    if (t.size() > s.size() || s.size() == 0 || t.size() == 0) {
      return 0;
    }

    vector<vector<long long>> board(t.size() + 1, vector<long long>(s.size() - t.size() + 1, 0));

    board[0][0] = 1;

    for (size_t i = 1; i < t.size() + 1; ++i) {
      if (s[i - 1] == t[i - 1] && board[i - 1][0] > 0) {
	board[i][0] = 1;
      } else {
	break;
      }
    }

    for (size_t j = 1; j < s.size() - t.size() + 1; ++j) {

	board[0][j] = 1;

    }

    for (size_t i = 1; i < t.size() + 1; ++i) {
      for (size_t j = 1; j < s.size() - t.size() + 1; ++j) {
	if (t[i - 1] == s[i + j - 1] ) {
	  board[i][j] += board[i - 1][j];
	}

	board[i][j] += board[i][j - 1];
      }
    }
   
    return board.back().back();
  }
};
