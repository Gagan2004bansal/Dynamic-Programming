#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int memo(vector< vector<long long> >&arr, int index, long long end, vector< vector<long long> >&dp){
    // Base Case
    if(index >= arr.size()){
        return 0;
    }

    if(dp[index][end] != -1){
        return dp[index][end];
    }

    long long take = 0;
    if(arr[index][0] > end){
        take = arr[index][2] + memo(arr, index+1, arr[index][1], dp);
    }
    long long notTake = memo(arr, index+1, end, dp);

    dp[index][end] = max(take, notTake);
    return dp[index][end];
}

int main(){
    
    long long n;
    cin >> n;

    vector< vector<long long> > arr(n, vector<long long>(3, 0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<3; j++){
            cin >> arr[i][j];
        }
    }   

    long long maxi = 0;
    for(int i = 0; i<n; i++){
        maxi = max(maxi, arr[i][2]);
    }

    sort(arr.begin(), arr.end());

    vector< vector<long long> > dp(n+1, vector<long long>(maxi, -1));
    cout << memo(arr, 0, 0, dp) << endl;

    return 0;
}