#include <iostream>
#include <vector>
using namespace std;
int LongestCommonSubstring(string str1, string str2){
    int n = str1.length();
    int m = str2.length();

    vector< vector<int> > dp(n+1, vector<int>(m+1, 0));

    int maxLen = 0;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                maxLen = max(maxLen, dp[i][j]);
            }
            else{
                dp[i][j] = 0;
            }
        }
    }

    return maxLen;
}
int main(){
    string str1, str2;
    cin >> str1 >> str2;

    cout << LongestCommonSubstring(str1, str2) << endl;
    return 0;
}