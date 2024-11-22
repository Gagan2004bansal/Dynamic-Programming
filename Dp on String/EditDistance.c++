#include <iostream>
#include <vector>

using namespace std;
int recursion(string str1, string str2, int n, int m){
    if(n == 0){
        return m;
    }

    if(m == 0){
        return n;
    }

    if(str1[n-1] == str2[m-1]){
        return recursion(str1, str2, n-1, m-1);
    }
    else{
        int insert = recursion(str1, str2, n, m-1);
        int replace = recursion(str1, str2,  n-1, m-1);
        int Delete = recursion(str1, str2, n-1, m);

        return 1 + min(insert, min(replace, Delete));
    }
}
int Memo(string str1, string str2, int n, int m, vector< vector<int> >&dp){
    if(n == 0){
        return m;
    }
    if(m == 0){
        return n;
    }

    // DP Check 
    if(dp[n][m] != -1){
        return dp[n][m];
    }

    if(str1[n-1] == str2[m-1]){
        return dp[n][m] = Memo(str1, str2, n-1, m-1, dp);
    }
    else{
        int insert = Memo(str1, str2, n, m-1, dp);
        int replace = Memo(str1, str2, n-1, m-1, dp);
        int Delete = Memo(str1, str2, n-1, m, dp);

        dp[n][m] = 1 + min(insert, min(replace, Delete));
        return dp[n][m];
    }

}
int Tabu(string str1, string str2){
    vector< vector<int> > dp(str1.length()+1, vector<int>(str2.length()+1, 0));

    for(int i = 0; i<=str1.length(); i++){
        dp[i][0] = i;
    }
    for(int i = 0; i<=str2.length(); i++){
        dp[0][i] = i;
    }

    for(int i = 1; i<=str1.length(); i++){
        for(int j = 1; j<=str2.length(); j++){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                int insert = dp[i][j-1];
                int replace = dp[i-1][j-1];
                int Delete = dp[i-1][j];

                dp[i][j] = 1 + min(insert, min(replace, Delete));
            }
        }
    }

    return dp[str1.length()][str2.length()];
}
int SO(string str1, string str2){

    vector<int> prev(str2.length()+1, 0);
    vector<int> curr(str2.length()+1, 0);

    for(int i = 0; i<=str2.length(); i++){
        prev[i] = i;
    }

    for(int i = 1; i<=str1.length(); i++){
        curr[0] = i;
        for(int j = 1; j<=str2.length(); j++){
            if(str1[i-1] == str2[j-1]){
                curr[j] = prev[j-1];
            }
            else{
                int insert = curr[j-1];
                int replace = prev[j-1];
                int Delete = prev[j];

                curr[j] = 1 + min(insert, min(replace, Delete));
            }
        }
        prev = curr;
    }

    return prev[str2.length()];
}
int main(){

    string str1;
    cin >> str1;
    string str2;
    cin >> str2;
    
    // cout << recursion(str1, str2, str1.length(), str2.length()) << endl;

    // vector< vector<int> > dp(str1.length()+1, vector<int>(str2.length()+1, -1));
    // cout << Memo(str1, str2, str1.length(), str2.length(), dp) << endl;

    // cout << Tabu(str1, str2) << endl;

    cout << SO(str1, str2) << endl;

    return 0;
}