#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream cin ("cowsignal.in");
    ofstream cout ("cowsignal.out");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n, k;
    cin >> m >> n >> k;
    char c[n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c[j];
        }
        for (int p = 0; p < k; p++) {
            for (char ch: c) {
                for (int u = 0; u < k; u++) cout << ch;
            }
            cout << endl;
        }
    }
    return 0;
}