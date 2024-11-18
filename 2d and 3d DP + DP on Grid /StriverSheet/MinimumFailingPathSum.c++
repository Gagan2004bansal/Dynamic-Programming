// link : https://leetcode.com/problems/minimum-falling-path-sum/description/

#include <iostream>
#include <vector>
using namespace std;
int delChange[3] = {-1, 0, 1};

int recursion(int m, int n, vector< vector<int> >&matrix){
    if(m == 0){
        return matrix[m][n];
    }

    int ans = 1e8;
    for(int i = 0; i<3; i++){
        int newCol = n + delChange[i];
        if(newCol >= 0 && newCol < matrix.size()){
            ans = min(ans, matrix[m][n] + recursion(m-1, newCol, matrix));
        }
    }
    return ans;
}

int memo(int m, int n, vector< vector<int> >&matrix, vector< vector<int> >&dp){

    if(m == 0){
        return dp[m][n];
    }

    if(dp[m][n] != -1){
        return dp[m][n];
    }

    int ans = 1e8;
    for(int i = 0; i<3; i++){
        int newCol = n + delChange[i];
        if(newCol >= 0 && newCol < matrix.size()){
            ans = min(ans, matrix[m][n] + memo(m-1, newCol, matrix, dp));
        }
    }

    dp[m][n] = ans;
    return ans;
}

int Tabu(vector< vector<int> >&matrix){
    int n = matrix.size();
    vector< vector<int> > dp(n+1, vector<int>(n+1, 0));
    for(int i = 0; i<n; i++){
        dp[0][i] = matrix[0][i];
    }

    for(int row = 1; row < n; row++){
        for(int col = 0; col < n; col++){
            int ans = 1e8;
            for(int i = 0; i<3; i++){
                int newCol = col + delChange[i];
                if(newCol >= 0 && newCol < matrix.size()){
                    ans = min(ans, matrix[row][col] + dp[row-1][newCol]);
                }
            }

            dp[row][col] = ans;
        }
    }

    int mini = INT_MAX;
    for(int i = 0; i<n; i++){
        mini = min(mini, dp[n-1][i]);
    }
    return mini;
}

void Solve(vector< vector<int> >&matrix){

    int n = matrix.size();
    // int ans = INT_MAX;
    // for(int i = 0; i<n; i++){
    //     ans = min(ans, recursion(n-1, i, matrix));
    // }
    // cout << ans << endl;

    // int ans = INT_MAX;
    // vector< vector<int> > dp(n+1, vector<int>(n+1, -1));
    // for(int i = 0; i<n; i++){
    //     ans = min(ans, memo(n-1, i, matrix, dp));
    // }
    // cout << ans << endl;  // Gives TLE 

    cout << Tabu(matrix) << endl;

}
int main(){

    int n, m; 
    cin >> m >> n;

    vector< vector<int> > matrix(m, vector<int>(n, 0));
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cin >> matrix[i][j];
        }
    }

    Solve(matrix);

    return 0;
}


