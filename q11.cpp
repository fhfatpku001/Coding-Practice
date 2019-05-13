/*Solution Explanation:
 * Proof: if a container has higher volumn, it's shorter edge must included inside the interval. */


class Solution {
public:
  int maxArea(const vector<int>& height) {
    if (!height.empty()) {
      return 0;
    }
    int max_area = 0;
    int l = 0;
    int r = height.size() - 1;
    while (l < r) {
      // calculate cur_area;
      max_area = max(max_area, (r-l)*min(height[l],height[r]));
      if (height[l] < height[r]) {
        ++l;
      } else {
        r--;
      }
    }
    return max_area;
  }
};
