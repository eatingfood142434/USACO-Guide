#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    map<char,int> moves {{'H',0},{'P',1},{'S',2}};
    int n;
    char t;
    cin >> n;
    int arr[n];
    int psa[3][n+1]; psa[0][0] = 0; psa[1][0] = 0; psa[2][0] = 0;
    for (int& i: arr) {
        cin >> t;
        i = moves[t];
    }
    for (int i = 0; i < 3; i++) {
        for (int k = 1; k < n+1; k++) {
            psa[i][k] = psa[i][k-1] + (arr[k-1] == i);
        }
    }
    
    int ret = 0, max_1 = 0, max_2 = 0;
    for (int i = 0; i < n; i++) {
        max_1 = 0; max_2 = 0;
        max_1 = max({psa[0][i]-psa[0][0], psa[1][i]-psa[1][0], psa[2][i]-psa[2][0]});
        max_2 = max({psa[0][n]-psa[0][i], psa[1][n]-psa[1][i], psa[2][n]-psa[2][i]});
        ret = max(ret, max_1+max_2);
    }
    cout << ret;
    return 0;
}