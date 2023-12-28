#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        bool bosses[n] = {};
        for (bool& i: bosses) cin >> i;
        
        vector<vector<int>> dp(2, vector<int>(n+1,1e9));
        dp[1][0] = 0;
        for (int i = 0; i < n; i++) {
            dp[0][i+1] = min(dp[0][i+1], dp[1][i]+bosses[i]);
            dp[1][i+1] = min(dp[1][i+1], dp[0][i]);
            if (i+2 <= n) {
                dp[0][i+2] = min(dp[0][i+2], dp[1][i]+bosses[i]+bosses[i+1]);
                dp[1][i+2] = min(dp[1][i+2], dp[0][i]);
            }
        }
        cout << min(dp[0][n],dp[1][n]) << "\n";
    }
    

    return 0;
}