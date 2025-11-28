/*
    121. Best Time to Buy and Sell Stock

    You are given an array prices where prices[i] is the price of a given stock on the i-th day.
    You want to maximize your profit by choosing a single day to buy one stock and choosing a
    different day in the future to sell that stock.

    Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

    Example:
    Input: [7,1,5,3,6,4] -> Output: 5  (buy at 1, sell at 6)
    Input: [7,6,4,3,1] -> Output: 0

    Idea:
    Track the minimum price so far and compute the profit if sold today, update best profit.
*/

#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices) {
    if (prices.size() <= 1) return 0;

    int minPrice = prices[0];
    int best = 0;

    for (int i = 1; i < (int)prices.size(); i++) {
        if (prices[i] < minPrice) minPrice = prices[i];
        else {
            int profit = prices[i] - minPrice;
            if (profit > best) best = profit;
        }
    }

    return best;
}

int main() {
    vector<int> a = {7,1,5,3,6,4};
    cout << "Max profit: " << maxProfit(a) << endl; // 5

    vector<int> b = {7,6,4,3,1};
    cout << "Max profit: " << maxProfit(b) << endl; // 0

    return 0;
}
