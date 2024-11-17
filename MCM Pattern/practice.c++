#include <iostream>
#include <vector>
using namespace std;

int minSubarray(vector<int>&arr, int k){
    int length = 0;
    int sum = 0;
    for(int i = 0; i<arr.size(); i++){
        sum += arr[i];
    }

    if(sum % k == 0) return 0;

    for(int i = 0; i<arr.size(); i++){
        if((sum - arr[i]) % k == 0){
            return 1;
        }
    }

    for(int i = 0; i<arr.size(); i++){
        sum -= arr[i];
        cout << sum << endl;
        if(sum % k == 0){
            return arr.size() - i + 1;
        }
    }


    return -1;
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << minSubarray(arr, k) << endl;
    return 0;
}