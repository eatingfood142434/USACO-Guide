#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int zeroes = 0, ones = 0;
    for (const char& c: s) {
      if (c == '0') zeroes++;
      else ones++;
    }
    zeroes = min(zeroes, ones);
    ones = min(zeroes, ones);

    // cout << zeroes << " " << ones << "\n";
    
    int stop = 0;
    for (int i = 0; i < s.size(); i++) {
      stop = i;
      if (s[i] == '0') zeroes--;
      else ones--;
      if (zeroes < 0 || ones < 0) break;
    }
    if (zeroes >= 0 && ones >= 0) stop = s.size();
    cout << s.size()-stop << "\n";
  }

  return 0;
}