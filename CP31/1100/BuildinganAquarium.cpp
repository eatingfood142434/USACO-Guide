#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solve() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (int& i: a) cin >> i;
  int l = 1, h = INT_MAX, m;
  while (l <= h) {
    m = l + (h-l)/2;
    ll amt = 0;
    for (int i = 0; i < n; i++) amt += max(0,m-a[i]);
    if (amt <= x) l = m+1;
    else h = m-1;
  }
  return l-1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) cout << solve() << "\n";

  return 0;
}