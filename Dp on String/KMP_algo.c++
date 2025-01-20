#include<iostream>
#include<vector>
using namespace std;
int main(){
    
    string s;
    cin >> s;
    
    int n = s.length();
    vector<int> lps(n, 0);
    int pre = 0, suff = 1;
    while(suff < n){
        if(s[pre] == s[suff]){
            pre++;
            lps[suff] = pre;
            suff++;
        }
        else{
            if(pre == 0){
                lps[suff] = 0;
                suff++;
            }
            else{
                pre = lps[pre-1];
            }
        }
    }

    cout << lps[n-1] << endl;

    cout << s.substr(0, lps[n-1]) << endl;

    return 0;
}