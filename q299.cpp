class Solution {
public:
  string getHint(string secret, string guess) {
    size_t count_bull = 0, count_all = 0;
    vector<size_t> sec_digits_count(10,0), guess_digits_count(10,0);
    string result;
    
    for (size_t i = 0; i < secret.size(); ++i) {
      ++sec_digits_count[secret[i] - '0'];
      if (secret[i] == guess[i]) {
	++count_bull;
      }
    }

    for (size_t i = 0; i < guess.size(); ++i) {
      ++guess_digits_count[guess[i] - '0'];
    }

    for (size_t k = 0; k < 10; ++k) {
      count_all += min(sec_digits_count[k], guess_digits_count[k]);
    }

    result += to_string(count_bull) + 'A' + to_string(count_all - count_bull) + 'B';
    return result;
  }
};

int main(int argc, char *argv[])
{
  Solution solve;

  string secret = "1089";
  string guess = "0187";

  cout << solve.getHint(secret, guess) <<endl;
  
  return 0;
}
