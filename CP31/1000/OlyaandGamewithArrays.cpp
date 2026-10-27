#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
  int n, m, min_array = INT_MAX;
  cin >> n;
  vector<vector<int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> m;
    for (int j = 0, temp; j < m; j++) {
      cin >> temp;
      a[i].push_back(temp);
      min_array = min(min_array,temp);
    }
    nth_element(a[i].begin(), a[i].begin()+2, a[i].end());
    sort(a[i].begin(), a[i].begin()+2);
  }
  
  ll sum = 0;
  int min_second = INT_MAX;
  for (int i = 0; i < n; i++) min_second = min(min_second,a[i][1]);
  for (int i = 0; i < n; i++) sum += a[i][1];
  sum += min_array - min_second;

  return sum;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) cout << solve() << "\n";

  return 0;
}