   
class Solution {
public:
  int trap(const vector<int>& height) {
    if (height.empty()) {
      return 0;
    }
    
    int top = height[0];
    vector<int> water(height.size(), 0);
    water[0] = height[0];
    
    for (size_t i = 1; i < height.size(); ++i) {
      if (water[i - 1] >= height[i]) {
	water[i] = water[i - 1];
      } else {
	water[i] = height[i];
	top = height[i];
      }
    }

    water.back() = height.back();
    
    int vol = 0;
    
    for (int r = (int) height.size() - 2; r >= 0; --r) {
      if (height[r] == top || height[r + 1] == top) {
	break;
      } else {
	water[r] = max(height[r], water[r + 1]);
      }
    }

    for (size_t i = 0; i < height.size(); ++i) {
      vol += water[i] - height[i];
    }

     return vol;
  }

  void print_vec (const vector<int>& nums) {
    for (auto it : nums) {
      cout << it << " ";
    }
    cout << endl;
  }
};
