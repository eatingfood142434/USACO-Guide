#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;

ll dp[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    int coins[n];
    dp[0] = 1;
    for (int& i: coins) cin >> i;
    for (int c = 0; c < n; c++) {
        for (int i = 0; i <= x; i++) {
            if (i+coins[c] <= x) dp[i+coins[c]] = (dp[i+coins[c]]+dp[i])%MOD;
        }
    }
    cout << dp[x];
    
    return 0;
}