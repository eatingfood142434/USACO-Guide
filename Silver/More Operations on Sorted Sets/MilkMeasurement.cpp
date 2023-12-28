#include <bits/stdc++.h>
using namespace std;

struct Cow {int d, id, change;};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("measurement.in","r",stdin);
    freopen("measurement.out","w",stdout);
    int n, g, num = 0, changes = 0;
    cin >> n >> g;
    vector<Cow> cows(n);
    map<int,int> cow_to_milk, milk_to_cow{{g,n}};
    for (Cow& c: cows) {
        cin >> c.d >> c.id >> c.change;
        cow_to_milk[c.id] = g;
    }
    sort(cows.begin(), cows.end(), [](const Cow& a, const Cow& b){return a.d < b.d;});
    
    int prev_milk, prev_amt, curr_amt;
    bool was_top, is_top;
    
    for (const Cow& c: cows) {
        prev_milk = cow_to_milk[c.id];
        was_top = prev_milk == milk_to_cow.rbegin()->first;
        prev_amt = milk_to_cow[prev_milk];
        
        cow_to_milk[c.id] += c.change;
        milk_to_cow[prev_milk]--;
        if (milk_to_cow[prev_milk] == 0) milk_to_cow.erase(prev_milk);
        milk_to_cow[cow_to_milk[c.id]]++;
        
        is_top = cow_to_milk[c.id] == milk_to_cow.rbegin()->first;
        curr_amt = milk_to_cow[cow_to_milk[c.id]];
        
        if (was_top) {
            if (is_top && prev_amt == curr_amt) continue;
            changes++;
        }
        else if (is_top) changes++;
    }
    cout << changes;
   
    return 0;
}