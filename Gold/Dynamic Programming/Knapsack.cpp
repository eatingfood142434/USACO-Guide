#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;

struct Item{int v, w, amt;};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int s, n;
    cin >> s >> n;
    Item items[n];
    for (Item& i: items) cin >> i.v >> i.w >> i.amt;
    sort(items, items+n, [](const Item& a, const Item& b){return a.v > b.v;});
    ll dp[s+1] = {}; dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = s; j >= 0; j--) {
            int a = min(items[i].amt, (int)ceil(((double)s-j)/items[i].w));
            if (j+items[i].w*a <= s && dp[j] > 0) dp[j+items[i].w*a] = max(dp[j+items[i].w*a],dp[j]+items[i].v*a);
        }
    }
    cout << *max_element(dp, dp+s+1)-1;
    
    return 0;
}