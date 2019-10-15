class Solution {
public:
  vector<vector<string>> solveNQueens(int n) {
    if (n < 1) {
      return {};
    }

    vector<vector<string>> result;
    vector<vector<int>> att_board(n, vector<int>(n, 0));
    vector<int> placed_queens;
    
    backtracking(result, att_board, placed_queens);

    return result;
  }

  void backtracking (vector<vector<string>>& result, vector<vector<int>>& att_board, vector<int>& placed_queens) {
    if (placed_queens.size() == att_board.size()) {
      result.push_back(print_queens(placed_queens));
    } else {
      int cur_row = placed_queens.size();

      for (int j = 0; j < att_board[cur_row].size(); ++j) {
	if (can_place_queen(att_board, cur_row, j)) {
	  place_queen(att_board, cur_row, j);
	  placed_queens.push_back(j);
	  backtracking(result, att_board, placed_queens);
	}
      } 
    }

    if (!placed_queens.empty()) {
      remove_queen(att_board, placed_queens.size() - 1, placed_queens.back());
      placed_queens.pop_back();
    }
  }

  vector<string> print_queens (const vector<int>& placed_queens) {
    vector<string> output;

    for (size_t i = 0; i < placed_queens.size(); ++i) {
      string s;

      for (int j = 0; j < placed_queens.size(); ++j) {
	if (j == placed_queens[i]) {
	  s.push_back('Q');
	} else {
	  s.push_back('.');
	}
      }

      output.push_back(s);
    }

    return output;
  }

  void place_queen (vector<vector<int>>& att_board, const int& row_pos, const int& col_pos) {
    //update the matrix
    for (size_t i = 0; i < att_board.size(); ++i) {
      att_board[i][col_pos]++;
    }// vertically;

    for (size_t j = 0; j < att_board[row_pos].size(); ++j) {
      att_board[row_pos][j]++;
    }// horizontally;

    for (int k = 0; k + row_pos < att_board.size() && k + col_pos < att_board[row_pos].size(); ++k) {
      att_board[k + row_pos][k + col_pos]++;
    }

    for (int k = 0; k + row_pos < att_board.size() &&  col_pos - k >= 0; ++k) {
      att_board[k + row_pos][col_pos - k]++;
    }

    for (int k = 0; row_pos - k >= 0 && col_pos - k >= 0; ++k) {
      att_board[row_pos - k][col_pos - k]++;
    }

    for (int k = 0; row_pos - k >= 0 && k + col_pos < att_board[row_pos].size(); ++k) {
      att_board[row_pos - k][k + col_pos]++;
    }
    
  }

  void remove_queen (vector<vector<int>>& att_board, const int& row_pos, const int& col_pos) {
    for (size_t i = 0; i < att_board.size(); ++i) {
      att_board[i][col_pos]--;
    }// vertically;

    for (size_t j = 0; j < att_board[row_pos].size(); ++j) {
      att_board[row_pos][j]--;
    }// horizontally;

    for (int k = 0; k + row_pos < att_board.size() && k + col_pos < att_board[row_pos].size(); ++k) {
      att_board[k + row_pos][k + col_pos]--;
    }

    for (int k = 0; k + row_pos < att_board.size() &&  col_pos - k >= 0; ++k) {
      att_board[k + row_pos][col_pos - k]--;
    }

    for (int k = 0; row_pos - k >= 0 && col_pos - k >= 0; ++k) {
      att_board[row_pos - k][col_pos - k]--;
    }

    for (int k = 0; row_pos - k >= 0 && k + col_pos < att_board[row_pos].size(); ++k) {
      att_board[row_pos - k][k + col_pos]--;
    }
  }

  bool can_place_queen (const vector<vector<int>>& att_board, const int& row_pos, const int& col_pos) {
    return (att_board[row_pos][col_pos] == 0) ? true : false;
  }
};
