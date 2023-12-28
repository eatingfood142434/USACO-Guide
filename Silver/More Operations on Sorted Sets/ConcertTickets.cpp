#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, price;
    cin >> n >> m;
    multiset<int> t;
    for (int i = 0; i < n; i++) {cin >> price; t.insert(price);}
    while (m--) {
        cin >> price;
        auto it = t.upper_bound(price);
        if (it == t.begin()) cout << -1 << "\n";
        else {cout << *--it << "\n"; t.erase(it);}
    }

    return 0;
}