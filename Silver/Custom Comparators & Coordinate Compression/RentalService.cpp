#include <bits/stdc++.h>
using namespace std;

int getMilk(vector<pair<int,int>>& milk, int cow) {
    int amt = 0;
    for (int i = 0; i < milk.size(); i++) {
        if (cow >= milk[i].second) {
            amt += milk[i].first*milk[i].second;
            cow -= milk[i].second;
        }
        else {
            amt += milk[i].first*cow;
            break;
        }
    }
    return amt;
}

int extractMilk(vector<pair<int,int>>& milk, int cow) {
    int amt = 0;
    for (int i = milk.size()-1; i >= 0 && cow > 0; i--) {
        if (cow >= milk[i].second) {
            amt += milk[i].first*milk[i].second;
            cow -= milk[i].second;
            milk.pop_back();
        }
        else {
            amt += milk[i].first*cow;
            milk[i].second -= cow;
            break;
        }
    }
    return amt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);
    int n, m, r;
    cin >> n >> m >> r;
    vector<pair<int,int>> milk(m);
    vector<int> cows(n), rent(r);
    for (int& i: cows) cin >> i;
    for (auto& i: milk) cin >> i.second >> i.first;
    for (int& i: rent) cin >> i;
    sort(cows.begin(), cows.end(), greater<int>());
    sort(milk.begin(), milk.end());
    sort(rent.begin(), rent.end());
    int ret = 0;
    while (true) {
        if (getMilk(milk, cows.back()) < rent.back()) {
            ret += rent.back();
            cows.pop_back();
            rent.pop_back();
        }
        else break;
    }
    for (int& i: cows) {
        ret += extractMilk(milk, i);
    }
    cout << ret;
    
    return 0;
}