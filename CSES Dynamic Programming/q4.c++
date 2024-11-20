#include <iostream>
#include <vector>
using namespace std;
const int mod = 1e9 + 7;
int Memo(int n, int target, int index, int *c, vector< vector<int> >&dp){
    if(target == 0){
        return 1;
    }
    if(index < 0 || target < 0){
        return 0;
    }

    if(dp[index][target] != -1){
        return dp[index][target];
    }

    int include = Memo(n, target - c[index], index, c, dp);
    int exclude = Memo(n, target, index - 1, c, dp);

    dp[index][target] = (include + exclude) % mod;
    return dp[index][target];
}
int main(){

    int n, x;
    cin >> n >> x;

    int *c = new int[n];
    for(int i = 0; i<n; i++){
        cin >> c[i];
    }


    vector< vector<int> > dp(n+1, vector<int>(x+1, -1)); 
    cout << Memo(n, x, n-1, c, dp) << endl;
    return 0;
}