#include <bits/stdc++.h>
using namespace std;
 
int main() {
    freopen("headshot.in", "r", stdin);
    freopen("headshot.out", "w", stdout);
    char t[102];
    char *s = t + 1;
    int a, b, x, y;
    a = b = x = y = 0;
    double i, j;
    scanf("%s", s);
    s[-1] = s[strlen(s) - 1];
    for (char *c = s; *c; c++) {
        if (*c == '1')
            a++;
        b++;
        if (*c == '1' && *(c - 1) == '0')
            x++;
        if (*c == '0')
            y++;
    }
    i = (double)a / (double) b;
    j = (double)x / (double) y;
    puts(fabs(i - j) < 1e-6 ? "EQUAL" : (i < j ? "ROTATE" : "SHOOT"));
    return 0;
}
