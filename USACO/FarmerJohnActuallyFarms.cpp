#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Plant{ll h, g, t, ind;};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        Plant p[n];
        for (Plant& i: p) cin >> i.h;
        for (Plant& i: p) cin >> i.g;
        for (Plant& i: p) cin >> i.t;
        if (n <= 1) {
            cout << 0 << "\n";
            continue;
        }
        for (int i = 0; i < n; i++) p[i].ind = i;
        sort(p, p+n, [](const Plant& a, const Plant& b){return a.t > b.t;});
        
        ll ret = INT_MIN;
        bool invalid = false;
        for (int i = 1; i < n; i++) {
            if (p[i].g <= p[i-1].g) {
                if (p[i].h <= p[i-1].h) {
                    invalid = true;
                    break;
                }
            }
            else ret = max(ret, (ll)floor((double)(p[i].h-p[i-1].h)/(p[i-1].g-p[i].g)+1));
        }
        for (int i = 1; i < n; i++) {
            if (p[i].h + p[i].g*ret <= p[i-1].h + p[i-1].g*ret) {
                invalid = true;
                break;
            }
        }
        
        if (!invalid && ret == INT_MIN) cout << 0 << "\n";
        else if (invalid || ret < 0) cout << -1 << "\n";
        else cout << ret << "\n";
    }

    return 0;
}