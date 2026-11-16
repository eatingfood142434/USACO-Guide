#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n), b(n);
  for (int& i: a) cin >> i;
  for (int& i: b) cin >> i;
  vector<int> psa(n);
  psa[0] = a[0];
  for (int i = 1; i < n; i++) psa[i] = a[i] + psa[i-1];
  int ret = 0, secondmax = 0;
  for (int i = 0; i < min(n,k); i++) {
    secondmax = max(secondmax,b[i]);
    ret = max(ret,psa[i]+(k-i-1)*secondmax);
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