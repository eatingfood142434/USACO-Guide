#include <bits/stdc++.h>
using namespace std;

struct Visit {int s, e, ind;};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, num = 0, t = 0;
    set<pair<int,int>> rooms;
    vector<int> people(200000,0);
    cin >> n;
    vector<Visit> visits(n);
    for (Visit& v: visits) {cin >> v.s >> v.e; v.ind = t++;}
    sort(visits.begin(), visits.end(), [](const Visit a, const Visit b){return a.e < b.e;});
    for (auto& [s,e,ind]: visits) {
        auto it = rooms.lower_bound({s,0});
        if (it != rooms.begin()) {
            t = (--it)->second;
            people[ind] = t;
            rooms.erase(it);
            rooms.insert({e,t});
        }
        else {
            num++;
            rooms.insert({e,num});
            people[ind] = num;
        }
    }
    cout << num << "\n";
    for (int& i: people) {
        if (i == 0) break;
        cout << i << " ";
    }
    
    return 0;
}