class Solution {
public:
  bool canCross(vector<int>& stones) {
    if (stones.size() < 2) {
      return false;
    }
    
    unordered_map<int, size_t> stonepos;
    // stonepos is used to store the position;
    for (size_t i = 0; i < stones.size(); ++i) {
      stonepos[stones[i]] = i;
    }

    vector<vector<bool>> mat(stones.size(), vector<bool> (stones.size(), false));

    if (stones[0] == 0 && stones[1] == 1) {
      mat[0][0] = 1;
      mat[0][1] = 1;
    } else {
      return false;
    }

    
    
    for (size_t i = 1; i < stones.size(); ++i) {
      for (size_t j = i + 1 ; j < stones.size(); ++j) {
	// stone[j] - stone[i]
	int k = stones[j] - stones[i]; // jump from i to j OK?
	// previously jump should be k - 1, k + 1, k.
	if (stonepos.count(stones[i] - k + 1)) {
	  size_t prev_pos = stonepos[stones[i] - k + 1];
	  // cur_pos = i;
	  if (mat[prev_pos][i]) {
	    mat[i][j] = true;
	  }
	}

	if (stonepos.count(stones[i] - k)) {
	  size_t prev_pos = stonepos[stones[i] - k];
	  // cur_pos = i;
	  if (mat[prev_pos][i]) {
	    mat[i][j] = true;
	  }
	}

	if (stonepos.count(stones[i] - k - 1)) {
	  size_t prev_pos = stonepos[stones[i] - k - 1];
	  // cur_pos = i;
	  if (mat[prev_pos][i]) {
	    mat[i][j] = true;
	  }
	}
      }
    }

    for (auto it : mat) {
      for (auto iit : it) {
	cout << iit << " ";
      }
      cout << endl;
    }

    cout << endl;
    
    for (size_t i = 0; i < stones.size(); ++i) {
      if (mat[i].back()) {
	return true;
      }
    }
    return false;
  }
};
