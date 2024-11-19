// link : https://cses.fi/problemset/task/1633

#include <iostream>
#include <vector>
using namespace std;
int memo(vector<int>&dp, int target){
    
    if(target == 0){
        return 1;
    }
    if(target < 0){
        return 0;
    }

    if(dp[target] != -1){
        return dp[target];
    }

    int include = 0;
    for(int i = 6; i>=1; i--){
        if(target - i >= 0){
            include += memo(dp, target - i);
        }
    }
    return dp[target] = include;
}
int main(){

    int n;
    cin >> n;

    // cout << memo(dp,n) << endl;

    vector<int> dp(n+1, -1);
    dp[0] = 1;

    for(int target = 1; target<=n; target++){
        int include = 0;
        for(int d = 6; d>=1; d--){
            if(target - d >= 0){
                include += dp[target - d];
            }
        }
        dp[target] = include;
    }

    cout << dp[n] << endl;

    return 0;
}