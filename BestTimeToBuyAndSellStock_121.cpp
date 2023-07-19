/*You are given an array prices where prices[i] is the price of a given 
stock on the ith day.You want to maximize your profit by choosing a single 
day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve 
any profit, return 0.*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, mp = 0;
        for(int r = 0; r < prices.size(); ++r){
            if (prices[r] < prices[l])
                l = r;
            else if (prices[r] - prices[l] > mp)
                mp = prices[r] - prices[l];
        }
        return mp;
    }
};