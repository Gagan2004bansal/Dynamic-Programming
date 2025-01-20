#include <iostream>
#include <vector>
using namespace std;
int recursion(string s, string t, int n, int m){
    if(m == 0){
        return 1;
    }
    if(n == 0){
        return 0;
    }

    if(s[n-1] == t[m-1]){
        return recursion(s, t, n-1, m-1) + recursion(s, t, n-1, m);
    }
    return recursion(s, t, n-1, m);
}
int memo(string s, string t, int n, int m, vector< vector<int> >&dp){
    if(m == 0){
        return 1;
    }
    if(n == 0){
        return 0;
    }
    // dp check
    if(dp[n][m] != -1){
        return dp[n][m];
    }

    if(s[n-1] == t[m-1]){
        dp[n][m] = memo(s, t, n-1, m-1, dp) + memo(s, t, n-1, m, dp);
        return dp[n][m];
    }
    dp[n][m] = memo(s, t, n-1, m, dp);
    return dp[n][m];
}
int tabu(string s, string t, int n, int m){
    vector< vector<int> > dp(n+1, vector<int>(m+1, 0));
    for(int i = 0; i<=n; i++){
        dp[i][0] = 1;
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][m];
}
int SO(string s, string t, int n, int m){
    vector<double> curr(m+1, 0);
    vector<double> prev(m+1, 0);

    curr[0] = 1;
    prev[0] = 1;

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(s[i-1] == t[j-1]){
                curr[j] = prev[j-1] + prev[j];
            }
            else{
                curr[j] = prev[j];
            }
        }
        prev = curr;
    }

    return (int)prev[m];
}
int main(){

    string s, t;
    cin >> s >> t;

    int n = s.length();
    int m = t.length();

    cout << recursion(s, t, n, m) << endl;

    vector< vector<int> > dp(n+1, vector<int>(m+1, -1));
    cout << memo(s, t, n, m, dp) << endl;

    cout << tabu(s, t, n, m) << endl;

    cout << SO(s, t, n, m) << endl;

    return 0;
}