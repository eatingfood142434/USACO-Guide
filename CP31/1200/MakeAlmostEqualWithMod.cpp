#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<ll> ref = v;
    ll m = 1;
    unordered_set<ll> r;
    while (r.size() != 2) {
      m *= 2;
      r.clear();
      for (const ll& i: v) r.insert(i % m);
    }
    cout << m << "\n";
  }

  return 0;
}