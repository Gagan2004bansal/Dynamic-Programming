#include <iostream>
#include <vector>
using namespace std;
int MinDeletionToMakeStringPalindromin(string str1, string str2){
    int n = str1.length();
    int m = str2.length();

    vector< vector<int> > dp(n+1, vector<int>(m+1, 0));
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

    return str1.length() - dp[n][m];
}
int main(){
    string str1;
    cin >> str1;

    string str2 = str1;
    reverse(str2.begin(), str2.end());

    cout << MinDeletionToMakeStringPalindromin(str1, str2) << endl;

    return 0;
}