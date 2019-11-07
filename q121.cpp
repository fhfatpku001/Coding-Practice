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

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() < 2) {
      return 0;
    }

    pair<int,int> buy_sell = {prices[0], prices[0]};
    int max_profit = 0;
    
    for (size_t i = 0; i < prices.size(); ++i) {
      if (prices[i] < buy_sell.first) {
	buy_sell = {prices[i], prices[i]};
      } else if (prices[i] > buy_sell.second) {
	buy_sell.second = prices[i];
	int diff = buy_sell.second - buy_sell.first;

	if (diff > max_profit) {
	  max_profit = diff;
	}
      }
    }

    return max_profit;
  }
};
