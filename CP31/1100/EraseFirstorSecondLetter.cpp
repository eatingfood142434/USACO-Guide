#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solve() {
  int n;
  string s;
  cin >> n >> s;
  int ret = 0;
  unordered_map<char,bool> found;
  for (int i = 0; i < n; i++) {
    if (!found[s[i]]) ret += n-i;
    found[s[i]] = true;
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