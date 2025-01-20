#include<iostream>
#include<vector>
using namespace std;

void solve(int n, vector<int>&arr){
    // LIS 
    vector<int> dpLIS(n, 1);    
    for(int index = 0; index<n; index++){
        for(int prev = 0; prev < index; prev++){
            if(arr[index] > arr[prev] && dpLIS[index] < 1 + dpLIS[prev]){
                dpLIS[index] = 1 + dpLIS[prev];
            }
        }
    }

    // LDS
    vector<int> dpLDS(n, 1);
    for(int index = n-1; index>=0; index--){
        for(int prev = n-1; prev > index; prev--){
            if(arr[index] > arr[prev] && dpLDS[index] < 1 + dpLDS[prev]){
                dpLDS[index] = 1 + dpLDS[prev];
            }
        }
    }

    int maxi = 0;
    for(int i = 1; i<n-1; i++){
        if(dpLIS[i] > 1 && dpLDS[i] > 1){
            maxi = max(maxi, dpLIS[i] + dpLDS[i] - 1);
        }
    }

    cout << maxi << endl;
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

    solve(n, arr);

    return 0;
}