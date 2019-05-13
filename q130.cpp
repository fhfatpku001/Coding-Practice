
class Solution {
	
// put public function in front of private
 // lets make sample comments	
  // Helper function with depth first search on the board	
  // @param: visited - input/output matrix marking the visited pos on the board	
  // @param: board   - input board matrix
  // @param: row     - index of the row for searching starting point
  // @param: col     - index of the col for searching starting point
  void helper_DFS (vector<vector<bool>>& visited, const vector<vector<char>>& board, const int row, const int col) {
    /*We mark all connected points as visited O points*/
    stack<pair<int,int>> st;
    visited[row][col] = true;
    st.push({row,col});
    
    int row_size = board.size();
    if (row_size == 0) return;
    int col_size = board[0].size();
    if (col_size == 0) return;
     
    int i,j; // store cur_pos;
    while (!st.empty()) {
      // check adjacent not visited tiles, mark it.put in
      i = st.top().first;
      j = st.top().second;
      if (i>0 && board[i-1][j] == 'O' && visited[i-1][j] == false) {
	st.push({i-1,j});
	visited[i-1][j] = true;
      } else if (j>0 && board[i][j-1] == 'O' && visited[i][j-1] == false) {
	st.push({i,j-1});
	visited[i][j-1] = true;
      } else if (i < row_size-1 && board[i+1][j] == 'O'&& visited[i+1][j] == false) {
	st.push({i+1,j});
	visited[i+1][j] = true;
      } else if (j < col_size-1 && board[i][j+1] == 'O' && visited[i][j+1] == false) {
	st.push({i,j+1});
	visited[i][j+1] = true;
      } else {
	st.pop();
      } 
    }
  }
  
public:
  void solve(vector<vector<char>>& board) {
    /*Strategy: Find all branches, which connects to the boundary of the board, 
     * Marked as fixed, all other coordinate are X
     * This algorithm should have O(n^2) extra space and O(n^2)-time*/

    // get the board size;
    int row_size = board.size();
    if (row_size == 0) return;
    int col_size = board[0].size();
    if (col_size == 0) return;

    // search fixed, not_visited O markings.
    vector<bool> t_v_b;
    vector<vector<bool>> visited;
    t_v_b.resize(col_size,false);
    visited.resize(row_size, t_v_b);

    // Search all boundary. 
    for (int i = 0; i < row_size; ++i) {
      if (board[i][0] == 'O' && visited[i][0] == false) {
	helper_DFS(visited, board, i, 0);
      }//left
      if (board[i][col_size-1] == 'O' && visited[i][col_size-1] == false) {
	helper_DFS(visited, board, i, col_size-1);
      }//right
    }

    for (int j = 1; j < col_size-1; ++j) {
      if (board[0][j] == 'O' && visited[0][j] == false) {
	helper_DFS(visited, board, 0, j);
      }
      if (board[row_size-1][j] == 'O' && visited[row_size-1][j] == false) {
	helper_DFS(visited, board, row_size-1, j);
      }
    }

    // fill the board
    for (int i = 0; i < row_size; ++i) {
      for (int j = 0; j < col_size; ++j) {
	if (visited[i][j]==false) {
	  board[i][j] = 'X';
	}
      }
    }
    
  }
};


int main( )
{
  Solution solve;

  vector<vector<char>> board = {{'X','O','X','O','X','O'},{'O','X','O','X','O','X'},{'X','O','X','O','X','O'},{'O','X','O','X','O','X'}};



  
  solve.solve(board);

  for (auto it : board) {
    cout << endl;
    for (auto iit: it) {
      cout << iit << " ";
    }
  }
  
  return 0;
}
