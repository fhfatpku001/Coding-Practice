class Solution {
public:
  vector<int> findOrder(const int& numCourses, vector<vector<int>>& prerequisites) {
    vector<int> result;

    while (!prerequisites.empty()) {
      vector<int> cand = find_root_courses(numCourses, prerequisites);
      
      if (cand.empty()) {
	return {};
      } else {
	result.insert(result.end(), cand.begin(), cand.end());
      }

      vector<bool> delete_num(numCourses, false);

      for (auto it : cand) {
	delete_num[it] = true;
      }

      vector<bool> reserved(prerequisites.size(), true);
      
      for (size_t i = 0; i < prerequisites.size(); ++i) {
	if (delete_num[prerequisites[i][1]]) {
	  reserved[i] = false;
	}
      }

      vector<vector<int>> new_preq;

      for (size_t i = 0; i < prerequisites.size(); ++i) {
	if (reserved[i]) {
	  new_preq.push_back(prerequisites[i]);
	}
      }

      prerequisites = new_preq;
    }

    vector<bool> visited(numCourses, false);

    for (auto it : result) {
      visited[it] = true;
    }
    
    for (int i = 0; i < numCourses; ++i) {
      if (!visited[i]) {
	result.push_back(i);
      }
    }

    return result;
  }

  vector<int> find_root_courses (const int& numCourses, vector<vector<int>>& prerequisites) {
    // if can't find return {}; We assume preq not empty.
    vector<bool> targets(numCourses, false);
    vector<bool> sources(numCourses, false);

    for (auto it : prerequisites) {
      targets[it[0]] = true;
      sources[it[1]] = true;
    }

    vector<int> result;
    
    for (int i = 0; i < numCourses; ++i) {
      if (!targets[i] && sources[i]) {
	result.push_back(i);
      }
    }

    return result;
    
  }
};
