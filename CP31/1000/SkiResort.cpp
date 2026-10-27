#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
  int n, k, q;
  cin >> n >> k >> q;
  ll streak = 0, ret = 0;
  for (int i = 0, temp; i < n; i++) {
    cin >> temp;
    if (temp <= q) streak++;
    else {
      if (streak >= k) ret += (streak-k+1)*(streak-k+2)/2;
      streak = 0;
    }
  }
  if (streak >= k) ret += (streak-k+1)*(streak-k+2)/2;
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