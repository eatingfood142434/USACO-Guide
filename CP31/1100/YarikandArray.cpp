#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& i: a) cin >> i;
  int parity = (a[0] % 2 == 1) ? 0 : 1;
  vector<pair<int,int>> inds;
  int l = 0, h = 0;
  for (int i = 0; i < n; i++) {
    if (abs(a[i] % 2) == parity) {
      inds.push_back({l,h});
      l = i;
    }
    h = i;
    parity = abs(a[i] % 2);
  }
  inds.push_back({l,h});
  int ret = INT_MIN;
  for (const auto& [b,e]: inds) {
    int curr = a[b], lmax = a[b];
    for (int i = b+1; i <= e; i++) {
      if (curr < 0) curr = 0;
      curr += a[i];
      lmax = max(lmax,curr);
    }
    ret = max(ret,lmax);
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