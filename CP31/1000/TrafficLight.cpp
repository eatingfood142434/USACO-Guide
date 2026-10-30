#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solve() {
  int n;
  char l;
  string s;
  cin >> n >> l >> s;
  s += s;

  vector<int> dist(2*n);
  for (int i = 2*n-2; i >= 0; i--) {
    if (s[i] == 'g') dist[i] = 0;
    else dist[i] = dist[i+1]+1;
  }
  int ret = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == l) ret = max(ret,dist[i]);
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) cout << solve() << "\n";
}