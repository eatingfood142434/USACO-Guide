#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t, n, k;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    int prev;
    cin >> prev;
    bool sorted = true;
    for (int i = 1, temp; i < n; i++) {
      cin >> temp;
      if (prev > temp) sorted = false;
      prev = temp;
    }
    if (sorted || k > 1) cout << "YES\n";
    else cout << "NO\n";
  }

  return 0;
}