#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Res {
  ll amt;
  ll cost;
};

ll solve() {
  ll n, p;
  cin >> n >> p;
  vector<ll> a(n), b(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  vector<Res> r;
  for (int i = 0; i < n; i++) if (b[i] < p) r.push_back({a[i],b[i]});
  sort(r.begin(),r.end(),[](const auto& p1, const auto& p2){return p1.cost < p2.cost;});

  if (r.empty()) return n*p;
  ll cost = p;
  n--;
  for (int i = 0; i < r.size() && n > 0; i++) {
    cost += r[i].cost*min(n,r[i].amt);
    n -= r[i].amt;
  }
  if (n > 0) cost += n*p;
  return cost;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) cout << solve() << "\n";

  return 0;
}