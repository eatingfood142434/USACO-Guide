#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
  string s;
  cin >> s;
  if (s[s.size()-1] == '1') {
    ll l = 0;
    while (l < s.size() && s[l] == '1') l++;
    if (l == s.size()) return l*l;
    for (int i = 0; i < l; i++) s += '1';
  }
  ll w = 0, amt = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '0') amt = 0;
    else {
      amt++;
      w = max(w,amt);
    }
  }
  // cerr << w << "\n";
  if (w % 2 == 0) return (w/2)*(w/2+1);
  else return (w/2+1)*(w/2+1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) cout << solve() << "\n";

  return 0;
}