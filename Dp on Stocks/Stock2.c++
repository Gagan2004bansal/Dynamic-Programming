#include <iostream>
#include <vector>
using namespace std;
int memo(vector<int>&prices, int index, int buy, vector< vector<int> >&dp){
    // Base Case 
    if(index == prices.size()){
        return 0;
    }
    // dp check
    if(dp[index][buy] != -1){
        return dp[index][buy];
    }

    int profit = 0;
    if(buy){
        int buys = -prices[index] + memo(prices, index + 1, 0, dp);
        int skip = memo(prices, index + 1, 1, dp);
        profit = max(buys, skip);
    }
    else{
        int sell = prices[index] + memo(prices, index + 1, 1, dp);
        int skip = memo(prices, index + 1, 0, dp);
        profit = max(sell, skip);
    }

    dp[index][buy] = profit;
    return dp[index][buy];
}
int main(){
    int n;
    cin >> n;

    vector<int> prices;
    for(int i = 0; i<n; i++){
        int input;
        cin >> input;
        prices.push_back(input);
    }

    vector< vector<int> > dp(n+1, vector<int>(2, -1));
    cout << memo(prices, 0, 1, dp) << endl;
    return 0;
}