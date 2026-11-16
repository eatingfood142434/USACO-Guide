#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
  ll n, c;
  cin >> n >> c;
  vector<ll> s(n);
  for (ll& i: s) cin >> i;
  ll l = 0, h = 1, m;
  int found = false;
  while (!found) {
    h *= 2;
    ll curr = 0;
    for (ll& i: s) {
      curr += (i+2*h)*(i+2*h);
      if (curr > c) {
        found = true;
        break;
      }
    }
  }
  while (l <= h) {
    m = l + (h-l)/2;
    ll curr = 0;
    for (ll& i: s) curr += (i+2*m)*(i+2*m);
    if (curr > c) h = m-1;
    else if (curr < c) l = m+1;
    else break;
  }
  return m;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) cout << solve() << "\n";

  return 0;
}