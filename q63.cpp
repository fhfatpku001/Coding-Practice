class Solution {
public:
  int uniquePathsWithObstacles(const vector<vector<int>>& obstacleGrid) {
    if (obstacleGrid.empty() || obstacleGrid[0].empty()) {
      return 0;
    }

    vector<vector<long long>> countGrid(obstacleGrid.size(), vector<long long>(obstacleGrid[0].size(), 0));
    
    for (size_t i = 0; i < obstacleGrid.size(); ++i) {
      if (obstacleGrid[i][0] == 1) {
	break;
      }

      countGrid[i][0] = 1;
    }

    for (size_t j = 0; j < obstacleGrid[0].size(); ++j) {
      if (obstacleGrid[0][j] == 1) {
	break;
      }

      countGrid[0][j] = 1;
    }

    
    for (size_t i = 1; i < obstacleGrid.size(); ++i) {
      for (size_t j = 1; j < obstacleGrid[i].size(); ++j) {
	if (obstacleGrid[i][j] == 1) {
	  countGrid[i][j] = 0;
	} else {
	  countGrid[i][j] = countGrid[i - 1][j] + countGrid[i][j - 1];
	}
      }
    }

   
    return countGrid.back().back();
  }

  void print_mat (const vector<vector<int>>& matrix) {
    for (size_t i = 0; i < matrix.size(); ++i) {
      for (size_t j = 0; j < matrix[0].size(); ++j) {
	cout << matrix[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }
};
