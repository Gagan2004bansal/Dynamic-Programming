// link : https://leetcode.com/problems/maximum-total-damage-with-spell-casting/description/

#include <iostream>
#include <vector>
using namespace std;
long long SolveUsingRec(int index, vector<int> &power)
{
    if (index >= power.size())
        return 0;

    long long p = 0;
    int i = index;
    while (i < power.size() && power[i] == power[index]){
        p += power[i];
        i++;
    }

    int ind1 = i;

    while (i < power.size() && power[i] == power[index] + 1)
    {
        i++;
    }
    while (i < power.size() && power[i] == power[index] + 2)
    {
        i++;
    }

    int ind2 = i;

    return max(p + SolveUsingRec(ind2, power), SolveUsingRec(ind1, power));
}
long long Memo(int index, vector<int>&power, vector<int>&dp){
    if(index >= power.size()) return 0;

    if(dp[index] != -1) return dp[index];

    long long p = 0;
    int i = index;
    while(i < power.size() && power[i] == power[index]){
        p += power[i];
        i++;
    }

    int indx1 = i;

    while(i < power.size() && power[i] == power[index] + 1){
        i++;
    }
    while(i < power.size() && power[i] == power[index] + 2){
        i++;
    }

    int indx2 = i;

    dp[index] = max(p + Memo(indx2, power, dp), Memo(indx1, power, dp));
    return dp[index];
}
void Solve(vector<int> &power)
{
    sort(power.begin(), power.end());
    cout << SolveUsingRec(0, power) << endl;

    vector<int> dp(1e6, -1 );
    cout << Memo(0, power, dp) << endl;
}
int main()
{

    int n;
    cin >> n;

    vector<int> power(n);
    for (int i = 0; i < n; i++)
    {
        cin >> power[i];
    }

    Solve(power);

    return 0;
}