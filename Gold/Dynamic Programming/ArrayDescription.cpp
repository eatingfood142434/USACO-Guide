#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int arr[n];
    for (int& i: arr) cin >> i;
    ll dp[n][m+2] = {};
    if (arr[0] != 0) dp[0][arr[0]] = 1;
    else for (int i = 1; i <= m; i++) dp[0][i] = 1;
    
    for (int r = 1; r < n; r++) {
        if (arr[r] != 0) dp[r][arr[r]] = (dp[r-1][arr[r]-1]+dp[r-1][arr[r]]+dp[r-1][arr[r]+1]) % MOD;
        else for (int c = 1; c <= m; c++) dp[r][c] = (dp[r-1][c-1]+dp[r-1][c]+dp[r-1][c+1]) % MOD;
    }
    ll ret = 0;
    for (int i = 0; i <= m; i++) ret = (ret+dp[n-1][i])%MOD;
    cout << ret;
    
    return 0;
}