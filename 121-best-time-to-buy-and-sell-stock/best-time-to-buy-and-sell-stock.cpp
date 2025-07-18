class Solution {
public:
    // M-1 Brute
    // TLE
    // int maxProfit(vector<int>& prices) {
    //     int profit = 0;
    //     for (int i = 0; i < prices.size() - 1; i++) {
    //         for (int j = i + 1; j < prices.size(); j++) {
    //             profit = max(profit, prices[j] - prices[i]);
    //         }
    //     }
    //     return profit;
    // }

    // M-2
    // int maxProfit(vector<int>& prices) {
        // int min = INT_MAX;
        // int maxProfit = 0;

        // for(int i = 0; i < prices.size(); i++) {
        //     if(prices[i] < min) {
        //         min = prices[i];
        //     }
        //     maxProfit = max(maxProfit, prices[i] - min);
        // }
        // return maxProfit;
    // }

    // M-3 : buy index, sell index
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        // Initialize buy index to 0
        int buyI = 0;
        int sellI = 0;

        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] - prices[buyI] > maxProfit) {
                maxProfit = prices[i] - prices[buyI];
                // assigning the selling day's index
                sellI = i;
            }

            // If ith day's price is lower than the buyI th day -> assign buyI =
            // i
            if (prices[i] < prices[buyI]) {
                buyI = i;
            }
        }

        return maxProfit;
    }
};