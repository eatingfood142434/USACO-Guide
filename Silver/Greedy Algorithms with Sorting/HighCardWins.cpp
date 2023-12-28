#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("highcard.in","r",stdin);
    freopen("highcard.out","w",stdout);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int& i: a) cin >> i;
    sort(a.begin(), a.end());
    int c = 1, d = 0;
    for (int i = 0; i < n; i++) {
        for (int j = c; j < a[i]; j++) b[d++] = j;
        c = a[i]+1;
    }
    for (int i = a[n-1]+1; i <= 2*n; i++) b[d++] = i;
    int p = 0, ret = n;
    for (int i = 0; i < n; i++,p++) {
        while (a[i] > b[p] && p < n) p++;
        if (p >= n) {ret = i; break;}
    }
    cout << ret;
    
    return 0;
}