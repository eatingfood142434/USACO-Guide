#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, t;
    cin >> t;
    while (t--) {
        cin >> n;
        int arr[n];
        for (int& i: arr) cin >> i;
        
        int ret = 0;
        for (int i = 1; i < n; i++) {
            int diff = max(0, arr[i-1]-arr[i]);
            if (diff) {
                arr[i] = arr[i-1];
                diff = log2(diff)+1;
            }
            ret = max(ret, diff);
        }
        cout << ret << "\n";
    }

    return 0;
}