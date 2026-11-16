#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int& i: a) cin >> i;
  sort(a.begin(), a.end());
  vector<ll> psa(n);
  psa[0] = a[0];
  for (int i = 1; i < n; i++) psa[i] = psa[i-1] + a[i];
  ll ret = psa[n-k-1];
  for (int i = 2; i <= 2*k; i += 2) {
    int h = n-(k-i/2)-1;
    ret = max(ret,psa[h]-psa[i-1]);
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