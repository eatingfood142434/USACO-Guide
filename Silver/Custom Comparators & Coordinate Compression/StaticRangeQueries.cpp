#include <bits/stdc++.h>
using namespace std;

vector<int> indx;
int new_indx(int l) {
    return lower_bound(indx.begin(),indx.end(),l)-indx.begin();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    
    vector<pair<int,int>> updates(2*n), queries(q);
    for (int i=0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        updates[2*i] = {a,c}; updates[2*i+1] = {b,-c};
        indx.push_back(a); indx.push_back(b);
    }
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        queries[i] = {a,b};
        indx.push_back(a); indx.push_back(b);
    }
    sort(indx.begin(), indx.end());
    indx.erase(unique(indx.begin(), indx.end()), indx.end());
    long long diff[indx.size()] = {}, psa[indx.size()] = {};
    for (auto& u: updates) diff[new_indx(u.first)+1] += u.second;
    for (int i=1; i <= indx.size(); i++) diff[i] += diff[i-1];
    for (int i=1; i < indx.size(); i++) psa[i] = psa[i-1] + diff[i]*(indx[i]-indx[i-1]);
    
    for(auto u: queries) cout << psa[new_indx(u.second)] - psa[new_indx(u.first)] << endl;
    
    return 0;
}