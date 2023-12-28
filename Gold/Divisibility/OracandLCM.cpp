#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<int,multiset<int>> factorexp;
vector<int> primes;
bool is_composite[(int)sqrt(200000)];
int lim = sqrt(200000);

void init() {
    for (int i = 2; i*i <= 200000; i++) {
        if (!is_composite[i]) primes.push_back(i);
        for (int j = 0; j < primes.size() && i*primes[j] < lim; j++) {
            is_composite[i*primes[j]] = true;
            if (i%primes[j] == 0) break;
        }
    }
}

void factor(int n) {
	map<int,int> factors;
	for (int& i: primes) {
		while (n%i == 0) {
			n /= i;
			factors[i]++;
		}
	}
	if (n > 1) factors[n]++;
	for (pair<int,int> primes: factors) factorexp[primes.first].insert(primes.second);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    init();
    int n, a;
    ll ret = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        factor(a);
    }
    for (auto it = factorexp.begin(); it != factorexp.end(); it++) {
        if ((it->second).size() == n-1) ret *= pow(it->first,*(it->second).begin());
        else if ((it->second).size() == n) ret *= pow(it->first,*(++(it->second).begin()));
    }
    cout << ret;
    
    return 0;
}