#include <iostream>
using namespace std;
int main(){

    int n;
    cin >> n;

    int *arr = new int[n];
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    int mini = arr[0];
    int profit = 0;

    for(int i = 1; i<n; i++){
        profit = max(profit, arr[i] - mini);
        mini = min(mini, arr[i]);
    }

    cout << profit << endl;

    return 0;
}