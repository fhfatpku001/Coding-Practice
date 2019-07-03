
class Solution {
public:
  /*Q40 : Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
    Each number in candidates may only be used once in the combination.
    Note:
    - All numbers (including target) will be positive integers.
    - The solution set must not contain duplicate combinations.*/

  /* Analysis: 
     First, we do some prepartion work. We should deal with dulplicates. We construct a vector<int> unique_cands, together with a map which counts the occurancy. Then we should sort the unique_cands;
     Second, we construct vector<int> count_unique_cands. Each vector<int> cand_vec = (a_0,...,a_n) denote a vector with unique_cands[i] appears a_i; The next cand_vec should be the NEXT one greater than cand_vec;
     
  */

  vector<int> convert (const vector<int>& unique_cands, const vector<int>& cur_cands) {
    vector<int> result;

    for (size_t i = 0; i < cur_cands.size(); ++i) {
      for (int j = 0; j < cur_cands[i]; ++j) {
	result.push_back(unique_cands[i]);
      }
    }

    return result;
  }
  
  vector<vector<int>> combinationSum2(const vector<int>& candidates, const int& target) {
    vector<vector<int>> result;
    if (candidates.empty()) {
      return result; 
    }
    
    vector<int> unique_cands, count_unique_cands;
    unordered_map<int,int> map_count_unique_cands; 
    
    for (size_t i = 0; i < candidates.size(); ++i) {
      if (map_count_unique_cands.count(candidates[i]) == 0) {
	map_count_unique_cands[candidates[i]] = 1;
	unique_cands.push_back(candidates[i]);
      } else {
	++map_count_unique_cands[candidates[i]];
      }
    }

    sort(unique_cands.begin(), unique_cands.end());
    count_unique_cands.resize(unique_cands.size(), 0);
    
    for (size_t i = 0; i < count_unique_cands.size(); ++i) {
      count_unique_cands[i] = map_count_unique_cands[unique_cands[i]];
    }
    
    int cur_sum = 0;
    int first_pos = 0;
    int cur_target = target;
    vector<int> cur_cands(unique_cands.size(), 0);
    cur_cands[0] = 1;
    cur_sum = unique_cands[0];
    
    while (unique_cands[first_pos] <= target) {
      if (cur_sum == target) {
	result.push_back(convert(unique_cands, cur_cands));
	// next_cand;
      } 
      
    }
    

    
    return result;
  }
};
 
int main()
{   
  Solution solve;
    
  return 0;
}
 




