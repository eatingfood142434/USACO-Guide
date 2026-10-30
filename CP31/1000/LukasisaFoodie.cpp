#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solve() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (int& i: a) cin >> i;
  int l = a[0], h = a[0], ret = 0;
  for (int i = 0; i < n; i++) {
    l = min(l,a[i]);
    h = max(h,a[i]);
    // cerr << "i = " << i << ", a[i]: " << a[i] << ", l: " << l << ", h: " << h << "\n"; 
    if (h-l > 2*x) {
      // cerr << "reset at i = " << i << ", a[i]: " << a[i] << ", l: " << l << ", h: " << h << "\n"; 
      ret++;
      l = a[i];
      h = a[i];
    }
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) cout << solve() <<  "\n";

  return 0;
}