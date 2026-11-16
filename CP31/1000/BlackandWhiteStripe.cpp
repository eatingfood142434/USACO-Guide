#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solve() {
  int n, m, k;
  cin >> n >> k;
  vector<int> a(n);
  char c;
  for (int& i: a) {
    cin >> c;
    i = (c == 'B') ? 0 : 1;
  }
  int curr = 0;
  for (int i = 0; i < k; i++) curr += a[i];
  int ret = curr;
  for (int i = 0; i < n-k; i++) {
    curr -= a[i];
    curr += a[i+k];
    ret = min(ret,curr);
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