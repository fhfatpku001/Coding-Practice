
class Solution {
public:
  void setZeroes(vector<vector<int>>& matrix) {
    print_mat(matrix);

    if (matrix.empty() || matrix[0].empty()) {
      return;
    }

    bool v_zero = false;
    bool h_zero = false;

    for (size_t i = 0; i < matrix.size(); ++i) {
      if (matrix[i][0] == 0) {
	v_zero = true;
	break;
      }
    }

    for (size_t j = 0; j < matrix[0].size(); ++j) {
      if (matrix[0][j] == 0) {
	h_zero = true;
      }
    }
    
    for (size_t i = 1; i < matrix.size(); ++i) {
      for (size_t j = 0; j < matrix[i].size(); ++j) {
	if (matrix[i][j] == 0) {
	  matrix[i][0] = 0;
	  break;
	}
      }
    }

    for (size_t j = 1; j < matrix[0].size(); ++j) {
      for (size_t i = 0; i < matrix.size(); ++i) {
	if (matrix[i][j] == 0) {
	  matrix[0][j] = 0;
	  break;
	}
      }
    }

    for (size_t i = 1; i < matrix.size(); ++i) {
      for (size_t j = 1; j < matrix[0].size(); ++j) {
	if (matrix[i][0] == 0 || matrix[0][j] == 0) {
	  matrix[i][j] = 0;
	}
      }
    }

    if (h_zero) {
      for (size_t j = 0; j < matrix[0].size(); ++j) {
	matrix[0][j] = 0;
      }
    }

    if (v_zero) {
      for (size_t i = 0; i < matrix.size(); ++i) {
	matrix[i][0] = 0;
      }
    }

    print_mat(matrix);
  }

  void print_mat (const vector<vector<int>>& matrix) {
    for (size_t i = 0; i < matrix.size(); ++i) {
      for (size_t j = 0; j < matrix[i].size(); ++j) {
	cout << matrix[i][j] << " ";
      }
      cout << endl;
    }
  }
};
