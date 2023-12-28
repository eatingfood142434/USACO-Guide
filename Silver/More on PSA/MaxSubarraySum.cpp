#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int arr[n]; long long psa[n+1]; psa[0] = 0;
    for (int& i: arr) cin >> i;
    for (int i = 0; i < n; i++) psa[i+1] = psa[i] + arr[i];
    long long min_i = psa[0], max_i = psa[1];
    for (int i = 1; i <= n; i++) {
        max_i = max(max_i, psa[i]-min_i);
        min_i = min(min_i, psa[i]);
    }
    cout << max_i;
    
    return 0;
}