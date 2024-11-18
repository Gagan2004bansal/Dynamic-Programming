// link : https://leetcode.com/problems/minimum-path-sum/description/

#include <iostream>
#include <vector>
using namespace std;
int recursion(int m, int n, vector < vector<int> >&grid){
    if(m == 0 && n == 0){
        return grid[0][0];
    }
    if(m < 0 || n < 0){
        return INT_MAX;
    }
    
    int up = INT_MAX;
    if(m - 1 >= 0){
        up = grid[m][n] + recursion(m-1, n, grid);
    }

    int left = INT_MAX;
    if(n - 1 >= 0){
        left = grid[m][n] + recursion(m, n-1, grid);
    }

    return min(left, up);
}
int memo(int m, int n, vector< vector<int> >&grid, vector< vector<int> >&dp){
    if(m == 0 && n == 0){
        return grid[0][0];
    }
    if(m < 0 || n < 0){
        return INT_MAX;
    }

    // DP CHECK
    if(dp[m][n] != -1){
        return dp[m][n];
    }

    int up = INT_MAX;
    if(m - 1 >= 0){
        up = grid[m][n] + memo(m-1, n, grid, dp);
    }
    int left = INT_MAX;
    if(n - 1 >= 0){
        left = grid[m][n] + memo(m, n-1, grid, dp);
    }

    dp[m][n] = min(left, up);
    return dp[m][n];
}
void Solve(int m, int n, vector< vector<int> >&grid){
    
    cout << recursion(m-1, n-1, grid) << endl;

    vector < vector<int> > dp(m, vector<int>(n, -1));
    cout << memo(m-1, n-1, grid, dp) << endl;

}
int main(){
    int m, n;
    cin >> m >> n;

    vector< vector<int> > grid(m, vector<int>(n, 0));
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cin >> grid[i][j];
        }
    }

    Solve(m, n, grid);

    return 0;
}