#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("square.in", "r", stdin);
	freopen("square.out", "w", stdout);
    int a, b, c, d;
    int e, f, g, h;
    cin >> a >> b >> c >> d;
    cin >> e >> f >> g >> h;
    int len = max(max(c, g) - min(a, e), max(d, h) - min(b, f));
    cout << len * len << "\n";
    return 0;
}