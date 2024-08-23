#include <iostream>
#include <vector>
using namespace std;
bool isSubsequence(string str1, string str2){
    int i = 0, j = 0;
    while(i < str1.length() && j < str2.length()){
        if(str1[i] == str2[j]){
            i++;
        }
        j++;
    }

    return i == str1.length();
}
int main(){
    string str1, str2;
    cin >> str1 >> str2;

    cout << isSubsequence(str1, str2) << endl;
    return 0;
}