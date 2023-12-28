#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    char flats[n];
    set<char> types;
    for (char& i: flats) {
        cin >> i;
        types.insert(i);
    }
    unordered_map<char,int> p_count;
    set<char> pokemon;
    int low = 0, ret = INT_MAX;
    for (int i = 0; i < n; i++) {
        p_count[flats[i]]++;    
        while (low + 1 <= i && p_count[flats[low]] > 1) p_count[flats[low++]]--;
        if (p_count.size() == types.size()) ret = min(ret, i-low+1);
    }
    cout << ret;
    
    return 0;
}