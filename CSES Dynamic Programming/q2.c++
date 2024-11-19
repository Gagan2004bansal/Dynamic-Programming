// link : https://cses.fi/problemset/task/1634

#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int Memo(int c[], int target, int size, vector<int>&dp){

    if(target == 0){
        return 0;
    }

    if(dp[target] != -1){
        return dp[target];
    }

    int include = INT_MAX;
    for(int i = 0; i<size; i++){
        if(target - c[i] >= 0){
            int ans = Memo( c, target - c[i], size, dp);
            if(ans != INT_MAX){
                include = min(include, 1 + ans);
            }
        }
    }
    dp[target] = include;
    return dp[target];
}
int main(){

    int n, x;
    cin >> n >> x;

    int *c = new int[n];
    for(int i = 0; i<n; i++){
        cin >> c[i];
    }

    vector<int> dp(x + 1, -1);
    int ans = Memo(c, x, n, dp);
    if(ans == INT_MAX){
        cout << -1 << endl;
    }
    else{
        cout << ans << endl;
    }

    return 0;
}


