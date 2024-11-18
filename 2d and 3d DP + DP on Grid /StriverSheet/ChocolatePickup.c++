// link : https://www.geeksforgeeks.org/problems/chocolates-pickup/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=chocolates-pickup

#include <iostream>
#include <vector>
using namespace std;
int Recursion(int row, int col1, int col2, vector< vector<int> >&grid){
    if(col1 < 0 || col2 < 0 || col1 >= grid[0].size() || col2 >= grid[0].size()){
        return -1e9;
    }
    if(row == grid.size()-1){
        if(col1 == col2){
            return grid[row][col1];
        }
        else{
            return (grid[row][col1] + grid[row][col2]);
        }
    }

    int maxi = INT_MIN;
    for(int i = -1; i<=1; i++){
        for(int j = -1; j<=1; j++){
            int ans;
            if(col1 == col2){
                ans = grid[row][col1] + Recursion(row+1, col1+i, col2+j, grid);
            }
            else{
                ans = grid[row][col1] + grid[row][col2] + Recursion(row+1, col1+i, col2+j, grid);
            }

            maxi = max(maxi, ans);
        }
    }

    return maxi;
}

int Memo(int row, int col1, int col2, vector< vector<int> >&grid, vector< vector< vector<int> > > &dp){
    if(col1 < 0 || col2 < 0 || col1 >= grid[0].size() || col2 >= grid[0].size()){
        return -1e9;
    }
    if(row == grid.size()-1){
        if(col1 == col2){
            return grid[row][col1];
        }
        else{
            return (grid[row][col1] + grid[row][col2]);
        }
    }

    if(dp[row][col1][col2] != -1){
        return dp[row][col1][col2];
    }

    int maxi = INT_MIN;
    for(int i = -1; i<=1; i++){
        for(int j = -1; j<=1; j++){
            int ans;
            if(col1 == col2){
                ans = grid[row][col1] + Memo(row+1, col1 + i, col2 + j, grid, dp);
            }
            else{
                ans = grid[row][col1] + grid[row][col2] + Memo(row+1, col1 + i, col2 + j, grid, dp); 
            }   

            maxi = max(maxi, ans);
        }
    }

    return dp[row][col1][col2] = maxi;
}

void Solve(vector< vector<int> >&grid){
    int m = grid.size();
    int n = grid[0].size();

    cout << Recursion(0, 0, n-1, grid) << endl;

    vector < vector< vector<int> > > dp(m+1, vector< vector<int> >(n+1 , vector<int> (n+1, -1)));
    cout << Memo(0, 0, n-1, grid, dp) << endl;
}
int main(){
    int n, m;
    cin >> n >> m;

    vector< vector<int> > grid(n, vector<int>(m, 0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> grid[i][j];
        }
    }

    Solve(grid);
    return 0;
}