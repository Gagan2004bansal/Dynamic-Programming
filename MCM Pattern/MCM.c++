#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int>&arr, int i , int j){
    // base case 
    if(i >= j){
        return 0;
    }

    int ans = 1e9;
    for(int k = i; k<j; k++){
        int temp = solve(arr, i, k) + solve(arr, k+1, j) + (arr[i-1] * arr[k] * arr[j]);
        ans = min(ans, temp); 
    }
    return ans;
}

int memo(vector<int>&arr, int i, int j, vector<vector<int> >&dp){
    if(i >= j){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int ans = 1e9;
    for(int k = i; k<j; k++){
        int temp = memo(arr, i, k, dp) + memo(arr, k+1, j, dp) + (arr[i-1] * arr[k] * arr[j]);
        ans = min(ans, temp);
    }
    return dp[i][j] = ans;
}

int main(){
    int n;
    cin >> n;

     vector<int> arr;
     for(int i = 0; i<n; i++){
        int input;
        cin >> input;

        arr.push_back(input);
     }

    cout << solve(arr, 1,  n-1) << endl;

    vector<vector<int> > dp(n+1, vector<int>(n+1, -1));
    cout << memo(arr, 1, n-1, dp) << endl; 

    return 0;
}