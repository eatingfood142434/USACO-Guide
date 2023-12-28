#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9+7;
ll facts[1000001], inv[1000001];

ll exp(ll x, ll n, ll m) {
	x %= m;
	ll res = 1;
	while (n > 0) {
		if (n % 2 == 1) { res = res * x % m; }
		x = x * x % m;
		n /= 2;
	}
	return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    facts[1] = 1;
    for (int i = 2; i <= 1000000; i++) facts[i] = (facts[i-1]*i)%MOD;
    inv[1000000] = exp(facts[1000000], MOD-2, MOD);
    for (int i = 1000000; i >= 1; i--) inv[i-1] = (inv[i]*i)%MOD;
    int n, a, b;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        cout << facts[a]*inv[b]%MOD*inv[a-b]%MOD << "\n";
    }
    
    return 0;
}