#include <iostream>
#include <vector>
using namespace std;

int solveUsingRec(int n, vector<int>&arr, int target){
    // Base Case
    if(n == 0 && target == 0){
        return 1;
    }
    if(n == 0 && target != 0){
        return 0;
    }
    if(n < 0){
        return 0;
    }

    int include = 0;
    if(arr[n-1] <= target){
        include = 0 + solveUsingRec(n-1, arr, target - arr[n-1]);
    }
    int exclude = 0 + solveUsingRec(n-1, arr, target);

    return include + exclude;
}

int solveUsingMemo(int n, vector<int>&arr, int target, vector< vector<int> > &dp){
    // Base case
    if(n == 0 && target == 0){
        return 1;
    }
    if(n == 0 && target != 0){
        return 0;
    }
    // Dp check
    if(dp[n-1][target] != -1){
        return dp[n-1][target];
    }

    int include = 0;
    if(arr[n-1] <= target){
        include = solveUsingMemo(n-1, arr, target - arr[n-1], dp);
    }
    int exclude = solveUsingMemo(n-1, arr, target, dp);

    dp[n-1][target] = include + exclude;
    return dp[n-1][target];
}

int solveUsingTabu(int n, vector<int>&arr, int target){
    vector< vector<int> > dp(n+1 , vector<int>(target + 1, 0));
    
    for(int i = 0; i<=n; i++){
        dp[i][0] = 1;
    }

    for(int i = 1; i<=n; i++){
        for(int sum = 0; sum <= target; sum++){
            int include = 0;
            if(arr[i-1] <= sum){
                include = dp[i-1][sum - arr[i-1]];
            }
            int exclude = dp[i-1][sum];

            dp[i][sum] = include + exclude;
        }
    }

    return dp[n][target];
}

int solveUsingSO(int n, vector<int>&arr, int target){
    vector<int> prev(target+1, 0);
    vector<int> curr(target+1, 0);
    prev[0] = 1;

    for(int i = 1; i<=n; i++){
        for(int sum = 0; sum <= target; sum++){
            int include = 0;
            if(arr[i-1] <= sum){
                include = prev[sum - arr[i-1]];
            }
            int exclude = prev[sum];

            curr[sum] = include + exclude;
        }
        prev = curr;
    }

    return prev[target];
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    int target;
    cin >> target;

    cout << solveUsingRec( n, arr, target) << endl;

    vector< vector<int> > dp(n , vector<int>(target+1, -1));
    cout << solveUsingMemo( n, arr, target, dp) << endl;

    cout << solveUsingTabu(n, arr, target) << endl;

    cout << solveUsingSO(n, arr, target) << endl;

    return 0;
}