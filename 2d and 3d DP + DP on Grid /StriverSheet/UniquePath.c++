// link : https://leetcode.com/problems/unique-paths/

#include <iostream>
#include <vector>
using namespace std;
int recursion(int m, int n){
    // Base Case 
    if(m == 0 && n == 0){
        return 1;
    }
    if(m < 0 || n < 0){
        return 0;
    }

    // up
    int up = recursion(m-1, n);
    // left
    int left = recursion(m, n-1);

    return left + up;
}
int memo(int m, int n, vector< vector<int> > &dp){
    if(m == 0 && n == 0){
        return 1;
    }
    if(m < 0 || n < 0){
        return 0;
    }
    // dp check
    if(dp[m][n] != -1){
        return dp[m][n];
    }

    // up 
    int up = memo(m-1, n, dp);
    // left
    int left = memo(m, n-1, dp);

    dp[m][n] = left + up;
    return dp[m][n];
}
void Solve(int m, int n){
    cout << recursion(m-1, n-1) << endl;

    vector < vector<int> > dp(m, vector<int>(n, -1));
    cout << memo(m-1, n-1, dp) << endl;
}
int main(){
    int m, n;
    cin >> m >> n;

    Solve(m , n);

    return 0;
}