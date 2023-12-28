#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    int n;
    cin >> n;
    int arr[n];
    long long psa[n+1]; psa[0] = 0;
    for (int& i: arr) cin >> i;
    for (int i = 1; i < n+1; i++) psa[i] = psa[i-1] + arr[i-1];
    int range = n+2;
    while (true) {
        range--;
        for (int i = 0; i < n-range+1; i++) {
            if ((psa[range+i]-psa[i]) % 7 == 0) {
                cout << range;
                return 0;
            }
        }
        if (range == 0) {
            cout << 0;
            return 0;
        }
    }
    return 0;
}