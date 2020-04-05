class Solution {
public:
  int longestIncreasingPath(const vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
      return 0;
    }

    vector<vector<int>> max_steps_start_from_matrix(matrix.size(), vector<int>(matrix[0].size(),0));
    int global_max = 0;
    
    for (int i = 0; i < matrix.size(); ++i) {
      for (int j = 0; j < matrix[i].size(); ++j) {
	      if (max_steps_start_from_matrix[i][j] == 0) {
	        DFS(matrix, max_steps_start_from_matrix, i, j, global_max);
	      }
      }
    }

    return global_max;
  }

  void DFS (const vector<vector<int>>& matrix,
	    vector<vector<int>>& max_steps_start_from_matrix,
	    int row, int col, int& global_max) {
    int count_max_step = 0;
    if (row > 0 && matrix[row - 1][col] < matrix[row][col]) {
      if (max_steps_start_from_matrix[row - 1][col] == 0) {
	      DFS(matrix, max_steps_start_from_matrix, row - 1, col, global_max);
      }
      DFS(matrix, max_steps_start_from_matrix, row - 1, col, global_max);
      count_max_step = max(count_max_step, max_steps_start_from_matrix[row - 1][col]); 
    }
    if (row + 1 < matrix.size() && matrix[row + 1][col] < matrix[row][col]) {
      if (max_steps_start_from_matrix[row + 1][col] == 0) {
	      DFS(matrix, max_steps_start_from_matrix, row + 1, col, global_max);
      }
      count_max_step = max(count_max_step, max_steps_start_from_matrix[row + 1][col]);
    }
    if (col > 0 && matrix[row][col - 1] < matrix[row][col]) {
      if (max_steps_start_from_matrix[row][col - 1] == 0) {
	      DFS(matrix, max_steps_start_from_matrix, row, col - 1, global_max);
      }
      count_max_step = max(count_max_step, max_steps_start_from_matrix[row][col - 1]);
    }
    if (col + 1 < matrix[0].size() && matrix[row][col + 1] < matrix[row][col]) {
      if (max_steps_start_from_matrix[row][col + 1] == 0) {
	      DFS(matrix, max_steps_start_from_matrix, row, col + 1, global_max);
      }
      count_max_step = max(count_max_step, max_steps_start_from_matrix[row][col + 1]);
    }

    ++count_max_step;
    max_steps_start_from_matrix[row][col] = count_max_step;
    global_max = max(count_max_step, global_max);
  }
};
