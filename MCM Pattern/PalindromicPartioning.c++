#include <iostream>
#include <vector>

using namespace std;

void palindromeCompute(string s, vector< vector<int> > &isPalindrome){

    int n = s.length();

    for(int i = 0; i<n; i++){
        isPalindrome[i][i] = 1;
    }

    for(int len = 2; len<=n; len++){
        for(int i = 0; i <= n - len; i++){
            int j = i + len - 1;

            if(s[i] == s[j]){
                isPalindrome[i][j] = (len == 2) ? true : isPalindrome[i+1][j-1];
            }
        }
    }
}

int solve(string str, int i, int j, vector< vector<int> >&isPalindrome, vector<int>&dp){
    // Base Case 
    if(i >= j){
        return 0;
    }   

    if(isPalindrome[i][j]){
        return 0;
    }

    // DP check
    if(dp[i] != -1){
        return dp[i];
    }

    int ans = INT_MAX;
    for(int k = i; k<j; k++){
        if(isPalindrome[i][k]){
            int value = 1 + solve(str, k+1, j, isPalindrome, dp);
            ans = min(ans, value);
        }
    }

    return dp[i] = ans;
}

int main(){
    
    string str;
    cin >> str;

    int n = str.length();
    vector<vector<int> > isPalindrome(n + 1, vector<int>(n+1, 0));
    palindromeCompute(str, isPalindrome);


    vector<int> dp(n+1, -1);
    cout << solve(str, 0, n-1, isPalindrome, dp) << endl;
    
    return 0;
}