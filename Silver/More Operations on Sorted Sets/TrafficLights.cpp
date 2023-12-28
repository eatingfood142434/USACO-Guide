#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int x, n, t;
    cin >> x >> n;
    set<int> lights{0,x};
    multiset<int> dists{x};
    while (n--) {
        cin >> t;
        auto hpos = lights.upper_bound(t);
        dists.insert({*hpos-t,t-*--hpos});
        dists.erase(dists.find(*++hpos-*--hpos));
        lights.insert(t);
        cout << *--dists.end() << "\n";
    }
    return 0;
}