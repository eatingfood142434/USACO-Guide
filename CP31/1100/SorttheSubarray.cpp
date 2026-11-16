#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int& i: a) cin >> i;
  for (int& i: b) cin >> i;
  int l = 0, h = n-1;
  while (a[l] == b[l]) l++;
  while (a[h] == b[h]) h--;
  while (h+1 < n && b[h+1] >= b[h]) h++;
  while (l-1 >= 0 && b[l-1] <= b[l]) l--;
  cout << l+1 << " " << h+1 << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}