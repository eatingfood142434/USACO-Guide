#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("speeding.in", "r", stdin);
	freopen("speeding.out", "w", stdout);
    int nroad, nbessie;
    int rroad[100];
    int len, speed, dif, max = 0;
    int pos = 0;
    scanf("%d %d", &nroad, &nbessie);
    for (int i = 0; i < nroad; i++) {
        scanf("%d %d", &len, &speed);
        for (int j = 0; j < len; j++) {
            rroad[pos] = speed;
            pos++;
        }
    }

    pos = 0;
    for (int i = 0; i < nbessie; i++) {
        scanf("%d %d", &len, &speed);
        if (pos == 100) pos = 99;
        dif = speed - rroad[pos];
        if (dif > max) max = dif;
        pos += len;
    }
    printf("%d", max);
}