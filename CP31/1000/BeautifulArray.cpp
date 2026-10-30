#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  ll n, k, b, s;
  cin >> n >> k >> b >> s;
  ll rem = b%n, div = b/n;
  vector<ll> a(n,k*div);
  for (ll i = 0; i < rem; i++) a[i] += k;
  ll diff = s-b*k;
  if (diff < 0 || diff > (k-1)*n) cout << -1 << "\n";
  else {
    for (int i = 0; i < n && diff > 0; i++) {
      if (diff <= k-1) {
        a[i] += diff;
        break;
      }
      else {
        diff -= k-1;
        a[i] += k-1;
      }
    }
    for (const ll& i: a) cout << i << " ";
    cout << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();

  return 0;
}