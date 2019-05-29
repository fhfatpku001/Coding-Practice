class Solution {
public:
  vector<vector<int>> fourSum(const vector<int>& nums, const int target) {
    /*Instead of doing O(N^3) hash, we do some fancy jobs.:)
     * We define an unordered_map from sum to pair of position.
     * If we know the sum, we know exactly the position. 
     */
    vector<vector<int>> result;
    size_t size = nums.size();
    if (size < 4) return result;

    sort(nums.begin(), nums.end());
    
    unordered_map<int,list<pair<int,int>>> pair_pos_map; // map sum to target position.

    int sum;
    
    for (size_t i = 0; i < size - 1; ++i) {
      for (size_t j = i+1; j < size; ++j) {
	sum = nums[i]+nums[j];
	if (pair_pos_map.count(sum) == 0) {
	  list<pair<int,int>> li_same_sum_pairs; // create new list;
	  li_same_sum_pairs.push_back({i,j});
	  pair_pos_map[sum] = li_same_sum_pairs;
	} else {
	  pair_pos_map[sum].push_back({i,j});
	}
      }
    }
    
    list<pair<int,int>>::iterator it_pair;
    int k,l;
    int last;
    
    for (size_t i = 0; i < size -3; ++i) {
      for (size_t j = i+1; j < size - 2; ++j) {
	sum = nums[i]+nums[j];
	if (pair_pos_map.count(target - sum)>0) {
	  it_pair = pair_pos_map[target-sum].begin();
	  while (it_pair!=pair_pos_map[target-sum].end()) {
	    k = it_pair->first;
	    l = it_pair->second;
	    if (k > j) {
	      if (result.size()==0) {
		result.push_back({nums[i],nums[j],nums[k],nums[l]});
	      } else {
		last = result.size()-1;
		vector<int> v = {nums[i],nums[j],nums[k],nums[l]};
		if (result[last]<v) {
		  result.push_back(v); 
		}
	      }
	    }
	    it_pair++;
	  }
	}
      }
    }
    
    return result;
  }
};



int main( )
{
  vector<int> v ={1, 0, -1, 0, -2, 2};
  
  Solution solve;

  int target = 0;

  vector<vector<int>> result = solve.fourSum(v, target);

  for (auto it: result) {
    cout << endl;
    for (auto iit:it) {
      cout << iit << " ";
    }
  }
    
  return 0;
}
