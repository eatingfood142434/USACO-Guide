#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int a[n];
    for (int& i: a) cin >> i;
    
    for (int i = 1; i < n; i++) a[i] = max(a[i], a[i-1]-m);
    for (int i = n-2; i >= 0; i--) a[i] = max(a[i], a[i+1]-m);
    
    for (const int& i: a) cout << i << " ";
    
    return 0;
}