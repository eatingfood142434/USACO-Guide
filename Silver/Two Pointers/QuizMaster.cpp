#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t, n, m, temp;
    cin >> t;
    while (t--) {
        bool cont = false;
        cin >> n >> m;
        set<int> students;
        vector<int> proficient(m-1,0);
        map<int,vector<int>> amts;
        for (int i = 0; i < n; i++) {cin >> temp; students.insert(temp);}
        if (m > *(--students.end())) {cout << "-1\n"; continue;}
        for (const int& s: students) {
            for (int i = 2; i <= m; i++) {
                if ((s%i) == 0) {
                    amts[s].push_back(i-2);
                    proficient[i-2]++;
                }
            }
        }
        if (proficient.size() == 0) {
            if (students.size() > 0 && m == 1) cout << "0\n";
            else cout << "-1\n";
            continue;
        }
        for (int& i: proficient) if (i == 0) {cout << "-1\n"; cont = true; break;}
        if (cont) continue;
        vector<int> proficient1(m-1,0);
        auto low = amts.begin();
        int ret = INT_MAX;
        bool stop, stop1;
        for (auto high = amts.begin(); high != amts.end(); high++) {
            for (const int& i: high->second) proficient1[i]++;
            stop = false; stop1 = false;
            for (const int& i: proficient1) if (i == 0) {stop1 = true; break;}
            if (stop1) continue;
            while (true) {
                for (const int& i: low->second) if (proficient1[i] == 1) {stop = true; break;}
                if (stop) break;
                for (const int& i: low->second) proficient1[i]--;
                low++;
            }
            ret = min(ret, high->first-low->first);
        }
        cout << ret << "\n";
    }

    return 0;
}