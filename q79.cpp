#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <list>
#include <cmath>
#include <sstream>
#include <climits>
using namespace std;

/* LeetCode Q79: Given a 2D board and a word, find if the word exists in the grid. The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once. 
 * Analysis:
 *   
 */

class Solution {
public:
  
  const vector<int> offset_row = {-1, 0, 1, 0};
  const vector<int> offset_col = {0, 1, 0, -1};
    
  // check if cur_pos is valid 
  
  bool can_place (const int& row, const int& col, const char& c, const vector<vector<char>>& board, const vector<vector<int>>& checker) {
    const int cur_pos = checker[row][col] - 1;

    if (cur_pos > 3) {
      return false;
    }
    
    const int next_row = row + offset_row[cur_pos];
    const int next_col = col + offset_col[cur_pos];

    if (next_row < 0 || next_col < 0 || next_row >= board.size() || next_col >= board[row].size()) {
      return false;
    } 
    
    return (board[next_row][next_col] == c && checker[next_row][next_col] == 0) ? true : false;
  }

  // cur_pos = checker - 1;
  void place_next_available (const int& row, const int& col, stack<pair<int,int>>& st, vector<vector<int>>& checker) {
    const int pos = checker[row][col] - 1;
    const int next_row = row + offset_row[pos];
    const int next_col = col + offset_col[pos];
    st.push({next_row, next_col});
    checker[next_row][next_col] = 1;
    ++checker[row][col];
  }

  void remove_top (stack<pair<int,int>>& st, vector<vector<int>>& checker) {
    // modify the stack and checker;
    // when removed, set checker to be original;
    checker[st.top().first][st.top().second] = 0;
    st.pop();
  }

  void print_checker (vector<vector<int>>& checker) {
    cout << "checker"<< endl;
    for (size_t m = 0; m < checker.size(); ++m) {
      cout << endl;
      for (size_t n = 0; n < checker[0].size(); ++n) {
	cout << checker[m][n] << " ";
      }
    }
  }
  
  bool exist(vector<vector<char>>& board, string word) {
    if (word.empty()) {
      return true;
    } else if (board.empty() || board[0].empty()) {
      return false;
    }
    
    stack<pair<int,int>> st;
    vector<vector<int>> checker(board.size(), vector<int>(board[0].size(), 0));

    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
	if (board[i][j] == word[0]) {
	  st.push({i,j});
	  checker[i][j] = 1;
	  size_t pos_word = 1;
	  
	  while (!st.empty()) {
	    if (pos_word == word.size()) {
	      return true;
	    }
	    
	    if (can_place(st.top().first, st.top().second, word[pos_word], board, checker)) {
	      place_next_available(st.top().first, st.top().second, st, checker);
	      ++pos_word;

	    } else {
	      if (checker[st.top().first][st.top().second] >= 5) {
		// remove;
		remove_top(st, checker);
		--pos_word;
	      } else {
		++checker[st.top().first][st.top().second];
	      }
	    }
	  }
	}
      }
    }
    return false;
  }

  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    vector<string> result;
    for (size_t i = 0; i < words.size(); ++i) {
      if (exist(board, words[i])) {
	result.push_back(words[i]);
      }
    }

    return result;
  }
};
 
int main()
{   
  Solution solve;

  vector<vector<char>> board = {{'A','B','C','E'},
				{'S','F','C','S'},
				{'A','D','E','E'}};

  vector<vector<char>> board2 = {{'E'},
				 {'S'}};
  
  string word = "ABCCED";

  cout << solve.exist(board, word) << endl;
  
  return 0;
}
 














 







