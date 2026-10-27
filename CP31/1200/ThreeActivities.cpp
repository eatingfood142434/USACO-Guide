#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<vector<int>> a(n,vector<int>(2,0)), b(n,vector<int>(2,0)), c(n,vector<int>(2,0));
    for (int i = 0, temp; i < n; i++) {
      cin >> temp;
      a[i] = {temp,i};
    }
    for (int i = 0, temp; i < n; i++) {
      cin >> temp;
      b[i] = {temp,i};
    }
    for (int i = 0, temp; i < n; i++) {
      cin >> temp;
      c[i] = {temp,i};
    }
    nth_element(a.begin(), a.begin()+2, a.end(), [](const auto& e1, const auto& e2){return e1[0] > e2[0];});
    nth_element(b.begin(), b.begin()+2, b.end(), [](const auto& e1, const auto& e2){return e1[0] > e2[0];});
    nth_element(c.begin(), c.begin()+2, c.end(), [](const auto& e1, const auto& e2){return e1[0] > e2[0];});

    // for (int i = 0; i < 3; i++) cout << a[i][0] << "," << a[i][1] << " ";
    // cout << "\n";
    // for (int i = 0; i < 3; i++) cout << b[i][0] << "," << b[i][1] << " ";
    // cout << "\n";
    // for (int i = 0; i < 3; i++) cout << c[i][0] << "," << c[i][1] << " ";
    // cout << "\n";

    int curr = 0;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
          if (a[i][1] == b[j][1] || b[j][1] == c[k][1] || a[i][1] == c[k][1]) continue;
          curr = max(curr, a[i][0]+b[j][0]+c[k][0]);
        }
      }
    }
    cout << curr << "\n";
  }

  return 0;
}