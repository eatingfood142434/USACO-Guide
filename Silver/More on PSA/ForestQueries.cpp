#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q, x1, y1, x2, y2;
    char temp;
    cin >> n >> q;
    int forest[n][n], psa[n+1][n+1] = {};
    for (auto& a: forest) for (int& b: a) {cin >> temp; b = (temp == '*') ? 1: 0;}
    for (int a = 1; a <= n; a++) for (int b = 1; b <= n; b++) psa[a][b] = psa[a][b-1] + psa[a-1][b] - psa[a-1][b-1] + forest[a-1][b-1];
    
    while (q--) {
        cin >> y1 >> x1 >> y2 >> x2;
        cout << psa[y2][x2]-psa[y1-1][x2]-psa[y2][x1-1]+psa[y1-1][x1-1] << "\n";
    }

    return 0;
}