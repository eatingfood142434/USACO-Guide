#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("haybales.in","r",stdin);
    freopen("haybales.out","w",stdout);
    int n, q, t1, t2;
    cin >> n >> q;
    vector<int> b(n);
    for (int& i: b) cin >> i;
    sort(b.begin(), b.end());
    while (q--) {
        cin >> t1 >> t2;
        cout << upper_bound(b.begin(), b.end(), t2)-lower_bound(b.begin(), b.end(), t1) << "\n";
    }
    
    return 0;
}