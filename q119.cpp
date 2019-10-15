class Solution {
public:
  vector<int> getRow(int rowIndex) {
    if (rowIndex < 0) {
      return {};
    }

    vector<int> result = {1};

    for (int i = 0; i < rowIndex; ++i) {
      next_pline(result);
    }

    return result;
  }

  void next_pline (vector<int>& input) {
    input.push_back(input.back());
    int temp_l = input[0];
    int temp_r = input[1];
    for (size_t i = 1; i < input.size() - 1; ++i) {
      int next_r = input[i + 1];
      int next_l = input[i];
      input[i] = temp_l + temp_r;
      temp_l = next_l;
      temp_r = next_r;
    }
  } 
};
