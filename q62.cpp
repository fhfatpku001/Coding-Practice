class Solution {
public:
  int uniquePaths(int m, int n) {
    if (m < 1 || n < 1) {
      return 0;
    }

    vector<vector<int>> matrix(m, vector<int>(n, 1));

    for (size_t i = 1; i < matrix.size(); ++i) {
      for (size_t j = 1; j < matrix[i].size(); ++j) {
	matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
      }
    }

    return matrix[m - 1][n - 1];
  }
};
