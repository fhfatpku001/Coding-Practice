class Solution {
public:
  int ladderLength(const string& beginWord, const string& endWord, vector<string>& wordList) {
    if (beginWord.empty() || endWord.empty() || wordList.size() < 2) {
      return 0;
    }

    unordered_map<string, size_t> pos_map;
    
    for (size_t i = 0; i < wordList.size(); ++i) {
      pos_map[wordList[i]] = i;
    }

    if (pos_map.count(endWord) == 0) {
      return 0;
    }

    if (pos_map.count(beginWord) == 0) {
      wordList.push_back(beginWord);
      pos_map[beginWord] = wordList.size() - 1;
    }
    
    int count = 1;
    queue<size_t> level_q;
    level_q.push(pos_map[beginWord]);
    unordered_set<size_t> visited;
    visited.insert(pos_map[beginWord]);

    while (!level_q.empty()) {
      ++count;
      size_t level_size = level_q.size();
      for (size_t i = 0; i < level_size; ++i) {
	string str = wordList[level_q.front()];


	// push in every possibility;
	vector<string> checkstrs = gen_str(str);

	for (auto it : checkstrs) {
	  if (pos_map.count(it) > 0 && visited.count(pos_map[it]) == 0) {
	    if (it == endWord) {
	      return count;
	    }
	    level_q.push(pos_map[it]);
	  }
	}

	level_q.pop();

      }
    }

    return 0;
  }

  vector<string> gen_str(const string& str) {
    vector<string> result;
    
    for (size_t i = 0; i < str.size(); ++i) {
      for (size_t j = 0; j < 26; ++j) {
	string newstr = str;
	newstr[i] = 'a' + j;
	if (newstr != str) {
	  result.push_back(newstr);
	}  
      }
    }

    return result;
  }
};
// another method

class Solution {
public:
  int ladderLength(const string& beginWord, const string& endWord, vector<string>& wordList) {
    if (beginWord.empty() || endWord.empty() || wordList.size() < 1) {
      return 0;
    }

    unordered_map<string, size_t> pos_map;
    
    for (size_t i = 0; i < wordList.size(); ++i) {
      pos_map[wordList[i]] = i;
    }
    
    queue<string> level_q;
    level_q.push(beginWord);
    unordered_set<string> visited;
    visited.insert(beginWord);
    int count = 1;

    while (!level_q.empty()) {
      ++count;
      size_t level_size = level_q.size();
      for (size_t i = 0; i < level_size; ++i) {
	for (size_t j = 0; j < wordList.size(); ++j) {
	  if (isadj(level_q.front(), wordList[j]) && visited.count(wordList[j]) == 0) {
	    level_q.push(wordList[j]);
	    if (wordList[j] == endWord) {
	      return count;
	    }
	    visited.insert(wordList[j]);
	  }
	}
	level_q.pop();
      }
    }
    

    return 0;
  }

  bool isadj (const string& str1, const string& str2) {
    int count = 0;

    for (size_t i = 0; i < str1.size(); ++i) {
      if (str1[i] != str2[i]) {
	++count;
	if (count > 1) {
	  return false;
	}
      }
    }

    return (count == 0) ? false : true;
  }
};
