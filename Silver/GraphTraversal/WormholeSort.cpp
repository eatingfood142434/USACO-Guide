#include <bits/stdc++.h>
using namespace std;

struct Wormhole{int a,b,w;};

class DSU {
  private:
	vector<int> parent;
	vector<int> size;

  public:
	DSU(int size) : parent(size), size(size, 1) {
		for (int i = 0; i < size; i++) parent[i] = i;
	}

	int get_top(int n) {
		return parent[n] == n ? n : (parent[n] = get_top(parent[n]));
	}

	bool link(int n1, int n2) {
		n1 = get_top(n1);
		n2 = get_top(n2);
		if (n1 == n2) return false;
		if (size[n2] > size[n1]) return link(n2, n1);
		parent[n2] = n1;
		size[n1] += size[n2];
		return true;
	}
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("wormsort.in","r",stdin);
    freopen("wormsort.out","w",stdout);
    int n, m, max_width = 0;
    bool sorted = true;
    cin >> n >> m;
    int cows[n];
    for (int i = 0; i < n; i++) {
        cin >> cows[i];
        cows[i]--;
        if (cows[i] != i) sorted = false;
    }
    if (sorted) {cout << -1; return 0;}
    
    Wormhole holes[m];
    for (Wormhole& w: holes) {
        cin >> w.a >> w.b >> w.w;
        w.a--; w.b--;
        max_width = max(max_width, w.w);
    }
    
    int l = 0, h = max_width+1, mid, valid = -1;
    bool sortable;
    while (h >= l) {
        mid = (h+l)/2;
        sortable = true;
        DSU dsu(n);
        for (const Wormhole w: holes) if (w.w >= mid) dsu.link(w.a, w.b);
        for (int i = 0; i < n; i++) {
            if (dsu.get_top(i) != dsu.get_top(cows[i])) {
                sortable = false;
                break;
            }
        }
        if (sortable) {
            valid = mid;
            l = mid+1;
        }
        else h = mid-1;
    }
    cout << (valid == max_width+1?-1:valid);
    
    return 0;
}