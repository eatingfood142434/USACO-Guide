#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, d;
  cin >> n >> d;
  vector<int> p(n);
  for (int& i: p) cin >> i;
  sort(p.begin(), p.end(), greater<int>());
  int ret = 0, used = n;
  for (int i = 0; i < n; i++) {
    // cout << "used before: " << used << "\n";
    used -= floor(d/(double)(p[i]))+1;
    // cout << "p[i]: " << p[i] << ", used after:" << used << "\n";
    if (used < 0) break;
    ret++;
  }
  cout << ret << "\n";
}