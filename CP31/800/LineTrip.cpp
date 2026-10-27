#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t, n, x;
  cin >> t;
  while (t--) {
    cin >> n >> x;
    vector<int> g(n);
    int max_dist = 0;
    for (int i = 0, temp; i < n; i++) {
      cin >> g[i];
      if (i > 0) max_dist = max(max_dist, g[i]-g[i-1]);
    }
    cout << max({g[0],max_dist,2*(x-g[n-1])}) << "\n";
  }

  return 0;
}