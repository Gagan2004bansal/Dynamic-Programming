#include <iostream>
#include <vector>
using namespace std;
// Printing and Maximum lIS
void PrintingLIS(int n, vector<int>&arr){
    vector<int> dp(n, 1), hash(n);
    int maxi = 1;
    int lastIndex = 0;
    for(int index = 0; index<n; index++){
        hash[index] = index;
        for(int prev = 0; prev < index; prev++){
            if(arr[index] > arr[prev] && dp[index] < 1 + dp[prev]){
                dp[index] = 1 + dp[prev];
                hash[index] = prev;
            }
        }

        if(dp[index] > maxi){
            maxi = dp[index];
            lastIndex = index;
        }
    }

    cout << maxi << endl;
    // Printing LIS
    vector<int> ans;
    ans.push_back(arr[lastIndex]);
    while(hash[lastIndex] != lastIndex){
        lastIndex = hash[lastIndex];
        ans.push_back(arr[lastIndex]);
    }

    reverse(ans.begin(), ans.end());
    
    cout << "Longest Increasing Subsequence : ";
    for(int i = 0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}
// Longest Divisible Subset
void LongestDivisibleSubset(int n, vector<int>&arr){
    sort(arr.begin(), arr.end());
    vector<int> dp(n, 1), hash(n);
    int maxi = 1, lastIndex = 0;
    for(int index = 0; index < n; index++){
        hash[index] = index;
        for(int prev = 0; prev < index; prev++){
            if((arr[index] % arr[prev] == 0 || arr[prev] % arr[index] == 0) && (dp[index] < 1 + dp[prev])){
                dp[index] = 1 + dp[prev];
                hash[index] = prev;
            }
        }

        if(dp[index] > maxi){
            maxi = dp[index];
            lastIndex = index;
        }
    }

    cout << "Largest Divisible Subset Size : " << maxi << endl;
    vector<int> ans;
    ans.push_back(arr[lastIndex]);
    while(lastIndex != hash[lastIndex]){
        lastIndex = hash[lastIndex];
        ans.push_back(arr[lastIndex]);
    }

    reverse(ans.begin(), ans.end());

    cout << "Largest Divisible Subset : ";
    for(int i = 0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}
// Number of Longest Increasing Subsequence
void CountLIS(int n, vector<int> &arr){
    int maxi = 1;
    vector<int> dp(n,1), hash(n,1);
    // dp ye btata h ke m pichle kitne element se bda hu
    for(int index = 0; index < n; index++){
        for(int prev = 0; prev < index; prev++){
            if(arr[index] > arr[prev] && dp[index] < 1 + dp[prev]){
                dp[index] = 1 + dp[prev];
                hash[index] = hash[prev];
            }
            else if(arr[index] > arr[prev] && dp[index] == 1 + dp[prev]){
                hash[index] += hash[prev];
            }
        }

        maxi = max(maxi, dp[index]);
    }

    int count = 0;
    for(int i = 0; i<n; i++){
        if(dp[i] == maxi){
            count += hash[i];
        }
    }

    cout << "Count of LIS : " << count << endl;
}
int main(){

    int n;
    cin >> n;

    vector<int> arr;
    for(int i = 0; i<n; i++){
        int input;
        cin >> input;
        arr.push_back(input);
    }

    // PrintingLIS(n, arr);

    // LongestDivisibleSubset(n, arr);

    CountLIS(n, arr);

    return 0;
}