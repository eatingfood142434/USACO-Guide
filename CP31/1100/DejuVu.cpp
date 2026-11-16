#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, q;
  cin >> n >> q;
  vector<ll> a(n), x(q);
  for (ll& i: a) cin >> i;
  for (ll& i: x) cin >> i;
  vector<ll> ops;
  ops.push_back(pow(2,x[0]));
  for (int i = 1; i < q; i++) {
    if (pow(2,x[i]) < ops.back()) ops.push_back(pow(2,x[i]));
  }
  vector<ll> adds(ops.size());
  for (int i = 0; i < ops.size(); i++) {
    ll curr = 0;
    for (int j = i; j < ops.size(); j++) curr += ops[j]/2;
    adds[i] = curr;
  }
  for (int i = 0; i < n; i++) {
    int ind = 0;
    while (ind < ops.size() && a[i] % ops[ind] != 0) ind++;
    if (ind == ops.size()) cout << a[i] << " ";
    else cout << a[i] + adds[ind] << " ";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();

  return 0;
}