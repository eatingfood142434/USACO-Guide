#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, t;
    cin >> t;
    while (t--) {
        cin >> n;
        int a[n], r[n], l[n];
        for (int& i: a) cin >> i;
        for (int i = 0; i < n; i++) {
            r[i] = a[i]-i;
            l[i] = a[i]+i;
        }
        for (int i = 1; i < n; i++) l[i] = max(l[i-1], l[i]);
        for (int i = n-2; i >= 0; i--) r[i] = max(r[i], r[i+1]);
        
        int ret = 0;
        for (int i = 1; i < n-1; i++) ret = max(ret, l[i-1]+a[i]+r[i+1]);
        cout << ret << "\n";
    }
    
    return 0;
}