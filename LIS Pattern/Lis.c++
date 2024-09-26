// Longest Increasing Subsequence
#include <iostream>
#include <vector>
using namespace std;
int solveUsingRec(int n, int index, vector<int>&arr, int prev){
    if(index == n){
        return 0;
    }

    int len = 0 + solveUsingRec(n, index+1, arr, prev);
    if(prev == -1 || arr[index] > arr[prev]){
        len = 1 + solveUsingRec(n, index+1, arr, index);
    }

    return len;
}
// Memoization
int solveUsingMemo(int n, int index, vector<int>&arr, int prev, vector< vector<int> >&dp){
    if(index == n){
        return 0;
    }

    // DP check
    if(dp[index][prev+1] != -1){
        return dp[index][prev+1];
    }

    int len = 0 + solveUsingMemo(n, index+1, arr, prev, dp);
    if(prev == -1 || arr[index] > arr[prev]){
        len = 1 + solveUsingMemo(n, index+1, arr, index, dp);
    }

    return dp[index][prev+1] = len;
}
// Tabulation
int solveUsingTabu(int n, vector<int>&arr){
    
    vector< vector<int> > dp(n+1, vector<int>(n+1, 0));
    for(int index = n-1; index>=0; index--){
        for(int prev = index-1; prev>=-1; prev--){
            int len = 0 + dp[index+1][prev+1];
            if(prev == -1 || arr[index] > arr[prev]){
                len = 1 + dp[index+1][index+1];
            }

            dp[index][prev+1] = len;
        }
    }

    return dp[0][0];
}
// Space Optimized 

// Intuition: The most optimized approach uses binary search to find the correct position in an array (temp) 
// where the current element should be placed to maintain the increasing order.
// If the element is larger than the last element, it's appended; otherwise,
// it replaces the smallest possible element that is larger than or equal to it.
// This doesn't give the actual subsequence but gives the length of the LIS.
// Time Complexity: O(n log n) because of binary search.

int solveUsingSO(int n, vector<int>&arr){
    vector<int> dp(n, 1), hash(n);
    int maxi = 1;
    int lastIndex = 0;
    for(int i = 0; i<n; i++){
        hash[i] = i;
        for(int prev = 0; prev < i; prev++){
            if(arr[prev] < arr[i] && dp[i] < dp[prev] + 1 ){
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }

        if(dp[i] > maxi){
            maxi = dp[i];
            lastIndex = i;
        }
    }

    vector<int> temp;
    temp.push_back(arr[lastIndex]);
    while(hash[lastIndex] != lastIndex){
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }

    reverse(temp.begin(), temp.end());
    cout << "Longest Increasing Subsequence \n";
    for(auto it : temp){
        cout << it << " ";
    }   
    cout << endl;

    return maxi;
}
// Optimized Approach -> Binary Search
int solveUsingPRO(int n , vector<int>&arr){
    vector<int> temp;
    temp.push_back(arr[0]);
    int len = 1;

    for(int i = 1; i<n; i++){
        if(arr[i] > temp.back()){
            temp.push_back(arr[i]);
            len++;
        }
        else{
            int index = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[index] = arr[i];
        }
    }

    return len;
}
int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    cout << solveUsingRec(n, 0, arr, -1) << endl; // GIVES TLE 
    vector< vector<int> > dp(n+1, vector<int>(n+1, -1));
    cout << solveUsingMemo(n, 0, arr, -1, dp) << endl; // GIVES TLE 
    cout << solveUsingTabu(n, arr) << endl; // GIVES TLE 
    cout << solveUsingSO(n, arr) << endl; // GIVES TLE  : usefull when to display the sequence 

    cout << solveUsingPRO(n, arr) << endl; // ULTRA OTIMIZED APPROACH 
    return 0;
}