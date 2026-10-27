#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solve() {
  int n;
  cin >> n;
  vector<char> a(n);
  for (char& c: a) cin >> c;
  unordered_map<char> occ1, occ2;
  int ret = 0, max1 = 0, max2 = 0;
  
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) cout << solve() << "\n";
}