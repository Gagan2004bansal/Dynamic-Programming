#include <iostream>
#include <vector>
using namespace std;
int LCSusingRec(int n, int m, string str1, string str2){
    // Base Case 
    if(n == 0 || m == 0){
        return 0;
    }

    if(str1[n-1] == str2[m-1]){
        return 1 + LCSusingRec(n-1, m-1, str1, str2);
    }
    else{
        return max(LCSusingRec(n-1, m, str1, str2), LCSusingRec(n, m-1, str1, str2));
    }
}
int LCSusingMemo(int n, int m, string str1, string str2, vector<vector<int> >&dp){
    // Base Case
    if(n == 0 || m == 0){
        return 0;
    }
    // DP check
    if(dp[n][m] != -1){
        return dp[n][m];
    }

    if(str1[n-1] == str2[m-1]){
        dp[n][m] = 1 + LCSusingMemo(n-1, m-1, str1, str2, dp);
        return dp[n][m];
    }
    else{
        dp[n][m] = max(LCSusingMemo(n-1, m, str1, str2, dp), LCSusingMemo(n, m-1, str1, str2, dp));
        return dp[n][m];
    }
}
int LCSusingTabu(int n, int m, string str1, string str2){
    vector<vector<int> > dp(n+1, vector<int>(m+1, 0));
    for(int i = 1; i<=n ; i++){
        for(int j = 1; j<=m; j++){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
int main(){
    string str1;
    cin >> str1;
    string str2;
    cin >> str2;

    int n = str1.length();
    int m = str2.length();

    cout << LCSusingRec(n, m, str1, str2) << endl;

    vector<vector<int> > dp(n+1, vector<int>(m+1, -1));
    cout << LCSusingMemo(n, m, str1, str2, dp) << endl;

    cout << LCSusingTabu(n, m, str1, str2) << endl;
    return 0;
}