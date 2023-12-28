#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dist(const pair<int,int>& a, const pair<int,int>& b) {
	int x = (a.first-b.first);
	int y = (a.second-b.second);
	return x*x+y*y;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("checklist.in", "r", stdin);
    freopen("checklist.out", "w", stdout);
    int h, g;
    cin >> h >> g;
    pair<int,int> hc[h], gc[g];
    for (auto& [r,c]: hc) cin >> r >> c;
    for (auto& [r,c]: gc) cin >> r >> c;
    vector<vector<vector<ll>>> dp(h+1, vector<vector<ll>>(g+1, vector<ll>(2, 1e18)));
    dp[1][0][0] = 0;
    for (int i = 0; i <= h; i++) {
        for (int j = 0; j <= g; j++) {
            if (i > 1) dp[i][j][0] = min(dp[i][j][0], dp[i-1][j][0] + dist(hc[i-1],hc[i-2]));
            if (j > 1) dp[i][j][1] = min(dp[i][j][1], dp[i][j-1][1] + dist(gc[j-1],gc[j-2]));
            if (i > 0 && j > 0) {
                dp[i][j][0] = min(dp[i][j][0], dp[i-1][j][1] + dist(hc[i-1],gc[j-1]));
                dp[i][j][1] = min(dp[i][j][1], dp[i][j-1][0] + dist(hc[i-1],gc[j-1]));
            }
        }
    }
    cout << dp[h][g][0];
    
    return 0;
}