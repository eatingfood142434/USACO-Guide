#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7, MAXN = 1e6;

ll fac[MAXN + 1];
ll inv[MAXN + 1];

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

void factorial() {
	fac[0] = 1;
	for (int i = 1; i <= MAXN; i++) { fac[i] = fac[i - 1] * i % MOD; }
}

void inverses() {
	inv[MAXN] = exp(fac[MAXN], MOD - 2, MOD);
	for (int i = MAXN; i >= 1; i--) { inv[i - 1] = inv[i] * i % MOD; }
}

ll choose(int n, int r) { return fac[n] * inv[r] % MOD * inv[n - r] % MOD; }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    map<char,int> counts;
    for (char& c: s) counts[c]++;
    factorial();
    inverses();
    ll ret = 1;
    for (auto& [k,v]: counts) {
        ret = ret*choose(n,v)%MOD;
        n -= v;
    }
    cout << ret;
    
    return 0;
}