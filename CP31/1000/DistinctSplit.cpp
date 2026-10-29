#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solve() {
  int n;
  cin >> n;
  vector<char> a(n);
  for (char& c: a) cin >> c;
  unordered_map<char,int> occ1, occ2; 
  for (char& c: a) occ2[c]++;
  int ret = occ2.size();
  for (int i = 0; i < n; i++) {
    occ1[a[i]]++;
    occ2[a[i]]--;
    if (occ2[a[i]] == 0) occ2.erase(a[i]);
    ret = max(ret,(int)(occ1.size()+occ2.size()));
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