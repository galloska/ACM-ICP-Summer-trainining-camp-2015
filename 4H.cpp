#include <bits/stdc++.h>
using namespace std;
 
vector< int > al[5005];
int cl[5005];
bool b[22];
int n, k, m;
 
void f(int i, int c) {
    if (cl[i]) {
        return;
    }
    fill_n(b, k + 1, false);
    for (auto j : al[i]) {
        b[cl[j]] = true;
    }
    while (b[c]) {
        c = (c % k) + 1;
    }
    cl[i] = c;
    for (auto j : al[i]) {
        f(j, (c % k) + 1);
    }
}
 
int main() {
    freopen("galaxy.in", "r", stdin);
    freopen("galaxy.out", "w", stdout);
    int a, b;
    scanf("%d%d%d", &n, &k, &m);
    while (m--) {
        scanf("%d%d", &a, &b);
        al[a].push_back(b);
        al[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        sort(al[i].begin(), al[i].end());
    }
    for (int i = 1; i <= n; i++) {
        if (cl[i] == 0)
            f(i, 1);
    }
    //f(1, 1);
    for(int i = 1; i <= n; i++) {
        printf("%d ", cl[i]);
    }
    puts("");
    return 0;
}
