#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t, n;
    char c;
    cin >> t;
    while (t--) {
        cin >> n;
        pair<int,int> r[n+1];
        r[0] = {0,0};
        for (int i = 1; i <= n; i++) {
            cin >> c;
            r[i].first = r[i-1].first + (c == 'K');
            r[i].second = r[i-1].second + (c == 'D');
        }
        for (int i = 1; i <= n; i++) {
            int g = __gcd(r[i].first,r[i].second);
            if (g > 1) {
                r[i].first /= g;
                r[i].second /= g;
            }
        }
        map<pair<int,int>,int> p;
        int pref[n];
        for (int i = 1; i <= n; i++) {
            p[r[i]]++;
            pref[i-1] = p[r[i]];
        }
        for (int& i: pref) cout << i << " ";
        cout << "\n";
    }
   
    return 0;
}