#include <bits/stdc++.h>
using namespace std;

struct Friend {int h, w, id;};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<Friend> friends(n);
        for (int i = 0; i < n; i++) {
            cin >> friends[i].h >> friends[i].w; friends[i].id = i;
            if (friends[i].h < friends[i].w) swap(friends[i].h, friends[i].w);
        }
        sort(friends.begin(), friends.end(), [](const Friend& a, const Friend& b){if (a.h == b.h) return a.w < b.w; return a.h < b.h;});
        // for (Friend& f: friends) cout << f.h << " " << f.w << " " << f.id+1 << "\n";
        vector<int> ret(n,-1);
        Friend pointer = friends[0], nextpointer = friends[0];
        for (int i = 1; i < n; i++) {
            if (friends[i].w > pointer.w && friends[i].h > friends[i-1].h) pointer = nextpointer;
            if (friends[i].w > pointer.w && friends[i].h > pointer.h) ret[friends[i].id] = pointer.id+1;
            else if (friends[i].w < pointer.w) nextpointer = friends[i];
        }
        for (int& i: ret) cout << i << " ";
        cout << "\n";
    }
    
    return 0;
}