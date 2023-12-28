#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[500001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int mx = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        if (c == k) ++cnt;
        else dp[c] = max(dp[c], cnt) + 1;
        mx = max(mx, dp[c]-cnt);
    }
    cout << mx+cnt;
}