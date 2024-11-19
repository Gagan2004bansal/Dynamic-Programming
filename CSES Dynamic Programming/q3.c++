// link : https://cses.fi/problemset/task/1635/

#include <iostream>
#include <vector>

using namespace std;

const int mod = 1e9 + 7;
int Memo(int index, int target, int *c, int n, vector<int> &dp)
{
    // Base Case
    if (target == 0)
    {
        return 1;
    }
    if (target < 0)
    {
        return 0;
    }

    // DP check
    if (dp[target] != -1)
    {
        return dp[target];
    }

    int include = 0;
    for (int i = 0; i < n; i++)
    {
        if (target - c[i] >= 0)
        {
            include = (include + Memo(i, target - c[i], c, n, dp)) % mod;
        }
    }

    return dp[target] = include;
}

int main()
{

    int n, x;
    cin >> n >> x;

    int *c = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    vector<int> dp(x + 1, -1);
    cout << Memo(n - 1, x, c, n, dp) << endl;
    return 0;
}