#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, a, b, ret = 0;
bool dp[5000001][2];
void traverse(int n, bool d) {
    dp[n][d] = true;
    if (n+a <= t && !dp[n+a][d]) traverse(n+a,d);
    if (n+b <= t && !dp[n+b][d]) traverse(n+b,d);
    if (!d && !dp[n/2][1]) traverse(n/2,1);
    ret = max(ret,n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);
    cin >> t >> a >> b;
    traverse(0,0);
    cout << ret;
    
    return 0;
}