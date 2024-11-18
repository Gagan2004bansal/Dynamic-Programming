// link : https://leetcode.com/problems/unique-paths-ii/description/

#include <iostream>
#include <vector>
using namespace std;

int recursion(int m, int n, vector< vector<int> >&obstacles){
    // Base Case
    if(m == 0 && n == 0){
        return 1;
    }
    if(m < 0 || n < 0){
        return 0;
    }

    // up
    int up = 0;
    if(m - 1 >= 0 && obstacles[m-1][n] == 0){
        up = recursion(m-1, n, obstacles);
    }

    int left = 0;
    if(n - 1 >= 0 && obstacles[m][n-1] == 0){
        left = recursion(m, n-1, obstacles);
    }

    return left + up;
}

int memo(int m, int n, vector< vector<int> >&obstacle, vector< vector<int> >&dp){
    // Base Case 
    if(m == 0 && n == 0){
        return 1;
    }
    if(m < 0 || n < 0)
    {
        return 0;
    }

    // DP check 
    if(dp[m][n] != -1){
        return dp[m][n];
    }

    // up  
    int up = 0;
    if(m - 1 >= 0 && obstacle[m-1][n] == 0){
        up = memo(m-1, n, obstacle, dp);
    }
    // left 
    int left = 0;
    if(n - 1 >= 0 && obstacle[m][n-1] == 0){
        left = memo(m, n-1, obstacle, dp);
    }

    dp[m][n] = left + up;
    return left + up;
}

void Solve(vector< vector<int> >&obstacle){
    int m = obstacle.size();
    int n = obstacle[0].size();

    if(obstacle[m-1][n-1] == 1 || obstacle[0][0] == 1){
        cout << 0 << endl;
    } 
    else{
        cout << recursion(m-1, n-1, obstacle) << endl;

        vector< vector<int> > dp(m, vector<int>(n, -1));
        cout << memo(m-1, n-1, obstacle, dp) << endl;
    }
}

int main(){
    int m, n;
    cin >> m >> n;

    vector< vector<int> > obstacle(m, vector<int>(n, 0));
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cin >> obstacle[i][j];
        }
    }

    Solve(obstacle);

    return 0;
}