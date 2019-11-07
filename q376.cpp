class Solution {
public:
  int wiggleMaxLength(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    } else if (nums.size() == 1) {
      return 1;
    } 
      
    vector<int> wigseq;
    wigseq.push_back(nums.front());

    bool is_inc;
    
    for (size_t i = 1; i < nums.size(); ++i) {
      if (wigseq.back() == nums[i]) {
	continue;
      } else if (wigseq.back() < nums[i]) {
	if (wigseq.size() == 1) {
	  wigseq.push_back(nums[i]);
	  is_inc = true;
	} else {
	  if (is_inc) {
	    wigseq.back() = nums[i];
	  } else {
	    wigseq.push_back(nums[i]);
	    is_inc = true;
	  }
	}
      } else if (wigseq.back() > nums[i]) {
	if (wigseq.size() == 1) {
	  wigseq.push_back(nums[i]);
	  is_inc = false;
	} else {
	  if (is_inc) {
	    wigseq.push_back(nums[i]);
	    is_inc = false;
	  } else {
	    wigseq.back() = nums[i];
	  }
	}
      }
    }

    /*for (auto it : wigseq) {
      cout << it << " ";
    }
    cout << endl;*/
    
    return (int)wigseq.size();
  }
};
