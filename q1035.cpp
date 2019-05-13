class Solution {
public:
  int maxUncrossedLines(const vector<int>& A, const vector<int>& B) {
    // use const whenever possible
    // use size_t
    const size_t m = A.size();
    const size_t n = B.size();
    if (m == 0 || n == 0) {
      return 0;
    }
	  
    vector<vector<int>> matrix(m + 1, vector<int>(n + 1, 0));
    for (size_t i = 0; i < m; ++i) {
      for (size_t j = 0; j < n; ++j) {
	if (A[i] == B[j]) {
	  matrix[i + 1][j + 1] = 1;
	}
      }
    }

    for (size_t i = 1; i < m + 1; ++i) {
      for (size_t j = 1; j < n + 1; ++j) {
	matrix[i][j] = max(max(matrix[i - 1][j - 1] + matrix[i][j], matrix[i - 1][j]), matrix[i][j - 1]);
      }
    }
    
    return matrix[m][n];
  }
};
