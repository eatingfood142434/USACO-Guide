#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
  int n, k, a, b;
  cin >> n >> k >> a >> b;
  vector<array<ll,2>> coords(n);
  for (auto& i: coords) cin >> i[0] >> i[1];
  array<ll,2> start = coords[a-1], end = coords[b-1];
  ll dist_a = 2*(ll)INT_MAX, dist_b = 2*(ll)INT_MAX;
  for (int i = 0; i < k; i++) {
    dist_a = min(dist_a, abs(start[0]-coords[i][0]) + abs(start[1]-coords[i][1]));
    dist_b = min(dist_b, abs(end[0]-coords[i][0]) + abs(end[1]-coords[i][1]));
  }
  return min(dist_a+dist_b, abs(start[0]-end[0]) + abs(start[1]-end[1]));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) cout << solve() << "\n";

  return 0;
}