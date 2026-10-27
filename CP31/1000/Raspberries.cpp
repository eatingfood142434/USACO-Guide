#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t, n, k;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    if (k != 4) {
      int ret = k;
      for (int i = 0; i < n; i++) {
        int diff = a[i]%k;
        if (diff == 0) ret = 0;
        else ret = min(ret,k-diff);
      }
      cout << ret << "\n";
    }
    else {
      if (n == 1) {
        int diff = a[0]%k;
        if (diff == 0) cout << "0\n";
        else cout << k-diff << "\n";
      }
      else {
        int mod2 = 0;
        bool mod3 = false;
        for (int i = 0; i < n; i++) {
          if (a[i] % 4 == 3) mod3 = true;
          if (a[i] % 8 == 0) mod2 += 3;
          else if (a[i] % 4 == 0) mod2 += 2;
          else if (a[i] % 2 == 0) mod2++;
        }
        if (mod2 >= 2) cout << "0\n";
        else if (mod3) cout << "1\n";
        else if (mod2 == 0) cout << "2\n";
        else cout << "1\n";
      }
    }
  }

  return 0;
}