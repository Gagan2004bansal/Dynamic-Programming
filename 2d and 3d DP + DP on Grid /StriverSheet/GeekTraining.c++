// link : https://www.geeksforgeeks.org/problems/geeks-training/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geeks-training

#include <iostream>
#include <vector>
using namespace std;
int recursion(int m, int n, vector< vector<int> > &arr){
    if(m == 0){
        int maxELe = INT_MIN;
        for(int i = 0; i<3; i++){
            if(i != n){
                maxELe = max(maxELe, arr[0][i]);
            }
        }
        return maxELe;
    }   

    int ans = INT_MIN;
    for(int i = 0; i<3; i++){
        if(i != n){
            ans = max(ans, arr[m][i] + recursion(m-1, i, arr));
        }
    }
    return ans;
}
int memo(int m, int n, vector < vector<int> >&arr, vector< vector<int> >&dp){
    // BASE CASE
    if(m == 0){
        int maxEle = INT_MIN;
        for(int i = 0; i<3; i++){
            if(i != n){
                maxEle = max(maxEle, arr[0][i]);
            }
        }
        return maxEle;
    }

    // DP check
    if(dp[m][n] != -1){
        return dp[m][n];
    }

    int ans = INT_MIN;
    for(int i = 0; i<3; i++){
        if(i != n){
            ans = max(ans, arr[m][i] + memo(m-1, i, arr, dp));
        }
    }

    dp[m][n] = ans;
    return ans;
}
void Solve(vector< vector<int> > &arr, int n){

    cout << recursion(n-1, 3, arr) << endl;

    vector < vector<int> > dp(n, vector<int>(4, -1));
    cout << memo(n-1, 3, arr, dp) << endl;
}
int main(){
    int n;
    cin >> n;

    vector< vector<int> > arr(n, vector<int>(3, 0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<3; j++){
            int input;
            cin >> input;
            arr[i][j] = input;
        }
    }

    Solve(arr, n);
    return 0;
}