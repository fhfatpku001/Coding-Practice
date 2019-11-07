class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    if (coins.empty()) {
      return (amount == 0) ? 0 : -1;
    } else {
      if (amount == 0) {
	return 0;
      } else if (amount < 0) {
	return -1;
      }
    }

    vector<int> vec;
    vec.push_back(0);
    sort(coins.begin(), coins.end());
    
    for (int i = 1; i <= amount; ++i) {
      vec.push_back(-1);
      for (size_t j = 0; j < coins.size(); ++j) {
	if (coins[j] > i) {
	  break;
	}

	int x = vec[i - coins[j]];
	if (x >= 0) {
	  // update;
	  if (vec[i] == -1) {
	    vec[i] = x + 1;
	  } else {
	    vec[i] = min(x + 1, vec[i]);
	  }
	}
      }
    }
    
    return vec.back();
  }
};
