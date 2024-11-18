// link : https://leetcode.com/problems/triangle/

#include <iostream>
#include <vector>
using namespace std;    
int delChange[2] = {0, 1};
int recursion(int m, int n, vector< vector<int> >&triangle){
    if(m == triangle.size()){
        return 0;
    }

    int ans = INT_MAX;
    for(int i = 0; i<2; i++){
        int newCol = n + delChange[i];
        ans = min(ans, triangle[m][n] + recursion(m+1, newCol, triangle));
    }
    return ans;
}

int memo(int m, int n, vector< vector<int> >&triangle, vector< vector<int> >&dp){
    if(m == triangle.size()){
        return 0;
    }
    if(dp[m][n] != -1){
        return dp[m][n];
    }

    int ans = INT_MAX;
    for(int i = 0; i<2; i++){
        int newCol = n + delChange[i];
        ans = min(ans, triangle[m][n] + memo(m+1, newCol, triangle, dp));
    }

    dp[m][n] = ans;
    return ans;
}

void Solve(vector< vector<int> >&triangle){
    cout << recursion(0, 0, triangle) << endl;

    int m = triangle.size();
    vector< vector<int> > dp(m+1, vector<int>(m + 1, -1));
    cout << memo(0, 0, triangle, dp) << endl;
}
int main(){
    int n;
    cin >> n;

    vector< vector<int> > triangle;
    for(int i = 0; i<n; i++){
        vector<int> temp;
        for(int j = 0; j<i+1; j++){
            int input;
            cin >> input;
            temp.push_back(input);
        }
        triangle.push_back(temp);
    }

    Solve(triangle);
    return 0;
}