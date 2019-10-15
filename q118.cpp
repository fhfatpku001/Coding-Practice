class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    if (numRows < 1) {
      return {};
    }

    vector<vector<int>> result = {{1}};

    for (int i = 1; i < numRows; ++i) {
      result.push_back(next_pline(result.back()));
    }

    return result;
  }

  vector<int> next_pline (const vector<int>& input) {
    vector<int> output(input.size() + 1, 0);
    output[0] = input[0];
    output.back() = input.back();
    
    for (size_t i = 1; i < input.size(); ++i) {
      output[i] = input[i] + input[i - 1];
    }

    return output;
  } 
};
