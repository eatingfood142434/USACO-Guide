#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, s = 0, ret = 0;
    cin >> n;
    int coins[n];
    for (int& i: coins) {
        cin >> i;
        s += i;
    }
    bool dp[s+1] = {}; dp[0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = s; j >= 0; j--) {
            if (j+coins[i] <= s && dp[j] == true) dp[j+coins[i]] = true;
        }
    }
    for (const bool& i: dp) ret += i;
    cout << ret-1 << "\n";
    for (int i = 1; i <= s; i++) if (dp[i]) cout << i << " ";
    
    return 0;
}