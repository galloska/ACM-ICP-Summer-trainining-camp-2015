#include <bits/stdc++.h>
using namespace std;
 
 
 
int main() {
    freopen("acm.in", "r", stdin);
    freopen("acm.out", "w", stdout);
    int n, m, a, i;
    int l[11];
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++) {
        scanf("%d", &a);
        l[i] = a;
    }
    while (m--) {
        scanf("%d", &a);
    }
    for (i = 0; i < n; i++) {
        printf("(10");
        while (l[i]--) {
            printf("-1");
        }
        printf(")");
        if (i + 1 < n) {
            printf("*");
        }
    }
    puts("=0");
}
