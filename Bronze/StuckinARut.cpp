#include <bits/stdc++.h>
using namespace std;

struct Cow {
    int ind;
    int x, y;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<Cow> north;
    vector<Cow> east;
    char dir;
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> dir >> x >> y;
        if (dir == 'N') north.push_back({i, x, y});
        else east.push_back({i, x, y});
    }

    sort(north.begin(), north.end(), [&](const Cow &c1, const Cow &c2) { return c1.x < c2.x;});
    sort(east.begin(), east.end(), [&](const Cow &c1, const Cow &c2) { return c1.y < c2.y;});
    
    vector<int> stop(n, -1);
    int ndist, edist;
    for (const Cow &ncow: north) {
        for (const Cow &ecow: east) {
            if (ncow.x > ecow.x && ncow.y < ecow.y) {
                ndist = ecow.y - ncow.y;
                edist = ncow.x - ecow.x;
                if (ndist < edist && stop[ecow.ind] == -1) {
                    stop[ecow.ind] = edist;
                }
                if (ndist > edist && stop[ecow.ind] == -1) {
                    stop[ncow.ind] = ndist;
                    break;
                }
            }
        }
    }

	for (int d : stop) cout << (d == -1 ? "Infinity" : to_string(d)) << '\n';
    return 0;
}