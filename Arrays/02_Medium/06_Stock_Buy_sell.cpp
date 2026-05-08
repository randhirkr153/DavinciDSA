#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumProfit(vector<int>& prices) {

        // Intuition:
        // Whenever today's price is greater
        // than yesterday's price,
        // add the profit difference.
        //
        // This captures every increasing slope
        // and gives maximum total profit
        // for multiple transactions.

        int profit = 0;

        for (int i = 1; i < prices.size(); i++) {

            if (prices[i] > prices[i - 1]) {

                profit += prices[i] - prices[i - 1];
            }
        }

        return profit;
    }
};

int main() {

    int n;

    cout << "Enter number of days: ";
    cin >> n;

    vector<int> prices(n);

    cout << "Enter stock prices: ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    Solution obj;

    cout << "Maximum Profit: "
         << obj.maximumProfit(prices);

    return 0;
}