#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int& i: a) cin >> i;
    sort(a.begin(), a.end());
    long long l = 0, h = 2e9+1, mid = (l+h)/2, amt = 0, maxmed = 0;
    while (h-l > 1) {
        amt = 0;
        for (int i = n/2; i < n; i++) amt += max(0ll, mid-a[i]);
        if (amt <= k) {
            maxmed = max(maxmed, mid);
            l = mid;
        }
        else if (amt > k) h = mid;
        mid = (l+h)/2;
    }
    cout << maxmed;
    
    return 0;
}