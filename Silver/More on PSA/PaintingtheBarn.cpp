#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("paintbarn.in","r",stdin);
    freopen("paintbarn.out","w",stdout);
    int n, k, x1, y1, x2, y2, ret = 0;
    cin >> n >> k;
    int arr[1001][1001] = {};
    for (int i = 0; i < n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        arr[x1][y1]++; arr[x1][y2]--; arr[x2][y1]--; arr[x2][y2]++;
    }
    for (int a = 0; a < 1001; a++) {
        for (int b = 0; b < 1001; b++) {
            if (a) arr[a][b] += arr[a-1][b];
            if (b) arr[a][b] += arr[a][b-1];
            if (a&&b) arr[a][b] -= arr[a-1][b-1];
            ret += arr[a][b] == k;
        }
    }
    cout << ret;
    
    return 0;
}