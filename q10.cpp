#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <list>
#include <cmath>
#include <sstream>
#include <climits>
using namespace std;

/* Analysis:
 * matches is equivalent to say:
 * ---a---b-----c----
 * ...a...b.....c....
 * matching condition:
 * extended pattern size = str.size.
 * any char should matches.
 * [*.*...*] = any str with at least length 4 = num_of '.';
 * should have a function determine the length range of this pieces;
 * [*.*...] [abcd.ef][*....]
 * divided into two kinds of pieces:
 * [*.*...*.] star_piece (free_piece);
 * [a.b..c.e] char_piece (fixed_piece);
 * the remaining is a backtracking problem;
 * [*...*..a.b...*.c..];
 * we record pos_of_first_star, {0, 5 '.'};
 * a:{8, 5 };
 * *:{14,1 };
 * c:{16, 3};
*/

class Solution {
  
public:
  bool isMatch(const string& str, const string& pattern) {
    // read the piece_pattern, search all candidate piece pattern;
    if (pattern.empty()) {
      return (str.empty()) ? true : false;
    }
    size_t min_length = 0;
    
    vector<piece_pattern*> piece = to_p_pattern(pattern, min_length);




    return false;
  }
    


  struct piece_pattern {
    size_t start_pos;
    bool is_star;
    size_t length; // at least;
    piece_pattern(size_t _pos, bool _is_star): start_pos(_pos), is_star(_is_star) {};
  };

  vector<piece_pattern*> to_p_pattern (const string& pattern, size_t& min_total_length) {
    vector<piece_pattern*> piece;
    size_t count_dot = 0;
    size_t length_str = 0;
    bool cur_piece_is_star = (pattern[0] == '*') ? false : true;
        
    for (size_t i = 0; i < pattern.size(); ++i) {
      if (pattern[i] == '*') {
	if (!cur_piece_is_star) {
	  if (length_str > 0) {
	    piece.back()->length = length_str;
	    min_total_length += length_str;
	  }
	  length_str = 0;
	  count_dot = 0;
	  cur_piece_is_star = true;
	  piece_pattern* next_piece = new piece_pattern(i, true);
	  piece.push_back(next_piece);
	} else {
	  continue;
	}
      } else if (pattern[i] == '.') {
	++count_dot;
	++length_str;
      } else {// is_char
	if (cur_piece_is_star) {
	  if (!piece.empty()) {
	    piece.back()->length = count_dot;
	    min_total_length += count_dot;
	  }
	  piece_pattern* next_piece = new piece_pattern(i, false);
	  piece.push_back(next_piece);
	  length_str = 0;
	  count_dot = 0;
	}
	cur_piece_is_star = false;
	++length_str;
      }
    }

    if (cur_piece_is_star) {
      piece.back()->length = count_dot;
    } else {
      piece.back()->length = length_str;
    }

    min_total_length += piece.back()->length;
    
    for (size_t i = 0; i < piece.size(); ++i) {
      print_p_pattern(piece[i]);
    }

    
    return piece;
  }

  void print_p_pattern (piece_pattern* input) {
    cout << "start_pos: " << input->start_pos << "|is_star: " << input->is_star << "| length: " << input->length << endl;
  }
};


int main(int argc, char *argv[])
{
  Solution solve;
  string pattern = "bec*.*...abcd.ef*....acd";
  bool result = solve.isMatch(pattern, pattern);
  
  return 0;
}


