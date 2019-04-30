class Solution {
public:
  int maxUncrossedLines(vector<int>& A, vector<int>& B) {
    int m = A.size();
    int n = B.size();
    if (m == 0 || n == 0) return 0;
    vector<int> temp;
    temp.resize(n+1,0);
    vector<vector<int>> matrix;
    matrix.resize(m+1,temp);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
	if (A[i] == B[j]) matrix[i+1][j+1] = 1;
      }
    }

    for (int i = 1; i < m+1; ++i) {
      for (int j = 1; j < n+1; ++j) {
	matrix[i][j] = max(max(matrix[i-1][j-1]+matrix[i][j],matrix[i-1][j]),matrix[i][j-1]);
      }
    }
    
    return matrix[m][n];
  }
};
