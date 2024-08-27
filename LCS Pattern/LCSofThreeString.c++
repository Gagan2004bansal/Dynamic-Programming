#include <iostream>
#include <vector>
using namespace std;
int LCS(string &str1, string &str2, string &str3, int n, int m, int o){
    vector < vector < vector<int> > > dp(n+1, vector< vector<int> > (m+1, vector<int>(o+1, 0)));
    
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            for(int k = 1; k<=o; k++){
                if(str1[i-1] == str2[j-1] && str2[j-1] == str3[k-1]){
                    dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
                }
                else{
                    dp[i][j][k] = max(dp[i-1][j][k], max(dp[i][j-1][k], dp[i][j][k-1]));
                }
            }
        }
    }

    return dp[n][m][o];
}
int main(){

    string str1, str2, str3;
    cin >> str1;
    cin >> str2;
    cin >> str3;

    int n = str1.length();
    int m = str2.length();
    int o = str3.length();

    cout << LCS(str1, str2, str3, n, m, o) << endl;

    return 0;
}