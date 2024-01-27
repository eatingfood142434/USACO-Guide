#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for (int& i: a) cin >> i;
    int psa_f[n], psa_r[n];
    psa_f[0] = a[0], psa_r[n-1] = a[n-1];
    for (int i = 1; i < n; i++) {
        psa_f[i] = __gcd(psa_f[i-1], a[i]);
        psa_r[n-i-1] = __gcd(psa_r[n-i], a[n-i-1]);
    }
    
    int ret = max(psa_f[n-2], psa_r[1]);
    for (int i = 0; i < n-2; i++) ret = max(ret, __gcd(psa_f[i], psa_r[i+2]));
    cout << ret;
    
    return 0;
}