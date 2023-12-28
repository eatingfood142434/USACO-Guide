#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<ll> cows(n), canes(m), ret(n,-1);
    for (ll& i: cows) cin >> i;
    for (ll& i: canes) cin >> i;
    
    for (int i = 0; i < m; i++) {
        ll pre = 0;
        for (int c = 0; c < n; c++) {
            if (pre > cows[c]) continue;
            else if (cows[c] > canes[i]) {
                cows[c] += canes[i]-pre;
                break;
            }
            ll b = cows[c];
            cows[c] += cows[c]-pre;
            pre = b;
        }
    }
    for (ll& i: cows) cout << i << "\n";
    
    return 0;
}