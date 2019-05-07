class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> result;
    vector<int> nums;
    unordered_map<int,int> num_count_map;
    
    // store: boundary points to nums;
    // store: left boundary count +1;
    // store: right boundary count -1;
    for (auto it : intervals) {
      // it[0] and it[1]
      if (num_count_map.count(it[0])==0) {
	nums.push_back(it[0]);
	num_count_map[it[0]] = 1;
      } else {
	num_count_map[it[0]]++;
      }

      if (num_count_map.count(it[1])==0) {
	nums.push_back(it[1]);
	num_count_map[it[1]] = -1;
      } else {
	num_count_map[it[1]]--;
      }
    }

    sort(nums.begin(), nums.end());// sort boundary points from left to right
    int cur_sum;
    int pos;
    /* Construction of Intervals;
     * Each left boundary sum + 1, Each right boundary sum -1
     * Notice that we may have multiple boundary at same position 
     * Cur_sum is always a non-neg number, when it reaches 0, 
     * we close the interval and begin next search */
    for (int i = 0; i < nums.size(); ++i) {
      //init
      cur_sum = num_count_map[nums[i]];
      pos = i+1;
      while(cur_sum>0 && pos!=nums.size()) {
	cur_sum += num_count_map[nums[pos]]; 
	pos++;
      }
      // pos -1 is the right boundary. output.
      result.push_back({nums[i],nums[pos-1]});
      i = pos-1;
    }

    return result;
  }
};




int main( )
{
  Solution solve;
  vector<vector<int>> input = {{1,3},{2,6},{8,10},{15,18}};
  vector<vector<int>> output = solve.merge(input);

  for (auto it : output) {
    cout << endl;
    for (auto iit : it) {
      cout << iit << " ";
    }
  }

  
  return 0;
}
