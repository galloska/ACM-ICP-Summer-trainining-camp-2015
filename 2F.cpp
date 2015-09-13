#include <bits/stdc++.h>
using namespace std;
 
 
 
pair< pair< int, int >, int > xa[1000001];
int w, h, x_1, y_1, x_2, y_2, i, j, xs;
 
char m[1003][1003];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
 
void bt(int i) {
    stack< pair< int, int > > s;
    while (i != -1) {
        s.push(make_pair(xa[i].first.first, xa[i].first.second));
        i = xa[i].second;
    }
    while (!s.empty()) {
        printf("%d %d\n", s.top().second, s.top().first);
        s.pop();
    }
}
 
int main() {
    freopen("dfsongrid.in", "r", stdin);
    freopen("dfsongrid.out", "w", stdout);
    scanf("%d%d%d%d%d%d", &w, &h, &y_1, &x_1, &y_2, &x_2);
    gets(m[0]);
    for (i = 1; i <= h; i++) {
        gets(m[i] + 1);
    }
    xa[0] = make_pair(make_pair(x_1, y_1), -1);
    xs = 1;
    m[x_1][y_1] = 0;
    for (i = 0; i < xs; i++) {
        if (xa[i].first.first == x_2 && xa[i].first.second == y_2) {
            puts("YES");
            bt(i);
            exit(0);
        }
        for (j = 0; j < 4; j++) {
            if (m[xa[i].first.first - dx[j]][xa[i].first.second - dy[j]] == '.') {
                m[xa[i].first.first - dx[j]][xa[i].first.second - dy[j]] = 0;
                xa[xs++] = make_pair(make_pair(xa[i].first.first - dx[j], xa[i].first.second - dy[j]), i);
            }
        }
    }
    puts("NO");
    return 0;
}
