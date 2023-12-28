#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if ((n*(n+1)/2)%2 == 1) {cout << 0; return 0;}
    int s = n*(n+1)/4;
    ll dp[s+1] = {}; dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = s; j >= 0; j--) if (j+i <= s) dp[j+i] = (dp[j]+dp[j+i])%(2*MOD);
    }
    cout << dp[s]/2;
    
    return 0;
}