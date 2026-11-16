#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string solve() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n), b(n), c(n);
  for (int& i: a) cin >> i;
  for (int& i: b) cin >> i;
  for (int& i: c) cin >> i;
  int start = 0;
  for (int& i: a) {
    if (!((start|i|x)&(~x))) start |= i;
    else break;
  }
  for (int& i: b) {
    if (!((start|i|x)&(~x))) start |= i;
    else break;
  }
  for (int& i: c) {
    if (!((start|i|x)&(~x))) start |= i;
    else break;
  }
  return (start == x) ? "Yes" : "No";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) cout << solve() << "\n";

  return 0;
}