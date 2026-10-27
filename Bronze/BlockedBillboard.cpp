#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout);
    int ax1, ay1, ax2, ay2;
    int bx1, by1, bx2, by2;
    int cx1, cy1, cx2, cy2;
    cin >> ax1 >> ay1 >> ax2 >> ay2;
    cin >> bx1 >> by1 >> bx2 >> by2;
    cin >> cx1 >> cy1 >> cx2 >> cy2;
    int ac_overlap = max(min(ax2, cx2) - max(ax1, cx1), 0) * max(min(ay2, cy2) - max(ay1, cy1), 0);
    int bc_overlap = max(min(bx2, cx2) - max(bx1, cx1), 0) * max(min(by2, cy2) - max(by1, cy1), 0);
    int ab_overlap = max(min(ax2, bx2) - max(ax1, bx1), 0) * max(min(by2, cy2) - max(by1, cy1), 0);
    cout << (ax2-ax1)*(ay2-ay1)+(bx2-bx1)*(by2-by1)-ab_overlap-bc_overlap-ac_overlap << "\n";
    return 0;
}