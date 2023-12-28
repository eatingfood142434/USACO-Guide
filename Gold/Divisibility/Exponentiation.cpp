#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, a, b;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        ll ret = 1;
        while (b > 0) {
            if (b&1) ret = (ret*a)%MOD;
            a = (a*a)%MOD;
            b >>= 1;
        }
        cout << ret << "\n";
    }

    return 0;
}