#include <bits/stdc++.h>
using namespace std;

struct Cow {int x, y, ind;};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    char c;
    int n, x1, y1;
    vector<Cow> n_cows, e_cows;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c;
        cin >> x1 >> y1;
        if (c == 'N') n_cows.push_back({x1,y1,i});
        else e_cows.push_back({x1,y1,i});
    }
    sort(n_cows.begin(), n_cows.end(), [](const Cow& a, const Cow& b){return a.x < b.x;});
    sort(e_cows.begin(), e_cows.end(), [](const Cow& a, const Cow& b){return a.y < b.y;});
    
    map<int,int> blocked;
    vector<int> amt_blocks(n,0);
    for (Cow& n_cow: n_cows) {
        for (Cow& e_cow: e_cows) {
            if (blocked[e_cow.ind] || blocked[n_cow.ind] || n_cow.x-e_cow.x < 0 || e_cow.y-n_cow.y < 0) continue;
            if (n_cow.x-e_cow.x > e_cow.y-n_cow.y) {
                // n_cow blocks e_cow
                blocked[e_cow.ind] = 1;
                amt_blocks[n_cow.ind] += amt_blocks[e_cow.ind]+1;
            }
            else if (e_cow.y-n_cow.y > n_cow.x-e_cow.x) {
                // e_cow blocks n_cow
                blocked[n_cow.ind] = 1;
                amt_blocks[e_cow.ind] += amt_blocks[n_cow.ind]+1;
            }
        }
    }
    for (int& i: amt_blocks) cout << i << "\n";
   
    return 0;
}