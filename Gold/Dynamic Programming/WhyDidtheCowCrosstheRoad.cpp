#include <bits/stdc++.h>
using namespace std;
#define a first
#define b second
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("nocross.in", "r", stdin);
    freopen("nocross.out", "w", stdout);
    int n;
    cin >> n;
    int s1[n], s2[n];
    for (int& i: s1) cin >> i;
    for (int& i: s2) cin >> i;
    ll dp[n+1][n+1] = {};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = max({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]+(abs(s1[i-1]-s2[j-1]) <= 4)});
        }
    }
    cout << dp[n][n];

    return 0;
}