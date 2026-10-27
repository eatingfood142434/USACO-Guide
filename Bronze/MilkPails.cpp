#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("pails.in", "r", stdin);
	freopen("pails.out", "w", stdout);
    int x, y, m;
    cin >> x >> y >> m;
    int n;
    int maximum;
    for (int i = 0; i < m; i++) {
        if (i*x > m) break;
        for (int j = 0; j < m; j++) {
            n = i*x + j*y;
            if (n > m) break;
            maximum = max(maximum, n);
        };
    }
    cout << maximum << "\n";
    return 0;
}