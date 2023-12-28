#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    int arr[n];
    int psa[3][n+1]; psa[0][0] = 0; psa[1][0] = 0; psa[2][0] = 0;
    for (int& i: arr) cin >> i;
    for (int k = 0; k < 3; k++) {
        for (int i = 1; i < n+1; i++) {
            psa[k][i] = psa[k][i-1];
            if (arr[i-1] == k+1) psa[k][i]++;
        }
    }
    
    int a, b;
    while (q--) {
        cin >> a >> b;
        for (int i = 0; i < 3; i++) {
            cout << psa[i][b] - psa[i][a-1];
            if (i < 2) cout << " ";
            }
        if (q != 0) cout << "\n";
    }

    return 0;
}