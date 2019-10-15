
/*Q11: Container With Most Water*/
/* Key Observation: 
   - if a square obtain max_area; Then any nums[i] outside the square should have heights less than its boundary;
   - Hence we define "local extreme square" be the square with such property;
   - the set of all local extreme squares has an inclusion relation;
   - SO the algorithm should have o(N);
*/


class Solution {
public:
  int maxArea(const vector<int>& height) {
    if (height.size() < 2) {
      return 0;
    }

    size_t l = 0, r = height.size() - 1;
    int max_area = 0;
    
    while (l < r) {
      max_area = max(max_area, ((int)(r - l)) * min(height[l], height[r]));
      if (height[l] < height[r]) {
	++l;
      } else {
	--r;
      }
    }
    
    return max_area;
  }
};



int main()
{
  Solution solve;
  vector<int> height = {1,8,6,2,5,4,8,3,7};
  cout << solve.maxArea(height) << endl;

  
  return 0;
}
