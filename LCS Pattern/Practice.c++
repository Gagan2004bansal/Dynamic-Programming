#include <iostream>
#include <vector>

using namespace std;

void reverse(string &ans){
    int i = 0, j = ans.length() - 1;
    while (i < j)
    {   
        swap(ans[i++], ans[j--]);   
    }
}

void ShortestCommmonSub(string str1, string str2){
    int n = str1.length();
    int m = str2.length();

    vector< vector<int> > dp(n + 1, vector<int>(m+1, 0));
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

    cout << n + m - dp[n][m] << endl;


    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=m; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    string ans = "";
    int i = n, j = m;
    while(i > 0 && j > 0){
        if(str1[i-1] == str2[j-1]){
            ans += str1[i-1];
            i--;
            j--;
        }
        else if(dp[i][j-1] < dp[i-1][j]){
            ans += str1[i-1];
            i--;
        }
        else{
            ans += str2[j-1];
            j--;
        }
    }

    while(i > 0){
        ans += str1[i-1];
        i--;
    }
    
    while(j > 0){
        ans += str2[j-1];
        j--;
    }

    reverse(ans);
    cout << ans << endl; 
}

int main(){
    
    string str1, str2;
    cin >> str1 >> str2;

    ShortestCommmonSub(str1, str2);

    return 0;
}