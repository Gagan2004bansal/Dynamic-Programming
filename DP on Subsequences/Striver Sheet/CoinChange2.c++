#include <iostream>
#include <vector>
using namespace std;
const int mod = 1e9 + 7;
int Memo(int n, int target, int index, int *c, vector<vector<int> > &dp)
{
    if (target == 0)
    {
        return 1;
    }
    if (index < 0 || target < 0)
    {
        return 0;
    }

    if (dp[index][target] != -1)
    {
        return dp[index][target];
    }

    int include = Memo(n, target - c[index], index, c, dp);
    int exclude = Memo(n, target, index - 1, c, dp);

    dp[index][target] = (include + exclude) % mod;
    return dp[index][target];
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

    // vector< vector<int> > dp(n+1, vector<int>(x+1, -1));
    // cout << Memo(n, x, n-1, c, dp) << endl;

    // vector< vector<int> > dp(n + 1, vector<int>(x + 1, 0));
    // for (int i = 0; i <= n; i++)
    // {
    //     dp[i][0] = 1;
    // }

    // for (int index = 0; index < n; index++)
    // {
    //     for (int target = 1; target <= x; target++)
    //     {
    //         int include = 0;
    //         if (target - c[index] >= 0)
    //         {
    //             include = dp[index][target - c[index]];
    //         }
    //         int exclude = 0;
    //         if (index > 0)
    //         {
    //             exclude = dp[index - 1][target];
    //         }

    //         dp[index][target] = (include + exclude) % mod;
    //     }
    // }

    // cout << dp[n - 1][x] << endl;

    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    for (int i = 0; i<n; i++)
    {
        for (int j = c[i]; j <= x; j++)
        {
            dp[j] = (dp[j] + dp[j - c[i]])%mod; 
        }
    }

    cout << dp[x] << endl;

    return 0;
}