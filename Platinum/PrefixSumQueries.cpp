#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Data {ll sum, pref;};
vector<Data> tree;

Data combine(Data l, Data r) {
    Data res;
    res.sum = l.sum+r.sum;
    res.pref = max(l.pref, l.sum+r.pref);
    return res;
}

Data findMaxPref(ll n, ll n_low, ll n_high, ll q_low, ll q_high) {
    if (q_low <= n_low && n_high <= q_high) return tree[n];
    if (n_high < q_low || n_low > q_high) return {0,0};
    
    ll mid = (n_low+n_high)/2;
    return combine(findMaxPref(2*n, n_low, mid, q_low, q_high), findMaxPref(2*n+1, mid+1, n_high, q_low, q_high));
}

void upd(ll n, ll n_low, ll n_high, ll pos, ll val) {
    if (n_low == n_high) tree[n] = {val,max(0ll,val)};
    else {
        ll mid = (n_low+n_high)/2;
        if (pos <= mid) upd(2*n, n_low, mid, pos, val);
        else upd(2*n+1, mid+1, n_high, pos, val);
        tree[n] = combine(tree[2*n], tree[2*n+1]);  
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q, c, l, r;
    cin >> n >> q;
    vector<ll> a(n);
    for (ll& i: a) cin >> i;
    while (__builtin_popcount(n) != 1) {
        a.push_back(0);
        n++;
    }
    tree.resize(2*n);
    
    for (int i = 0; i < n; i++) tree[n+i] = {a[i],max(0ll,a[i])};
    for (int i = n-1; i >= 0; i--) tree[i] = combine(tree[2*i], tree[2*i+1]);
    
    while (q--) {
        cin >> c >> l >> r;
        if (c == 2) cout << findMaxPref(1, 0, n-1, l-1, r-1).pref << "\n";
        else upd(1, 0, n-1, l-1, r);
    }

    return 0;
}