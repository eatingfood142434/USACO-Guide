#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    char grid[n][n];
    for (auto& a: grid) for (char& b: a) cin >> b;
    ll dp[n+1][n+1] = {};
    dp[1][1] = (grid[0][0] == '.');
    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= n; c++) {
            if (grid[r-1][c-1] == '.') {
                dp[r][c] += dp[r][c-1]+dp[r-1][c];
                if (dp[r][c] >= MOD) dp[r][c] -= MOD;
            }
        }
    }
    cout << dp[n][n];
    
    return 0;
}