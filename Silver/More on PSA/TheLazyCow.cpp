#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("lazy.in", "r", stdin);
    freopen("lazy.out", "w", stdout);
    int n, k, ret = 0;
    cin >> n >> k;
    if (n == 1) {cin >> k; cout << k; return 0;}
    int arr[n][n], temp[2*n-1][2*n-1] = {}, psa[2*n][2*n] = {};
    for (auto& a: arr) for (int& b: a) cin >> b;
    for (int r = 0; r < n; r++) for (int c = 0; c < n; c++) temp[r+c][n-1+c-r] = arr[r][c];
    for (int r = 1; r < 2*n; r++) for (int c = 1; c < 2*n; c++) psa[r][c] = psa[r-1][c] + psa[r][c-1] - psa[r-1][c-1] + temp[r-1][c-1];
    for (int r = k; r < 2*n-1-k; r++) {
        for (int c = k; c < 2*n-1-k; c++) {
            if (temp[r][c] == -1) continue;
            ret = max(ret, psa[r+k+1][c+k+1]-psa[r-k][c+k+1]-psa[r+k+1][c-k]+psa[r-k][c-k]);
        }
    }
    
    if (k >= n) ret = psa[2*n-1][2*n-1];
    
    cout << ret;
    
    return 0;
}