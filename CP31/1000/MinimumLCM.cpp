#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, d = 1;
  cin >> n;
  for (int i = 2; i*i <= n; i++) {
    if (n % i == 0) {
      d = i;
      break;
    }
  }
  if (d == 1) cout << 1 << " " << n-1 << "\n";
  else cout << n/d << " " << n-n/d << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t, n;
  cin >> t;
  while (t--) solve();
}