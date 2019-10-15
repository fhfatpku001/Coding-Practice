class Solution {
public:
  vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
    if (queens.empty() || king.size() < 2) {
      return {};
    }

    vector<int> dir_distance(8, 0);
    vector<int> cor_pos(8, -1); 
    int k_row = king[0];
    int k_col = king[1];
    
    for (size_t i = 0; i < queens.size(); ++i) {
      int q_row = queens[i][0];
      int q_col = queens[i][1];

      if (k_col == q_col) {
	// 0,4;
	if (q_row > k_row) {
	  if (dir_distance[4] == 0) {
	    dir_distance[4] = q_row - k_row;
	    cor_pos[4] = i;
	  } else if (dir_distance[4] > q_row - k_row) {
	    dir_distance[4] = q_row - k_row;
	    cor_pos[4] = i;
	  }
	} else {
	  if (dir_distance[0] == 0) {
	    dir_distance[0] = k_row - q_row;
	    cor_pos[0] = i;
	  } else if (dir_distance[0] > k_row - q_row) {
	    dir_distance[0] = q_row - k_row;
	    cor_pos[0] = i;
	  }
	}
      } else if (k_row == q_row) {
	// 2. 6
	if (q_col > k_col) {
	  // 2;
	  if (dir_distance[2] == 0 || dir_distance[2] > q_col - k_col) {
	    dir_distance[2] = q_col - k_col;
	    cor_pos[2] = i;
	  } 
	} else {
	  if (dir_distance[6] == 0 || dir_distance[6] > k_col - q_col) {
	    dir_distance[6] = k_col - q_col;
	    cor_pos[6] = i;
	  }
	}
      } else if (k_col - q_col == k_row - q_row) {
	// 3, 7;
	if (q_col > k_col) {
	  // 2;
	  if (dir_distance[3] == 0 || dir_distance[3] > q_col - k_col) {
	    dir_distance[3] = q_col - k_col;
	    cor_pos[3] = i;
	  } 
	} else {
	  if (dir_distance[7] == 0 || dir_distance[7] > k_col - q_col) {
	    dir_distance[7] = k_col - q_col;
	    cor_pos[7] = i;
	  }
	}
		
      } else if (k_col - q_col == q_row - k_row) {
	// 1,5;
	if (q_col > k_col) {
	  // 2;
	  if (dir_distance[1] == 0 || dir_distance[1] > q_col - k_col) {
	    dir_distance[1] = q_col - k_col;
	    cor_pos[1] = i;
	  } 
	} else {
	  if (dir_distance[5] == 0 || dir_distance[5] > k_col - q_col) {
	    dir_distance[5] = k_col - q_col;
	    cor_pos[5] = i;
	  }
	}
      }
    }

    vector<vector<int>> result;
    for (size_t i = 0; i < cor_pos.size(); ++i) {
      if (cor_pos[i] >= 0) {
	result.push_back(queens[cor_pos[i]]);
      }
    }

    return result;
   }
};
 
int main()
{   
  Solution solve;
  vector<vector<int>> queens = {{5,6},{7,7},{2,1},{0,7},{1,6},{5,1},{3,7},{0,3},{4,0},{1,2},{6,3},{5,0},{0,4},{2,2},{1,1},{6,4},{5,4},{0,0},{2,6},{4,5},{5,2},{1,4},{7,5},{2,3},{0,5},{4,2},{1,0},{2,7},{0,1},{4,6},{6,1},{0,6},{4,3},{1,7}};
  vector<int> king = {3,4};
  
  vector<vector<int>> output = solve.queensAttacktheKing(queens, king); 

  for (auto it : output) {
    for (auto iit : it) {
      cout << iit << " ";
    }
    cout << endl;
  }
  cout << endl;
  
  return 0;
}
