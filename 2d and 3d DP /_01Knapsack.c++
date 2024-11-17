#include <iostream>
#include <vector>
using namespace std;
int solveRec(int n, int capacity, int index,  vector<int>&weight, vector<int>&profit){
    // Base Case 
    if(index == n-1){
        if(weight[index] <= capacity){
            return profit[index];
        }
        else{
            return 0;
        }
    }

    int include = 0, exclude = 0;
    if(weight[index] <= capacity){
        include = profit[index] + solveRec(n, capacity - weight[index], index+1, weight, profit);
    }
    exclude = 0 + solveRec(n, capacity, index+1, weight, profit);

    return max(include, exclude);
}
int solveMemo(int n, int capacity, int index, vector<int>&weight, vector<int>&profit, vector< vector<int> > &dp){
    // Base Case
    if(index >= n){
        return 0;
    }
    // choice of taking base case 
    // if(index == n-1){
    //     if(weight[index] <= capacity){
    //         return profit[index];
    //     }
    //     else{
    //         return 0;
    //     }
    // }

    // Dp check
    if(dp[capacity][index] != -1){
        return dp[capacity][index];
    }

    int exclude = 0, include = 0;
    if(weight[index] <= capacity){
        include = profit[index] + solveMemo(n, capacity - weight[index], index+1, weight, profit, dp);
    }   
    exclude = 0 + solveMemo(n, capacity, index+1, weight, profit, dp);

    dp[capacity][index] = max(include, exclude); 
    return dp[capacity][index];
}
int solveTabu(int capacity, vector<int>&weight, vector<int>& profit){
    int n = weight.size();
    vector< vector<int> > dp(capacity + 1, vector<int>(n+1, -1));

    for(int row = 0; row <= capacity; row++){
        dp[row][n] = 0;
    }

    for(int i = 0; i<=capacity; i++){
        for(int j = n-1; j>=0; j--){
            int exclude = 0, include = 0;
            if(weight[j] <= i){
                include = profit[j] + dp[i - weight[j]][j+1];
            }   
            exclude = 0 + dp[i][j+1];

            dp[i][j] = max(include, exclude);
        }
    }
    return dp[capacity][0];
}
int solveS0(int capacity, vector<int>&weight, vector<int>& profit){
    int n = weight.size();
    vector<int> next(capacity+1, 0);
    vector<int> curr(capacity+1, 0);

    for(int j = n-1; j>=0; j--){
        for(int i = 0; i<=capacity; i++){
            int exclude = 0, include = 0;
            if(weight[j] <= i){
                include = profit[j] + next[i - weight[j]];
            }   
            exclude = 0 + next[i];

            curr[i] = max(include, exclude);
        }
        next = curr;
    }
    return next[capacity];
}
int solveS02(int capacity, vector<int>&weight, vector<int>& profit){
    int n = weight.size();
    vector<int> next(capacity+1, 0);

    for(int j = n-1; j>=0; j--){
        for(int i = capacity; i>=0; i--){
            int exclude = 0, include = 0;
            if(weight[j] <= i){
                include = profit[j] + next[i - weight[j]];
            }   
            exclude = 0 + next[i];

            next[i] = max(include, exclude);
        }
    }
    return next[capacity];
}
int main(){
    int n;
    cin >> n;

    int capacity;
    cin >> capacity;

    vector<int> weight(n);
    for(int i = 0; i<n; i++)
    {
        cin >> weight[i];
    }

    vector<int> profit(n);
    for(int i = 0; i<n; i++)
    {
        cin >> profit[i];
    }

    cout << solveRec(n, capacity, 0, weight, profit) << endl;

    vector< vector<int> > dp(capacity+1, vector<int>(n, -1));
    cout << solveMemo(n, capacity, 0, weight, profit, dp) << endl;

    cout << solveTabu(capacity, weight, profit) << endl;

    cout << solveS0(capacity, weight, profit) << endl;

    cout << solveS02(capacity, weight, profit) << endl;
 
    return 0;
}