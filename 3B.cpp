#include <bits/stdc++.h>
using namespace std;
 
#define MAXN 50005
 
int ft[MAXN + 1];
 
void update(int i, int v) {
    while (i < MAXN) {
        ft[i] += v;
        i += (i & -i);
    }
}
 
int read(int i) {
    int v = 0;
    while (i) {
        v += ft[i];
        i -= (i & -i);
    }
    return v;
}
 
int main() {
    int n, i, a[500002], r = 0;
    pair< int, int > p[500002];
    freopen("inverse.in", "r", stdin);
    freopen("inverse.out", "w", stdout);
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        p[i] = make_pair(a[i], i);
    }
    sort(p, p + n);
    for (i = 0; i < n; i++) {
        a[p[i].second] = i + 2;
    }
    for (i = n - 1; i >= 0; i--) {
        update(a[i], 1);
        r += read(a[i] - 1);
    }
    printf("%d\n", r);
    return 0;
}
