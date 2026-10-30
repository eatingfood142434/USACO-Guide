#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& i: a) cin >> i;
  map<int,int> occ;
  for (int& i: a) occ[i]++;
  for (auto& [k,v]: occ) {
    if (v == 1) {
      cout << "-1\n";
      return;
    }
  }
  int curr = 0;
  for (auto& [k,v]: occ) {
    cout << curr+v << " ";
    for (int i = 1; i < v; i++) cout << curr+i << " ";
    curr += v;
  }
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