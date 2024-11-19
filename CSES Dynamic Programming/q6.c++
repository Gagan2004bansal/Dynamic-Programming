#include <iostream>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;

int Memo(vector< vector<char> >&arr, int m, int n, vector< vector<int> >&dp){
    if(m == 0 && n == 0){
        return 1;
    }

    if(dp[m][n] != -1){
        return dp[m][n];
    }

    // up 
    int up = 0;
    if(m - 1 >= 0 && arr[m-1][n] != '*'){
        up = Memo(arr, m-1, n, dp);
    }
    // left
    int left = 0;
    if(n - 1 >= 0 && arr[m][n-1] != '*'){
        left = Memo(arr, m, n-1, dp);
    }

    dp[m][n] = (left + up) % mod;
    return dp[m][n];
}

int main() {

    int n;
    cin >> n;

    vector< vector<char> > arr(n, vector<char>(n, '.'));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    if(arr[0][0] == '*' || arr[n-1][n-1] == '*'){
        cout << 0 << endl;
    }
    else {
        vector< vector<int> > dp(n , vector<int>(n, -1));
        cout << Memo(arr, n-1, n-1, dp) << endl;
    }

    return 0;
}


