class Solution {
public:
  void rotate(vector<vector<int>>& matrix) {
    int n = (int) matrix.size();
    if (n == 0) {
      return;
    }

    print_mat(matrix);
    
    if (n % 2 == 0) {
      for (int i = 0; i < n / 2; ++i) {
	for (int j = 0; j < n / 2; ++j) {
	  int temp = matrix[n - 1 - j][i];
	  matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
	  matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
	  matrix[j][n - 1 - i] = matrix[i][j];
	  matrix[i][j] = temp;
	}
      }
    } else {
      for (int i = 0; i < n / 2; ++i) {
	for (int j = 0; j <= n / 2; ++j) {
	  int temp = matrix[n - 1 - j][i];
	  matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
	  matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
	  matrix[j][n - 1 - i] = matrix[i][j];
	  matrix[i][j] = temp;
	}
      }
    }

    print_mat(matrix);
  }

  void print_mat (vector<vector<int>> matrix) {
    for (size_t i = 0; i < matrix.size(); ++i) {
      for (size_t j = 0; j < matrix[i].size(); ++j) {
	cout << matrix[i][j] << " ";
      }
      cout << endl;
    }
  }
};
