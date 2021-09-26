/*
309. Best Time to Buy and Sell Stock with Cooldown
Medium

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

    After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]

Example 2:

Input: prices = [1]
Output: 0

 

Constraints:

    1 <= prices.length <= 5000
    0 <= prices[i] <= 1000

*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int nostock=0,inhand=-prices[0],sell=0,t;
        for(int i=1;i<prices.size();i++){
            t=max(nostock,sell);
            sell=max(inhand+prices[i],sell);
            inhand=max(inhand,nostock-prices[i]);
            nostock=t;
        }
        return max(nostock,sell);
    }
};
//method 2
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> nostock(n,0),inhand(n,0),sell(n,0);
        inhand[0]=-prices[0];
        for(int i=1;i<n;i++){
            nostock[i]=max(nostock[i-1],sell[i-1]);
            inhand[i]=max(inhand[i-1],nostock[i-1]-prices[i]);
            sell[i]=max(nostock[i-1],inhand[i-1]+prices[i]);
        }
        return max(nostock[n-1],sell[n-1]);
    }
};
