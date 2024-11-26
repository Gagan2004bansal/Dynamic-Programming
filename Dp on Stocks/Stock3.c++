#include <iostream>
#include <vector>
using namespace std;
int memo(vector<int>&prices, int index, int buy, int limit, vector< vector< vector<int> > >&dp){
    // Base Case 
    if(index == prices.size()){
        return 0;
    }
    // dp check
    if(dp[index][buy][limit] != -1){
        return dp[index][buy][limit];
    }

    if(limit == 0){
        return 0;
    }

    int profit = 0;
    if(buy){
        int buys = -prices[index] + memo(prices, index + 1, 0, limit, dp);
        int skip = memo(prices, index + 1, 1, limit, dp);
        profit = max(buys, skip);
    }
    else{
        int sell = prices[index] + memo(prices, index + 1, 1, limit - 1, dp);
        int skip = memo(prices, index + 1, 0, limit, dp);
        profit = max(sell, skip);
    }

    dp[index][buy][limit] = profit;
    return dp[index][buy][limit];
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

    
    vector< vector< vector<int> > > dp(n + 1, vector< vector<int> > (2, vector<int>(3, -1)));
    cout << memo(prices, 0, 1, 2, dp) << endl;
    return 0;
}