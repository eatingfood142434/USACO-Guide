#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& i: a) cin >> i;
  vector<pair<int,int>> pairs(n);
  for (int i = 0; i < n; i++) pairs[i] = {a[i],i};
  vector<int> new_ind(n);
  sort(a.begin(), a.end());
  sort(pairs.begin(), pairs.end());
  for (int i = 0; i < n; i++) new_ind[pairs[i].second] = i;
  vector<ll> psa(n);
  psa[0] = a[0];
  for (int i = 1; i < n; i++) psa[i] = a[i] + psa[i-1];
  for (int i = 0; i < n; i++) {
    ll ind = new_ind[i];
    while (true) {
      int next = upper_bound(a.begin(), a.end(), psa[ind]) - a.begin() - 1;
      if (ind == next) break;
      ind = next;
    }
    cout << ind << " ";
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