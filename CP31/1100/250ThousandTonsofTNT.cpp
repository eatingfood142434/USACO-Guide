#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (ll& i: a) cin >> i;
  vector<ll> psa(n);
  psa[0] = a[0];
  for (int i = 1; i < n; i++) psa[i] = abs(a[i] + psa[i-1]);
  ll ret = a[n-1]-a[0];
  for (int i = 1; i*i <= n; i++) {
    if (n % i == 0) {
      ll l = psa[i-1], h = psa[i-1];
      for (int k = i; k < n; k += i) {
        l = min(l, psa[k+i-1]-psa[k-1]);
        h = max(h, psa[k+i-1]-psa[k-1]);
      }
      // cerr << "n: " << n << " i: " << i << " l: " << l << " h: " << h << "\n";
      ret = max(ret,h-l);
      l = psa[n/i-1], h = psa[n/i-1];
      for (int k = n/i; k < n; k += n/i) {
        l = min(l, psa[k+n/i-1]-psa[k-1]);
        h = max(h, psa[k+n/i-1]-psa[k-1]);
      }
      // cerr << "n: " << n << " n/i: " << n/i << " l: " << l << " h: " << h << "\n";
      ret = max(ret,h-l);
    }
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) cout << solve() << "\n";

  return 0;
}