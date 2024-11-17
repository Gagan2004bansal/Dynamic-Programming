// Condition : No two adjacent posts have the same color
// Given : N posts , K colors

#include <iostream>
#include <vector>
using namespace std;
int solveUsingRec(int n, int k){
    // Base Case 
    if(n <= 2){
        if(n == 1){
            return k;
        }
        else{
            return k + k*(k-1);
        }
    }

    int same = (k-1)*solveUsingRec(n-1, k);
    int diff = (k-1)*solveUsingRec(n-2, k);

    return same + diff;
}
int solveMemo(int n, int k, vector<int>&dp){
    // Base Case 
    if(n <= 2){
        if(n == 1){
            return k;
        }
        else{
            return k + k*(k-1);
        }
    }

    // Dp check
    if(dp[n] != -1){
        return dp[n];
    }

    int same = (k-1)*solveUsingRec(n-1, k);
    int diff = (k-1)*solveUsingRec(n-2, k);

    return dp[n] = same + diff;
}
int solveTabu(int n, int k){
    vector<int> dp(n+1, 0);
    dp[1] = k;
    dp[2] = k + k * (k - 1);
    for(int i = 3; i<=n; i++){
        dp[i] = (dp[i-1] + dp[i-2])*(k-1);
    }

    return dp[n];
}
int solveSO(int n, int k){
    int curr = 0;
    int prev2 = k;
    if(n == 1){
        return prev2;
    }
    int prev1 = k + k * (k-1);
    if(n == 2){
        return prev1;
    }
    for(int i = 3; i<=n; i++){
        curr = (prev1 + prev2)*(k-1);
        prev2 = prev1;
        prev1 = curr;
    }

    return curr ;
}
int main() {
    int n;
    cin >> n;

    int k;
    cin >> k; 

    cout << solveUsingRec(n, k) << endl;

    vector<int> dp(n+1, -1);
    cout << solveMemo(n, k, dp) << endl;

    cout << solveTabu(n, k) << endl;

    cout << solveSO(n, k) << endl;

    return 0;
}