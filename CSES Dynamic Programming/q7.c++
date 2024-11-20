#include <iostream>
#include <vector>
#include <climits>

using namespace std;
const int mod = 1e9 + 7;
int memo(int n, int x, vector<int> &price, vector<int> &pages, int index, vector< vector<int> > &dp)
{
    if (index == 0 || x == 0)
    {
        return 0;
    }

    if (dp[index][x] != -1)
    {
        return dp[index][x];
    }

    int include = 0;
    if (x - price[index - 1] >= 0)
    {
        include = (pages[index - 1] + memo(n, x - price[index - 1], price, pages, index - 1, dp)) % mod;
    }
    int exclude = memo(n, x, price, pages, index - 1, dp);

    dp[index][x] = max(include, exclude);
    return dp[index][x];
}
int Tabu(int n, int x, vector<int> &prices, vector<int> &pages)
{
    vector< vector<int> > dp(n + 1, vector<int>(x + 1, 0));

    for (int index = 1; index <= n; index++)
    {
        for (int amount = 1; amount <= x; amount++)
        {
            int include = 0, exclude = 0;
            if (amount - prices[index-1] >= 0)
            {
                include = pages[index-1] + dp[index - 1][amount - prices[index-1]];
            }
            exclude = dp[index - 1][amount];

            dp[index][amount] = max(include, exclude);
        }
    }

    return dp[n][x];
}

int SO(int n, int x, vector<int> &prices, vector<int> &pages)
{
    vector<int> curr(x+1, 0);
    vector<int> prev(x+1, 0);

    for (int index = 1; index <= n; index++)
    {
        for (int amount = 1; amount <= x; amount++)
        {
            int include = 0, exclude = 0;
            if (amount - prices[index-1] >= 0)
            {
                include = pages[index-1] + prev[amount - prices[index-1]];
            }
            exclude = prev[amount];

            curr[amount] = max(include, exclude);
        }
        prev = curr;
    }

    return curr[x];
}

int main()
{

    int n, x;
    cin >> n >> x;

    vector<int> price(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }

    vector<int> pages(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
    }

    // vector< vector<int> > dp(n + 1, vector<int>(x + 1, -1));
    // cout << memo(n, x, price, pages, n, dp) << endl;

    cout << SO(n, x, price, pages) << endl;

    return 0;
}