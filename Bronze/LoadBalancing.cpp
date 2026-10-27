#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    int n;
    cin >> n;
    vector<pair<int,int>> coords(n);
    for (int i = 0; i < n; i++) cin >> coords[i].F >> coords[i].S;
    vector<pair<int,int>> coordsx = coords, coordsy = coords;
    sort(coordsx.begin(), coordsx.end());
    sort(coordsy.begin(), coordsy.end(), [](const pair<int,int>& l, const pair<int,int>& r){return l.S < r.S;});
    
    int linex = 0, liney = 0, bl = 0, br = 0, tl = 0, tr = n, ret = n;
    for (int x = 0; x < n; x++) {
        linex = coordsx[x].F;
        while (linex == coordsx[x+1].F) x++;
        tl = x+1;
        tr = n-x-1;
        br = 0;
        bl = 0;
        for (int y = 0; y < n; y++) {
            liney = coordsy[y].S;
            if (coordsy[y].F <= linex) {
                bl++;
                tl--;
            }
            else {
                br++;
                tr--;
            }
            ret = min(ret, max({tl,tr,bl,br}));
        }
    }
    cout << ret;
    
    return 0;
}