class Solution {
public:
  int minimumTotal(vector<vector<int>>& triangle) {
    if (triangle.empty()) {
      return 0;
    } 

    for (size_t i = 1; i < triangle.size(); ++i) {
      triangle[i][0] += triangle[i - 1][0];
      triangle[i].back() += triangle[i - 1].back();
      for (size_t j = 1; j + 1 < triangle[i].size(); ++j) {
	triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
      }
    }

    int min_sum = triangle.back()[0];

    for (size_t j = 0; j < triangle.back().size(); ++j) {
      if (triangle.back()[j] < min_sum) {
	min_sum = triangle.back()[j];
      }
    }

    return min_sum;
  }
};
