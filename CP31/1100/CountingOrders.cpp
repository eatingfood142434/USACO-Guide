#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1000000007;

int solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int& i: a) cin >> i;
  for (int& i: b) cin >> i;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  ll ret = 1;
  int h = n-1, l = n-1;
  while (l >= 0) {
    while (h >= 0 && a[h] > b[l]) h--;
    ret *= l-h;
    ret %= MOD;
    // cerr << l << " " << h << "\n";
    l--;
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