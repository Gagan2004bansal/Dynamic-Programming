#include <iostream>
#include <vector>
using namespace std;
int ShortestCommonSub(string str1, string str2){
    int n = str1.length();
    int m = str2.length();

    vector<vector<int> > dp(n+1, vector<int>(m + 1, 0));

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    return (n + m - dp[n][m]);
}
int main(){
    string str1, str2;
    cin >> str1 >> str2;

    cout << ShortestCommonSub(str1, str2) << endl;
    return 0;
}