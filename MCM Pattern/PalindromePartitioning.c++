#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(string str, int left, int right){
    while(left < right){
        if(str[left] != str[right]){
            return false;
        }
        left++;
        right--;
    }

    return true;
}

void solveBacktrack(string str, int start, vector< vector<string> >&ans, vector<string>&temp){

    // Base Case 
    if(start >= str.length()){
        ans.push_back(temp);
        return;
    }

    for(int end = start + 1; end <= str.length(); end++){
        if(isPalindrome(str, start, end - 1)){
            temp.push_back(str.substr(start, end - start));
            solveBacktrack(str, end, ans, temp);
            temp.pop_back();
        }
    }
}

int main(){

    string str;
    cin >> str;

    vector< vector<string> > ans;
    vector<string> temp;
    solveBacktrack(str, 0, ans, temp);

    for(auto it : ans){
        for(auto j : it){
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}