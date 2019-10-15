// first sort the vector [1,1,1,2,2].
// in the backtracking search if the next pos is the same, we will not jump in the same number group;

class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    if (nums.empty()) {
      return {};
    } else if (nums.size() == 1) {
      return {nums};
    }

    sort(nums.begin(), nums.end());
    vector<bool> occupied(nums.size(), false);
    vector<int> cur_vec;
    vector<vector<int>> result;

    backtracking(result, nums, occupied, cur_vec);

    return result;
  }

  void print_vec (vector<int>& vec) {
    for (auto it : vec) {
      cout << it << " ";
    }
    cout << endl;
  }

  
  void backtracking (vector<vector<int>>& result, const vector<int>& nums, vector<bool>& occupied, vector<int>& cur_vec) {
    //print_vec(cur_vec);


    if (cur_vec.size() == nums.size()) {
      result.push_back(cur_vec);
    } else {
      bool first_ava_ele = true; 
      int cur_val;
	
      for (size_t i = 0; i < nums.size(); ++i) {
	if (!occupied[i]) {
	  if (first_ava_ele) {
	    cur_val = nums[i];
	    first_ava_ele = false;
	    occupied[i] = true;
	    cur_vec.push_back(nums[i]);
	    backtracking(result, nums, occupied, cur_vec);
	  } else {
	    if (cur_val == nums[i]) {
	      continue;
	    } else {
	      cur_vec.push_back(nums[i]);
	      cur_val = nums[i];
	      occupied[i] = true;
	      backtracking(result, nums, occupied, cur_vec);
	    }
	  }
	}
      }
    }

           // remove if non-empty;    
    if (!cur_vec.empty()) {
      /*int pos;
      
      for (size_t i = 0; i < nums.size(); ++i) {
	if (nums[i] == cur_vec.back() && occupied[i]) {
	  pos = i;
	}
      }

      occupied[pos] = false;
      cur_vec.pop_back();*/

      remove_last_element(cur_vec, occupied, nums);
    }
  }

  void remove_last_element (vector<int>& cur_vec, vector<bool>& occupied, const vector<int>& nums) {


    int l = 0;
    int r = nums.size();
    while (l < r - 1) {
      int mid = (r - l)/ 2 + l;
      if (nums[mid] < cur_vec.back()) {
	l = mid;
      } else if (nums[mid] > cur_vec.back()) {
	r = mid;
      } else {
	if (occupied[mid]) {
	  l = mid;
	} else {
	  r = mid;
	}
      }
    }

    int pos = l;
    occupied[pos] = false;
    cur_vec.pop_back();
    
  }
};
 
