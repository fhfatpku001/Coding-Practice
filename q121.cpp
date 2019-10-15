class Solution {
public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() < 2) {
      return 0;
    }
    int max_profit = 0;

    for (size_t i = 1; i < prices.size(); ++i) {
      int cur_profit = prices[i] - prices[i - 1];
      if (cur_profit > max_profit) {
	max_profit = cur_profit;
      }

      if (cur_profit > 0) {
	prices[i] = prices[i - 1];
      }
    }

    return max_profit;
  }
};
