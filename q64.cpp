class Solution {
public:
  int minPathSum(vector<vector<int>>& grid) {
    if (grid.empty() || grid[0].empty()) {
      return 0;
    }

    for (size_t i = 1; i < grid.size(); ++i) {
      grid[i][0] += grid[i - 1][0];
    }

    for (size_t j = 1; j < grid[0].size(); ++j) {
      grid[0][j] += grid[0][j - 1];
    }

    for (size_t i = 1; i < grid.size(); ++i) {
      for (size_t j = 1; j < grid[i].size(); ++j) {
	grid[i][j] += min(grid[i - 1][j], grid[i][j -1]);
      }
    }

    return grid.back().back();
  }
};
