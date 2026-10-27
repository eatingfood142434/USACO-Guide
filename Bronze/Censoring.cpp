#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream fin ("censor.in");
    ofstream fout ("censor.out");
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str, sub, censored;
    fin >> str >> sub;

    for (int i = 0; i < str.size(); i++) {
        censored += str[i];
        if (censored.size() > sub.size() && censored.substr(censored.size() - sub.size()) == sub) {
			censored.resize(censored.size() - sub.size());
        }
    }

    fout << censored << endl;
    return 0;
}