#include <bits/stdc++.h>
using namespace std;
 
int b[51][51];
 
int main() {
    int n, m, i, j;
    b[1][1] = 1;
    freopen("knight.in", "r", stdin);
    freopen("knight.out", "w", stdout);
    for (i = 1; i <= 50; i++) {
        for (j = 1; j <= 50; j++) {
            if (i >= 3 && j >= 2) {
                b[i][j] += b[i - 2][j - 1];
            }
            if (i >= 2 && j >= 3) {
                b[i][j] += b[i - 1][j - 2];
            }
        }
    }
    scanf("%d%d", &n, &m);
    printf("%d\n", b[n][m]);
    return 0;
}
