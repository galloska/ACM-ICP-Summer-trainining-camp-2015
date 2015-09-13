#include <bits/stdc++.h>
using namespace std;
 
 
struct Job {
    int a, b;
    bool operator<(const Job& x) const {
        return min(this->a, x.b) < min(this->b, x.a);
    }
};
Job ja[1000001];
 
int main() {
    int n, r = 0, q = 0, i, j;
    freopen("climb.in", "r", stdin);
    freopen("climb.out", "w", stdout);
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d%d", &(ja[i].a), &(ja[i].b));
    }
    sort(ja, ja + n);
    r = 0;
    i = j = 0;
    while (i < n) {
        if (ja[i].a < q) {
            r += ja[i].a;
            q -= ja[i].a;
            q += ja[i].b;
            i++;
        } else {
            r += ja[i].a;
            q = ja[i].b;
            i++;
        }
    }
    printf("%d\n", r + q);
    return 0;
}
