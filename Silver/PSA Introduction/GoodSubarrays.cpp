#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, t;
    char c;
    cin >> t;
    while (t--) {
        cin >> n;
        int arr[n], psa[n+1]; psa[0] = 0;
        for (int i = 0; i < n; i++) {cin >> c; arr[i] = c-'0';}
        for (int i = 1; i <= n; i++) psa[i] = psa[i-1] + arr[i-1];
        map<int,long long> dists;
        for (int i = 0; i <= n; i++) dists[psa[i]-i]++;
        long long ret = 0;
        for (const auto& [_,d]: dists) ret += d*(d-1)/2;
        cout << ret << "\n";
    }
    
    return 0;
}