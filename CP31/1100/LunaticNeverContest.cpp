#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& i: a) cin >> i;
  vector<int> nums;
  for (int i = 0; i < n/2; i++) nums.push_back(abs(a[i]-a[n-i-1]));
  int ret = 0;
  for (int& i: nums) ret = gcd(ret,i);
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