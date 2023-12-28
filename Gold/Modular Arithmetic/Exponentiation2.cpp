#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9+7;

ll ex(ll x, ll n, ll m) {
	assert(n >= 0);
	x %= m;
	ll res = 1;
	while (n > 0) {
		if (n % 2 == 1) res = res * x % m;
		x = x * x % m;
		n /= 2;
	}
	return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, a, b, c;
    cin >> n;
    while (n--) {
        cin >> a >> b >> c;
        ll new_b = ex(b,c,MOD-1);
        ll ret = ex(a,new_b,MOD);
        cout << ret << "\n";
    }

    return 0;
}