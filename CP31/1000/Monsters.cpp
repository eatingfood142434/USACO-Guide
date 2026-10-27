#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<pair<int,int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  for (int i = 0; i < n; i++) {
    if (a[i].first > k) {
      a[i].first %= k;
      if (a[i].first == 0) a[i].first = k;
    }
  }
  
  sort(a.begin(),a.end(),
  [](const auto& p1, const auto& p2) {
    if (p1.first == p2.first) return p1.second < p2.second;
    else return p1.first > p2.first;
  });
  // for (int i = 0; i < n; i++) cout << a[i].first << "," << a[i].second << " ";
  // cout << "\n";
  for (const auto& p: a) cout << p.second+1 << " ";
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();

  return 0;
}