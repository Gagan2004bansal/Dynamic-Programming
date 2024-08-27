#include <iostream>
#include <vector>
using namespace std;
int solveUsingRec(string &str, string &pattern, int n, int m){
    // Base Case 
    if(n == 0 && m == 0){
        return 1;
    }
    if(n > 0 && m == 0){
        return 0;
    }
    if(n == 0 && m > 0){
        for(int i = 0; i<m; i++){
            if(pattern[i] != '*'){
                return 0;
            }
        }
        return 1;
    }

    if(str[n-1] == pattern[m-1] || pattern[m-1] == '?'){
        return solveUsingRec(str, pattern, n-1, m-1);
    }
    else if(pattern[m-1] == '*'){
        return (solveUsingRec(str, pattern, n-1, m) || solveUsingRec(str, pattern, n, m-1));
    }
    else{
        return 0;
    }
}
int solveUsingMemo(string &str, string &pattern, int n, int m, vector< vector<int> > &dp){
    // Base Case
    if(n == 0 && m == 0){
        return 1;
    }
    if(n > 0 && m == 0){
        return 0;
    }
    if(n == 0 && m > 0){
        for(int i = 0; i<m; i++){
            if(pattern[i] != '*'){
                return 0;
            }
        }
        return 1;
    }

    // dp check
    if(dp[n][m] != -1){
        return dp[n][m];
    }

    if(pattern[m-1] == str[n-1] || pattern[m-1] == '?'){
        return dp[n][m] = solveUsingMemo(str, pattern, n-1, m-1, dp);
    }
    else if(pattern[m-1] == '*'){
        dp[n][m] = (solveUsingMemo(str, pattern, n-1, m, dp) || solveUsingMemo(str, pattern, n, m-1, dp));
        return dp[n][m];
    }
    else{
        dp[n][m] = 0;
        return dp[n][m];
    }
}
int main(){
    string str, pattern;
    cin >> str;
    cin >> pattern;

    int n = str.length();
    int m = pattern.length();

    cout << solveUsingRec(str, pattern, n, m) << endl;

    vector< vector<int> > dp(n+1, vector<int>(m+1, -1));
    cout << solveUsingMemo(str, pattern, n, m, dp) << endl;
    return 0;
}