#include <iostream>
#include <vector>
using namespace std;
string PrintLCS(string str1, string str2){
    int n = str1.length();
    int m = str2.length();

    vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
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


    string ans = "";
    int i = n, j = m;
    while(i > 0 && j > 0){
        if(str1[i-1] == str2[j-1]){
            ans += str1[i-1];
            i--; 
            j--;
        }
        else if(dp[i][j-1] > dp[i-1][j]){
            j--;
        }
        else{
            i--;
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}
int main(){
    
    string str1, str2;
    cin >> str1 >> str2;

    cout << PrintLCS(str1 , str2) << endl;

    return 0;
}