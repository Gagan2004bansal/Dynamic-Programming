#include <iostream>
#include <vector>
using namespace std;

int solveUsingRec(vector<int>&arr, int sum, int n){
    if(sum == 0){
        return true;
    }
    if(sum < 0){
        return false;
    }
    if(n <= 0){
        return false;
    }

    bool include = solveUsingRec(arr, sum - arr[n-1], n-1);
    bool exclude = solveUsingRec(arr, sum, n-1);

    return (include or exclude);
}

int solveUsingMemo(vector<int> &arr, int target, int n, vector< vector<int> >&dp){
    // Base Case
    if(target == 0){
        return true;
    }
    if(target < 0){
        return false;
    }
    if(n <= 0){
        return false;
    }
    // DP CHECK
    if(dp[n-1][target] != -1){
        return dp[n-1][target];  
    }

    bool include = solveUsingMemo(arr, target - arr[n-1], n-1, dp);
    bool exclude = solveUsingMemo(arr, target, n-1, dp);

    dp[n-1][target] = include + exclude;
    return dp[n-1][target];
}

bool solveUsingTabu(vector<int>&arr, int target, int n){
    vector< vector<int> > dp(n, vector<int>(target + 1, 0));

    for(int i = 0; i<=n; i++){
        dp[i][0] = 1;
    }

    return dp[n][target];
}

bool Solve(vector<int>&arr){

    int sum = 0;
    for(int i = 0; i<arr.size(); i++){
        sum += arr[i];
    }

    if(sum % 2 != 0){
        return false;
    }

    int n = arr.size();

    // return solveUsingRec(arr, sum/2, n);

    vector < vector<int> > dp(n, vector<int>(sum/2 + 1, -1));
    return solveUsingMemo(arr, sum/2, n, dp);
}

int main(){
    int n;
    cin >> n;

    vector<int> temp;
    for(int i = 0; i<n; i++){
        int input;
        cin >> input;
        temp.push_back(input);
    }

    cout << Solve(temp) << endl;

    return 0;
}