class Solution {
public:
  int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
      return 0;
    }

    int max_length = 0;
    vector<vector<int>> A_mat(matrix.size(), vector<int>(matrix[0].size(), 0));
    
    for (size_t i = 0; i < matrix.size(); ++i) {
      if (matrix[i][0] == '1') {
	A_mat[i][0] = 1;
	max_length = 1;
      }
    }
    
    for (size_t j = 0; j < matrix[0].size(); ++j) {
      if (matrix[0][j] == '1') {
	A_mat[0][j] = 1;
	max_length = 1;
      }
    }

    for (size_t i = 1; i < matrix.size(); ++i) {
      for (size_t j = 1; j < matrix[i].size(); ++j) {
	if (matrix[i][j] != '0') {
	  A_mat[i][j] = min(min(A_mat[i - 1][j], A_mat[i][j - 1]), A_mat[i - 1][j - 1]) + 1;
	  if (A_mat[i][j] > max_length) {
	    max_length = A_mat[i][j];
	  }
	}
      }
    }

    
    return max_length * max_length;
  }
};
