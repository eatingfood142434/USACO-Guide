#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("billboard.in", "r", stdin);
	//freopen("billboard.out", "w", stdout);
    int ax1, ay1, ax2, ay2;
    int bx1, by1, bx2, by2;
    cin >> ax1 >> ay1 >> ax2 >> ay2;
    cin >> bx1 >> by1 >> bx2 >> by2;
    pair<int, int> c1, c2; 
    if (ax1 < bx1 || ay1 < by1) c1 = {ax1, ay1};
    else c1 = {ax2, by1};
    if (ax2 > bx2 || ay2 > by2) c2 = {ax2, ay2};
    else c2 = {ax1, by2};
    cout << (c2.first - c1.first) * (c2.second - c1.second) << "\n";
    return 0;
}