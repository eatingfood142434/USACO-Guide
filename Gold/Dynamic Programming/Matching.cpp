#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;

ll dp[1<<21];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    bool arr[n][n];
    for (auto& a: arr) for (bool& b: a) cin >> b;
    
    dp[0] = 1;
    for (int s = 0; s < (1 << n); s++) {
        int amt_men = __builtin_popcount(s);
        for (int w = 0; w < n; w++) {
            if (!(s & (1 << w)) && arr[amt_men][w]) dp[s|(1 << w)] = (dp[s|(1 << w)] + dp[s]) % MOD;
        }
    }
    cout << dp[(1 << n)-1];
    
    return 0;
}