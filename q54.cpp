class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

      // get the size of matrix;

      int m = 0, n = 0;
      m = matrix.size();
      if (m != 0) {
	n = matrix[0].size();
      }

      // set the initial search condition

      int t = 0, b = m-1;
      int l = 0, r = n-1;
      int k = 0; // k % 4 determine the spiral search case.
      
      vector<int> result;

      while (b >= t && r >= l) {

	if (k == 0) {
	  // right:
	  for (int i = l; i <= r; ++i) {
	    result.push_back(matrix[t][i]);
	  }
	  t++;
	  k++;
	} else if (k == 1) {
	  //Down
	  for (int i = t; i <= b; ++i) {
	    result.push_back(matrix[i][r]);
	   }
	  r--;
	  k++;
	} else if (k == 2) {
	  //left
	  for (int i = r; i >= l; --i) {
	     result.push_back(matrix[b][i]);
	   }
	  b--;
	  k++;
	  
	} else {
	  //up
	  for (int i = b; i >= t; --i) {
	    result.push_back(matrix[i][l]);
	   }
	  l++;
	  k -= 3;
	}
	
      }

      return result;
    }
};

class Solution {
public:
  vector<int> spiralOrder(const vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
      return {};
    }

    int l = 0, r = (int) matrix[0].size() - 1;
    int b = 0, e = (int) matrix.size() - 1;

    int dir = 0; // direction {0, 1, 2, 3};
    vector<int> result;
    
    while ((b <= e) && (l <= r)) {
      if (dir == 0) {
	for (int j = l; j <= r; ++j) {
	  result.push_back(matrix[b][j]);
	}

	++b;
      } else if (dir == 1) {
	for (int i = b; i <= e; ++i) {
	  result.push_back(matrix[i][r]);
	}
	
	--r;
      } else if (dir == 2) {
	for (int j = r; j >= l; --j) {
	  result.push_back(matrix[e][j]);
	}

	--e;
      } else {
	for (int i = e; i >= b; --i) {
	  result.push_back(matrix[i][l]);
	}

	++l;
      }

      dir = (dir + 1) % 4;
    }

    return result;
  }
};
