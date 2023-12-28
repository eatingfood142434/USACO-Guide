#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("lemonade.in","r",stdin);
    freopen("lemonade.out","w",stdout);
    int n, amt = 0;
    cin >> n;
    vector<int> a(n);
    for (int& i: a) cin >> i;
    sort(a.begin(), a.end(), greater<int>());
    for (int i = 0; i < n; i++) {
        if (a[i] >= amt) amt++;
    }
    cout << amt;
    
    return 0;
}