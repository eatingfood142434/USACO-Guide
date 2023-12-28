#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int v[n];
    for (int& i: v) cin >> i;
    bool dp[k+1][k+1] = {};
    dp[0][0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = k; j >= 0; j--) {
            if (j-v[i] >= 0) {
                for (int sum = j-v[i]; sum >= 0; sum--) {
                    if (dp[j-v[i]][sum]) {
                        if (sum+v[i] <= k) dp[j][sum+v[i]] = true;
                        dp[j][sum] = true;
                    }
                }
            }
        }
    }
    
    int ret = 0;
    for (const bool& i: dp[k]) ret += i;
    cout << ret << "\n";
    for (int i = 0; i <= k; i++) if (dp[k][i]) cout << i << " ";
    
    return 0;
}