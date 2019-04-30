class Solution {
public:
  int circle (int x){
    // Get circular position, should return postive num.
    // Example: -1 return 9, 15 return 5;
    x= x%10;
    return (x < 0)? x+10 : x;
  }
  
  int openLock(vector<string>& deadends, string target) {
    /*
     Geometric Interpretation:
     We consider all Wheels combination as coordinates of a four-dimensional toroidal grid-diagram. Each wheel represent a dimension. 
     1) A badend is a X-point (non-touchable) on the grid.
     2) A path from the (0,0,0,0) to target = (t1,t2,t3,t4) corresponds to a way move the wheel.
     3) The question ask us to find the "Shortest Path" connecting init point to target point. 
     
     Algorithm Choice (BFS):
     BFS is an algorithm finding shortest path in a "Graph" or "Geomtric objects". 
     
     1): We construct the four-dimensional toroidal grid (initialized with "0").
     2): Store the badend on the grid. (I prefer "-1". As the question asked if not reachable, return -1);
     3): BFS, return the val at the target position;
     */

    // Step 1: toroidal grid initialization.
    vector<int> one_dim_grid;
    vector<vector<int>> two_dim_grid;
    vector<vector<vector<int>>> three_dim_grid;
    vector<vector<vector<vector<int>>>> four_dim_grid;
    one_dim_grid.resize(10, 0);
    two_dim_grid.resize(10, one_dim_grid);
    three_dim_grid.resize(10, two_dim_grid);
    four_dim_grid.resize(10, three_dim_grid);
    // Step 2: store the bad_end value;

    int a,b,c,d; // four coordinates;
    
    for (int i = 0; i < deadends.size(); ++i) {
      a = deadends[i][0] - '0';
      b = deadends[i][1] - '0';
      c = deadends[i][2] - '0';
      d = deadends[i][3] - '0';
      four_dim_grid[a][b][c][d] = -1; 
    }

    int t_a,t_b,t_c,t_d; // four coordinates of target.
    t_a = target[0] - '0';
    t_b = target[1] - '0';
    t_c = target[2] - '0';
    t_d = target[3] - '0';
    if (four_dim_grid[t_a][t_b][t_c][t_d] == -1) return -1;
    
    
    // Step 3: BFS; stop when queue empty or target pos found;
    
    vector<int> grid_pos,temp;
    grid_pos.resize(4,0);
    queue<vector<int>> q_BFS;
    if (four_dim_grid[0][0][0][0] == 0) {
       q_BFS.push(grid_pos);
    }
    
    while (!q_BFS.empty()) {
      grid_pos = q_BFS.front();
      a = grid_pos[0];
      b = grid_pos[1];
      c = grid_pos[2];
      d = grid_pos[3];

      //cout << a  << b << c << d << endl;
      //cout << " val is : " << four_dim_grid[a][b][c][d]<< endl;
      
      if (a == t_a && b == t_b && c == t_c && d == t_d) return four_dim_grid[a][b][c][d];
      // Check four ajacent tile;
      for (int i  = 0; i < 4; ++i) {
	temp = grid_pos;
	temp[i] = circle(temp[i]+1); // dont care first tile is zero.
	// found 0 tile, assign val and push in;
	if(four_dim_grid[temp[0]][temp[1]][temp[2]][temp[3]] == 0) {
	  four_dim_grid[temp[0]][temp[1]][temp[2]][temp[3]] = four_dim_grid[a][b][c][d] + 1;
	  q_BFS.push(temp);
	}

	temp = grid_pos;
	temp[i] = circle(temp[i]-1); // another direction;

	if(four_dim_grid[temp[0]][temp[1]][temp[2]][temp[3]] == 0) {
	  four_dim_grid[temp[0]][temp[1]][temp[2]][temp[3]] = four_dim_grid[a][b][c][d] + 1;
	  q_BFS.push(temp);
	}
	
      }

      q_BFS.pop();
    }
    
    
    
    // Final Step , return val at target position;
    if (four_dim_grid[t_a][t_b][t_c][t_d] == 0) return -1;
    return four_dim_grid[t_a][t_b][t_c][t_d];
  }
};
