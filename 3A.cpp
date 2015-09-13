#include <bits/stdc++.h>
using namespace std;
 
int n, m;
list< int > al[100001];
int col[100001];
//int in[100001];
 
void paint(int i, int nc) {
    if (col[i] == nc)
        return;
    if (col[i]) {
        puts("NO");
        exit(0);
    }
    col[i] = nc;
    for (auto j : al[i])
        paint(j, nc == 1 ? 2 : 1);
}
 
int main() {
    int i, a, b;
    freopen("bipartite.in", "r", stdin);
    freopen("bipartite.out", "w", stdout);
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &a, &b);
        al[a].push_back(b);
        al[b].push_back(a);
    }
    for (i = 1; i <= n; i++) {
        if(col[i] == 0) paint(i, 1);
    }
    puts("YES");
    for (i = 1; i <= n; i++) {
        printf("%d ", col[i]);
    }
    puts("");
    return 0;
}
