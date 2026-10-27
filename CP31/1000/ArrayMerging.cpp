#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int& i: a) cin >> i;
  for (int& i: b) cin >> i;
  unordered_map<int,int> longest_a;
  unordered_map<int,int> longest_b;
  
  longest_a[a[0]] = 1;
  int curr = a[0], streak = 1;
  for (int i = 1; i < n; i++) {
    if (a[i] == curr) streak++;
    else {
      streak = 1;
      curr = a[i];
    }
    longest_a[curr] = max(longest_a[curr],streak);
  }
  longest_b[b[0]] = 1;
  curr = b[0];
  streak = 1;
  for (int i = 1; i < n; i++) {
    if (b[i] == curr) streak++;
    else {
      streak = 1;
      curr = b[i];
    }
    longest_b[curr] = max(longest_b[curr],streak);
  }
  int ret = 0;
  for (auto& i: a) ret = max(ret,longest_a[i]+longest_b[i]);
  for (auto& i: b) ret = max(ret,longest_a[i]+longest_b[i]);
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) cout << solve() << "\n";
}