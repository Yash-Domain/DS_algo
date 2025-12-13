class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        int buy = prices[0];
        for(int i = 1 ; i < n ; i++){
            int profit = prices[i] - buy;
            maxProfit = max(maxProfit,profit);
            buy = min(buy,prices[i]);
        }
        return maxProfit;
    }
};