// link : https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=knapsack-with-duplicate-items

#include <iostream>
#include <vector>
using namespace std;
int solveUsingRec(int n, int weight, vector<int>&val, vector<int>&CurrW){
    // Base Case
    if(weight == 0 || n == 0){
        return 0;
    }

    if(CurrW[n] <= weight){
        return max(val[n] + solveUsingRec(n, weight - CurrW[n], val, CurrW), solveUsingRec(n-1, weight, val, CurrW));
    }   
    else{
        return solveUsingRec(n-1, weight, val, CurrW);
    }
}
int solveUsingMemo(int n, int weight, vector<int>&val, vector<int>&CurrW, vector< vector<int> >&dp){
    // Base Case
    if(weight == 0 || n == 0){
        return 0;
    }

    // DP Check
    if(dp[n][weight] != -1){
        return dp[n][weight];
    }

    if(CurrW[n] <= weight){
        return dp[n][weight] = max(val[n] + solveUsingMemo(n, weight - CurrW[n], val, CurrW, dp), solveUsingMemo(n-1, weight, val, CurrW, dp));
    }
    else{
        return dp[n][weight] = solveUsingMemo(n-1, weight, val, CurrW, dp);
    }
}
int solveTabu(int n, int weight, vector<int>&val, vector<int>&CurrW){

    vector<int> dp(weight + 1, 0); 
    for(int i = 0; i<n; i++){
        for(int wt = CurrW[i]; wt <= weight; wt++){
            dp[wt] = max(dp[wt], dp[wt - CurrW[i]] + val[i]);
        }
    }

    return dp[weight];
}
int main(){
    int n;
    cin>>n;

    vector<int> val;
    for(int i = 0; i<n; i++){
        int input;
        cin >> input;
        val.push_back(input);
    }

    vector<int> CurrW;
    for(int i = 0; i<n; i++){
        int input;
        cin >> input;
        CurrW.push_back(input);
    }

    int weight;
    cin >> weight;

    cout << solveUsingRec(n-1, weight, val, CurrW) << endl;

    vector< vector<int> > dp(n, vector<int>(weight + 1, -1));
    cout << solveUsingMemo(n-1, weight, val, CurrW, dp) << endl;

    cout << solveTabu(n-1, weight, val, CurrW) << endl; 

    return 0;
}