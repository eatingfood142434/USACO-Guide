#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
const int MAX_N = 20;

ll dp[1 << MAX_N][MAX_N];
vector<int> come_from[MAX_N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        come_from[b-1].push_back(a-1);
    }
    
    dp[1][0] = 1;
    for (int s = 2; s < (1 << n); s++) {
        if ((s & (1 << 0)) == 0) continue;
		if ((s & (1 << (n-1))) && s != ((1 << n) - 1)) continue;

        for (int end = 0; end < n; end++) {
            if ((s & (1 << end)) == 0) continue;
            
            int prev = s - (1 << end);
            for (const int& j: come_from[end]) {
                if (s & (1 << j)) dp[s][end] = (dp[s][end]+dp[prev][j])%MOD;
            }
        }
    }
    cout << dp[(1 << n)-1][n-1];
    
    return 0;
}